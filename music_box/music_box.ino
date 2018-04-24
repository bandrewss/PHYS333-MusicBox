// Ben Andrews
// PHYS333 Final Project: Music Box
// 2018-4-10

#include <setjmp.h>
#include "music_box.h"

#define DEBOUNCE_TIME (200)

#define SPEAKER_PIN 13
#define SNG_SEL_PIN 2
#define BPM_SEL_PIN 3

static jmp_buf jump_buffer;

static volatile long time_pressed_sng = 0;
static volatile long time_pressed_bpm = 0;

static int selector = 0;

void setup() 
{
    Serial.begin(9600);
    
    pinMode(SPEAKER_PIN, OUTPUT);
    
    pinMode(SNG_SEL_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(SNG_SEL_PIN), change_song, RISING);

    pinMode(BPM_SEL_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(BPM_SEL_PIN), cycle_bpm, RISING);

    set_bpm(bpms[bpm_sel]);
}


// change the song selector to the next song, return to setjmp
void change_song()
{    
    if(millis() - time_pressed_sng < DEBOUNCE_TIME)
        return;

    time_pressed_sng = millis();
    
    //Serial.println("\nchanging the song");

    ++selector;
    selector %= 3;
    
    longjmp(jump_buffer, 1);
}


// cycle the bpm
void cycle_bpm()
{
    if(millis() - time_pressed_bpm < DEBOUNCE_TIME)
        return;

    time_pressed_bpm = millis();

    ++bpm_sel;
    bpm_sel %=  num_bpms;

    set_bpm(bpms[bpm_sel]);
}


void loop() 
{
    setjmp(jump_buffer);
    /*
    if(setjmp(jump_buffer))
    {
        Serial.println("returning from longjump");
        return;
    }
    else
    {
        Serial.println("set the jmp buffer");
    }
    */
    
    Serial.println("top of the loop");
    
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

    REST(WREST);
}


// set the duration of notes and rests based on given beats per minute
void set_bpm(int bpm)
{
    float bps = bpm / 60.0;

    float whole_notes_per_second = 4.0 / bps;
    
    long whole_note_micro = 1000000 * whole_notes_per_second;

    //long whole_note_micro = 1000000;

    Serial.println(whole_note_micro);

    // notes
    WNOTE = whole_note_micro;
    HNOTE = (WNOTE /2);
    QNOTE = (WNOTE /4);
    ENOTE = (WNOTE /8);
    SNOTE = (WNOTE /16);
    
    DHNOTE = (HNOTE + QNOTE);
    DQNOTE = (QNOTE + ENOTE);
    DENOTE = (ENOTE + SNOTE);
    
    TRIPLT = (QNOTE / 3);
    
    // rests
    WREST = WNOTE /1000;
    HREST = HNOTE /1000;
    QREST = QNOTE /1000;
    EREST = ENOTE /1000;
    SREST = SNOTE /1000;
}


// play a note based on the frequncy given in Hz, for duration given in microseconds
long i;
void play_note(int pin, long note, long dur)
{
    dur /= note * 2;

    for(i = 0; i < dur; ++i)
    {
        digitalWrite(pin, HIGH);
        delayMicroseconds(note);
    
        digitalWrite(pin, LOW);
        delayMicroseconds(note);
    }

    delay(6); // put some seperation between notes
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
    REST(QREST)
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
