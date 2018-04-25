// Ben Andrews
// PHYS333 Final Project: Music Box
// 2018-4-10

#include <Wire.h>
#include <setjmp.h>
#include <LiquidCrystal_I2C.h>

#include "music_box.h"

#define DEBOUNCE_TIME (200)

#define LCD_BLANK_LINE ("                ")

#define SPEAKER_PIN 13
#define SNG_SEL_PIN 2
#define BPM_SEL_PIN 3

static jmp_buf jump_buffer;

static volatile long time_pressed_sng = 0;
static volatile long time_pressed_bpm = 0;

static volatile int selector = 0;

static LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
    Serial.begin(9600);
    
    pinMode(SPEAKER_PIN, OUTPUT);
    
    pinMode(SNG_SEL_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(SNG_SEL_PIN), change_song, RISING);

    pinMode(BPM_SEL_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(BPM_SEL_PIN), cycle_bpm, RISING);

    lcd.init();
    lcd.backlight();
    lcd.clear();

     set_bpm(bpms[bpm_sel]);
}


// change the song selector to the next song, return to setjmp
void change_song()
{    
    if(millis() - time_pressed_sng < DEBOUNCE_TIME)
        return;

    time_pressed_sng = millis();

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
    
    Serial.println("top of the loop");
    
    switch(selector)
    {
        case 0:
            set_lcd_song("C Scale");
            c_scale();
            break;
        case 1:
            set_lcd_song("Happy Birthday");
            happy_birthday();
            break;
        case 2:
            set_lcd_song("Star Wars Theme");
            star_wars();
            break;
        case 3:
            set_lcd_song("Linus and Lucy");
            linus_and_lucy();
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
    set_lcd_bpm(bpm);

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


// set the bpm the lcd is displaying
void set_lcd_bpm(int bpm)
{
    lcd.setCursor(0, 1);
    lcd.print(LCD_BLANK_LINE);

    lcd.setCursor(0, 1);
    lcd.print("BPM: ");
    lcd.print(bpm);
}


// set the song title that the lcd is displaying
void set_lcd_song(char *song)
{
    lcd.setCursor(0, 0);
    lcd.print(LCD_BLANK_LINE);

    lcd.setCursor(0, 0);
    lcd.print(song);
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


// play the star wars anthem
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


// play linus and lucy, the peanuts anthem
void linus_and_lucy()
{
    // 4/4
    // C
    play_note(SPEAKER_PIN, C2, ENOTE); // 1
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, C3, ENOTE);
    play_note(SPEAKER_PIN, C2, ENOTE); 
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, C3, DQNOTE);

    play_note(SPEAKER_PIN, C2, ENOTE); // 2
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, A2, ENOTE);
    play_note(SPEAKER_PIN, C2, ENOTE); 
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, A2, DQNOTE);

    play_note(SPEAKER_PIN, C2, ENOTE); // 3
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, C3, ENOTE);
    play_note(SPEAKER_PIN, C2, ENOTE); 
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, C3, DQNOTE);

    play_note(SPEAKER_PIN, C2, ENOTE); // 4
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, A2, ENOTE);
    play_note(SPEAKER_PIN, C2, ENOTE); 
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, A2, DQNOTE);

    play_note(SPEAKER_PIN, C5, ENOTE); // 5
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, E5, QNOTE);
    play_note(SPEAKER_PIN, E5, ENOTE);
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, C5, QNOTE);

    play_note(SPEAKER_PIN, D5, DQNOTE); // 6
    play_note(SPEAKER_PIN, C5, ENOTE + HNOTE);

    play_note(SPEAKER_PIN, C5, ENOTE); // 7
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, E5, QNOTE);
    play_note(SPEAKER_PIN, E5, HNOTE + WNOTE); // 8

     play_note(SPEAKER_PIN, C5, ENOTE); // 9
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, E5, QNOTE);
    play_note(SPEAKER_PIN, E5, ENOTE);
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, C5, QNOTE);

    play_note(SPEAKER_PIN, D5, DQNOTE); // 10
    play_note(SPEAKER_PIN, C5, ENOTE + HNOTE);

    play_note(SPEAKER_PIN, C5, DQNOTE); // 11
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, D5, HNOTE + WNOTE); // 12

    play_note(SPEAKER_PIN, C5, DQNOTE); // 13A
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, D5, HNOTE + WNOTE); // 14A

    // **repeat**

    play_note(SPEAKER_PIN, C5, ENOTE); // 5
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, E5, QNOTE);
    play_note(SPEAKER_PIN, E5, ENOTE);
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, C5, QNOTE);

    play_note(SPEAKER_PIN, D5, DQNOTE); // 6
    play_note(SPEAKER_PIN, C5, ENOTE + HNOTE);

    play_note(SPEAKER_PIN, C5, ENOTE); // 7
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, E5, QNOTE);
    play_note(SPEAKER_PIN, E5, HNOTE + WNOTE); // 8

    play_note(SPEAKER_PIN, C5, ENOTE); // 9
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, E5, QNOTE);
    play_note(SPEAKER_PIN, E5, ENOTE);
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, C5, QNOTE);

    play_note(SPEAKER_PIN, D5, DQNOTE); // 10
    play_note(SPEAKER_PIN, C5, ENOTE + HNOTE);

    play_note(SPEAKER_PIN, C5, DQNOTE); // 11
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, D5, HNOTE + WNOTE); // 12

    play_note(SPEAKER_PIN, C5, DQNOTE); // 13B
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, D5, HNOTE + WNOTE); // 14B
    
    // end repeat

    play_note(SPEAKER_PIN, F5, ENOTE); // 16
    play_note(SPEAKER_PIN, F5, ENOTE);
    play_note(SPEAKER_PIN, F5, ENOTE);
    play_note(SPEAKER_PIN, G5, ENOTE);
    REST(EREST)
    play_note(SPEAKER_PIN, C6, ENOTE);
    play_note(SPEAKER_PIN, A5, ENOTE);
    play_note(SPEAKER_PIN, C6, ENOTE);
    
    play_note(SPEAKER_PIN, C6, ENOTE); // 17
    play_note(SPEAKER_PIN, A5, ENOTE);
    play_note(SPEAKER_PIN, C6, ENOTE);
    play_note(SPEAKER_PIN, C6, ENOTE);
    play_note(SPEAKER_PIN, A5, QNOTE);
    play_note(SPEAKER_PIN, G5, QNOTE);

    play_note(SPEAKER_PIN, F5, ENOTE); // 18
    play_note(SPEAKER_PIN, F5, ENOTE);
    play_note(SPEAKER_PIN, F5, ENOTE);
    play_note(SPEAKER_PIN, G5, ENOTE);
    REST(EREST)
    play_note(SPEAKER_PIN, C6, ENOTE);
    play_note(SPEAKER_PIN, A5, ENOTE);
    play_note(SPEAKER_PIN, C6, ENOTE);
    
    play_note(SPEAKER_PIN, C6, ENOTE); // 19
    play_note(SPEAKER_PIN, A5, ENOTE);
    play_note(SPEAKER_PIN, C6, ENOTE);
    play_note(SPEAKER_PIN, C6, ENOTE);
    play_note(SPEAKER_PIN, A5, QNOTE);
    play_note(SPEAKER_PIN, G5, QNOTE);

    play_note(SPEAKER_PIN, F5, ENOTE); // 20
    play_note(SPEAKER_PIN, F5, ENOTE);
    play_note(SPEAKER_PIN, F5, ENOTE);
    play_note(SPEAKER_PIN, G5, ENOTE);
    REST(EREST)
    play_note(SPEAKER_PIN, C6, ENOTE);
    play_note(SPEAKER_PIN, A5, ENOTE);
    play_note(SPEAKER_PIN, C6, ENOTE);
    
    play_note(SPEAKER_PIN, C6, ENOTE); // 21
    play_note(SPEAKER_PIN, A5, ENOTE);
    play_note(SPEAKER_PIN, C6, ENOTE);
    play_note(SPEAKER_PIN, C6, ENOTE);
    play_note(SPEAKER_PIN, A5, QNOTE);
    play_note(SPEAKER_PIN, G5, QNOTE);

    play_note(SPEAKER_PIN, C6, WNOTE); // 22

    play_note(SPEAKER_PIN, C2, ENOTE); // 23.0
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, C3, ENOTE);
    play_note(SPEAKER_PIN, C2, ENOTE); 
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, C3, DQNOTE);

    play_note(SPEAKER_PIN, C2, ENOTE); // 23.1
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, A2, ENOTE);
    play_note(SPEAKER_PIN, C2, ENOTE); 
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, A2, DQNOTE);

    play_note(SPEAKER_PIN, C5, ENOTE); // 24
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, E5, QNOTE);
    play_note(SPEAKER_PIN, E5, ENOTE);
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, C5, QNOTE);

    play_note(SPEAKER_PIN, D5, DQNOTE); // 25
    play_note(SPEAKER_PIN, C5, ENOTE + HNOTE);

    play_note(SPEAKER_PIN, C5, ENOTE); // 26
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, E5, QNOTE);
    play_note(SPEAKER_PIN, E5, HNOTE + WNOTE); // 27

    play_note(SPEAKER_PIN, C5, ENOTE); // 28
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, E5, QNOTE);
    play_note(SPEAKER_PIN, E5, ENOTE);
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, C5, QNOTE);

    play_note(SPEAKER_PIN, D5, DQNOTE); // 29
    play_note(SPEAKER_PIN, C5, ENOTE + HNOTE);

    play_note(SPEAKER_PIN, C5, DQNOTE); // 30
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, D5, HNOTE + WNOTE); // 31

    play_note(SPEAKER_PIN, C5, DQNOTE); // 32
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, D5, HNOTE + WNOTE); // 33

    play_note(SPEAKER_PIN, C2, ENOTE); // 34
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, C3, ENOTE);
    play_note(SPEAKER_PIN, C2, ENOTE); 
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, C3, DQNOTE);

    play_note(SPEAKER_PIN, C2, ENOTE); // 35
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, A2, ENOTE);
    play_note(SPEAKER_PIN, C2, ENOTE); 
    play_note(SPEAKER_PIN, G2, ENOTE);
    play_note(SPEAKER_PIN, A2, DQNOTE);

    play_note(SPEAKER_PIN, C2, ENOTE); // 36
    play_note(SPEAKER_PIN, C4, ENOTE);
    play_note(SPEAKER_PIN, D4, ENOTE);
    play_note(SPEAKER_PIN, E4, ENOTE);
    play_note(SPEAKER_PIN, C4, ENOTE);
    play_note(SPEAKER_PIN, D4, ENOTE);
    play_note(SPEAKER_PIN, E4, ENOTE);
    play_note(SPEAKER_PIN, C5, ENOTE);

    play_note(SPEAKER_PIN, D5, ENOTE); // 37
    play_note(SPEAKER_PIN, F5, DQNOTE);
    play_note(SPEAKER_PIN, E5, QNOTE);
    play_note(SPEAKER_PIN, D5, ENOTE);
    play_note(SPEAKER_PIN, C5, ENOTE);

    play_note(SPEAKER_PIN, D5, DQNOTE); // 38
    play_note(SPEAKER_PIN, C5, QNOTE + HNOTE);
}



















