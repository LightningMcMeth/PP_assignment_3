#include "pch.h"
#include "CaesarCipher.h"
#include <utility>
#include <limits.h>
#include <iostream>
#include <cctype>


void encryptText(char* rawText, int key) {

    key = (key % 26 + 26) % 26;

    for (size_t i = 0; rawText[i] != '\0'; i++)
    {
        if (rawText[i] == ' ' || rawText[i] == '\n') {
            continue;
        }

        if (std::isupper(rawText[i])) {

            rawText[i] = 'A' + (rawText[i] - 'A' + key) % 26;

            continue;
        }

        rawText[i] = 'a' + (rawText[i] - 'a' + key) % 26;
    }
}

void decryptText(char* encryptedText, int key) {

    key = (key % 26 + 26) % 26;

    for (size_t i = 0; encryptedText[i] != '\0'; i++)
    {
        if (encryptedText[i] == ' ') {
            continue;
        }

        if (std::isupper(encryptedText[i])) {

            encryptedText[i] = 'A' + (encryptedText[i] - 'A' - key) % 26;

            continue;
        }

        encryptedText[i] = 'a' + (encryptedText[i] - 'a' - key) % 26;
    }
}

void printText(char* encryptedText) {

    for (size_t i = 0; encryptedText[i] != '\0'; i++)
    {
        std::cout << encryptedText[i];
    }
}