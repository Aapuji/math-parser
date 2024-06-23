#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 256

int main(void) {
    char input[MAX_INPUT_LEN];

    printf("> ");

    fgets(input, MAX_INPUT_LEN, stdin);

    printf("%s", input);
    
    return 0;
}
