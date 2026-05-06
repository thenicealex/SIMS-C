.PHONY: all clean run

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
TARGET = student_manager
SRC = src
BUILD = build

all: $(TARGET)

$(TARGET): $(SRC)/student.c include/mylist.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)/student.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD) $(TARGET)

install:
	cp $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)
