## Final Project Writeup
__Ben Andrews__  
PHYS 333  
*2018-4-30*  

#### Purpose
Use the Arduino as a music box like toy for entertainment/annoyance. To do this the bare minimum required is an Arduino and a speaker or passive buzzer. A little more flair was added by having an LCD display show the current song and BPM (beats per minute).

#### Future Work
To continue to expand on this project one would need to have knowledge of C/C++ and how the Arduino works. Beyond that, one would need to be able to understand the small API I created to play notes. Not much documentation was left, but I believe looking at the existing code for the songs written should be explanatory enough for anyone with basic music understanding.  
One future expansion could be rewriting the note API to store and play sine waves instead of square waves. This would give all around better sound if this could be achieved efficiently. Short of creating sine waves, creating sawtooth waves may prove more doable and would still give better sound with the added benefit of sounding like early game consoles.  
Another future expansion could be reading a file from an SD card and translating it to play through the API I created. This would make writing songs to be played dramatically easier and less tedious. An example of this file structure could be:
```
CN4, QUARTER
DN4, QUARTER
EN4, EIGHT
EN4, EIGHT
FS4, HALF
```

#### TODO
There currently aren't any known bugs or issues with the project because was scoped for success. One place for improvement would be finding a better way to handle the song and BPM interrupts. Currently saving the context stack with `setjmp` and jumping with `longjmp` is a cute trick, but ugly by principle. I can not currently think of a better way to do the song interrupts, but that does not mean it doesn't exist. As for the BPM interrupts, they would work without long jumping if it weren't for the LCD needing to be updated. Talking to the LCD over I2C while playing a note makes a  timer conflict that lead to an infinite loop somewhere.  
Another nice feature would be replacing the buttons that change the song and BPM with rotary encoders. This would allow the user to select what they want without having to cycle through all of the available options.  
Another improvement would be to put function pointers to all the songs in an array, and to have the song selector cycle through the array. This would allow the total number of songs to be derived rather than hard coded.
