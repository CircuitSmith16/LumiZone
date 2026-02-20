# LumiZone
A project that addresses a real-life issue existing in common spaces mainly classrooms.
This project is aimed at reducing wastage of energy by timely switching off of devices when not in use.

Description:
This system divides the space into zones. Each zone consists of an ultrasonic sensor, a LDR, a load (in real-life : a fan and a light; for simulation: led and a servo)
The ultrasonic sensor has a set threshold. If a person is detected, the motor turns on. The LDR checks if the light intensity in the room is adequate. If the room is already well-lit, the light does not turn on. If the light level read by the LDR is below the threshold, the lights turn on.
If the person walks away from the sensor, there is a buffer time of 5 seconds (for simulation purposes. Can be modified for practical purposes) upto which the devices will run. After this buffer time, the devices will turn off.

(*ALL VALUES OF LIGHT,PROXIMITY AND TIME THRESHOLD VALUES ARE SET SOLELY FOR DEMONSTRATION PURPOSES. IF PRACTICALLY IMPLEMENTED, THESE VALUES REQUIRE PROPER SETTING)
