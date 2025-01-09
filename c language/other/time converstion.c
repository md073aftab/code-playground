#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* timeConversion(char* s) 
{
  if (s[8]=='P')
  {
    s[8]='\0';
    int first_digit = s[0] - '0';
    int second_digit = s[1] - '0';
    
    if (first_digit==1 && second_digit==2)
    {
      return s;
    }
    else
    {
      int hours = first_digit*10 + second_digit;
      int converted_hour = 12 + hours;
    
      s[1] = converted_hour%10 ;
      s[0] = converted_hour/10 ;
      
      return s;
    }  
  }
  else
  {
     s[8]='\0';
    int first_digit = s[0] - '0';
    int second_digit = s[1] - '0';
    
    if (first_digit==1 && second_digit==2)
    {
      s[1]= '0';
      s[0]= '0';
     return s;
    }
    else
    {
      // int hours = first_digit*10 + second_digit;
      // int converted_hour = 12+ hours;
    
      // s[1] = converted_hour%10 ;
      // s[0] = converted_hour/10 ;
      
      return s;
    }  
  
  }
  

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
 
