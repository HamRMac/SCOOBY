from gpiozero import DistanceSensor
from gpiozero import LED
import RPi.GPIO as GPIO
import time
#from gpiozero import Buzzer

#ultrasonic = DistanceSensor(echo=23, trigger=22, max_distance=1, threshold_distance=0.03)
led = LED(27)
#buzzer = Buzzer(GPIOpin)
GPIO.setmode(GPIO.BCM)
GPIO_TRIGGER = 22
GPIO_ECHO = 23
GPIO.setup(GPIO_TRIGGER, GPIO.OUT)
GPIO.setup(GPIO_ECHO, GPIO.IN)

def distance():
    # set Trigger to HIGH
    GPIO.output(GPIO_TRIGGER, True)
 
    # set Trigger after 0.01ms to LOW
    time.sleep(0.00001)
    GPIO.output(GPIO_TRIGGER, False)
 
    StartTime = time.time()
    StopTime = time.time()
 
    # save StartTime
    while GPIO.input(GPIO_ECHO) == 0:
        StartTime = time.time()
 
    # save time of arrival
    while GPIO.input(GPIO_ECHO) == 1:
        StopTime = time.time()
 
    # time difference between start and arrival
    TimeElapsed = StopTime - StartTime
    # multiply with the sonic speed (34300 cm/s)
    # and divide by 2, because there and back
    distance = (TimeElapsed * 34300) / 2
 
    return distance


while True:
    #print(ultrasonic.distance)
    #ultrasonic.threshold_distance = ???
    #ultrasonic.wait_for_in_range = function for lifting scooper
    #ultrasonic.wait_for_out_of_range = function
    while True:
        dist = distance()
        #print ("Measured Distance = %.1f cm" % dist)
        print(dist)
        time.sleep(0.1)
        if dist < 5:
            #print ("In Range")
            led.on()
            #time.sleep(1)
        else:
            led.off()
        
        #ultrasonic.wait_for_in_range()
        #print("In range")

        #buzzer.beep()
        #ultrasonic.wait_for_out_of_range()
        #print("Out of range")
        #led.off()


