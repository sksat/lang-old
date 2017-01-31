#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "lang.h"

#define MAX_LINE_LEN	256
#define INTERPRET	0
#define COMPILE		1

typedef struct {
	char *fname;
	unsigned int line;
	char *token;
}DEBUG_INFO;

int EXEC_MODE;

int langMainLoop(FILE *fp);
int is_sentence(char *buf);
int sentence_num(char *buf);

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
	int i,j;
	
	buf = (char*)malloc(sizeof(char)*MAX_LINE_LEN);
	
	for(;;){
		if(EXEC_MODE == INTERPRET){
			printf("> ");
		}

		// get line
		if(fgets(buf, MAX_LINE_LEN, fp) == NULL){ return 0; }
skip_fgets:
		int snum = sentence_num(buf);
		
		if(snum <= 0){
			char *tmp = (char*)malloc(sizeof(char)*MAX_LINE_LEN);
			if(fgets(tmp, MAX_LINE_LEN, fp) == NULL){
				break;
			}
			
			int buflen = strlen(buf);
			int tmplen = strlen(tmp);
			
			char *buf2 = (char*)malloc(sizeof(char)*(
					buflen + tmplen + 1)); // \0
			strcpy(buf2, buf); //まずはbufをコピー
			strcpy(&buf2[buflen+1], tmp);
			
			free(buf);
			free(tmp);

			buf = buf2;
			goto skip_fgets;
		}
		
		if(snum > 1){
			int len = sentence_len(buf);
			char *buf2 = (char*)malloc(sizeof(char) * (len+1));
			strcpy_n(buf2, buf, len);
			buf2[len] = '\0';
			char *tmp = (char*)malloc(sizeof(char) * (strlen(buf) - len));
			strcpy_n(tmp, &buf[len+1],  strlen(buf)-len);
			free(buf);
			buf = tmp;
		}
		
                int len = strlen(buf);
                
		
        }
}
