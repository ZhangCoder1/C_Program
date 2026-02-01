#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// The following definitions are for your Morse code, do NOT modify
static const char* MORSE_AZ[26] = {
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
    "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
    "..-","...-",".--","-..-","-.--","--.."
};

static const char* MORSE_09[10] = {
    "-----",".----","..---","...--","....-",".....","-....","--...","---..","----."
};

int main() {
    char inText[256];
    char outMorse[4096] = "";

    // Read input
    if (gets(inText) == NULL) {
        puts("");
        return 0;
    }
    int len = strlen(inText);
    // Check for empty or space-only input
    int EMPTY = 0;
    for (int i = 0; i < len; i++) {
        if (inText[i] != ' ') {
            EMPTY = 1;
            break;
        }
    }

    if (EMPTY==0) 
    {
        puts("");
        return 0;
    }

    // Validate all characters
    char ignored[] = ",.;:-!?'\"";
    int valid = 1;
    for (int i = 0; i < len; i++) {
        char c = inText[i];
        int is_valid = 0;

        // Check if valid character
        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') ||
            c == ' ') {
            is_valid = 1;
        }
        else {
            // Check if ignored punctuation
            int is_ignored = 0;
            for (int j = 0; ignored[j] != '\0'; j++) {
                if (c == ignored[j]) {
                    is_ignored = 1;
                    break;
                }
            }
            is_valid = is_ignored;
        }

        if (is_valid==0) {
            valid = 0;
            break;
        }
    }

    if (valid==0) {
        puts("ERROR");
        return 0;
    }

    // Process input
    int index = 0;  // Current position in output buffer
    int in_word = 0;    // Currently processing a word
    int first_char = 1; // First character in output

    for (int i = 0; i < len; i++) {
        char c = inText[i];

        // Check if ignored punctuation
        int is_ignored = 0;
        for (int j = 0; ignored[j] != '\0'; j++) {
            if (c == ignored[j]) {
                is_ignored = 1;
                break;
            }
        }

        // Skip ignored punctuation
        if (is_ignored) {
            continue;
        }

        // Handle spaces
        if (c == ' ') {
            if (in_word) {
                in_word = 0;
            }
            continue;
        }

        // Handle word separator
        if (in_word==0 && first_char==0) {
            outMorse[index++] = '/';
        }

        // Handle character separator
        if (first_char==0 && in_word) {
            outMorse[index++] = ' ';
        }

        // Convert character to Morse code
        const char* morse = NULL;
        if (c >= 'A' && c <= 'Z') {
            morse = MORSE_AZ[c - 'A'];
        }
        else if (c >= 'a' && c <= 'z') {
            morse = MORSE_AZ[toupper(c) - 'A'];
        }
        else if (c >= '0' && c <= '9') {
            morse = MORSE_09[c - '0'];
        }

        // Copy Morse code to output
        if (morse != NULL) {
            for (int j = 0; morse[j] != '\0'; j++) {
                outMorse[index++] = morse[j];
            }
        }
        in_word = 1;
        first_char = 0;
    }

    // Null-terminate the output string
    outMorse[index] = '\0';

    puts(outMorse);
    return 0;
}


