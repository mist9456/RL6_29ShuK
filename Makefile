# Компилятор
CC = g++

# Флаги компиляции
CFLAGS = -Wall -std=c++11

# Имя исполняемого файла
TARGET = program

# Исходные файлы и объектные файлы
SRCS = main.cpp dz1.cpp
OBJS = $(SRCS:.cpp=.o)

# Основная цель
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Правило для компиляции каждого .cpp файла в .o
%.o: %.cpp dz1.h
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJS) $(TARGET)

# Установка (опционально)
install:
	cp $(TARGET) /usr/local/bin
