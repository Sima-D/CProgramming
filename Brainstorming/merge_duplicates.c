#include <stdio.h>   /* printf */
#include <assert.h>  /* assert */
#include <string.h>  /* strcmp */

#define YELLOW "\x1b[1;33m"
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define FAILURE printf(RED"FAILED\n"RESET)
#define SUCCESS printf(GREEN"SUCCESS\n"RESET)
/******************************************************************************/
static void TestMergeDupChars(void);
static void CompareString(const char *to_check, const char *expected);
/******************************************************************************/
/* Complexity O(n) */
char* MergeDupChars(char *str)
{
    char *reader = (str + 1);
    char *writer = (str + 1);
    
    assert(str);

    while ('\0' != *reader)
    {
        while ((*reader != *(writer - 1)) && '\0' != *reader)
        {
            *writer = *reader;
            ++reader;
            ++writer;
        }
          
        while ((*reader == *(writer - 1)) && '\0' != *reader)                                                
        {
            ++reader;
        }   
    }
         
    *writer = '\0';
    
    return (str);
 }   
/******************************************************************************/
int main(void)
{
     TestMergeDupChars();
     
     return 0;
}
/******************************************************************************/
static void TestMergeDupChars(void)
{
    char str1[] = "accessing";
    char str2[] = "YYYg888cccA";
    char str3[] = "abbbabaab";
    char str4[] = "YYYYYYYYYYYY";
    char str5[] = "         ";
    char str6[] = "No Duplicates";
    char str7[] = "abbbbbbabaaaaaabcccaa";
    char str8[] = "";
    
    char expected_str1[] = "acesing"; 
    char expected_str2[] = "Yg8cA";
    char expected_str3[] = "ababab";
    char expected_str4[] = "Y";
    char expected_str5[] = " ";
    char expected_str6[] = "No Duplicates";
    char expected_str7[] = "abababca";
    char expected_str8[] = "";

    char *actual_string1 = MergeDupChars(str1);
    char *actual_string2 = MergeDupChars(str2);
    char *actual_string3 = MergeDupChars(str3);
    char *actual_string4 = MergeDupChars(str4);
    char *actual_string5 = MergeDupChars(str5);
    char *actual_string6 = MergeDupChars(str6);
    char *actual_string7 = MergeDupChars(str7);
    char *actual_string8 = MergeDupChars(str8);
    
    CompareString(actual_string1, expected_str1);
    CompareString(actual_string2, expected_str2);
    CompareString(actual_string3, expected_str3);
    CompareString(actual_string4, expected_str4);
    CompareString(actual_string5, expected_str5);
    CompareString(actual_string6, expected_str6);
    CompareString(actual_string7, expected_str7);
    CompareString(actual_string8, expected_str8);
    
}
/******************************************************************************/        

static void CompareString(const char *to_check, const char *expected)
{
    if (0 == strcmp(to_check, expected))
    {
        SUCCESS;
    }
    else
    {
        FAILURE;
        printf("expected: %s, actual: %s\n", expected, to_check);
    }
}
