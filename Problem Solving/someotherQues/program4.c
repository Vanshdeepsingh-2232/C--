#include <stdio.h>
int validateRegex(const char *str)
{
    int i = 0;
    while (str[i] == 'a')
        i++;
    if (str[i] != 'b')
        return 0;
    while (str[i] == 'b')
        i++;
    if (str[i] == '\0')
        return 1;
    return 0;
}
int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (validateRegex(str))
        printf("The string '%s' matches the regex 'a*b+'.\n", str);
    else
        printf("The string '%s' does NOT match the regex 'a*b+'.\n", str);
    return 0;
}
