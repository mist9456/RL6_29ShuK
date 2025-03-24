#include "dz1.h"

int CountSimilarBytes(long long int chislo) {
    unsigned char bytes[8];
    int count[256] = {0};
    int max = 0;

    for (int i = 0; i < 8; i++) {
        bytes[i] = (chislo >> (i * 8)) & 0xFF;
        if (bytes[i] != 0xFF && bytes[i] != 0x00) {
            count[bytes[i]]++;
        }
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] > max) {
            max = count[i];
        }
    }

    return max;
}

void SwapBytes(unsigned short* chislo) {
    unsigned char* bytes = reinterpret_cast<unsigned char*>(chislo);
    unsigned char temp = bytes[0];
    bytes[0] = bytes[1];
    bytes[1] = temp;
}

unsigned char GetMaxByte(const unsigned int* ar, std::size_t size) {
    unsigned char maxByte = 0;

    for (std::size_t i = 0; i < size; i++) {
        unsigned int current = ar[i];
        for (int j = 0; j < 4; j++) {
            unsigned char byte = (current >> (j * 8)) & 0xFF;
            // Игнорируем байты 0xFF и 0x00
            if (byte != 0xFF && byte != 0x00 && byte > maxByte) {
                maxByte = byte;
            }
        }
    }

    return maxByte;
}
