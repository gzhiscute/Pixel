CC = g++
#CFLAGS = -g -Wall
CFLAGS = -O2 -Wall

all: server.exe
server.exe: pixel.cpp utils.cpp server.cpp
	$(CC) $(CFLAGS) -o server.exe pixel.cpp utils.cpp server.cpp -lws2_32

static: server_static.exe
server_static.exe: pixel.cpp utils.cpp server.cpp
	$(CC) $(CFLAGS) -o server_static.exe pixel.cpp utils.cpp server.cpp -lws2_32 --static

.PHONY:clean
clean:
	del *.exe

