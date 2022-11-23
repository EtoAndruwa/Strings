#include <stdio.h>

void puts_my(const char* str); // prints string with \n in the end of string
size_t strlen_null_my(const char* str);
size_t strlen_no_null_my(const char* str);
const char* strchr_my(const char* str, char chr);
char* strcpy_my(char* dest, size_t dest_length, const char* src);
void strncpy_my(char* dest, size_t dest_length, const char* src);
char* strcat_my(char* dest, const char* src, size_t max_length);
char* strncat_my(char* dest, const char* src, size_t count);

int main()
{
    char string[15] = "Hello World";
    char copy[18] = "Hi";

    return 0;
}

void puts_my(const char* str)// prints string with \n in the end of string
{
    size_t lenght = strlen_null_my(str);

    if (lenght != 0)// if success prints string
    {
        for (size_t i = 0; i < lenght; i++)
        {
            putchar(str[i]);
        }
        putchar('\n');
    }
    else // if failure prints EOF
    {                               
        printf("%d", EOF);          
    }                              
}

size_t strlen_null_my(const char* str)// with \0 DONE
{
    size_t i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    i++;
    return i;
}

size_t strlen_no_null_my(const char* str) // without \0 DONE
{
    size_t i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

const char* strchr_my(const char* str, char chr) // DONE
{
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
    return chr_ptr;
    // printf("Char: '%c'\n", *chr_ptr);
    // printf("ASCII code: %d\n", *chr_ptr);
}

char* strcpy_my(char* dest, size_t dest_length, const char* src) // DONE
{
    size_t leght_scr = strlen_null_my(src);
    if (dest_length >= leght_scr)
    {
        // printf("Source string: %s\n", src);
        // printf("String before: %s\n", dest);
        for (size_t i = 0; i <= leght_scr; i++)
        {
            dest[i] = src[i];
        }
        // printf("String after: %s\n", dest);
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
        printf("String: %s\n", src);
        printf("String before: %s\n", dest);
        printf("String after: %s\n", dest);
    }
    else
    {
        printf("String scr cannot be copied to the string dest (not enough space)");
    }
}

char* strcat_my(char* dest, const char* src, size_t max_length)//DONE
{
    size_t position_to_write = strlen_null_my(dest) - 1;

    if(max_length >= (strlen_null_my(src) + strlen_null_my(dest)))
    {   
        for(size_t i = 0; i < strlen_null_my(src); i++)
        {
            dest[position_to_write] = src[i];
            position_to_write++;   
        }
        return dest;
    }
    else
    {
        return dest; 
    }
}

char* strncat_my( char* dest, const char* src, size_t count)//DONE
{
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

