import asyncio
import json
import cv2
import websockets

import time

import concurrent.futures

# Async encode function using a thread pool
async def encode_image_async(image):
    loop = asyncio.get_running_loop()
    with concurrent.futures.ThreadPoolExecutor() as pool:
        # Offload the image encoding to a separate thread
        result, compressed_image = await loop.run_in_executor(pool, cv2.imencode, '.webp', image, [int(cv2.IMWRITE_WEBP_QUALITY), 70])
        return compressed_image

class WebSocketClient:
    def __init__(self, websocket_url, logger):
        self.websocket_url = websocket_url
        self.websocket = None
        self.connection_lock = asyncio.Lock()
        self.logger = logger
        self.logger.info("Using .webp encoding with resize")
    
    async def connect(self):
        async with self.connection_lock:
            if self.websocket is None or self.websocket.closed:
                try:
                    self.websocket = await websockets.connect(self.websocket_url)
                    print("WebSocket connection established.")
                except Exception as e:
                    print(f"Failed to connect to WebSocket server: {e}")
                    self.websocket = None
    
    async def send_receive(self, image):
        await self.connect()  # Ensure connection is established
        if self.websocket is None:
            raise ConnectionError("WebSocket connection is not established.")
        
        try:
            # Compress the image using WebP
            process_time_start = time.time()
            resized_image = cv2.resize(image, (320, 320), interpolation=cv2.INTER_NEAREST)
            _, compressed_image = cv2.imencode('.webp', resized_image, [int(cv2.IMWRITE_WEBP_QUALITY), 50])
            #_, compressed_image = cv2.imencode('.png', image)
            #compressed_image = await encode_image_async(image)
            process_time_end = time.time()
            process_time = process_time_end - process_time_start
            self.logger.debug(f'Encoding Time: {process_time:.4f}')

            wait_time_start = time.time()
            await self.websocket.send(compressed_image.tobytes())
            
            # Receive and process the result
            result = await self.websocket.recv()
            #self.logger.info(str(result))

            # Calculate time
            wait_time_end = time.time()
            wait_time = wait_time_end - wait_time_start
            self.logger.debug(f'Server waiting Time: {wait_time:.4f}')
            return json.loads(result)
        
        except websockets.exceptions.ConnectionClosed as e:
            print(f"Connection closed unexpectedly: {e}")
            self.websocket = None  # Reset connection
            # Optionally, implement reconnection logic here
            raise e
        
        except Exception as e:
            print(f"An error occurred during send/receive: {e}")
            raise e
    
    async def close(self):
        async with self.connection_lock:
            if self.websocket and not self.websocket.closed:
                await self.websocket.close()
                print("WebSocket connection closed.")
