#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

	res = sscanf(string, "%d%c", width, &endpoint); // #10k
	if(res == 2) {
		if(endpoint == 'k' && *width > 0) {
			return 3;
		}
	}	
	res = sscanf(string, "%d%c%d%c", width, &dot, precision, &endpoint); // #10.10k
	if(res == 4) {
		if(*width > 0 && dot == '.' && *precision >= 0 && endpoint == 'k') {
			return 4;
		}
	}

	return -1;
}
void print_swapcase(const char * string, int width, int precision) {
	if(width != -1) {
		int spaces = width - (precision > strlen(string) ? strlen(string) : precision);
		for(int i = 0; i < spaces; i++) {
			putchar(' ');
		}
	}
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
		int valid = 0;
		if((format_string[i] == '#')){
			const char * tmp = format_string + i + 1;
			int width, precision;
			int res = validate_format(tmp, &width, &precision);
            if(res != -1) {
                if(res == 1) {
				    print_swapcase(param, -1, strlen(param)); // #k
                } else if(res == 2) {
                    print_swapcase(param, -1, precision); // #.10k 
                } else if(res == 3) {
                    print_swapcase(param, width, strlen(param)); // #10k
                } else if(res == 4) {
                    print_swapcase(param, width, precision); // #10.10k
                }
                for(;;i++) {
                    char c = format_string[i];
                    if(c == 'k') {
                        break;
                    }
                }
				valid = 1;
            }
		}
		// display single char
		if(!valid) {
			putchar(format_string[i]);
		}
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
