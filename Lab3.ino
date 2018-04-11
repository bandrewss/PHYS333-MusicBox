// Ben Andrews
// PHYS 333 Lab 3
// 2018-2-16

// define pins for various things
#define PIN 12
#define MUSIC_PIN 13

// define music note freqencies scaled to delay time
//  this should be in a header file
#define SCALER 1000000 /2 /

#define A3 SCALER 220
#define AS3 SCALER 233
#define BF3 AS3
#define B3 SCALER 246 
#define C4 SCALER 261 
#define CS4 SCALER 277
#define DF4 CS4
#define D4 SCALER 293 
#define DS4 SCALER 311
#define EF4 DS4
#define E4 SCALER 329 
#define F4 SCALER 349 
#define FS4 SCALER 370
#define GF4 FS4
#define G4 SCALER 391 
#define GS4 SCALER 415
#define AF4 GS4
#define A4 SCALER 440
#define AS4 SCALER 466
#define BF4 AS4
#define B4 SCALER 493 
#define C5 SCALER 523 
#define CS5 SCALER 554
#define DF5 CS5
#define D5 SCALER 587
#define DS5 SCALER 622
#define EF5 DS5
#define E5 SCALER 659
#define F5 SCALER 698
#define FS5 SCALER 739
#define GF5 FS5
#define G5 SCALER 783
#define GS5 SCALER 830
#define AF5 GS5

#define WNOTE 1000000
#define HNOTE WNOTE /2
#define QNOTE WNOTE /4
#define ENOTE WNOTE /8
#define SNOTE WNOTE /16

#define DHNOTE HNOTE + QNOTE
#define DQNOTE QNOTE + ENOTE
#define DENOTE ENOTE + SNOTE

#define TRIPLT QNOTE / 3

#define WREST delay(WNOTE /1000);
#define HREST delay(HNOTE /1000);
#define QREST delay(QNOTE /1000);
#define EREST delay(ENOTE /1000);
#define SREST delay(SNOTE /1000);

// problem definitions
//#define NUM_1

//#define NUM_2

// taking the L on number 3

//#define C_SCALE

//#define B_DAY

#define STAR_WARS

void setup() 
{
    pinMode(PIN, OUTPUT);
    pinMode(MUSIC_PIN, OUTPUT);
}

void loop() 
{
#ifdef NUM_1
    // get 3.27V avg
    pwm(PIN, 642, 1000);
    
#endif // NUM_1

#ifdef NUM_2
    // get 1.22V for 100ms
    for(int i = 0; i < 100; ++i)
        pwm(PIN, 238, 1000);

    // get 3.77V for 200ms
    for(int i = 0; i < 200; ++i)
        pwm(PIN, 750, 1000);
        
#endif // NUM_2

#ifdef C_SCALE
    play_note(MUSIC_PIN, C4, HNOTE);
    play_note(MUSIC_PIN, D4, HNOTE);
    play_note(MUSIC_PIN, E4, HNOTE);
    play_note(MUSIC_PIN, F4, HNOTE);
    play_note(MUSIC_PIN, G4, HNOTE);
    play_note(MUSIC_PIN, A4, HNOTE);
    play_note(MUSIC_PIN, B4, HNOTE);
    play_note(MUSIC_PIN, C5, HNOTE);

    QREST 

    play_note(MUSIC_PIN, C5, HNOTE);
    play_note(MUSIC_PIN, B4, HNOTE);
    play_note(MUSIC_PIN, A4, HNOTE);
    play_note(MUSIC_PIN, G4, HNOTE);
    play_note(MUSIC_PIN, F4, HNOTE);
    play_note(MUSIC_PIN, E4, HNOTE);
    play_note(MUSIC_PIN, D4, HNOTE);
    play_note(MUSIC_PIN, C4, HNOTE);

    HREST
    
#endif // C_SCALE

#ifdef B_DAY

    // 3/4
    // key: F Major
    play_note(MUSIC_PIN, C4, DENOTE); // hap
    play_note(MUSIC_PIN, C4, SNOTE); // py

    play_note(MUSIC_PIN, D4, QNOTE); // birth
    play_note(MUSIC_PIN, C4, QNOTE); // day
    play_note(MUSIC_PIN, F4, QNOTE); // to
    
    play_note(MUSIC_PIN, E4, HNOTE); // you
    play_note(MUSIC_PIN, C4, DENOTE); // hap
    play_note(MUSIC_PIN, C4, SNOTE); // py

    play_note(MUSIC_PIN, D4, QNOTE); // birth 
    play_note(MUSIC_PIN, C4, QNOTE); // day
    play_note(MUSIC_PIN, G4, QNOTE); // to
    
    play_note(MUSIC_PIN, F4, HNOTE); // you
    play_note(MUSIC_PIN, C4, DENOTE); // hap
    play_note(MUSIC_PIN, C4, SNOTE); // py

    play_note(MUSIC_PIN, C5, QNOTE); // birth
    play_note(MUSIC_PIN, A4, QNOTE); // day
    play_note(MUSIC_PIN, F4, QNOTE); // dear

    play_note(MUSIC_PIN, E4, QNOTE); //Na
    play_note(MUSIC_PIN, D4, DHNOTE); //than -fermata

    play_note(MUSIC_PIN, BF4, DENOTE); // hap
    play_note(MUSIC_PIN, BF4, SNOTE); // py

    play_note(MUSIC_PIN, A4, QNOTE); // birth
    play_note(MUSIC_PIN, F4, QNOTE); // day
    play_note(MUSIC_PIN, G4, QNOTE); // to

    play_note(MUSIC_PIN, F4, HNOTE); // you
    

#endif // B_DAY

#ifdef STAR_WARS
    // 4/4
    // G Major
    play_note(MUSIC_PIN, D4, TRIPLT); // 0
    play_note(MUSIC_PIN, D4, TRIPLT);
    play_note(MUSIC_PIN, D4, TRIPLT);
    
    play_note(MUSIC_PIN, G4, HNOTE); // 1
    play_note(MUSIC_PIN, D5, HNOTE);
    
    play_note(MUSIC_PIN, C5, TRIPLT); // 2
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, A4, TRIPLT);
    play_note(MUSIC_PIN, G5, HNOTE);
    play_note(MUSIC_PIN, D5, QNOTE);
    
    play_note(MUSIC_PIN, C5, TRIPLT); // 3
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, A4, TRIPLT);
    play_note(MUSIC_PIN, G5, HNOTE);
    play_note(MUSIC_PIN, D5, QNOTE);
    
    play_note(MUSIC_PIN, C5, TRIPLT); // 4
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, C5, TRIPLT);
    play_note(MUSIC_PIN, A4, HNOTE);
    play_note(MUSIC_PIN, D4, TRIPLT);
    play_note(MUSIC_PIN, D4, TRIPLT);
    play_note(MUSIC_PIN, D4, TRIPLT);
    
    play_note(MUSIC_PIN, G4, HNOTE); // 5
    play_note(MUSIC_PIN, D5, HNOTE);
    
    play_note(MUSIC_PIN, C5, TRIPLT); // 6
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, A4, TRIPLT);
    play_note(MUSIC_PIN, G5, HNOTE);
    play_note(MUSIC_PIN, D5, QNOTE);
    
    play_note(MUSIC_PIN, C5, TRIPLT); // 7
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, A4, TRIPLT);
    play_note(MUSIC_PIN, G5, HNOTE);
    play_note(MUSIC_PIN, D5, QNOTE);
    
    play_note(MUSIC_PIN, C5, TRIPLT); // 8
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, C5, TRIPLT);
    play_note(MUSIC_PIN, A4, HNOTE);
    play_note(MUSIC_PIN, D4, DENOTE);
    play_note(MUSIC_PIN, D4, SNOTE);
    
    play_note(MUSIC_PIN, E4, DQNOTE); // 9
    play_note(MUSIC_PIN, E4, ENOTE);
    play_note(MUSIC_PIN, C5, ENOTE);
    play_note(MUSIC_PIN, B4, ENOTE);
    play_note(MUSIC_PIN, A4, ENOTE);
    play_note(MUSIC_PIN, G4, ENOTE);
    
    play_note(MUSIC_PIN, G4, TRIPLT); // 10
    play_note(MUSIC_PIN, A4, TRIPLT);
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, A4, ENOTE);
    play_note(MUSIC_PIN, E4, ENOTE);
    play_note(MUSIC_PIN, FS4, QNOTE);
    play_note(MUSIC_PIN, D4, DENOTE);
    play_note(MUSIC_PIN, D4, SNOTE);
    
    play_note(MUSIC_PIN, E4, DQNOTE); // 11
    play_note(MUSIC_PIN, E4, ENOTE);
    play_note(MUSIC_PIN, C5, ENOTE);
    play_note(MUSIC_PIN, B4, ENOTE);
    play_note(MUSIC_PIN, A4, ENOTE);
    play_note(MUSIC_PIN, G4, ENOTE);
    
    play_note(MUSIC_PIN, D5, DQNOTE); // 12
    play_note(MUSIC_PIN, A4, ENOTE);  
    play_note(MUSIC_PIN, FS4, QNOTE);
    play_note(MUSIC_PIN, D4, DENOTE);
    play_note(MUSIC_PIN, D4, SNOTE);

    play_note(MUSIC_PIN, E4, DQNOTE); // 13
    play_note(MUSIC_PIN, E4, ENOTE);
    play_note(MUSIC_PIN, C5, ENOTE);
    play_note(MUSIC_PIN, B4, ENOTE);
    play_note(MUSIC_PIN, A4, ENOTE);
    play_note(MUSIC_PIN, G4, ENOTE);

    play_note(MUSIC_PIN, G4, TRIPLT); // 14
    play_note(MUSIC_PIN, A4, TRIPLT);
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, A4, ENOTE);
    play_note(MUSIC_PIN, E4, ENOTE);
    play_note(MUSIC_PIN, FS4, QNOTE);
    play_note(MUSIC_PIN, D5, DENOTE);
    play_note(MUSIC_PIN, D5, SNOTE);

    play_note(MUSIC_PIN, G5, ENOTE); // 15
    play_note(MUSIC_PIN, F5, ENOTE);
    play_note(MUSIC_PIN, EF5, ENOTE);
    play_note(MUSIC_PIN, D5, ENOTE);
    play_note(MUSIC_PIN, C5, ENOTE);
    play_note(MUSIC_PIN, BF4, ENOTE);
    play_note(MUSIC_PIN, A4, ENOTE);
    play_note(MUSIC_PIN, G4, ENOTE);

    play_note(MUSIC_PIN, FS4, HNOTE); // 16
    QREST
    play_note(MUSIC_PIN, D4, TRIPLT);
    play_note(MUSIC_PIN, D4, TRIPLT);
    play_note(MUSIC_PIN, D4, TRIPLT);

    play_note(MUSIC_PIN, G4, HNOTE); // 17
    play_note(MUSIC_PIN, D5, HNOTE);

    play_note(MUSIC_PIN, C5, TRIPLT); // 18
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, A4, TRIPLT);
    play_note(MUSIC_PIN, G5, HNOTE);
    play_note(MUSIC_PIN, D5, QNOTE);

    play_note(MUSIC_PIN, C5, TRIPLT); // 19
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, A4, TRIPLT);
    play_note(MUSIC_PIN, G5, HNOTE);
    play_note(MUSIC_PIN, D5, QNOTE);

    play_note(MUSIC_PIN, C5, TRIPLT); // 20
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, C5, TRIPLT);
    play_note(MUSIC_PIN, A4, HNOTE);
    play_note(MUSIC_PIN, D4, TRIPLT);
    play_note(MUSIC_PIN, D4, TRIPLT);
    play_note(MUSIC_PIN, D4, TRIPLT);

    play_note(MUSIC_PIN, G4, HNOTE); // 21
    play_note(MUSIC_PIN, D5, HNOTE);

    play_note(MUSIC_PIN, C5, TRIPLT); // 22
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, A4, TRIPLT);
    play_note(MUSIC_PIN, G5, HNOTE);
    play_note(MUSIC_PIN, D5, QNOTE);

    play_note(MUSIC_PIN, C5, TRIPLT); // 23
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, A4, TRIPLT);
    play_note(MUSIC_PIN, G5, HNOTE);
    play_note(MUSIC_PIN, D5, QNOTE);

    play_note(MUSIC_PIN, C5, TRIPLT); // 24
    play_note(MUSIC_PIN, B4, TRIPLT);
    play_note(MUSIC_PIN, C5, TRIPLT);
    play_note(MUSIC_PIN, A4, HNOTE);
    play_note(MUSIC_PIN, D5, DENOTE);
    play_note(MUSIC_PIN, D5, SNOTE);

    play_note(MUSIC_PIN, G5, ENOTE); // 25
    play_note(MUSIC_PIN, F5, ENOTE);
    play_note(MUSIC_PIN, EF5, ENOTE);
    play_note(MUSIC_PIN, D5, ENOTE);
    play_note(MUSIC_PIN, C5, ENOTE);
    play_note(MUSIC_PIN, BF4, ENOTE);
    play_note(MUSIC_PIN, A4, ENOTE);
    play_note(MUSIC_PIN, G4, ENOTE);
    
    play_note(MUSIC_PIN, D5, QNOTE); // 26
    play_note(MUSIC_PIN, G4, TRIPLT);
    play_note(MUSIC_PIN, G4, TRIPLT);
    play_note(MUSIC_PIN, G4, TRIPLT);
    play_note(MUSIC_PIN, G4, QNOTE);
    
   
    WREST
    
#endif // STAR_WARS

}


void pwm(int pin, int on_time, int total_time)
{
    digitalWrite(pin, HIGH);
    delayMicroseconds(on_time);

    digitalWrite(pin, LOW);
    delayMicroseconds(total_time - on_time);
}

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

    delay(6);
}








