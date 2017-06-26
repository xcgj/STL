#pragma once
typedef int(*pCompare)(int d1, int d2);

typedef struct A
{
	char name[10];
	int age;
}A;

int Compare(void *d1, void *d2, pCompare pfunc);