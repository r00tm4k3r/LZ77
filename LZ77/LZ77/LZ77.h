#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SBSIZE 128
#define LABSIZE 16

typedef struct _SEARCHBUFFERSTRUCT
{
    unsigned short writeIteration;
    char character;
}searchBuffer_s;

typedef struct _TOKEN
{
    unsigned char flag : 1;
    unsigned short posInText : 11;
    unsigned char  length : 4;
}token;

void* LZ77Encoder(char* const);