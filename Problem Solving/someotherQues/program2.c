#include <stdio.h>
#include <ctype.h> // Required for isspace()

int startsWithComment(const char *line)
{
    int i = 0;
    while (line[i] != '\0' && isspace(line[i]))
        i++;

    // Check for single-line or multi-line comment
    if (line[i] == '/' && line[i + 1] == '/')
        return 1;
    if (line[i] == '/' && line[i + 1] == '*')
        return 1;

    return 0;
}

int main()
{
    char line[500];

    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);

    if (startsWithComment(line))
        printf("The line can't be processed (it's a comment).\n");
    else
        printf("The line can be processed.\n");

    return 0;
}
