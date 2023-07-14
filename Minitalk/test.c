#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char binaryToChar(const char* binary) {
    int len = strlen(binary);
    if (len != 8) {
        printf("Invalid binary string. Expected 8 characters.\n");
        return '\0';
    }

    int value = 0;
    for (int i = 0; i < len; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Invalid binary character. Only '0' and '1' are allowed.\n");
            return '\0';
        }
        value = (value << 1) + (binary[i] - '0');
    }

    return (char)value;
}

int main() {
    const char* binaryString = "01001001";

    char result = binaryToChar(binaryString);
    if (result != '\0') {
        printf("Binary character value: %c\n", result);
    }

    return 0;
}