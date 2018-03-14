## Frivolous Music Box

__Ben Andrews__  
PHYS 333 Final Project Proposal  
*3-12-17*  

#### Overview:
A small assembly of components that plays several (think 5ish) songs. The notes
for the music will be created with square waves. Only one note will be played at
a time limiting all music to only a melody. Once the Arduino is powered on it
will output music until power is lost, or until a tragic memory leak forces a
restart. Songs will be repeated until the user changes the song.

#### Data In:
There will be 2 knobs. One will change the current looping song. The other will
change the current beats per minute (BPM). These knobs may be substituted for
buttons, to be determined.

#### Data Out:
There will be a data line to a speaker to create tones with a modified PWM.
There will also be an LCD display to show the current song and BPM.

#### Computation and Control:
There will be several songs hard coded into the firmware. Each time the song
select knob is turned a CPU interrupt will be handled to switch the current
playing song without waiting for song completion. Each time the BPM is changed
an interrupt will be handled to update the length of every note and rest before
picking the song up where it was interrupted.

#### Stretch Goal:
Have a third knob to move songs up and down octaves. All notes would have to be
recomputed or scaled (to be determined).

#### Fall back:
If interrupt handling proves too difficult, do all computation between songs.

#### Hardware Requirements:
* Arduino
* Speaker
* LCD Display + optional I2C
* Components for high pass filter (to be determined)
* etc wires
