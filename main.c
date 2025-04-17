#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum
{
    EXIT,
} TypeKeyword;

typedef enum
{
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
} TypeSeperator;

typedef enum
{
    INT,
} TypeLiteral;

typedef struct
{
    TypeKeyword type;
} TokenKeyword;

typedef struct
{
    TypeLiteral type;
    int value;
} TokenLiteral;

typedef struct
{
    TypeSeperator type;
    char *value;
} TokenSeperator;

TokenLiteral *generate_number(char *current, int *current_index)
{
    TokenLiteral *token = malloc(sizeof(TokenLiteral));
    token->type = INT;
    char *value = malloc(sizeof(char) * 8);
    int index_value = 0;
    while (isdigit(current[*current_index]) && current[*current_index] != '\0')
    {
        if (!isdigit(current[*current_index]))
        {
            break;
        }
        value[index_value] = current[*current_index];
        index_value++;
        *current_index += 1;
    }
    value[index_value] = '\0';
    token->value = atoi(value);
    return token;
}

TokenKeyword *generate_keyword(char *current, int *current_index)
{
    TokenKeyword *token = malloc(sizeof(TokenKeyword));
    char *keyword = malloc(sizeof(char) * 8);
    int keyword_index = 0;
    while (isalpha(current[*current_index]) && current[*current_index] != '\0')
    {
        keyword[keyword_index] = current[*current_index];
        keyword_index++;
        *current_index += 1;
    }
    keyword[keyword_index] = '\0';
    if (strcmp(keyword, "exit") == 0)
    {
        printf("TYPE EXIT\n");
        token->type = EXIT;
    }
    return token;
}

void lexer(FILE *file)
{
    int length;
    char *buffer = 0;
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(sizeof(char) * length);
    fread(buffer, 1, length, file);
    fclose(file);
    buffer[length + 1] = '\0';
    char *current = malloc(sizeof(char) * length + 1);
    current = buffer;
    int current_index = 0;

    while (current[current_index] != '\0')
    {
        if (current[current_index] == ';')
        {
            printf("SEMI\n");
        }
        else if (current[current_index] == '(')
        {
            printf("OPEN_PAREN\n");
        }
        else if (current[current_index] == ')')
        {
            printf("CLOSE_PAREN\n");
        }
        else if (isdigit(current[current_index]))
        {
            TokenLiteral *text_token = generate_number(current, &current_index);
            current_index--;
            printf("TEST TOKEN VALUE: %d\n", text_token->value);
        }
        else if (isalpha(current[current_index]))
        {
            TokenKeyword *text_keyword = generate_keyword(current, &current_index);
            current_index--;
        }
        current_index++;
    }
}

int main()
{
    FILE *file;
    file = fopen("test.el", "r");
    lexer(file);
    return 0;
}