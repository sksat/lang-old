#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "lang.h"

#define MAX_LINE_LEN	256
#define INTERPRET	0
#define COMPILE		1

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
        char buf[MAX_LINE_LEN];

        for(;;){
                if(EXEC_MODE == INTERPRET){
                        printf("> ");
                }

                if(fgets(buf, MAX_LINE_LEN, fp) == NULL){
                        return 0;
                }
                int len = strlen(buf);

                
        }
}
