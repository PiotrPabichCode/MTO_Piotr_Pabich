#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_changed_lettercase(const char * data) {
	for(int i = 0; i < strlen(data); i++) {
		if(islower(data[i])) {
			putchar(toupper(data[i]));
		} else if(isupper(data[i])) {
			putchar(tolower(data[i]));
		} else {
			putchar(data[i]);
		}
	}
}

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'k')){
			i++;
			print_changed_lettercase(param);
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
