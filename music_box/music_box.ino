// Ben Andrews
// PHYS333 Final Project: Music Box
// 2018-4-10

#include "music_box.h"

#define SPEAKER_PIN 13

void setup() 
{
    pinMode(SPEAKER_PIN, OUTPUT);
}

int selector = 0;
void loop() 
{
    switch(selector)
    {
        case 0:
            c_scale();
            break;
        case 1:
            happy_birthday();
            break;
        case 2:
            star_wars();
            break;
    }
}


// play the c scale, pun intended
void c_scale()
{
    play_note(SPEAKER_PIN, C4, HNOTE);
    play_note(SPEAKER_PIN, D4, HNOTE);
    play_note(SPEAKER_PIN, E4, HNOTE);
    play_note(SPEAKER_PIN, F4, HNOTE);
    play_note(SPEAKER_PIN, G4, HNOTE);
    play_note(SPEAKER_PIN, A4, HNOTE);
    play_note(SPEAKER_PIN, B4, HNOTE);
    play_note(SPEAKER_PIN, C5, HNOTE);

    QREST 

    play_note(SPEAKER_PIN, C5, HNOTE);
    play_note(SPEAKER_PIN, B4, HNOTE);
    play_note(SPEAKER_PIN, A4, HNOTE);
    play_note(SPEAKER_PIN, G4, HNOTE);
    play_note(SPEAKER_PIN, F4, HNOTE);
    play_note(SPEAKER_PIN, E4, HNOTE);
    play_note(SPEAKER_PIN, D4, HNOTE);
    play_note(SPEAKER_PIN, C4, HNOTE);
}


// play happy birthday
void happy_birthday()
{
    // 3/4
    // key: F Major
    play_note(SPEAKER_PIN, C4, DENOTE); // hap
    play_note(SPEAKER_PIN, C4, SNOTE); // py

    play_note(SPEAKER_PIN, D4, QNOTE); // birth
    play_note(SPEAKER_PIN, C4, QNOTE); // day
    play_note(SPEAKER_PIN, F4, QNOTE); // to
    
    play_note(SPEAKER_PIN, E4, HNOTE); // you
    play_note(SPEAKER_PIN, C4, DENOTE); // hap
    play_note(SPEAKER_PIN, C4, SNOTE); // py

    play_note(SPEAKER_PIN, D4, QNOTE); // birth 
    play_note(SPEAKER_PIN, C4, QNOTE); // day
    play_note(SPEAKER_PIN, G4, QNOTE); // to
    
    play_note(SPEAKER_PIN, F4, HNOTE); // you
    play_note(SPEAKER_PIN, C4, DENOTE); // hap
    play_note(SPEAKER_PIN, C4, SNOTE); // py

    play_note(SPEAKER_PIN, C5, QNOTE); // birth
    play_note(SPEAKER_PIN, A4, QNOTE); // day
    play_note(SPEAKER_PIN, F4, QNOTE); // dear

    play_note(SPEAKER_PIN, E4, QNOTE); //Na
    play_note(SPEAKER_PIN, D4, DHNOTE); //than -fermata

    play_note(SPEAKER_PIN, BF4, DENOTE); // hap
    play_note(SPEAKER_PIN, BF4, SNOTE); // py

    play_note(SPEAKER_PIN, A4, QNOTE); // birth
    play_note(SPEAKER_PIN, F4, QNOTE); // day
    play_note(SPEAKER_PIN, G4, QNOTE); // to

    play_note(SPEAKER_PIN, F4, HNOTE); // you
}


// play the star_wars anthem
void star_wars()
{
    // 4/4
    // G Major
    play_note(SPEAKER_PIN, D4, TRIPLT); // 0
    play_note(SPEAKER_PIN, D4, TRIPLT);
    play_note(SPEAKER_PIN, D4, TRIPLT);
    
    play_note(SPEAKER_PIN, G4, HNOTE); // 1
    play_note(SPEAKER_PIN, D5, HNOTE);
    
    play_note(SPEAKER_PIN, C5, TRIPLT); // 2
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, A4, TRIPLT);
    play_note(SPEAKER_PIN, G5, HNOTE);
    play_note(SPEAKER_PIN, D5, QNOTE);
    
    play_note(SPEAKER_PIN, C5, TRIPLT); // 3
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, A4, TRIPLT);
    play_note(SPEAKER_PIN, G5, HNOTE);
    play_note(SPEAKER_PIN, D5, QNOTE);
    
    play_note(SPEAKER_PIN, C5, TRIPLT); // 4
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, C5, TRIPLT);
    play_note(SPEAKER_PIN, A4, HNOTE);
    play_note(SPEAKER_PIN, D4, TRIPLT);
    play_note(SPEAKER_PIN, D4, TRIPLT);
    play_note(SPEAKER_PIN, D4, TRIPLT);
    
    play_note(SPEAKER_PIN, G4, HNOTE); // 5
    play_note(SPEAKER_PIN, D5, HNOTE);
    
    play_note(SPEAKER_PIN, C5, TRIPLT); // 6
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, A4, TRIPLT);
    play_note(SPEAKER_PIN, G5, HNOTE);
    play_note(SPEAKER_PIN, D5, QNOTE);
    
    play_note(SPEAKER_PIN, C5, TRIPLT); // 7
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, A4, TRIPLT);
    play_note(SPEAKER_PIN, G5, HNOTE);
    play_note(SPEAKER_PIN, D5, QNOTE);
    
    play_note(SPEAKER_PIN, C5, TRIPLT); // 8
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, C5, TRIPLT);
    play_note(SPEAKER_PIN, A4, HNOTE);
    play_note(SPEAKER_PIN, D4, DENOTE);
    play_note(SPEAKER_PIN, D4, SNOTE);
    
    play_note(SPEAKER_PIN, E4, DQNOTE); // 9
    play_note(SPEAKER_PIN, E4, ENOTE);
    play_note(SPEAKER_PIN, C5, ENOTE);
    play_note(SPEAKER_PIN, B4, ENOTE);
    play_note(SPEAKER_PIN, A4, ENOTE);
    play_note(SPEAKER_PIN, G4, ENOTE);
    
    play_note(SPEAKER_PIN, G4, TRIPLT); // 10
    play_note(SPEAKER_PIN, A4, TRIPLT);
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, A4, ENOTE);
    play_note(SPEAKER_PIN, E4, ENOTE);
    play_note(SPEAKER_PIN, FS4, QNOTE);
    play_note(SPEAKER_PIN, D4, DENOTE);
    play_note(SPEAKER_PIN, D4, SNOTE);
    
    play_note(SPEAKER_PIN, E4, DQNOTE); // 11
    play_note(SPEAKER_PIN, E4, ENOTE);
    play_note(SPEAKER_PIN, C5, ENOTE);
    play_note(SPEAKER_PIN, B4, ENOTE);
    play_note(SPEAKER_PIN, A4, ENOTE);
    play_note(SPEAKER_PIN, G4, ENOTE);
    
    play_note(SPEAKER_PIN, D5, DQNOTE); // 12
    play_note(SPEAKER_PIN, A4, ENOTE);  
    play_note(SPEAKER_PIN, FS4, QNOTE);
    play_note(SPEAKER_PIN, D4, DENOTE);
    play_note(SPEAKER_PIN, D4, SNOTE);

    play_note(SPEAKER_PIN, E4, DQNOTE); // 13
    play_note(SPEAKER_PIN, E4, ENOTE);
    play_note(SPEAKER_PIN, C5, ENOTE);
    play_note(SPEAKER_PIN, B4, ENOTE);
    play_note(SPEAKER_PIN, A4, ENOTE);
    play_note(SPEAKER_PIN, G4, ENOTE);

    play_note(SPEAKER_PIN, G4, TRIPLT); // 14
    play_note(SPEAKER_PIN, A4, TRIPLT);
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, A4, ENOTE);
    play_note(SPEAKER_PIN, E4, ENOTE);
    play_note(SPEAKER_PIN, FS4, QNOTE);
    play_note(SPEAKER_PIN, D5, DENOTE);
    play_note(SPEAKER_PIN, D5, SNOTE);

    play_note(SPEAKER_PIN, G5, ENOTE); // 15
    play_note(SPEAKER_PIN, F5, ENOTE);
    play_note(SPEAKER_PIN, EF5, ENOTE);
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, C5, ENOTE);
    play_note(SPEAKER_PIN, BF4, ENOTE);
    play_note(SPEAKER_PIN, A4, ENOTE);
    play_note(SPEAKER_PIN, G4, ENOTE);

    play_note(SPEAKER_PIN, FS4, HNOTE); // 16
    QREST
    play_note(SPEAKER_PIN, D4, TRIPLT);
    play_note(SPEAKER_PIN, D4, TRIPLT);
    play_note(SPEAKER_PIN, D4, TRIPLT);

    play_note(SPEAKER_PIN, G4, HNOTE); // 17
    play_note(SPEAKER_PIN, D5, HNOTE);

    play_note(SPEAKER_PIN, C5, TRIPLT); // 18
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, A4, TRIPLT);
    play_note(SPEAKER_PIN, G5, HNOTE);
    play_note(SPEAKER_PIN, D5, QNOTE);

    play_note(SPEAKER_PIN, C5, TRIPLT); // 19
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, A4, TRIPLT);
    play_note(SPEAKER_PIN, G5, HNOTE);
    play_note(SPEAKER_PIN, D5, QNOTE);

    play_note(SPEAKER_PIN, C5, TRIPLT); // 20
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, C5, TRIPLT);
    play_note(SPEAKER_PIN, A4, HNOTE);
    play_note(SPEAKER_PIN, D4, TRIPLT);
    play_note(SPEAKER_PIN, D4, TRIPLT);
    play_note(SPEAKER_PIN, D4, TRIPLT);

    play_note(SPEAKER_PIN, G4, HNOTE); // 21
    play_note(SPEAKER_PIN, D5, HNOTE);

    play_note(SPEAKER_PIN, C5, TRIPLT); // 22
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, A4, TRIPLT);
    play_note(SPEAKER_PIN, G5, HNOTE);
    play_note(SPEAKER_PIN, D5, QNOTE);

    play_note(SPEAKER_PIN, C5, TRIPLT); // 23
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, A4, TRIPLT);
    play_note(SPEAKER_PIN, G5, HNOTE);
    play_note(SPEAKER_PIN, D5, QNOTE);

    play_note(SPEAKER_PIN, C5, TRIPLT); // 24
    play_note(SPEAKER_PIN, B4, TRIPLT);
    play_note(SPEAKER_PIN, C5, TRIPLT);
    play_note(SPEAKER_PIN, A4, HNOTE);
    play_note(SPEAKER_PIN, D5, DENOTE);
    play_note(SPEAKER_PIN, D5, SNOTE);

    play_note(SPEAKER_PIN, G5, ENOTE); // 25
    play_note(SPEAKER_PIN, F5, ENOTE);
    play_note(SPEAKER_PIN, EF5, ENOTE);
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, C5, ENOTE);
    play_note(SPEAKER_PIN, BF4, ENOTE);
    play_note(SPEAKER_PIN, A4, ENOTE);
    play_note(SPEAKER_PIN, G4, ENOTE);
    
    play_note(SPEAKER_PIN, D5, QNOTE); // 26
    play_note(SPEAKER_PIN, G4, TRIPLT);
    play_note(SPEAKER_PIN, G4, TRIPLT);
    play_note(SPEAKER_PIN, G4, TRIPLT);
    play_note(SPEAKER_PIN, G4, QNOTE);
}


// play a note specified in the header file
long i;
void play_note(int pin, long note, long dur)
{
    dur /= note;

    for(i = 0; i < dur; ++i)
    {
        digitalWrite(pin, HIGH);
        delayMicroseconds(note);
    
        digitalWrite(pin, LOW);
        delayMicroseconds(note);
    }

    delay(6); // put some seperation between notes
}
