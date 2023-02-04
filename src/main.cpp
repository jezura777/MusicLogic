#include "Logic.hpp"
#include "freertos/FreeRTOS.h"

#define NOTE_C4  (262)
#define NOTE_C4S (277)
#define NOTE_D4  (294)
#define NOTE_D4S (311)
#define NOTE_E4  (330)
#define NOTE_F4  (349)
#define NOTE_F4S (370)
#define NOTE_G4  (392)
#define NOTE_G4S (415)
#define NOTE_A4  (440)
#define NOTE_A4S (466)
#define NOTE_B4  (494)
#define NOTE_C5  (523)
#define NOTE_C5S (554)
#define NOTE_D5  (587)
#define NOTE_D5S (622)
#define NOTE_E5  (659)
#define NOTE_F5  (698)
#define NOTE_F5S (740)
#define NOTE_G5  (784)
#define NOTE_G5S (831)
#define NOTE_A5  (880)
#define NOTE_A5S (932)
#define NOTE_B5  (988)

#define BLANK    (0)


void playNote(int note, float durationInS) {
    float halfPeriod = (1000000 / note) / 2;

    durationInS=durationInS*2;

    for (int i = 0; i < (note * durationInS); i++) {
        buzzer.on();
        ets_delay_us(halfPeriod);
        buzzer.off();
        ets_delay_us(halfPeriod);
    }
}

void playScale() {
    playNote(NOTE_C4, 0.2);
    playNote(NOTE_D4, 0.2);
    playNote(NOTE_E4, 0.2);
    playNote(NOTE_F4, 0.2);
    playNote(NOTE_G4, 0.2);
    playNote(NOTE_A4, 0.2);
    playNote(NOTE_B4, 0.2);
    playNote(NOTE_C5, 0.2);
    playNote(NOTE_B4, 0.2);
    playNote(NOTE_A4, 0.2);
    playNote(NOTE_G4, 0.2);
    playNote(NOTE_F4, 0.2);
    playNote(NOTE_E4, 0.2);
    playNote(NOTE_D4, 0.2);
    playNote(NOTE_C4, 0.2);
}

void play8bitSong() {
    // simple 8-bit song generated using chatGPT
    playNote(NOTE_E5, 0.125);
    playNote(NOTE_E5, 0.125);
    playNote(NOTE_E5, 0.125);
    playNote(NOTE_C5, 0.125);
    playNote(NOTE_E5, 0.125);
    playNote(NOTE_G5, 0.25);
    playNote(NOTE_G4, 0.25);

    playNote(NOTE_C5, 0.125);
    playNote(NOTE_G4, 0.125);
    playNote(NOTE_E4, 0.125);
    playNote(NOTE_A4, 0.125);
    playNote(NOTE_B4, 0.125);
    playNote(NOTE_A5, 0.125);
    playNote(NOTE_A4, 0.125);
    playNote(NOTE_C5, 0.125);
    playNote(NOTE_D5, 0.125);
    playNote(NOTE_B4, 0.125);
    playNote(NOTE_B4, 0.125);
    playNote(NOTE_C5, 0.125);
    playNote(NOTE_G4, 0.125);
    playNote(NOTE_E4, 0.125);
    playNote(NOTE_A4, 0.125);
    playNote(NOTE_B4, 0.125);
    playNote(NOTE_A5, 0.125);
    playNote(NOTE_A4, 0.125);
    playNote(NOTE_C5, 0.125);
    playNote(NOTE_D5, 0.125);
    playNote(NOTE_E5, 0.25);
    playNote(NOTE_C5, 0.125);
    playNote(NOTE_A4, 0.125);
    playNote(NOTE_A4, 0.125);
    playNote(NOTE_D5, 0.125);
    playNote(NOTE_F5, 0.125);
    playNote(NOTE_A5, 0.25);
    playNote(NOTE_G5, 0.125);
    playNote(NOTE_D5, 0.125);
    playNote(NOTE_C5, 0.125);
}

void play(unsigned int song[74]) {
    for (int i = 0; i < 74; i++)
    {
        if (song[i] !=0)
        {
            playNote(song[i], 0.12);
        } else
        {
            ets_delay_us(120000);
        }
        
        
    }
    
}

// void play3(unsigned int song[64]) {
//     for (int i = 0; i >= 64; i++)
//     {
//         if(song[i]!=0) playNote(song[i], 0.333);
//         else ets_delay_us(3333);
//     }
    
// }

void logicMain() {
    playScale();
    waitSeconds(2);
    // play8bitSong();
    // waitSeconds(2);
    unsigned int song[74] = {
        NOTE_G5, 0, 0, 0,
        NOTE_G4, 0, 0, 0,

        NOTE_C5, 0, 0, NOTE_G4,
        0, 0, NOTE_E4, 0,
        0, NOTE_A4, 0, NOTE_B4,
        0, NOTE_A4S, NOTE_A4, 0,

        NOTE_G4, NOTE_E5, NOTE_G5,
        NOTE_A5, 0, NOTE_F5, NOTE_G5,
        0, NOTE_E5, 0, NOTE_C5,
        NOTE_D5, NOTE_B4, 0, 0,

        NOTE_C5, 0, 0, NOTE_G4,
        0, 0, NOTE_E4, 0,
        0, NOTE_A4, 0, NOTE_B4,
        0, NOTE_A4S, NOTE_A4, 0,

        NOTE_G4, NOTE_E5, NOTE_G5,
        NOTE_A5, 0, NOTE_F5, NOTE_G5,
        0, NOTE_E5, 0, NOTE_C5,
        NOTE_D5, NOTE_B4, 0, 0
    };


    play(song);

}