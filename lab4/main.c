#include <stdio.h>
#include <string.h>

int validate_number(const char * text, int * error) {
	long num;
	if(sscanf(text, "%ld", &num) != 1) {
		*error = 1;
		return 0;	
	}
	*error = 0;
	return num;
}

void print_reverse_number(long number) {
	char buff[50] = {0};
	sprintf(buff, "%ld", number);
	int pos = strlen(buff) - 1;
	while(pos >= 0) {
		putchar(buff[pos--]);
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
