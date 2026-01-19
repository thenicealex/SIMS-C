.PHONY: all clean run

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
TARGET = student_manager
SRC = src
BUILD = build
OBJS = $(BUILD)/student.o $(BUILD)/mylist.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(BUILD)/student.o: $(SRC)/student.c include/mylist.h
	$(CC) $(CFLAGS) -c $(SRC)/student.c -o $(BUILD)/student.o

$(BUILD)/mylist.o: $(SRC)/mylist.c include/mylist.h
	$(CC) $(CFLAGS) -c $(SRC)/mylist.c -o $(BUILD)/mylist.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD)/*.o $(TARGET)

install:
	cp $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)
