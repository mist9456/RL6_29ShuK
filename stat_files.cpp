#include "file_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 64

void CountWords(const char* fileName) {
    // Проверка входного параметра
    if (fileName == NULL) {
        fprintf(stderr, "Error: NULL filename\n");
        return;
    }

    // Открытие файла
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", fileName);
        return;
    }

    // Чтение файла
    char content[1024];  // Упрощённый буфер
    size_t i = 0;
    int c;
    while ((c = fgetc(file)) != EOF && i < sizeof(content)-1) {
        content[i++] = (char)c;
    }
    content[i] = '\0';
    fclose(file);

    // Обработка слов
    struct Word {
        char text[MAX_WORD_LEN];
        int count;
    } words[MAX_WORDS];

    int wordCount = 0;
    char* token = content;

    while (*token) {
        // Пропуск пробелов
        while (*token && isspace(*token)) token++;
        if (!*token) break;

        // Выделение слова
        char* start = token;
        while (*token && !isspace(*token)) token++;

        // Сохранение слова
        if (wordCount < MAX_WORDS) {
            int len = token - start;
            len = (len < MAX_WORD_LEN-1) ? len : MAX_WORD_LEN-1;

            strncpy(words[wordCount].text, start, len);
            words[wordCount].text[len] = '\0';
            words[wordCount].count = 1;
            wordCount++;
        }
    }

    // Запись результата
    FILE* out = fopen("result.txt", "w");
    if (out) {
        for (int i = 0; i < wordCount; i++) {
            fprintf(out, "%s\t%d\n", words[i].text, words[i].count);
        }
        fclose(out);
    }
}
