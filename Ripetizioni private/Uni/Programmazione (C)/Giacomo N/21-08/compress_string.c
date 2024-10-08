// PRE: s è una stringa terminata da null contenente solo caratteri alfabetici
//      result è un array di caratteri con dimensione sufficiente per contenere la stringa compressa
// POST: result contiene la versione compressa di s, terminata da null

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void compress_string(char* s, char* result) {
    if (*s == '\0') {
        *result = '\0';
        return;
    }

    char current = *s;
    int count = 1;
    s++;

    while (*s == current) {
        count++;
        s++;
    }

    *result = current;
    result++;

    if (count > 1) {
        int digits = sprintf(result, "%d", count);
        result += digits;
    }

    compress_string(s, result);
}

int main() {
    char s[100] = "aabbbccccaaa";
    char result[100];
    compress_string(s, result);
    printf("%s\n", result);
    return 0;
}