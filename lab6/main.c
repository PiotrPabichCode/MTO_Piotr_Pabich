#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validate_format(const char * string, int * width, int * precision) {
    char endpoint, dot;
    int res = sscanf(string, "%c", &endpoint); // #g
    if(res == 1) {
        if(endpoint == '#') {
            return 0;
        }
        if(endpoint == 'g') {
            return 1;
        }
    }

	res = sscanf(string, "%c%d%c", &dot, precision, &endpoint); // #.10g
	if(res == 3) {
		if(dot == '.' && *precision > 0 && endpoint == 'g') {
			return 2;
		}
	}

    res = sscanf(string, "%d%c", precision, &endpoint); // #10g
    if(res == 2) {
        if(endpoint == 'g') {
            return 3;
        }
    }

	res = sscanf(string, "%d%c%d%c", width, &dot, precision, &endpoint); // #10.10g
	if(res == 4) {
		if(dot == '.' && *precision >= 0 && endpoint == 'g') {
			return 4;
		}
	}

    return -1;
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

long validate_number(const char * text, int * error) {
    long num;
    if(sscanf(text, "%ld", &num) != 1) {
        *error = 1;
        return 0;
    }
    *error = 0;
    return num;
}

void single_change(char c) {
	int num = (int)(c - '0');
	int num1 = (num*9+1)%10;
	char out = num1 + '0';
	putchar(out);
}

int main(int argc, char *argv[]){
	char buf[1024],buf2[1024];
	while(gets(buf)){
		gets(buf2);
		my_printf(buf,buf2);
	}
	return 0;
}

