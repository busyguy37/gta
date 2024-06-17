/*
You have to fill in values to a template letter.txt
letter.txt looks like this:
Thanks {{name}} for purchasing {{item}} from our outlet {{outlet}}.
Please visit our {{outlet}} for any kind of problems. We plan to serve you again soon.
you have to read this file and replace these values:
{{name}} - Vishwas
{{item}} - table fan
{{outlet}} - Ram laxmi fan outlet
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * replaceWord(const char * str, const char * oldWord, const char * newWord)
{
    char * resultString;
    int i, count = 0;
    int newWordLength = strlen(newWord);
    int oldWordLength = strlen(oldWord);

    // lets count the number of times old word occurs in the string
    for (i = 0; str[i] != '\0'; i++)
    {
        if (strstr(&str[i], oldWord) == &str[i])
        {
            count++;

            // jump over this word
            i = i + oldWordLength - 1;
        }
    }

    // Making a new string to fit in the replaced words
    resultString = (char * )malloc((i + count * (newWordLength - oldWordLength) + 1));

    i = 0;
    while (*str)
    {
        // compare the substring with result
        if (strstr(str, oldWord) == str)
        {
            strcpy(&resultString[i], newWord);
            i += newWordLength;
            str += oldWordLength;
        }
        else
        {
            resultString[i] = *str;
            i += 1;
            str += 1;
        }
    }
    resultString[i] = '\0';
    return resultString;
}

int main()
{
    FILE * ptr = NULL;
    FILE * ptr2 = NULL;
    ptr = fopen("bill.txt", "r");
    ptr2 = fopen("genBill.txt", "w");
    char str[200];
    fgets(str, 200, ptr);
    printf("The given bill template was: %s\n", str);

    // Call the replaceWord function and generate newStr
    char * newstr;
    newstr = replaceWord(str, "{{item}}", "Table fan");
    newstr = replaceWord(newstr, "{{outlet}}", "Ram Laxmi fan outlet");
    newstr = replaceWord(newstr, "{{name}}", "Vishwas");
    printf("The actual bill generated is: %s\n", newstr);
    printf("The generated bill has been written to the file genBill.txt\n");


    fprintf(ptr2, "%s", newstr);
    fclose(ptr);
    fclose(ptr2);
    return 0;
}