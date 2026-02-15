# LumiZone
A zone based system, that can be implemented in a classroom environment, to conserve electricity

Description:
This system divides the space into zones. Each zone consists of an ultrasonic sensor, a LDR, a load (in real-life : a fan and a light; for simulation: led and a servo)
The ultrasonic sensor has a set threshold. If a person is detected, the motor turns on. The LDR checks if the light intensity in the room is adequate. If its not adequate, the led turns on. 
If the person walks off from the sensor, there is a buffer time of 5 seconds upto which the devices will run. After this buffer time, the devices will turn off.
