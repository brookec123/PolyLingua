#include "include/token.h"
#include <stdlib.h>

token_T *init_token(int type, char *value)
{
    token_T *token = (token_T *)malloc(sizeof(token_T));
    token->type = type;
    token->value = value;
    return token;
}