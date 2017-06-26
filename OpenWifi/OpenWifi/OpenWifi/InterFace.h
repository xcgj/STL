#pragma once

typedef void (*CHOICE)(void);

typedef struct CHO
{
	CHOICE a[2];
}CHO;

void INIT_choice(CHO * stru, CHOICE a, CHOICE b);