#include <stdio.h>

void puts_my(const char* str); // prints the string with the charecter '\n' in the end of the string.

size_t strlen_null_my(const char* str); // returns the length of the string, counts the null terminator as a character of the string. 

size_t strlen_no_null_my(const char* str); // returns the length of the string, doesn't count the null terminator as a character of the string.

const char* strchr_my(const char* str, char chr); // returns the pointer to the found character in the given string
                                                  // or returns the nullptr if the character was not found

char* strcpy_my(char* dest, size_t dest_length, const char* src);

void strncpy_my(char* dest, size_t dest_length, const char* src);

char* strcat_my(char* dest, const char* src, size_t max_length); // (modified by me) returns the pointer to the string dest, checks 
                                                                 // for enough space and appends the copy of the string src 

char* strncat_my(char* dest, const char* src, size_t count); // returns the pointer to the string dest, copies the entered 
                                                             // number of characters from the string scr to the string dest.

int main()
{
    char string[15] = "Hello World";
    char copy[18] = "Hi";

    return 0;
}

void puts_my(const char* str) // prints the string with the charecter '\n' in the end of the string.
{
    size_t lenght = strlen_null_my(str);

    if (lenght != 0)
    {
        for (size_t i = 0; i < lenght; i++)
        {
            putchar(str[i]);
        }
        putchar('\n');
    }
    else 
    {                               
        printf("%d", EOF);          
    }                              
}

size_t strlen_null_my(const char* str) // returns the length of the string, counts the null terminator as a character of the string.
{
    size_t i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    i++;
    return i;
}

size_t strlen_no_null_my(const char* str) // returns the length of the string, doesn't count the null terminator as a character of the string.
{
    size_t i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

const char* strchr_my(const char* str, char chr) // returns the pointer to the found character in the given string 
{                                                // or returns the nullptr if the character was not found
    size_t i = 0;
    const char* chr_ptr = nullptr;

    while (str[i] != '\0')
    {
        if (str[i] == chr)
        {
            chr_ptr = &str[i];
            return chr_ptr;
        }
        i++;
    }

    if (str[i] == '\0')
    {
        chr_ptr = &str[i];
        return chr_ptr;
    }
    else
    {
        return chr_ptr;
    }
}

char* strcpy_my(char* dest, size_t dest_length, const char* src) // DONE
{
    size_t leght_scr = strlen_null_my(src);
    if (dest_length >= leght_scr)
    {
        for (size_t i = 0; i <= leght_scr; i++)
        {
            dest[i] = src[i];
        }
        return dest;
    }
    else
    {
        return dest;
    }
}

void strncpy_my(char* dest, size_t dest_length, const char* src)
{
    if (dest_length >= strlen_null_my(src))
    {
        for (size_t i = 0; i < strlen_null_my(src); i++)
        {
            dest[i] = src[i];
        }
    }
    else
    {
        
    }
}

char* strcat_my(char* dest, const char* src, size_t max_length) // returns the pointer to the string dest, appends the copy of 
{                                                               // for enough space and appends the copy of the string src
    size_t position_to_write = strlen_null_my(dest) - 1;

    if(max_length >= (strlen_null_my(src) + strlen_null_my(dest))) // (modified by me) returns the pointer to the string dest, checks 
    {   
        for(size_t i = 0; i < strlen_null_my(src); i++)
        {
            dest[position_to_write] = src[i];
            position_to_write++;   
        }
        dest[position_to_write++] = '\0';
        return dest;
    }
    else
    {
        return dest; 
    }
}

char* strncat_my( char* dest, const char* src, size_t count) // returns the pointer to the string dest, copies the entered 
{                                                            // number of characters from the string scr to the string dest.
    size_t position_to_write = strlen_null_my(dest) - 1;
    for(size_t i = 0; i < count; i++)
    {
        dest[position_to_write] = src[i];
        position_to_write++;
    }
    position_to_write++;
    dest[position_to_write] = '\0';

    return dest;
}

