// Ben Andrews
// PHYS333 Final Project: Music Box header file
// 2018-4-10

// define music note freqencies scaled to delay time
//  scaled to a pwm based on microseconds
#define SCALER (1000000 /2 /

#define  NOTE_C1  SCALER    ( 33 ))     // Pedal C
#define  NOTE_CS1  SCALER   ( 35 ))
#define  NOTE_DF1  NOTE_CS1                
#define  NOTE_D1  SCALER    ( 37 ))
#define  NOTE_DS1  SCALER   ( 39 ))
#define  NOTE_EF1  NOTE_DS1
#define  NOTE_E1  SCALER    ( 41 ))
#define  NOTE_F1  SCALER    ( 44 ))
#define  NOTE_FS1  SCALER   ( 56 ))
#define  NOTE_GF1  NOTE_FS1
#define  NOTE_G1  SCALER    ( 49 ))
#define  NOTE_GS1  SCALER   ( 52 ))
#define  NOTE_A1  SCALER    ( 55 ))
#define  NOTE_AS1  SCALER   ( 58 ))
#define  NOTE_BF1  NOTE_AS1
#define  NOTE_B1  SCALER    ( 62 ))

#define  NOTE_C2  SCALER    ( 65 ))     // Deep C
#define  NOTE_CS2  SCALER   ( 69 ))
#define  NOTE_DF2  NOTE_CS2                 
#define  NOTE_D2  SCALER    ( 73 ))
#define  NOTE_DS2  SCALER   ( 77 ))
#define  NOTE_EF2  NOTE_DS2
#define  NOTE_E2  SCALER    ( 82 ))
#define  NOTE_F2  SCALER    ( 87 ))
#define  NOTE_FS2  SCALER   ( 93 ))
#define  NOTE_GF2  NOTE_FS2
#define  NOTE_G2  SCALER    ( 98 ))
#define  NOTE_GS2  SCALER   ( 103 ))
#define  NOTE_A2  SCALER    ( 110 ))
#define  NOTE_AS2  SCALER   ( 117 )) 
#define  NOTE_BF2  NOTE_AS2
#define  NOTE_B2  SCALER    ( 123 ))

#define  NOTE_C3  SCALER    ( 131 ))     // C3
#define  NOTE_CS3  SCALER   ( 139 ))
#define  NOTE_DF3  NOTE_CS3                 
#define  NOTE_D3  SCALER    ( 147 ))
#define  NOTE_DS3  SCALER   ( 156 ))
#define  NOTE_EF3  NOTE_DS3
#define  NOTE_E3  SCALER    ( 165 ))
#define  NOTE_F3  SCALER    ( 175 ))
#define  NOTE_FS3  SCALER   ( 185 ))
#define  NOTE_GF3  NOTE_FS3
#define  NOTE_G3  SCALER    ( 195 ))
#define  NOTE_GS3  SCALER   ( 208 ))
#define  NOTE_A3  SCALER    ( 220 ))
#define  NOTE_AS3  SCALER   ( 233 ))
#define  NOTE_BF3  NOTE_AS3
#define  NOTE_B3  SCALER    ( 246 ))

#define  NOTE_C4  SCALER    ( 261 ))     // middle C
#define  NOTE_CS4  SCALER   ( 277 ))
#define  NOTE_DF4  NOTE_CS4                 
#define  NOTE_D4  SCALER    ( 293 ))
#define  NOTE_DS4  SCALER   ( 311 ))
#define  NOTE_EF4  NOTE_DS4
#define  NOTE_E4  SCALER    ( 329 ))
#define  NOTE_F4  SCALER    ( 349 ))
#define  NOTE_FS4  SCALER   ( 370 ))
#define  NOTE_GF4  NOTE_FS4
#define  NOTE_G4  SCALER    ( 391 ))
#define  NOTE_GS4  SCALER   ( 415 ))
#define  NOTE_AF4  NOTE_GS4
#define  NOTE_A4  SCALER    ( 440 ))
#define  NOTE_AS4  SCALER   ( 466 ))
#define  NOTE_BF4  NOTE_AS4
#define  NOTE_B4  SCALER    ( 493 ))

#define  NOTE_C5  SCALER    ( 523 ))     // tenor C
#define  NOTE_CS5  SCALER   ( 554 ))
#define  NOTE_DF5  NOTE_CS5
#define  NOTE_D5  SCALER    ( 587 ))
#define  NOTE_DS5  SCALER   ( 622 ))
#define  NOTE_EF5  NOTE_DS5
#define  NOTE_E5  SCALER    ( 659 ))
#define  NOTE_F5  SCALER    ( 698 ))
#define  NOTE_FS5  SCALER   ( 739 ))
#define  NOTE_GF5  NOTE_FS5
#define  NOTE_G5  SCALER    ( 783 ))
#define  NOTE_GS5  SCALER   ( 830 ))
#define  NOTE_AF5 NOTE_GS5
#define  NOTE_A5  SCALER    ( 880 ))
#define  NOTE_AS5  SCALER   ( 932 ))
#define  NOTE_BF5  NOTE_AS5
#define  NOTE_B5  SCALER    ( 988 ))


#define  NOTE_C6  SCALER    ( 1047 ))     // soprano C
#define  NOTE_CS6  SCALER   ( 1109 ))
#define  NOTE_DF6  NOTE_CS6
#define  NOTE_D6  SCALER    ( 1175 ))
#define  NOTE_DS6  SCALER   ( 1245 ))
#define  NOTE_EF6  NOTE_DS6
#define  NOTE_E6  SCALER    ( 1319 ))
#define  NOTE_F6  SCALER    ( 1397 ))
#define  NOTE_FS6  SCALER   ( 1480 ))
#define  NOTE_GF6  NOTE_FS6
#define  NOTE_G6  SCALER    ( 1568 ))
#define  NOTE_GS6  SCALER   ( 1661 ))
#define  NOTE_AF6  NOTE_GS6
#define  NOTE_A6  SCALER    ( 1760 ))
#define  NOTE_AS6  SCALER   ( 1865 ))
#define  NOTE_BF6  NOTE_AS6
#define  NOTE_B6  SCALER    ( 1975 ))


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
#define TNOTE note_dur[5]

#define  DHNOTE  note_dur[6]
#define  DQNOTE  note_dur[7]
#define  DENOTE  note_dur[8]

#define  TRIPLT  note_dur[9]

// rests
#define  REST(D) delay(D);
#define  WREST  note_dur[10]
#define  HREST  note_dur[11]
#define  QREST  note_dur[12]
#define  EREST  note_dur[13]
#define  SREST  note_dur[14]




