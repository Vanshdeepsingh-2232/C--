#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

char input[MAX_LEN];
int pos = 0;

void E();
void EPrime();
void T();
void TPrime();
void F();
void error();

void match(char expected)
{
    if (input[pos] == expected)
    {
        pos++;
    }
    else
    {
        error();
    }
}

void error()
{
    printf("Syntax Error at position %d\n", pos);
    exit(1);
}

void E()
{
    T();
    EPrime();
}

void EPrime()
{
    if (input[pos] == '+')
    {
        match('+');
        T();
        EPrime();
    }
}

void T()
{
    F();
    TPrime();
}

void TPrime()
{
    if (input[pos] == '*')
    {
        match('*');
        F();
        TPrime();
    }
}

void F()
{
    if (input[pos] == '(')
    {
        match('(');
        E();
        match(')');
    }
    else if (isalpha(input[pos]))
    {
        match(input[pos]);
    }
    else
    {
        error();
    }
}

int main()
{
    printf("Enter the expression: ");
    scanf("%s", input);

    E();

    if (input[pos] == '\0')
    {
        printf("Parsing successful!\n");
    }
    else
    {
        printf("Syntax Error at end\n");
    }

    return 0;
}
