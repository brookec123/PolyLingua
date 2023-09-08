// %{
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "include/token.h"
// #include "include/lexer.h"

// #define MAX_TOKENS_PER_LINE 100 // Define a suitable maximum number of tokens per line
// token_T* line_tokens[MAX_TOKENS_PER_LINE]; // Array to store tokens for the current line
// int token_count = 0; // Counter to keep track of the number of tokens

// %}
    
// %%

// if      { 
//     token_T* token = init_token(TOKEN_KEYWORD, strdup(yytext));
//     line_tokens[token_count++] = token;
//     return TOKEN_KEYWORD;
// }
// =       { 
//     token_T* token = init_token(TOKEN_EQUALS, strdup(yytext));
//     line_tokens[token_count++] = token;
//     return TOKEN_EQUALS;
// }
// \"[^\"]*\"   { 
//     token_T* token = init_token(TOKEN_STRING, strdup(yytext));
//     line_tokens[token_count++] = token;
//     return TOKEN_STRING;
// }
// [(]     { 
//     token_T* token = init_token(TOKEN_LPAREN, strdup(yytext));
//     line_tokens[token_count++] = token;
//     return TOKEN_LPAREN;
// }
// [)]     { 
//     token_T* token = init_token(TOKEN_RPAREN, strdup(yytext));
//     line_tokens[token_count++] = token;
//     return TOKEN_RPAREN;
// }
// [{}]    { 
//     if (yytext[0] == '{') {
//         token_T* token = init_token(TOKEN_LBRACE, strdup(yytext));
//         line_tokens[token_count++] = token;
//         return TOKEN_LBRACE;
//     } else {
//         token_T* token = init_token(TOKEN_RBRACE, strdup(yytext));
//         line_tokens[token_count++] = token;
//         return TOKEN_RBRACE;
//     }
// }
// ,       { 
//     token_T* token = init_token(TOKEN_COMMA, strdup(yytext));
//     line_tokens[token_count++] = token;
//     return TOKEN_COMMA;
// }
// \n      { 
//     token_T* token = init_token(TOKEN_EOF, strdup(yytext));
//     line_tokens[token_count++] = token;
//     return TOKEN_EOF;
// }
// [ \t]   ;  // Ignore whitespace
// .       { 
//     token_T* token = init_token(TOKEN_EOF, strdup(yytext));
//     line_tokens[token_count++] = token;
//     return TOKEN_EOF;
// }
// %%

// int yywrap(){}
// int main() {
//     yylex();  // Tokenization happens here
//     return 0;
// }
