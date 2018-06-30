During this Task i wanted to accomplish the mission of collecting the temprature data from 
the edge device(Arduino in this case) and share it back on the monitor,
through USB interfacing between the device and the back-end system 
NOTE: such concept can be implemented through other communication interfaces like wireless, Low Energy Bluetooth.
------------------------------------------------------------------
------------------------------------------------------------------

Behind the scenes: interrupt design pattern

I implemented the interrupt design pattern through configuring the switch pin on the arduino as a interrupt pin
when there is a rise in the signal on the pin which means that the switch is pressed, when this happens the led is on or off.
This pattern will prevent missing the switch event, this helps in forcing of executing 
essential actions during critical situations.

Main procceses

The task is composed of two main processes,
Background process which is the sensor publishing it's reading every 3 seconds on the monitor.
Froeground process which is the interrupt that happens when pressing the switch to set it on or of.

The sensor reading algorithm:

I connected the sensor to 5V pin so the maximum input to the arduino from the sensor is 5V 
which corresponds to integer value 1024 of the ADC, so the mv from the sensor = (value/1024)*5000
then every 10 mV corresponds to 1C so the temprature=mV*10


-------------------------------------------------------------------
-------------------------------------------------------------------
During this task i applied my konwldge and skills i have in :
- Dealing with Edge devices(Sensors, system-on-board Chips).
- Embeded programming.
- Connectivity.
- Using Github as code repository.
- Documentation
I applied the best practices in each of the above topics to enusre realibility and usability of the 
provided components.

