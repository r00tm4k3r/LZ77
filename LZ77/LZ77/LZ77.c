#include "LZ77.h"
#define _CRT_SECURE_NO_WARNINGS

void* LZ77Encoder(char* const text)
{
    //FILE* compFile = fopen("../compressed/text.lz77", "wb");
    char sb[SBSIZE];
    char lab[LABSIZE];
    int textLen = strlen(text), i = 0;
    char* outText = calloc(textLen, sizeof(char));

    memset(sb, -1, (SBSIZE * sizeof (char)));

    //if ((textLen = strlen(text)) < LABSIZE)
    //{
    //    puts("Input string is small");
    //    abort();
    //}

    //if (!compFile)
    //{
    //    puts("Compressed file didn't created");
    //    abort();
    //}

    while (text[i] != '\0')
    {
        token currToken = {0b1, 0, 0};
        short seqCount = 0;
        memmove(lab, text + i, LABSIZE);

        for (short j = SBSIZE - 1; j >= 0 && sb[j] != -1; j--)
        {
            if (sb[j] == lab[seqCount])
            {
                for (;  
                        (seqCount < LABSIZE) && 
                        ((j + seqCount) < SBSIZE) && 
                        (sb[j + seqCount] == lab[seqCount]); 
                    seqCount++);
                
                if (seqCount >= 2)
                {
                    currToken.posInText = j & 0x07FF;
                    currToken.length = seqCount & 0x000F;
                    break;
                }
            }
            seqCount = 0;
        }

        memmove(
                sb + ((SBSIZE - 1) - ((i + seqCount) % SBSIZE)), 
                sb + ((SBSIZE - (i % SBSIZE))), 
                seqCount + 1
        );
        memmove(sb + (SBSIZE - 1), lab, seqCount + 1);
        i+= seqCount + 1;
    }

    return;
}