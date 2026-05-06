.PHONY: all clean run

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = student_manager
BUILD = build

all: $(TARGET)

$(TARGET): student.c mylist.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(TARGET) student.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD) $(TARGET)

install:
	cp $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)
