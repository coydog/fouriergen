/* coydog - sandbox program for testing portaudio functionality. Yes, it has globals. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <portaudio.h>
#include "tonegenerator.h"

#include <poll.h>
#define DEBUG 0

int main (int argc, char **argv) {
	TG_State tg;
	tone_t tone = {440, 1000};
	int i = 0;

	struct pollfd pol = {0, POLLIN, 0};
	float shift = 0.1;
#define NUM_TONES 5000
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
	tone_t harmony[6] = { {220, 5000}, {440, 5000}, {554.37, 5000}, {329.63, 5000},   {0, 0}} ;

	/* TODO: Not working; troubleshoot. Maybe close/reopen stdin? ioctl()? */
	setvbuf(stdin, NULL, _IONBF, 0); /* unbuffered stdin for sort-of realtime response */

	if (argc > 1 ) 
		tone.frequency = atof(argv[1]);

	if (argc > 2)
		tone.duration = atof(argv[2]);
	printf("Using frequency %f\n", tone.frequency);


	TG_Init(&tg);
	/*TG_WriteBuffered(&tg, tone);*/
	TG_WriteHarmony(&tg, harmony);
	/*while (1) {
		TG_WriteHarmony(&tg, harmony);
		harmony[2].frequency += shift;
		harmony[1].frequency -= shift;

		if (poll(&pol, 1, 1)) {
			printf("polled input event!\n");
			getchar();
			shift *= -1.;
		}

	}*/
	/*TG_WriteBufferedSequence(&tg, tones);*/
	TG_DeInit(&tg);
	return 0;
}
