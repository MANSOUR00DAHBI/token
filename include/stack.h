// Stock.c

#ifndef STOCK_H
#define SOCKT_h
#include "token.h"
#define MAXSTOCK 256
typedef struct STOCK
{
    double Stack[MAXSTOCK];
    int top;
    int opStock[MAXSTOCK];
    int opTop;
}STOCK;

void push_stock(double val);
double pop_stock();
void push_opTop(int op);
int pop_opTop();

#endif

#ifdef STOCK_H

void pushNum(double val) { numStack[++numTop] = val; }
double popNum() { return numStack[numTop--]; }

void pushOp(int op) { opStack[++opTop] = op; }
int popOp() { return opStack[opTop--]; }

#endif