#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int StringMatch(char text[], char pattern[])
{
    int i, j, m, n;
    n = strlen(text);
    m = strlen(pattern);
    for (i = 0; i <= n - m; i++) // Align pattern under every characters of text
    {
        j = 0;
        while (j < m && tolower(text[i + j]) == tolower(pattern[j])) // Compare pattern with text at ith position
        {
            j++;
        }
        if (j == m) // If all characters of pattern are matched with the text
        {
            return i + 1;
        }
    }
    return -1;
}
int main()
{
    char text[100], pattern[25];
    int pos;
    printf("Enter the text : \n");
    gets(text);
    printf("Enter the pattern :\n");
    gets(pattern);
    pos = StringMatch(text, pattern);
    if (pos != -1)
        printf("The pattern %s is found at position %d\n", pattern, pos);
    else
        printf("Pattern Not Found!!");
    return 0;
}