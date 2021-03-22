CC = g++

CFLAGS  = -Wall

TARGET = ./src/main.cpp

make:
	$(CC) $(TARGET) $(CFLAGS) -o f09f

clean:
	rm ./f09f
