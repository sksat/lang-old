#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lang.h"

int EXEC_MODE;

int main(int argc, char **argv){
	FILE *fp;
	
	if(argc == 1){
		EXEC_MODE = INTERPRET;
		fp = stdin;
	}else{
		EXEC_MODE = COMPILE;
	}
}


