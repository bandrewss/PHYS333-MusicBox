// Ben Andrews
// PHYS333 Final Project: Music Box header file
// 2018-4-10

// define music note freqencies scaled to delay time
//  scaled to a pwm based on microseconds
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

// note lengths
#define WNOTE 1000000
#define HNOTE WNOTE /2
#define QNOTE WNOTE /4
#define ENOTE WNOTE /8
#define SNOTE WNOTE /16

#define DHNOTE HNOTE + QNOTE
#define DQNOTE QNOTE + ENOTE
#define DENOTE ENOTE + SNOTE

#define TRIPLT QNOTE / 3

// rests
#define WREST delay(WNOTE /1000);
#define HREST delay(HNOTE /1000);
#define QREST delay(QNOTE /1000);
#define EREST delay(ENOTE /1000);
#define SREST delay(SNOTE /1000);
