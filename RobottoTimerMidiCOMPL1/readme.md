       OneVoiceArduinoTimer with Robotto 
 speaking the count-off: One, two, three, four.
Run the RobottoTimerMidiCOMPL1.ino firmware to your Robotto via a FTDI interface
Add Midi-library, see ipeggio readme also
Robotto controls, the Pots, are used to control
- 1 the speed of the MuSiC.
- 2 the speed of the Robotto-voice
- 3 the brightness of the voice, called bend in the Babblebot chip
Connect a Midi-in and -out to the Tx and Rx on the Robotto and 
connect 5 Volt and Ground to the Midi-port.   
 Run the Robotto on your Euro-rack power. 
 - Midi-Channel 1 is to play in the basic notes and pattern
 - Midi-Channel 3 is used to play the ipeggio
 - Midi-Channel 10 is used to play a basic drum-pattern 

After use, run the "standard" Robotto-Firmware to the Robotto and it is default again,
Like yesterday. The standard Robotto-Firmware from Soundmachines is forked here on arpeggio1234
for easy taking the original firmware.
Have fun making MuSiC on the Fly
