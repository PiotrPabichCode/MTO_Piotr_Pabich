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
