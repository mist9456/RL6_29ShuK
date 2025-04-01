#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

#define MAX_FILE_SIZE (64*1024)
#define MAX_WORD_LENGTH 64

struct WordEntry {
    char word[MAX_WORD_LENGTH];
    int letter_count;
};

struct WordStats {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void CountWords(const char* fileName);

#endif
