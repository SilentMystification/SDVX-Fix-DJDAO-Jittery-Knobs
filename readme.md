# A small piece of code to load onto an Arduino Leonardo to handle the knobs on the SVSE5 and SVRE9

This program was made for the DJDAO controllers that have knob jittering issues. This is an issue that has affected many of the pre-2020 models of the SVSE5 and SVRE9. It might also affect the 2020 models but I have yet to find complaints that it does. Regardless this can be used with both models, pre and post 2020. 

### What you need
* SVSE5 or SVRE9 controller that has knob jitter when spinning, especially when spinning quickly
* Arduino Leonardo or a Leonardo Clone (ATmega32U4 based)
    * MUST BE A LEONARD OR LEONARDO PRO MICRO, NOT AN UNO OR NANO OR OTHER
    * This must be something that is ATmega32U4 based otherwise you will not be able to use the Arduino as a HID USB device and SpiceTools will not be able to recognize this
* Some male to male jumper cables
or
* Wire and some soldering skills for something more permanent


### Adding Funcionality
This code was stripped down to only handle the knobs from the DAO board. If you would like to wire everything including the buttons into the Arduino, I recommend following the original guide this was based off of here: https://sdvx-diy.github.io/

### WHICH PINS TO USE
THIS IS EXTREMELY IMPORTANT!!! If you are using a Leonardo, ONLY wire up the knobs to pins 0, 1, 2, and 3. DO NOT CHANGE THIS IN CODE AND WIRE IT UP TO OTHER PINS.

The reason for this is because pins 0-3 are interrupt based and will update the the knob position as soon as it gets a signal on those pins instead of processing the knobs within the `loop()` function. Failure to do this can lead to jittery knobs and is what I hypothesize causes the problem on some DAO board. 

If you are using another board make sure that there are 4 interrupt pins and that all 4 data wires for the knobs are plugged into those pins

### Wiring things up
NOTE: Please be careful when wiring things up and make sure that grounds are connected to grounds and 5v/vcc is connected to 5v. My DAO board came wired correctly but the wire colors were very much not right with red ground wires and black 5v wires.

You can either use jumper wire to hook everything up if you don't want to make any destructive changes and then plug those into the Arduino or you can splice the wires and solder them to the arduino to make it a bit more permanent. Just make sure to connect the VCCs on the knobs with eachother and plug both into a `5v` pin and to connect the grounds and plug them into the `GND` pin.

Then wire things accordingly:
![image](https://github.com/SilentMystification/SDVX-Fix-DJDAO-Jittery-Knobs/blob/main/Wiring%20Diagram.png)

NOTE:
This leave the cables plugged into this board and plug your jumper wires into the other end of these cables in their appropriate locations

### Pushing the code to the Arduino
If you have experience with programming Arduinos, just push the included `SDVX-Fix-DJDAO-Jittery-Knobs.ino` to your device and skip to the next section.

* Download the Arduino IDE here:
    * https://www.arduino.cc/en/software

* Download this repository and rename the folder from `SDVX-Fix-DJDAO-Jittery-Knobs-main` to `SDVX-Fix-DJDAO-Jittery-Knobs`

* Open `...\SDVX-Fix-DJDAO-Jittery-Knobs\SDVX-Fix-DJDAO-Jittery-Knobs.ino

* Navigate to `Tools > Board` and Select `Leonardo` or `Leonardo ETH`, either should work but if youre having issues pushing code using `Leonardo ETH` switch to `Leonardo`

* Navigate to `Tools > Port` and choose your device (It will NOT be COM1, it'll be a differnet number) 

* Press the Upload arrow in the top left of the IDE or press `CTRL + U` to upload the code to the Arduino

* Wait till you get a `Done Uploading` confirmation on the bottom right and confirm that turning the knobs move the mouse



### Wrapping up
After everything is wired up plug the Arduino in without unplugging the original controller and go to SpiceTools or BTools and rebind your knobs to the Arduino. Depending on how you wired up the data pins your turn directions might be inverted but this can be corrected within SpiceTools or by rewiring and swapping pins 1 and 2 or pins 3 and 4

And wallah it's done! Enjoy jitter free knobs! Now you can confidently play USC or SDVX while knowing that every time the knob gets off of the track its 100% your fault!

### Credits
Code this repo was based off of this [repository](https://github.com/Reyn-Mukai/SDVX-DIY/tree/Standard).
Please check out [this guide](https://sdvx-diy.github.io/) if you would like to wire everything into the Arduino
DJDAO, creator / seller of the SVSE5 and SVSR9: https://www.gamo2.com/en/index.php
Code for the encoder library was sourced from this [repository](https://github.com/PaulStoffregen/Encoder).
