#include "./include/token.h"
#define IMPLEMENTED_H

int main(void)
{
    TOKEN tokens[100];
    char expr[256];
    printf("Enter the mathematical expression: ");
    if (!fgets(expr, sizeof(expr), stdin))
    {
        printf("Input error\n");
        return 1;
    }

    double n = tokenize(expr, tokens, 100);
    if (n < 0)
    {
        printf("Failed to parse the expression\n");
        return 1;
    }
    // Print the codes to verify the analysis
    for (int i = 0; i < n; i++)
    {
        if (tokens[i].symbole == TOK_OPERAND)
        {
            printf("number: %.2f\n", tokens[i].value);
        }
        else
        {
            switch (tokens[i].symbole)
            {
            case OP_PLUS:
                printf("operation: +\n");
                break;
            case OP_MINUS:
                printf("operation: -\n");
                break;
            case OP_MULTIPLY:
                printf("operation: *\n");
                break;
            case OP_DIVIDE:
                printf("operation: /\n");
                break;
            case OP_POWER:
                printf("operation: ^\n");
                break;
            case OP_MOD:
                printf("operation: %%\n");
                break;
            case OP_LPAREN:
                printf("operation: (\n");
                break;
            case OP_RPAREN:
                printf("operation: )\n");
                break;
            default:
                printf("operation: ?\n");
                break;
            }
        }
    }

    return 0;
}