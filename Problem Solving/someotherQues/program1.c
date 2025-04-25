#include <stdio.h>
int splitStringBySpaceIgnoringComments(char *str)
{
    int i = 0, start = 0, count = 0;
    int inSingleLineComment = 0, inMultiLineComment = 0;
    while (str[i] != '\0')
    {
        if (!inMultiLineComment && str[i] == '/' && str[i + 1] == '/')
        {
            inSingleLineComment = 1;
            i += 2;
            continue;
        }
        if (!inSingleLineComment && str[i] == '/' && str[i + 1] == '*')
        {
            inMultiLineComment = 1;
            i += 2;
            continue;
        }
        if (inSingleLineComment && str[i] == '\n')
        {
            inSingleLineComment = 0;
            i++;
            continue;
        }
        if (inMultiLineComment && str[i] == '*' && str[i + 1] == '/')
        {
            inMultiLineComment = 0;
            i += 2;
            continue;
        }
        if (inSingleLineComment || inMultiLineComment)
        {
            i++;
            continue;
        }
        if (str[i] == ' ' || str[i] == '\n')
        {
            if (start < i)
            {
                for (int j = start; j < i; j++)
                    putchar(str[j]);
                putchar('\n');
                count++;
            }
            i++;
            while (str[i] == ' ')
                i++;
            start = i;
        }
        else
            i++;
    }
    if (start < i)
    {
        for (int j = start; j < i; j++)
            putchar(str[j]);
        putchar('\n');
        count++;
    }
    return count;
}

int main()
{
    char str[1000];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    int wordCount = splitStringBySpaceIgnoringComments(str);
    printf("Number of words (excluding comments): %d\n", wordCount);
    return 0;
}
