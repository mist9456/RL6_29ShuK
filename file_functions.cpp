#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE (1024)
#define MAX_WORD_LENGTH 64

void CountWords(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) return;

    int c, i = 0;
    char Full_Txt[MAX_FILE_SIZE + 1];

    while ((c = fgetc(file)) != EOF && i < MAX_FILE_SIZE) {
        Full_Txt[i++] = (char)c;
    }
    Full_Txt[i] = '\0';
    fclose(file);

    struct word {
        char WORD[MAX_WORD_LENGTH];
        int number_latters;
    };

    struct rez {
        char WORD[MAX_WORD_LENGTH];
        int chastota;
    };

    int space = 0;
    for (int j = 0; j < i; j++) {
        if (Full_Txt[j] == ' ') space++;
    }
    const int Space_con = space;

    word* W_ord = new word[Space_con + 1];
    int* word_counts = new int[Space_con + 1];
    int nach = 0;
    int konch = 0;
    int o = 0;
    int z = 0;

    nach = 0;

    for (int j = 0; j <= i; j++) {
        if (Full_Txt[j] == ' ' || Full_Txt[j] == '\0') {
            if (j > nach) {
                int word_len = j - nach;
                if (word_len >= MAX_WORD_LENGTH) {
                    word_len = MAX_WORD_LENGTH - 1;
                }

                for (int k = 0; k < word_len; k++) {
                    W_ord[o].WORD[k] = Full_Txt[nach + k];
                }
                W_ord[o].WORD[word_len] = '\0';
                W_ord[o].number_latters = o + 1;
                o++;
            }
            nach = j + 1;
        }
    }

    rez* R_ez = new rez[o];
    int unique_count = 0;

    for (int j = 0; j < o; j++) {
        int found = 0;
        for (int k = 0; k < unique_count; k++) {
            int match = 1;
            int m = 0;
            while (W_ord[j].WORD[m] != '\0' && R_ez[k].WORD[m] != '\0') {
                if (W_ord[j].WORD[m] != R_ez[k].WORD[m]) {
                    match = 0;
                    break;
                }
                m++;
            }
            if (match && W_ord[j].WORD[m] == '\0' && R_ez[k].WORD[m] == '\0') {
                R_ez[k].chastota++;
                found = 1;
                break;
            }
        }
        if (!found) {
            int m = 0;
            while (W_ord[j].WORD[m] != '\0') {
                R_ez[unique_count].WORD[m] = W_ord[j].WORD[m];
                m++;
            }
            R_ez[unique_count].WORD[m] = '\0';
            R_ez[unique_count].chastota = 1;
            unique_count++;
        }
    }

    for (int j = 0; j < unique_count - 1; j++) {
        for (int k = 0; k < unique_count - j - 1; k++) {
            int len1 = 0, len2 = 0;
            while (R_ez[k].WORD[len1] != '\0') len1++;
            while (R_ez[k + 1].WORD[len2] != '\0') len2++;
            if (len1 < len2) {
                rez temp = R_ez[k];
                R_ez[k] = R_ez[k + 1];
                R_ez[k + 1] = temp;
            }
        }
    }

    FILE* rez_file = fopen("rez.txt", "w");
    if (rez_file != NULL) {
        for (int j = 0; j < unique_count; j++) {
            fprintf(rez_file, "%s\t%d\n", R_ez[j].WORD, R_ez[j].chastota);
        }
        fclose(rez_file);
    }

    delete[] W_ord;
    delete[] word_counts;
    delete[] R_ez;
}
