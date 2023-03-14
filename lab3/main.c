#include <stdio.h>
#include <string.h>

int validate_format(const char * string, int * width, int * precision) {
	char dot, endpoint;
	int res = sscanf(string, "%c", &endpoint); // #k
	if(res == 1) {
		if(endpoint == 'k') {
			return 1;
		}
	}
	res = sscanf(string, "%c%d%c", &dot, precision, &endpoint); // #.10k
	if(res == 3) {
		if(dot == '.' && *precision > 0 && endpoint == 'k') {
			return 2;
		}
	}

	return -1;
}
void print_swapcase(const char * string, int width, int precision) {
	for(int i = 0; i < strlen(string) && i < precision; i++) {
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
