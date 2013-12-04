/* coydog - sandbox program for testing portaudio functionality. Yes, it has globals. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <portaudio.h>
#include "tonegenerator.h"

#define DEBUG 0

int main (int argc, char **argv) {
	TG_State tg;
	tone_t tone = {440, 10};
	int i = 0;
#define NUM_TONES 5000
	tone_t tones[NUM_TONES+1];
	memset (tones, '\0', sizeof(tones));
	while (i < NUM_TONES) {
		tones[i].frequency = 4 + i * 10;
		tones[i].duration = (1) * 4;
		i++;
	}

	/* TODO: Bad idea to use tone_t array as both sequence of tones, and fourier series. 
	 * Very confusing. Find another way to express fourier, to distinguis, since array of
	 * tones is already established by the BSD ioctl we are mimicking. */
	/* This will work for initial proof of concept tho, I guess... */
	tone_t harmony[3] = {{440, 5000}, {220, 5000}, {0, 0}} ;


	if (argc > 1 ) 
		tone.frequency = atoi(argv[1]);

	if (argc > 2)
		tone.duration = atoi(argv[2]);
	printf("Using frequency %d\n", tone.frequency);

	TG_Init(&tg);
	TG_WriteBuffered(&tg, tone);
	TG_WriteBufferedSequence(&tg, tones);
	TG_DeInit(&tg);
	return 0;
}
