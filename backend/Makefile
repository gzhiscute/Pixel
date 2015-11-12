CC = g++
#CFLAGS = -g -Wall
CFLAGS = -O2 -Wall

all: server.exe
server.exe: server.cpp
	$(CC) $(CFLAGS) -o server.exe pixel.cpp server.cpp -lws2_32

.PHONY:clean
clean:
	del *.exe

