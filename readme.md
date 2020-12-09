# A small piece of code to load onto an Arduino to handle the knobs on the SVSE5 and SVRE9

This program was made for the DJDAO controllers that have knob jittering issues. This is an issue that has affected many of the pre-2020 models of the SVSE5 and SVRE9. It might also affect the 2020 models but I have yet to find complaints that it does. Regardless this can be used with both models, pre and post 2020. 

##### Adding Funcionality
This code was stripped down to only handle the knobs from the DAO board. If you would like to wire everything including the buttons into the Arduino, please follow the original guide here: https://sdvx-diy.github.io/

##### Credits
Code for the encoder library was sourced from this [repository](https://github.com/PaulStoffregen/Encoder).
Code this repo was based off of: [repository](https://github.com/Reyn-Mukai/SDVX-DIY/tree/Standard).
Tutorial for assembling an entire controller instead of just repurposing the knobs: https://sdvx-diy.github.io/
DJDAO, creator / seller of the SVSE5 and SVSR9: https://www.gamo2.com/en/index.php
