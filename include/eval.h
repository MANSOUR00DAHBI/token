// eval.h
#ifndef EVAL_H
#define EVAL_H
#include "stack.h"
int precedence(int op);
void applyOp();
double evaluate(TOKEN tokens[], int n , STOCK stock);

#endif

#ifdef EVAL_H
int precedence(int op) {
    switch(op) {
        case OP_PLUS:
        case OP_MINUS: return 1;
        case OP_MULTIPLY:
        case OP_DIVIDE:
        case OP_MOD: return 2;
        case OP_POWER: return 3;
        default: return 0;
    }
}
void applyOp() {
    double b = pop_stock();
    double a = pop_stock();
    int op = pop_opTop();

    switch(op) {
        case OP_PLUS: push_stock(a + b); break;
        case OP_MINUS: push_stock(a - b); break;
        case OP_MULTIPLY: push_stock(a * b); break;
        case OP_DIVIDE: push_stock(a / b); break;
        case OP_MOD: push_stock(fmod(a, b)); break;
        case OP_POWER: push_stock(pow(a, b)); break;
    }
}
double evaluate(TOKEN tokens[], int n , STOCK stock) {
    for (int i = 0; i < n; i++) {
        if (tokens[i].symbole == TOK_OPERAND) {
            push_stock(tokens[i].value);
        } else if (tokens[i].symbole == OP_LPAREN) {
            push_opTop(OP_LPAREN);
        } else if (tokens[i].symbole == OP_RPAREN) {
            while (pop_opTop >= 0 && stock.opStock[stock.opTop] != OP_LPAREN) {
                applyOp();
            }
            pop_opTop(); // remove '('
        } else {
            while (pop_opTop >= 0 && precedence(stock.opStock[stock.opTop]) >= precedence(tokens[i].symbole)) {
                applyOp();
            }
            push_opTop(tokens[i].symbole);
        }
    }
    while (pop_opTop >= 0) {
        applyOp();
    }
    return pop_stock();
}


#endif



