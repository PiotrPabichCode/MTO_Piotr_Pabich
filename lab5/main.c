#include <stdio.h>
#include <string.h>

int validate_format(const char * string, int * precision) {
    char endpoint;
    int res = sscanf(string, "%c", &endpoint); // #g
    if(res == 1) {
        if(endpoint == '#') {
            return 3;
        }
        if(endpoint == 'g') {
            return 1;
        }
    }
    res = sscanf(string, "%d%c", precision, &endpoint); // #10g
    if(res == 2) {
        if(endpoint == 'g' && *precision >= 0) {
            return 2;
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

void print_changed_number(long number, int precision) {
    //printf("%s\n", number);
    char buff[100] = {0};
    sprintf(buff, "%ld", number);
    if(precision != -1) {
        int spaces = precision - strlen(buff);
        for(int i = 0; i < spaces; i++) {
            //printf("i: %d | %d\n", i, precision - strlen(number));
            putchar(' ');
        }
    }
   // printf("Here\n");
    for(int i = 0; i < strlen(buff); i++) {
        if(buff[i] == '-') {
            putchar(buff[i]);
            continue;
        }
        char num = buff[i] - 1;
        if(num < '0') {
            num = '9';
        }
        putchar(num);
    }
}

int my_printf(char *format_string, char *param){
    for(int i=0;i<strlen(format_string);i++){
        int valid = 0;
        if(format_string[i] == '#'){
            const char * tmp = format_string + i + 1;
            int precision;
            int res = validate_format(tmp, &precision);
            int error = 1;
            if(res != -1) {
                long number = validate_number(param, &error);
                if(error == 0) {
                    if(res == 1) {
                        print_changed_number(number, -1);
                    } else {
                        print_changed_number(number, precision);
                    }
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
