#define _CRT_SECURE_NO_WARNINGS
#include "file_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <cstring>
#include <sys/resource.h>  // Для setrlimit

void CountWords(const char* fileName) {
    // Увеличиваем стек до 64 МБ перед обработкой файла
    struct rlimit stack_limit;
    stack_limit.rlim_cur = 64 * 1024 * 1024;  // 64 МБ
    stack_limit.rlim_max = 64 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &stack_limit);

    // Оригинальный код функции (без изменений)
    FILE* file = fopen(fileName, "r");
    if (file == NULL) return;

    int current_char, buffer_index = 0;
    char file_buffer[MAX_FILE_SIZE + 1];

    while ((current_char = fgetc(file)) != EOF && buffer_index < MAX_FILE_SIZE) {
        file_buffer[buffer_index++] = (char)current_char;
    }
    file_buffer[buffer_index] = '\0';
    fclose(file);

    int space_count = 0;
    for (int i = 0; i < buffer_index; i++) {
        if (isspace(file_buffer[i])) space_count++;
    }
    const int max_words = space_count + 1;

    WordEntry* words = new WordEntry[max_words];
    int word_index = 0;
    int word_start = 0;

    for (int i = 0; i <= buffer_index; i++) {
        if (isspace(file_buffer[i]) || file_buffer[i] == '\0') {
            if (i > word_start) {
                int word_length = i - word_start;
                if (word_length >= MAX_WORD_LENGTH) {
                    word_length = MAX_WORD_LENGTH - 1;
                }

                int valid_chars = 0;
                for (int j = 0; j < word_length; j++) {
                    if (!isspace(file_buffer[word_start + j])) {
                        words[word_index].word[valid_chars++] = tolower(file_buffer[word_start + j]);
                    }
                }

                if (valid_chars > 0) {
                    words[word_index].word[valid_chars] = '\0';
                    word_index++;
                }
            }
            word_start = i + 1;
        }
    }

    WordStats* word_stats = new WordStats[word_index];
    int unique_words_count = 0;

    for (int i = 0; i < word_index; i++) {
        bool word_found = false;
        for (int j = 0; j < unique_words_count; j++) {
            if (strcmp(words[i].word, word_stats[j].word) == 0) {
                word_stats[j].frequency++;
                word_found = true;
                break;
            }
        }

        if (!word_found) {
            strcpy(word_stats[unique_words_count].word, words[i].word);
            word_stats[unique_words_count].frequency = 1;
            unique_words_count++;
        }
    }

    for (int i = 0; i < unique_words_count - 1; i++) {
        for (int j = 0; j < unique_words_count - i - 1; j++) {
            if (word_stats[j].frequency < word_stats[j+1].frequency) {
                WordStats temp = word_stats[j];
                word_stats[j] = word_stats[j+1];
                word_stats[j+1] = temp;
            }
        }
    }

    FILE* result_file = fopen("rez.txt", "w");
    if (result_file != NULL) {
        for (int i = 0; i < unique_words_count; i++) {
            fprintf(result_file, "%s\t%d\n", word_stats[i].word, word_stats[i].frequency);
        }
        fclose(result_file);
    }

    delete[] words;
    delete[] word_stats;
}
