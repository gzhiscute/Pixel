#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "parse.h"
#include "utils.h"
#include <stdlib.h>
#include <string>

extern lines_node *root;
extern int yyparse(void *);
extern std::string ans;
extern std::map<std::string, BaseType *> vars;
extern std::map<std::string, def_func *> funcs;
extern int TreeBottomLength; /* The length between two bottom nodes. */
extern int DrawWidth;
extern int DrawHeight;

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

std::string UrlDecode(const std::string& szToDecode)
{
	std::string result;
	int hex = 0;
	for (size_t i = 0; i < szToDecode.length(); ++i)
	{
		switch (szToDecode[i])
		{
		case '+':
			result += ' ';
			break;
		case '%':
			if (isxdigit(szToDecode[i + 1]) && isxdigit(szToDecode[i + 2]))
			{
				std::string hexStr = szToDecode.substr(i + 1, 2);
				hex = strtol(hexStr.c_str(), 0, 16);
				result += char(hex);
				i += 2;
			}else {
				result += '%';
			}
			break;
		default:
			result += szToDecode[i];
			break;
		}
	}
	return result;
}

#define BUF_SIZE 40960
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
		const char *header = "HTTP/1.0 200 OK\r\nAccess-Control-Allow-Origin: *\r\n\r\n";
		send(clientfd, header, strlen(header), 0);
		char *s = strstr(buf, "\r\n\r\n");
		if (s && s[4]) {
			s += 4;
			std::map<std::string, std::string> args;
			while (*s) {
				char *eq = strchr(s, '=');
				*eq = 0;
				std::string name = s;
				s = eq + 1;
				char *token = strchr(s, '&');
				if (token) {
					*token = 0;
					args[name] = s;
					s = token + 1;
				} else {
					args[name] = s;
					break;
				}
			}
			if (args.count(std::string("code"))) {
				std::string k = args[std::string("code")];
				k = UrlDecode(k);
				strcpy(s, k.c_str());
				//ans = (char *)malloc(10000);
				// code is stored in the string s
				char tmpstr[100];
				k = args[std::string("width")];
				k = UrlDecode(k);
				DrawWidth = strtol(k.c_str(), 0, 10);

				k = args[std::string("height")];
				k = UrlDecode(k);
				DrawHeight = strtol(k.c_str(), 0, 10);

				ans = "";
				printf("the s is: %s\n", s);
				vars.clear();
				funcs.clear();
				yyparse(s);
				printf("the root is: 0x%lx", root);
				if (root) {
					root->evaluate();
					delete root;
					root = NULL;					
				}
				else {
					ans = "error! cannot run!";
				}

				len = ans.length();
				//printf("%s\n", ans.c_str());
				send(clientfd, ans.c_str(), len, 0);
				//free(ans);
			}
		}
		closesocket(clientfd);
	}
	return 0;
}
