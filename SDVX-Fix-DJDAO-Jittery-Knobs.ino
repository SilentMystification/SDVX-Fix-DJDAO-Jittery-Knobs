/*
This code is a stripped down version of the code found here: https://sdvx-diy.github.io/

It only includes the logic for handling knobs as this is intended to be used
to fix issues with the knob handling on the stock DJDAO boards

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "./src/Encoder/Encoder.h"
#include <Mouse.h>

/* Encoder */
#define ENC_1_PIN_A 0
#define ENC_1_PIN_B 1
#define ENC_2_PIN_A 2
#define ENC_2_PIN_B 3

/* Encoder */
Encoder encLeft(ENC_1_PIN_A, ENC_1_PIN_B);
Encoder encRight(ENC_2_PIN_A, ENC_2_PIN_B);

/* Startup Loop */
void setup() {
  Mouse.begin();
}

/* Main Loop */
void loop() {
  encFuncLeft();
  encFuncRight();
}

void encFuncLeft(){
  Mouse.move(encLeft.read(), 0, 0);
  encLeft.write(0);
}

void encFuncRight(){
  Mouse.move(0, encRight.read(), 0);
  encRight.write(0);
}
