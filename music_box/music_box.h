// Ben Andrews
// PHYS333 Final Project: Music Box header file
// 2018-4-10

// define music note freqencies scaled to delay time
//  scaled to a pwm based on microseconds
#define SCALER (1000000 /2 /

#define C1  SCALER ( 33 ))     // Pedal C
#define CS1 SCALER ( 35 ))
#define DF1 CS1                
#define D1  SCALER ( 37 ))
#define DS1 SCALER ( 39 ))
#define EF1 DS1
#define E1  SCALER ( 41 ))
#define F1  SCALER ( 44 ))
#define FS1 SCALER ( 56 ))
#define GF1 FS1
#define G1  SCALER ( 49 ))
#define GS1 SCALER ( 52 ))
#define A1  SCALER ( 55 ))
#define AS1 SCALER ( 58 ))
#define BF1 AS1
#define B1  SCALER ( 62 ))

#define C2  SCALER ( 65 ))     // Deep C
#define CS2 SCALER ( 69 ))
#define DF2 CS2                 
#define D2  SCALER ( 73 ))
#define DS2 SCALER ( 77 ))
#define EF2 DS2
#define E2  SCALER ( 82 ))
#define F2  SCALER ( 87 ))
#define FS2 SCALER ( 93 ))
#define GF2 FS2
#define G2  SCALER ( 98 ))
#define GS2 SCALER ( 103 ))
#define A2  SCALER ( 110 ))
#define AS2 SCALER ( 117 ))
#define BF2 AS2
#define B2  SCALER ( 123 ))

#define C3  SCALER ( 131 ))     // C3
#define CS3 SCALER ( 139 ))
#define DF3 CS3                 
#define D3  SCALER ( 147 ))
#define DS3 SCALER ( 156 ))
#define EF3 DS3
#define E3  SCALER ( 165 ))
#define F3  SCALER ( 175 ))
#define FS3 SCALER ( 185 ))
#define GF3 FS3
#define G3  SCALER ( 195 ))
#define GS3 SCALER ( 208 ))
#define A3  SCALER ( 220 ))
#define AS3 SCALER ( 233 ))
#define BF3 AS3
#define B3  SCALER ( 246 ))

#define C4  SCALER ( 261 ))     // middle C
#define CS4 SCALER ( 277 ))
#define DF4 CS4                 
#define D4  SCALER ( 293 ))
#define DS4 SCALER ( 311 ))
#define EF4 DS4
#define E4  SCALER ( 329 ))
#define F4  SCALER ( 349 ))
#define FS4 SCALER ( 370 ))
#define GF4 FS4
#define G4  SCALER ( 391 ))
#define GS4 SCALER ( 415 ))
#define AF4 GS4
#define A4  SCALER ( 440 ))
#define AS4 SCALER ( 466 ))
#define BF4 AS4
#define B4  SCALER ( 493 ))

#define C5  SCALER ( 523 ))     // tenor C
#define CS5 SCALER ( 554 ))
#define DF5 CS5
#define D5  SCALER ( 587 ))
#define DS5 SCALER ( 622 ))
#define EF5 DS5
#define E5  SCALER ( 659 ))
#define F5  SCALER ( 698 ))
#define FS5 SCALER ( 739 ))
#define GF5 FS5
#define G5  SCALER ( 783 ))
#define GS5 SCALER ( 830 ))
#define AF5 GS5
#define A5  SCALER ( 880 ))
#define AS5 SCALER ( 932 ))
#define BF5 AS4
#define B5  SCALER ( 988 ))


#define C6  SCALER ( 1047 ))     // soprano C
#define CS6 SCALER ( 1109 ))
#define DF6 CS6
#define D6  SCALER ( 1175 ))
#define DS6 SCALER ( 1245 ))
#define EF6 DS6
#define E6  SCALER ( 1319 ))
#define F6  SCALER ( 1397 ))
#define FS6 SCALER ( 1480 ))
#define GF6 FS6
#define G6  SCALER ( 1568 ))
#define GS6 SCALER ( 1661 ))
#define AF6 GS6
#define A6  SCALER ( 1760 ))
#define AS6 SCALER ( 1865 ))
#define BF6 AS4
#define B6  SCALER ( 1975 ))


// note lengths
volatile int bpm_sel = 0;
int const bpms[] = {60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300};
const int num_bpms = sizeof(bpms) / sizeof(int);

long volatile note_dur[15];

#define WNOTE note_dur[0]
#define HNOTE note_dur[1]
#define QNOTE note_dur[2]
#define ENOTE note_dur[3]
#define SNOTE note_dur[4]

#define DHNOTE note_dur[5]
#define DQNOTE note_dur[6]
#define DENOTE note_dur[7]

#define TRIPLT note_dur[8]

// rests
#define REST(D) delay(D);
#define WREST note_dur[9]
#define HREST note_dur[10]
#define QREST note_dur[11]
#define EREST note_dur[12]
#define SREST note_dur[13]




