# Makerspace-RFID
This code distinguishes between keypresses and an RFID scan. 
It adds a prefix of an “R" for RFID or “K" for keypad before it sends the numbers via serial to another device (in our case a pi).
It also waits for a for enter to be pressed when typing a code in. The esc button on the keypad clears the code.
You should be able to this code with any Wigand device.

In our case we use it with the following devices:
https://www.amazon.com/gp/product/B00G4UF7NA/
https://www.amazon.com/UHPPOTE-125KHz-Wiegand-Control-Proximity/dp/B00UX01Z8S
