# Reverse Engineering of the Xbox 360 ChatPad



This is a guide on how to get started with replacing the microcontroller on the official Xbox 360 chatpad. During my research, there were too many broken links/inconsistencies with the current documentation. The model that I had in particular, could not be flashed with the PIC firmware that was circulating as it had the Microsoft branded chip in it. I wanted to have something that would not require any drivers to use, so it could be easily transferrable between different projects. I used a RPi Pico in this project, but any QMK compatible board can be used.

Most of the images included in this guide are just rough notes that I have taken throughout my project, I wanted to share with those that are interested, and hope that it all makes sense.


# Mapping Out The Chip Pins

One thing I had to do when first starting off, was to find out which pin was which on the original microcontroller. I desoldered the old chip and started probing with the multimeter. At the same time, I had to figure out how the keyboard matix was laid out on the board, so on top of mapping the pins I was noting the layout of the keys.

As you can see on the keymap image, it appears that things were started by one engineer, then someone else took over to quickly finish things off before releasing. One half seems to make sense, the rest doesn't. I noted in the image for each key what row and column they belong to. I treated the area marked in yellow as a separate column.



<p align="center">
  <img width="80%" src="docs/static/img/chatpad pin mapping.jpg">
</p>


<p align="center">
  <img width="80%" src="docs/static/img/chatpad keymap.jpg">
</p>





# Connecting to the Pico
This part of the guide is more to point you in the right direction, there are many possible ways of doing this. Although it might not have been the cleanest method, I soldered a ribbon cable connecting all the GPIO pins on the Pico to the vias on the 360 Chatpad board. For 3.3v and GND I used TP5 and TP8. I probably could have soldered directly to the pins where the old microcontroller was, but I did not do a good job with desoldering and some of the pads were lifted int he process. One thing not noted in the image below is the Circle LED indicator, I did not see any vias nearby, so I just scraped my own solder pad on the PCB trace.
If you do want to solder through the vias, you will have to peel off the white sticker holding all the buttons, as well as making sure your soldering is flush on the opposite side of the board.

<p align="center">
  <img width="80%" src="docs/static/img/360 chatpad vias.jpg">
</p>


# Programming the Pico

Once all the hardware parts were completed, it was time to move onto the software. For this, I used the QMK firmware. This project is very well documentated, but can still be intimidating at first. I have created a QMK firmware that semi-works for me, there are still issues that I need to sort out with it. Hopefully it will get you started with getting something functional.





# Obligatory Disclaimer
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.