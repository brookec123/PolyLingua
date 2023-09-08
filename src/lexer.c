#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/token.h"
#include "include/lexer.h"

lexer_T *init_lexer(char *source_code_contents)
{
    lexer_T *lexer = (lexer_T *)malloc(sizeof(struct LEXER_STRUCT));
    lexer->source_code_contents = source_code_contents;
    lexer->character_index = 0;
    lexer->current_character = source_code_contents[lexer->character_index];
    return lexer;
}

void lexer_advance(lexer_T *lexer)
{
    if (lexer->current_character != '\0' && lexer->character_index < strlen(lexer->source_code_contents))
    {
        lexer->character_index++;
        lexer->current_character = lexer->source_code_contents[lexer->character_index];
    }
}

void lexer_skip_whitespace(lexer_T *lexer)
{
    while (lexer->current_character == ' ' || lexer->current_character == '\t' || lexer->current_character == '\n')
    {
        lexer_advance(lexer);
    }
}

token_T *lexer_advance_with_token(lexer_T *lexer, token_T *token)
{
    lexer_advance(lexer);
    return token;
}

char *lexer_get_current_char_as_string(lexer_T *lexer)
{
    char *str = (char *)malloc(2 * sizeof(char));
    str[0] = lexer->current_character;
    str[1] = '\0';
    return str;
}

token_T *lexer_collect_string(lexer_T *lexer)
{
    lexer_advance(lexer);
    char *string = (char *)malloc(1 * sizeof(char));
    string[0] = '\0';
    while (lexer->current_character != '"')
    {
        char *char_string = lexer_get_current_char_as_string(lexer);
        string = (char *)realloc(string, (strlen(string) + strlen(char_string) + 1) * sizeof(char));
        strcat_s(string, strlen(string) + strlen(char_string) + 1, char_string);
        lexer_advance(lexer);
    }
    lexer_advance(lexer);
    return init_token(TOKEN_STRING, string);
}

token_T *lexer_collect_id(lexer_T *lexer)
{
    char *id = (char *)malloc(1 * sizeof(char));
    id[0] = '\0';
    while (isalpha(lexer->current_character) || isdigit(lexer->current_character) || lexer->current_character == '_')
    {
        char *char_string = lexer_get_current_char_as_string(lexer);
        id = (char *)realloc(id, (strlen(id) + strlen(char_string) + 1) * sizeof(char));
        strcat_s(id, strlen(id) + strlen(char_string) + 1, char_string);
        lexer_advance(lexer);
    }
    return init_token(TOKEN_KEYWORD, id);
}

token_T *lexer_get_next_token(lexer_T *lexer)
{
    while (lexer->current_character != '\0' && lexer->character_index < strlen(lexer->source_code_contents))
    {
        if (lexer->current_character == ' ' || lexer->current_character == '\t' || lexer->current_character == '\n')
        {
            lexer_skip_whitespace(lexer);
            continue;
        }

        if (lexer->current_character == '=')
        {
            return lexer_advance_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_string(lexer)));
        }
        
        if (lexer->current_character == '(')
        {
            return lexer_advance_with_token(lexer, init_token(TOKEN_LPAREN, lexer_get_current_char_as_string(lexer)));
        }

        if (lexer->current_character == ')')
        {
            return lexer_advance_with_token(lexer, init_token(TOKEN_RPAREN, lexer_get_current_char_as_string(lexer)));
        }

        if (lexer->current_character == '{')
        {
            return lexer_advance_with_token(lexer, init_token(TOKEN_LBRACE, lexer_get_current_char_as_string(lexer)));
        }

        if (lexer->current_character == '}')
        {
            return lexer_advance_with_token(lexer, init_token(TOKEN_RBRACE, lexer_get_current_char_as_string(lexer)));
        }

        if (lexer->current_character == ',')
        {
            return lexer_advance_with_token(lexer, init_token(TOKEN_COMMA, lexer_get_current_char_as_string(lexer)));
        }

        if (lexer->current_character == '"')
        {
            return lexer_collect_string(lexer);
        }

        if (isalpha(lexer->current_character))
        {
            return lexer_collect_id(lexer);
        }

        // Unexpected character
        lexer_advance(lexer);
    }

    return init_token(TOKEN_EOF, "");
}
