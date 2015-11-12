#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pixel.cpp"
char InputBuffer[4096];

void DecodeAndProcessData(int len) {
    InputBuffer[len] = ' 1';
    InputBuffer[len+2] = 0;
    yy_switch_to_buffer(InputBuffer);
    yyparse((void *)InputBuffer);
    //printf("<BODY>The information you supplied has been accepted.</BODY>\n");
    //printf("<circle cx=\"20\" cy=\"20\" r=\"2\" style=\"fill:rgb(20,20,23)\"/>");
    return;
}

int main(int argc, char *argv[]) {
    int ContentLength;	 /*数据长度*/
    int x;
    int i;
    char *p;
    char *pRequestMethod;	  /* METHOD属性值 */
    setvbuf(stdin,NULL,_IONBF,0);	  /*关闭stdin的缓冲*/
    printf("Content-type: text/html\n");  /*从stdout中输出，告诉Web服务器返回的信息类型*/
    printf("\n");                        /*插入一个空行，结束头部信息*/
    /* 从环境变量REQUEST_METHOD中得到METHOD属性值 */
    pRequestMethod = getenv("REQUEST_METHOD");	
    if (pRequestMethod==NULL) {
      return 0;
    }
    if (strcmp(pRequestMethod,"POST")==0) {
        p = getenv("CONTENT_LENGTH");  /*从环境变量CONTENT_LENGTH中得到数据长度*/
        if (p!=NULL) {
          ContentLength = atoi(p);
        } 
        else {
          ContentLength = 0;
        }
        if (ContentLength>sizeof(InputBuffer)-1) {
          ContentLength = sizeof(InputBuffer)-1;
        }
        i = 0;
        while (i<ContentLength) {	            /*从stdin中得到Form数据*/
          x = fgetc(stdin);
          if (x==EOF) break;
          InputBuffer[i++] = x;
        }
        InputBuffer[i] = '\0';
        ContentLength = i;
        DecodeAndProcessData(ContentLength);        /*具体译码和处理数据，该函数代码略*/
    } 
    else if (strcmp(pRequestMethod,"GET")==0) {
        p = getenv("QUERY_STRING");	  /*从环境变量QUERY_STRING中得到Form数据*/
        if (p!=NULL) {
          strncpy(InputBuffer,p,sizeof(InputBuffer));
          //DecodeAndProcessData();               /*具体译码和处理数据，该函数代码略*/
        }
    }
    return 0;
}