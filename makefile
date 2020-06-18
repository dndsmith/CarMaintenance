CC=g++
CFLAGS=-Wall
BINS=carMaintenance

default: main.cpp
	$(CC) $(CFLAGS) main.cpp -o carMaintenance

clean:
	rm $(BINS)
