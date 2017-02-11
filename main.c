#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strtols.h"

//#include "lang.h"

#define MAX_LINE_LEN	256
#define INTERPRET	0
#define COMPILE		1

#define IGNORE_NEWLINE	"\\"	// 複数文字でも大丈夫なように''でなく""

typedef struct {
	char *fname;
	unsigned int line;
	char *token;
}DEBUG_INFO;

int EXEC_MODE;

char* PROMPT		= ">>> ";
char* BROCK_PROMPT	= "... ";


int langMainLoop(FILE *fp);
int is_sentence(char *buf);
int sentence_num(char *buf, int read);
int sentence_len(char *buf);

int sentence_num(char *buf, int read){
	int len = strlen(buf);
	
	int i = findstr(buf+read, IGNORE_NEWLINE), j;
	if(i >= 0){
		rmstr(buf+read+i, strlen(IGNORE_NEWLINE));
		for(j=0;j<(len-read-i);j++){
			if((buf+read+i)[j] == '\n'){
				(buf+read+i)[j] = ' ';
			}
		}
		return -1;
	}
	return 0;
}

int sentence_len(char *buf){
	return 0;
}

int main(int argc, char **argv){
	FILE *fp;
	
	if(argc == 1){
		EXEC_MODE = INTERPRET;
		fp = stdin;
		printf("interpretor mode.\n");
	}else{
		EXEC_MODE = COMPILE;
		fp = fopen(argv[1], "r");
		if(fp == NULL){
			printf("error:\n\tcan't open file:%s\n", argv[1]);
			return -1;
		}
	}

	return langMainLoop(fp);
}

int langMainLoop(FILE *fp){
	char *buf;
	int snum;
	int i,j;
	
	//バッファの確保
	buf = (char*)malloc(sizeof(char)*MAX_LINE_LEN);
	
	for(;;){
		// インタプリタの時はプロンプト表示
		if(EXEC_MODE == INTERPRET){
			printf("%s", PROMPT);
		}

		// get line
		if(fgets(buf, MAX_LINE_LEN, fp) == NULL){ return 0; }
		i = 0;

skip_fgets:
		snum = sentence_num(buf, i);
		printf("snum = %d\n", snum);
		printf("buf = %s\n", buf);
		
		if(snum < 0){
			char *tmp = (char*)malloc(sizeof(char)*MAX_LINE_LEN);

			printf("%s", BROCK_PROMPT);

			if(fgets(tmp, MAX_LINE_LEN, fp) == NULL){
				break;
			}
			
			int buflen = strlen(buf);
			int tmplen = strlen(tmp);
			i += tmplen;
			
			char *buf2 = (char*)malloc(sizeof(char)*(
					buflen + tmplen + 1)); // \0
			strcpy(buf2, buf); //まずはbufをコピー
			strcpy(&buf2[buflen], tmp);
			
			free(buf);
			free(tmp);

			buf = buf2;
			goto skip_fgets;
		}
		
		if(snum > 1){
			int len = sentence_len(buf);
			char *buf2 = (char*)malloc(sizeof(char) * (len+1));
			strncpy(buf2, buf, len);
			buf2[len] = '\0';
			char *tmp = (char*)malloc(sizeof(char) * (strlen(buf) - len));
			strncpy(tmp, &buf[len+1],  strlen(buf)-len);
			free(buf);
			buf = tmp;
		}
		
                int len = strlen(buf);
                
		printf("buf:%s\n", buf);
        }
}
