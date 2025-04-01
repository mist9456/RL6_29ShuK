#include "stat_files.h"
#include <cstring>
#include <cstdio>
#include <cctype>
StatFileInfo::StatFileInfo()
: _letters(new int[256]{}),  // Фигурные скобки {} обнуляют массив
fileName_(nullptr)
{}

StatFileInfo::StatFileInfo(const char* file_name)
: _letters(new int[256]{}),
fileName_(new char[strlen(file_name) + 1])
{
    strcpy(fileName_, file_name);
}

// Деструктор
StatFileInfo::~StatFileInfo() {
    delete[] _letters;
    delete[] fileName_;
}

void GetCountLetters(StatFileInfo* fileInfo, const char* fileName) {
    // Открываем файл
    FILE* file = fopen(fileName, "r");
    if (!file) return;

    // Читаем посимвольно (массив УЖЕ обнулён в конструкторе)
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {  // Только буквы (A-Z, a-z)
            fileInfo->_letters[c]++;  // Учитываем оригинальный регистр
        }
    }

    fclose(file);

    delete[] fileInfo->fileName_;
    fileInfo->fileName_ = new char[strlen(fileName) + 1];
    strcpy(fileInfo->fileName_, fileName);
}
