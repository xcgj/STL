

#include "InterFace.h"

int call(FunCall *set, INIT init, SEND send, GAIN gain, WIPE wipe)
{
	int res = 0;
	if (1)
	{

	}

	set->init_mes = init;
	set->send_mes = send;
	set->gain_mes = gain;
	set->wipe_mes = wipe;

	return 0;
}