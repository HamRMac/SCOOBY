import asyncio
import json
import cv2
import websockets

class WebSocketClient:
    def __init__(self, websocket_url):
        self.websocket_url = websocket_url
        self.websocket = None
        self.connection_lock = asyncio.Lock()
    
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
            _, compressed_image = cv2.imencode('.webp', image, [int(cv2.IMWRITE_WEBP_QUALITY), 70])
            await self.websocket.send(compressed_image.tobytes())
            
            # Receive and process the result
            result = await self.websocket.recv()
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
