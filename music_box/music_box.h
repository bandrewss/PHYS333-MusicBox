// Ben Andrews
// PHYS333 Final Project: Music Box header file
// 2018-4-10

// define music note freqencies scaled to delay time
//  scaled to a pwm based on microseconds
#define SCALER (1000000 /2 /

#define A3 SCALER ( 220 ))
#define AS3 SCALER ( 233 ))
#define BF3 AS3
#define B3 SCALER ( 246 ))
#define C4 SCALER ( 261 ))
#define CS4 SCALER ( 277 ))
#define DF4 CS4
#define D4 SCALER ( 293 ))
#define DS4 SCALER ( 311 ))
#define EF4 DS4
#define E4 SCALER ( 329 ))
#define F4 SCALER ( 349 ))
#define FS4 SCALER ( 370 ))
#define GF4 FS4
#define G4 SCALER ( 391 ))
#define GS4 SCALER ( 415 ))
#define AF4 GS4
#define A4 SCALER ( 440 ))
#define AS4 SCALER ( 466 ))
#define BF4 AS4
#define B4 SCALER ( 493 ))
#define C5 SCALER ( 523 ))
#define CS5 SCALER ( 554 ))
#define DF5 CS5
#define D5 SCALER ( 587 ))
#define DS5 SCALER ( 622 ))
#define EF5 DS5
#define E5 SCALER ( 659 ))
#define F5 SCALER ( 698 ))
#define FS5 SCALER ( 739 ))
#define GF5 FS5
#define G5 SCALER ( 783 ))
#define GS5 SCALER ( 830 ))
#define AF5 GS5

// note lengths
int bpm;
long note_dur[14];

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




