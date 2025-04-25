#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

// Token types
#define ID     0
#define PLUS   1
#define MUL    2
#define LPAREN 3
#define RPAREN 4
#define DOLLAR 5

// Action types
#define SHIFT  1
#define REDUCE 2
#define ACCEPT 3
#define ERROR  0

// Production rules: left side and their lengths
int lhs[] = {0, 'E', 'E', 'T', 'T', 'F', 'F'};
int rhs_len[] = {0, 3, 1, 3, 1, 3, 1};

// Mapping char to token
int getToken(char ch) {
    if (islower(ch)) return ID;
    if (ch == '+') return PLUS;
    if (ch == '*') return MUL;
    if (ch == '(') return LPAREN;
    if (ch == ')') return RPAREN;
    if (ch == '$') return DOLLAR;
    return -1;
}

// ACTION table: rows = states, cols = terminals
int action[12][6] = {
/*             id   +    *    (    )   $  */
/*0*/      {  S5,  0,   0,  S4,   0,  0 },
/*1*/      {  0,  S6,   0,   0,   0, ACC },
/*2*/      {  0,  R2,  S7,   0,  R2, R2 },
/*3*/      {  0,  R4,  R4,   0,  R4, R4 },
/*4*/      {  S5,  0,   0,  S4,   0,  0 },
/*5*/      {  0,  R6,  R6,   0,  R6, R6 },
/*6*/      {  S5,  0,   0,  S4,   0,  0 },
/*7*/      {  S5,  0,   0,  S4,   0,  0 },
/*8*/      {  0,  S6,   0,   0, S11, 0 },
/*9*/      {  0,  R1,  S7,   0,  R1, R1 },
/*10*/     {  0,  R3,  R3,   0,  R3, R3 },
/*11*/     {  0,  R5,  R5,   0,  R5, R5 }
};

// GOTO table: rows = states, cols = non-terminals (E=0, T=1, F=2)
int goTo[12][3] = {
/*0*/      { 1, 2, 3 },
/*1*/      { 0, 0, 0 },
/*2*/      { 0, 0, 0 },
/*3*/      { 0, 0, 0 },
/*4*/      { 8, 2, 3 },
/*5*/      { 0, 0, 0 },
/*6*/      { 0, 9, 3 },
/*7*/      { 0, 0,10 },
/*8*/      { 0, 0, 0 },
/*9*/      { 0, 0, 0 },
/*10*/     { 0, 0, 0 },
/*11*/     { 0, 0, 0 }
};

#define S(x) (SHIFT << 4 | (x))
#define R(x) (REDUCE << 4 | (x))
#define ACC (ACCEPT << 4)

int parse(const char *input) {
    int stack[STACK_SIZE];
    int top = 0;
    int i = 0;
    stack[top++] = 0;

    char symbol;
    int token, state, action_code, type, value;

    while (1) {
        state = stack[top - 1];
        symbol = input[i];
        token = getToken(symbol);
        if (token == -1) {
            printf("Invalid symbol: %c\n", symbol);
            return 0;
        }

        action_code = action[state][token];
        type = action_code >> 4;
        value = action_code & 0xF;

        if (type == SHIFT) {
            stack[top++] = token + 100;  // store terminal token
            stack[top++] = value;        // store state
            i++;
        } else if (type == REDUCE) {
            int len = rhs_len[value];
            int LHS = lhs[value];

            // Pop 2 * len
            for (int j = 0; j < 2 * len; j++) top--;

            state = stack[top - 1];
            int col;
            if (LHS == 'E') col = 0;
            else if (LHS == 'T') col = 1;
            else if (LHS == 'F') col = 2;

            stack[top++] = LHS;               // push non-terminal
            stack[top++] = goTo[state][col];  // push new state
        } else if (type == ACCEPT) {
            printf("✔ Accepted: Valid expression.\n");
            return 1;
        } else {
            printf("✖ Syntax error at '%c'\n", symbol);
            return 0;
        }
    }
}

int main() {
    char input[100];
    printf("Enter expression (end with $): ");
    scanf("%s", input);

    if (input[strlen(input) - 1] != '$') {
        printf("Error: Input must end with $\n");
        return 1;
    }

    parse(input);
    return 0;
}
