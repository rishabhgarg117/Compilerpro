#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>4

#include "lexerf.h";

int main(){
    FILE *file;
    file = fopen("test.el", "r");
    Token *tokens = lexer(file);

    /*for(size_t i = 0; tokens[i].type!= END_OF_TOKENS ; i++){
        printf("%p\n", tokens[i].value);
        print_token(tokens[i]);
    }*/
    return 0;
}