#ifndef H_TOKEN
#define H_TOKEN
#define IMPLEMENTED_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef enum
{
    TOK_OPERAND = 0,
    TOK_OPRATOP = 1,
    OP_PLUS = '+',
    OP_MINUS = '-',
    OP_MULTIPLY = '*',
    OP_DIVIDE = '/',
    OP_POWER = '^',
    OP_MOD = '%',
    OP_RPAREN = ')',
    OP_LPAREN = '(',
    OP_BAD = 11
} symbole_token;
typedef struct TOKEN
{
    double value;
    int symbole;
} TOKEN;
double read_number(char **p);
char *GetNextToken(char *input, TOKEN *tokens);
double tokenize(char *expr, TOKEN tokens[], int max_tokens);
#endif

#ifdef IMPLEMENTED_H
double tokenize(char *expr, TOKEN tokens[], int max_tokens)
{
    int count = 0;
    char *p = expr;
    while (*p && isspace(*p))
        p++; // Skip leading withspace
    while (*p != '\0' && count < max_tokens)
    {
        if (isspace(*p))
        {
            p++;
            continue;
        }
        if (isdigit(*p) || *p == '.')
        {
            tokens[count].symbole = TOK_OPERAND;
            tokens[count].value = read_number(&p);
            count++;
            continue;
        }
        if (*p == '-')
        {
            if (count == 0 || tokens[count - 1].symbole == OP_LPAREN)
            {
                p++;
                tokens[count].symbole = TOK_OPERAND;
                tokens[count].value = -read_number(&p);
                count++;
                continue;
            }
            else
            {
                tokens[count].symbole = OP_MINUS;
                tokens[count].value = 0;
                count++;
                p++;
                continue;
            }
        }
        TOKEN t;
        p = GetNextToken(p, &t);
        if (t.symbole == OP_BAD)
        {
            printf("Error: invalid code '%c'\n", *p);
            return -1;
        }
        tokens[count++] = t;
    }
    return count;
}

char *GetNextToken(char *input, TOKEN *tokens)
{
    int count ;
    while (*input && isspace(*input))
        input++; // Skip leading withspace
  
        if (isspace(*input))
        {
            input++;
           // continue;
        }
        if (isdigit(*input) || *input == '.')
        {
            tokens[count].symbole = TOK_OPERAND;
            tokens[count].value = read_number(&input);
            count++;
            return input;
           // continue;
        }
        if (*input == '-')
        {
            if (count == 0 || tokens[count - 1].symbole == OP_LPAREN)
            {
                input++;
                int val = 0;
                while (isdigit(*input))
                {
                    val = val * 10 + (*input - '0');
                    input++;
                }
                tokens[count].symbole = TOK_OPERAND;
                tokens[count].value = -val;
                count++;
                 return input;
              //  continue;
            }
            else
            {
                tokens[count].symbole = OP_MINUS;
                tokens[count].value = 0;
                count++;
                input++;
                 return input;
            //  continue;
            }
        }
    
    switch (*input)
    {
    case '+':
        tokens->symbole = OP_PLUS;
        break;
    case '-':
        tokens->symbole = OP_MINUS;
        break;
    case '*':
        tokens->symbole = OP_MULTIPLY;
        break;
    case '/':
        tokens->symbole = OP_DIVIDE;
        break;
    case '^':
        tokens->symbole = OP_POWER;
        break;
    case '%':
        tokens->symbole = OP_MOD;
        break;
    case '(':
        tokens->symbole = OP_LPAREN;
        break;
    case ')':
        tokens->symbole = OP_RPAREN;
        break;
    default:
        tokens->symbole = OP_BAD;
        break;
    };
    tokens->value = *input;
    input++;
    return input ;
}
double read_number(char **p)
{
    double val = 0.0, frac = 0.0, divisor = 1.0;
    while (**p && isspace(**p))
        p++; // Skip leading withspace
  
    while (isdigit(**p))
    {
        val = val * 10 + (**p - '0');
        (*p)++;
    }
    if (**p == '.')
    {
        (*p)++;
        while (isdigit(**p))
        {
            frac = frac * 10 + (**p - '0');
            divisor *= 10.0;
            (*p)++;
        }
        val += frac / divisor;
    }
    return val;
}

#endif