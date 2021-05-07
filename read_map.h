#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxNum 10000
typedef struct AMGraph{
	float length[MaxNum][MaxNum];
	float path[MaxNum][MaxNum];
	int nodenum,pathnum;
}AMGraph;