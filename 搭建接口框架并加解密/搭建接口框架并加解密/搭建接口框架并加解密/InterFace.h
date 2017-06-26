#pragma once

typedef int(*INIT)(void ** handle);

typedef int(*SEND)(void * handle, char * send_mes, int send_len);

typedef int(*GAIN)(void * handle, char * gain_mes, int * gain_len);

typedef int(*WIPE)(void ** handle);

typedef struct FunCall
{
	INIT init_mes;
	SEND send_mes;
	GAIN gain_mes;
	WIPE wipe_mes;
}FunCall;

int call(FunCall *set, INIT init, SEND send, GAIN gain, WIPE wipe);