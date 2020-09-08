#include "LZ77/LZ77.h"

int main()
{
    char arr[128] = "AAVAABSSABASDFLFFFSAAVSBBSDFAASLSIONAADNSAAAALN";
    LZ77Encoder(arr);

    return 0;
}