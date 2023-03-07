#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validate_format(const char * string, int * len) {
	if(strlen(string) < 4) {
		return -1;
	}
	int i = 1;
	char dot = string[i++];
	if(dot != '.') {
		return -1;
	}

	int counter = 0;
	char buff[1024] = {0};	
	char tmp;
	for(;;) {
		tmp = string[i++];
		if(isdigit(tmp)) {
			buff[counter++] = tmp;
		} else {
			break;
		}
	}
	if(tmp != 'k' || counter == 0) {
		return -1;
	}
	int value;
	sscanf(buff, "%d", &value);
	*len = counter;
	return value;
}

void print_swapcase(const char * string, int length) {
	for(int i = 0; i < length; i++) {
		if(islower(string[i])) {
			putchar(toupper(string[i]));	
		} else if(isupper(string[i])) {
			putchar(tolower(string[i]));
		} else {
			putchar(string[i]);
		}
	}
}

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'k')){
			i++;
			printf("%s",param);
		}else
			putchar(format_string[i]);
	}
	puts("");
	return 0;
}

int main(int argc, char *argv[]){
	char buf[1024],buf2[1024];
	while(gets(buf)){
		gets(buf2);
		my_printf(buf,buf2);
	}
	return 0;
}
