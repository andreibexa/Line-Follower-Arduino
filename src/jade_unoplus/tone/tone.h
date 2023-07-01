#ifndef JADE_UNOPLUS_TONE_TONE_H_
#define JADE_UNOPLUS_TONE_TONE_H_

#include "jade_unoplus/tone/notes.h"
#include "jade_unoplus/pins_jade_unoplus.h"
#include <Arduino.h>

#define S_CONNECTION 0
#define S_BUTTON_PUSHED 1
#define S_SLEEPING 2
#define S_CONFUSED 3

/**
 * @brief Play a tone
 *
 * @param noteFrequency The frequency of the tone to play
 * @param noteDuration The duration of the tone to play
 * @param silentDuration The duration of the silence after the tone
 */
void playTone(float noteFrequency, long noteDuration, int silentDuration);

/**
 * @brief Play a tone with a frequency that changes from initFrequency to finalFrequency
 *
 * @param initFrequency Initial frequency
 * @param finalFrequency Final frequency
 * @param prop Proportion of the frequency change
 * @param noteDuration Duration of the tone
 * @param silentDuration Duration of the silence after the tone
 */
void bendTones(float initFrequency, float finalFrequency, float prop,
               long noteDuration, int silentDuration);

/**
 * @brief Play a sequence of tones
 *
 * @param sequence The sequence to play
 */
void playSequence(uint8_t sequence);

#endif  // JADE_UNOPLUS_TONE_TONE_H_
