//
// Created by alvaro on 2/10/20.
//

#include "utils.h"

char *readStringFromStdin() {
    // prepare buffer
    size_t size = INPUT_BUFFER_SIZE;
    char *buffer = (char *) malloc(size * sizeof(char));
    memset(buffer, 0, size);

    // read until new char is found
    int hasReachedNewLineChar = 0;
    while (!hasReachedNewLineChar && fgets(buffer, INPUT_BUFFER_SIZE, stdin) != NULL) {
        unsigned long length = strlen(buffer);

        // protect from over stepping the bounds of the buffer
        if (length == INPUT_BUFFER_SIZE - 1 && buffer[length - 1] != '\n') {
            printf("Error, line over reached buffer!\n");
            return NULL;
        }

        if (buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
            hasReachedNewLineChar = 1;
        }
    }

    return buffer;
}

int readIntFromStdin() {
    char *input;
    char *ptr;
    long ret;

    input = readStringFromStdin();
    ret = strtol(input, &ptr, 10);
    free(input);

    return (int) ret;
}