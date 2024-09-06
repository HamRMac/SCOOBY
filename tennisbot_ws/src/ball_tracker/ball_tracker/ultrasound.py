from gpiozero import DistanceSensor
#from gpiozero import LED
#from gpiozero import Buzzer

ultrasonic = DistanceSensor(echo=16, trigger=15, max_distance=1, threshold_distance=0.03)
#led = LED(GPIOpin)
#buzzer = Buzzer(GPIOpin)

while True:
    print(ultrasonic.distance)
    #ultrasonic.threshold_distance = ???
    #ultrasonic.wait_for_in_range = function for lifting scooper
    #ultrasonic.wait_for_out_of_range = function
    while True:
        ultrasonic.wait_for_in_range()
        print("In range")
        #led.on()
        #buzzer.beep()
        ultrasonic.wait_for_out_of_range()
        print("Out of range")
        #led.off()
