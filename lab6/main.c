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

    res = sscanf(string, "%d%c", width, &endpoint); // #10g
    if(res == 2) {
        if(endpoint == 'g') {
			*precision = 0;
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

void print_changed_number(long number, int width, int precision) {
	char buff[100] = {0};
	sprintf(buff, "%ld", number);
	int number_len = strlen(buff);

	int max_precision = number_len;
	if(max_precision < precision) {
		max_precision = precision;
	}

	// printowanie spacji na poczatku
	if(abs(width) > max_precision && width > 0) {
		int spaces = abs(width) - max_precision;
		for(int i = 0; i < spaces; i++) {
			putchar(' ');
		}
	}

	//printf("Precision: %d | width: %d\n", precision, width);
	// printowanie zer
	int zeros_counter = precision - number_len;
	if(zeros_counter > 0) {
		for(int i = 0; i < zeros_counter; i++) {
			putchar('0');
		}
	}


	// wyświetlanie liczby
	for(int start = 0; start < strlen(buff); start++) {			
		if(buff[start] == '-') {
        	putchar('-');
			continue;
    	}
        single_change(buff[start]);
    }


	// printowanie spacji na koncu

	// printowanie spacji na poczatku
	if(abs(width) > max_precision && width < 0) {
		int spaces = abs(width) - max_precision;
		for(int i = 0; i < spaces; i++) {
			putchar(' ');
		}
	}
}

int my_printf(char *format_string, char *param){
    for(int i=0;i<strlen(format_string);i++){
        int valid = 0;
        if(format_string[i] == '#'){
            const char * tmp = format_string + i + 1;
            int precision=0, width=0;
            int res = validate_format(tmp, &width, &precision);
            if(res == 0) {
                putchar('#');
                putchar('#');
                i++;
                continue;
            }
            int error = 1;
            if(res != -1) {
                long number = validate_number(param, &error);
                if(error == 0) {
                    print_changed_number(number, width, precision);
                    valid = 1;
                    for(;;i++) {
                        char c = format_string[i];
                        if(c == 'g') {
                            break;
                        }
                    }
                }
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

