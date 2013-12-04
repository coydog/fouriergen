/* coydog - sandbox program for testing portaudio functionality. Yes, it has globals. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <portaudio.h>
#include "tonegenerator.h"

#include <math.h>

#define DEBUG 0

int main (int argc, char **argv) {
	TG_State tg;
	tone_t tone = {440, 1000};
	short i = 0;
#define NUM_TONES 10000
	/*tone_t tones[NUM_TONES+1];
	memset (tones, '\0', sizeof(tones));
	while (i < NUM_TONES) {
		tones[i].frequency = 4 + i * 10;
		tones[i].duration = (1) * 8;
		i++;
	}*/

	/* TODO: Bad idea to use tone_t array as both sequence of tones, and fourier series. 
	 * Very confusing. Find another way to express fourier, to distinguis, since array of
	 * tones is already established by the BSD ioctl we are mimicking. */
	/* This will work for initial proof of concept tho, I guess... */
	/*tone_t harmony[5] = { {220, 5000}, {440, 5000}, {277, 5000}, {330, 5000}, {0, 0}} ;*/


	TG_Init(&tg);
	tone_t harmony[5];
	harmony[5].duration = 0;
	while (!(i = 0)) {
		while (i < NUM_TONES) {
			tone.frequency =  5000 * sin((float)i / ((float)NUM_TONES * 2. * M_PI) );
				
			tone.duration = 3;

			printf("Using frequency %d\n", tone.frequency);
			harmony[0] = tone;

			harmony[1].frequency = tone.frequency >>2;
			harmony[1].duration = tone.duration;
			harmony[2].frequency = tone.frequency >>3;
			harmony[2].duration = tone.duration;
			harmony[3].frequency = tone.frequency >>4;
			harmony[3].duration = tone.duration;
			harmony[4].frequency = tone.frequency >>5;
			harmony[4].duration = tone.duration;

			/*TG_WriteBuffered(&tg, tone);*/
			TG_WriteHarmony(&tg, harmony);
			i++;
		}
	}
	/*TG_WriteBufferedSequence(&tg, tones);*/
	TG_DeInit(&tg);
	return 0;
}
