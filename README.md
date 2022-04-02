# PCB ETHCHER

###### CURRENT VERSION : 1.0.2
###### All updates made to this project are mentioned in the **versionlist.txt** file.

## ABOUT ME
* A controller based programmable PCB etcher.
* Etching is a PCB making process through which PCBs can be made. 
* Etching-a-PCB method is great for prototyping or creating simple PCBs yourself.
* This project's primary motive is to automate the process of Etching so that no human intervention is required while the process is going on.
* You can read more on the process of etching [here](https://www.protoexpress.com/blog/wet-pcb-etching-acidic-alkaline-methods/#:~:text=PCB%20etching%20is%20a%20process%20of%20removal%20of%20unwanted%20copper,like%20chiseling%20the%20circuit%20board.).

* Controller used in this project is Arduino Nano.
* This project involves Electronic circuitry and C-programming as well.
* To make this project you first need to build the electronic circuitry to get the complete set of features that comes with it.
* After the hardware is created...debug the same using example codes provided in the **/code files/examples** folder.
* After all peripherals are tested...upload the controller.ino code provided in the **/code files/controller** folder.

## STEPS TO MAKE THE BOARD
* Schematic Diagrams, Bill Of Materials, Board Routing files are provided in the **/PCB files** folder.
* Create a PCB either via Etching, GPP, or by paying a professional to create it for you.\
*NOTE: The routing of the board has been done specifically to accomodate GPP boards...for those hobbyists who cannot purchase or etch PCBs.*
* Assemble and solder all the components.

## STEPS TO RUN THE SOFTWARE
* Download the zip files provided in the **/code files/libraries** directory and add them to the Arduino library.
* The files mentioned above are the library files required for driving the OLED.
* Open the **controller.ino** file through the arduino software and upload the code to your Arduino Nano controller.
* The device is now ready!

## HOW TO USE THE DEVICE
![Img](https://github.com/benahalkar/PCB_ETCHER/blob/main/images/PWM.jpg)

* Initially the device starts in SETUP mode.
* Here, you can set the parameters of the etching process with the help of 3 trimmers/potentiometers.
* The first potentiometer sets the time (in seconds) duration for which the motor will remain ON (T on).
* The second potentiometer sets the time (in seconds) duration for which the motor will remain OFF (T off).
* This turning ON and OFF of the motor is called a cycle.
* The third potentiometer sets the time (in minutes) duration for which the cycles shall occur (T total).
* All the values that are set during the SETUP mode time are visible on the OLED screen.
* Once you are satisfied with the parameters set, then press the button to initiate the etching process.
* During this time the device is in ETCHING mode.
* During Etching mode, the time left is displayed on the OLED.
* After the etching process is completed, the BUZZER will be activated and shall remain so until the user presses the button again. This has been done to ensure that the etching process is not over-done.

=================================================================\

If you have further queries...then do not hesitate to contact me on mail.

This application has been designed to act as a simple solution to automate the etching process; however, do let me know if you have any suggestions on improving the application.