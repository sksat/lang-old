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
//		if(fgets(buf, MAX_LINE_LEN, fp) == NULL){
//			return 0;
//		}
//		
//		if(!(is_sentence(buf))){
//			
//		}
		
		// 文の塊になるまで読み込み続ける
		for(i=0;;i++){
			if(is_sentence(buf)){
				break;
			}
			if(i != 0){
				
			}
		}
		
                int len = strlen(buf);
                
		
        }
}
