#include <stdio.h>
#include <string.h>

void fz(char* str){
    int len = strlen(str);
    char* left = str;
    char* right = str + len -1;
    while(left<right)
    {
        char div = *left;
        *left = *right;
        *right = div;
        --right;
        ++left;
    }
}

int main(){
    char str[100];
    gets(str);
    fz(str);
    printf("%s",str);
    return 0;
}