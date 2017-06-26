#pragma once

#include "InterFace.h"
#include "CodeInterFace.h"

typedef struct Handle
{
	char	ip[32];
	int		port;
	char	*info;
	int		len;
}Handle;

int frame(FunCall * pfc, CODE * setcode, char * sendmes, int sendlen, char * getmes, int *getlen);