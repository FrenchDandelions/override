#include <stdio.h>
#include <string.h>

int main(void){
    char str[100];
    unsigned int i;
    i = 0;
    fgets(str, 100, stdin);
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] > 64 && str[i] <= 90)
            str[i] ^= 0x20u;
    }
    printf(str);
    exit(0);
}