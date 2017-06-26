#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CommunicationInterface.h"

int sere(SERE * stru, INIT ini, SENT sen, RECE rec, CLEA cle)
{
	stru->init = ini;
	stru->sent = sen;
	stru->rece = rec;
	stru->clea = cle;
	return 0;
}