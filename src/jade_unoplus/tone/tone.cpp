#include "jade_unoplus/tone/tone.h"

/**
 * @brief Play a tone
 *
 * @param noteFrequency The frequency of the tone to play
 * @param noteDuration The duration of the tone to play
 * @param silentDuration The duration of the silence after the tone
 */
void playTone(float noteFrequency, long noteDuration, int silentDuration) {
  if (silentDuration == 0) {
    silentDuration = 1;
  }

  tone(BUZZER_PIN, noteFrequency, noteDuration);
  delay(noteDuration);
  delay(silentDuration);
}

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
               long noteDuration, int silentDuration) {
  if (silentDuration == 0) {
    silentDuration = 1;
  }

  float currentFrequency = initFrequency;

  if (initFrequency < finalFrequency) {
    while (currentFrequency < finalFrequency) {
      playTone(currentFrequency, noteDuration, silentDuration);
      currentFrequency *= prop;
    }
  } else {
    while (currentFrequency > finalFrequency) {
      playTone(currentFrequency, noteDuration, silentDuration);
      currentFrequency /= prop;
    }
  }

  noTone(BUZZER_PIN);
}

/**
 * @brief Play a sequence of tones
 *
 * @param sequence The sequence to play
 */
void playSequence(uint8_t sequence) {
  switch (sequence) {
    case S_CONNECTION:
      playTone(NOTE_E5, 50, 30);
      playTone(NOTE_E6, 55, 25);
      playTone(NOTE_A6, 60, 10);
      break;
    case S_BUTTON_PUSHED:
      bendTones(NOTE_E6, NOTE_G6, 1.03, 20, 2);
      delay(30);
      bendTones(NOTE_E6, NOTE_D7, 1.04, 10, 2);
      break;
    case S_SLEEPING:
      bendTones(100, 500, 1.04, 10, 10);
      delay(500);
      bendTones(400, 100, 1.04, 10, 1);
      break;
    case S_CONFUSED:
      bendTones(1000, 1700, 1.03, 8, 2);
      bendTones(1699, 500, 1.04, 8, 3);
      bendTones(1000, 1700, 1.05, 9, 10);
      break;
  }
}
