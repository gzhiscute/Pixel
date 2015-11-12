#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>

SOCKET soc;
SOCKET init_soc(int port) {
    struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons((unsigned short)port);
    if (bind(soc, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
    	puts("Failed: Bind");
		exit(-1);
    }
    if (listen(soc, SOMAXCONN) < 0) {
    	puts("Failed: Listen");
		exit(-1);
    }
    printf("Listening: %d\n", port);
    return soc;
}

BOOL CtrlHandler(DWORD fdwCtrlType) {
	closesocket(soc);
	WSACleanup();
	puts("Closed");
	exit(0);
}

#define BUF_SIZE 4096
char buf[BUF_SIZE];
int main() {
	WSADATA wsa;
	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE)) {
		;
	} else {
		puts("Failed: Catch Ctrl-C");
		puts("But it's safe to continue...");
	}
    if (WSAStartup(MAKEWORD(2, 2), &wsa) ||
		(soc = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) < 0) {
    	puts("Failed: Initialize");
		exit(-1);
    }
	init_soc(8123);
	while ("serve forever") {
		struct sockaddr clientaddr;
		int addrlen = sizeof clientaddr;
		SOCKET clientfd;
		int len;
		do clientfd = accept(soc, &clientaddr, &addrlen);
		while (clientfd < 0);
		//TODO: thread
		len = recv(clientfd, buf, BUF_SIZE, 0);
		buf[len] = 0;
		//puts(buf);
		char *header = "HTTP/1.0 200 OK\r\nAccess-Control-Allow-Origin: *\r\n\r\n";
		send(clientfd, header, strlen(header), 0);
		char *s = strstr(buf, "\r\n\r\n");
		if (s >= 0 && s + 9 - buf < len) {
			s += 9;
			// code is stored in the string s
			send(clientfd, s, len - (s - buf), 0);
		}
		closesocket(clientfd);
	}
	return 0;
}
