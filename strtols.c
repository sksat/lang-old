#include "strtols.h"

int findstr(char *src, char *str){
	int i;
	int srclen = strlen(src);
	int len = strlen(str);
	
	if(srclen < len){ return -1;  }// あるわけねえ
	if(srclen == len){
		if(strcmp(src, str) == 0) return 0;
		return -1;
	}
	
	for(i=0;i<(srclen-len);i++){
		if(strncmp(src+i, str, len) == 0) return i;
	}
	
	return -1;
}

int rmstr(char *str, int len){
	int i;
	for(i=0;i<len;i++){
		if(str[i]=='\0') break;
		str[i] = str[i+1];
	}
}


