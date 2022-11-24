#include <stdio.h>

void puts_my(const char* str); // prints the string with the charecter '\n' in the end of the string.

size_t strlen_null_my(const char* str); // returns the length of the string, counts the null terminator as a character of the string. 

size_t strlen_no_null_my(const char* str); // returns the length of the string, doesn't count the null terminator as a character of the string.

const char* strchr_my(const char* str, char chr); // returns the pointer to the found character in the given string
                                                  // or returns the nullptr if the character was not found

char* strcpy_my(char* dest, size_t size_of_dest, const char* src); // (modified by me) returns the pointer to the string dest into which
                                                                  // the string src was copied, checks the string dest for enough space

char* strncpy_my(char* dest, const char* src, size_t count); // returns the pointer to the string dest into which
                                                             // the given number of characters from the string src were copied
                                                                                 

char* strcat_my(char* dest, const char* src, size_t size_of_dest); // (modified by me) returns the pointer to the string dest, checks 
                                                                 // for enough space and appends the copy of the string src 

char* strncat_my(char* dest, const char* src, size_t count); // returns the pointer to the string dest, copies the entered 
                                                             // number of characters from the string scr to the string dest.

int main()
{
    char string[15] = "Hello World";
    char copy[18] = "Hi";
    char text1[10] = "Pri";
    char text2[10] = "vet";
    char text3[10] = "Mir";
    char text4[15] = " Mir! Yra!";
    char text5[12] = "Home";
    char text6[15] = "Works";
    
    printf("Result of puts(copy): ");
    puts_my(copy);
    printf("Length without 0: %ld\n", strlen_no_null_my(copy));
    printf("Length with 0: %ld\n", strlen_null_my(copy));
    printf("Character found: %c\n", *strchr_my(copy, 'H'));
    printf("New string 'copy': %s\n", strcpy_my(copy, sizeof(copy), string));
    printf("Result of strcat(text1, text2): %s\n", strcat_my(text1, text2, sizeof(text1)));
    printf("Result of strncat(text3, text4): %s\n", strncat_my(text3, text4, 5));
    printf("Result of strncopy(text5, text6): %s\n", strncpy_my(text5, text6, 6));


    return 0;
}

void puts_my(const char* str) // prints the string with the charecter '\n' in the end of the string.
{
    size_t length = strlen_null_my(str);

    if (length != 0)
    {
        for (size_t i = 0; i < length; i++)
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

char* strcpy_my(char* dest, size_t size_of_dest, const char* src) // (modified by me) returns the pointer to the string dest into which 
{                                                                // the string src was copied, checks the string dest for enough space
    size_t leght_scr = strlen_null_my(src);
    if (size_of_dest >= leght_scr)
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

char* strncpy_my(char* dest, const char* src, size_t count) // returns the pointer to the string dest into which the
{                                                           // given number of characters from the string src were copied
    if (strlen_null_my(src) < count)                        
    {
        for (size_t i = 0; i < count; i++)
        {   
            if(i < strlen_null_my(src))
            {
                dest[i] = src[i];
            }
            else
            {
                dest[i] = '\0';   
            }
        }
        return dest;
    }
    else if(strlen_null_my(src) >= count)
    {
        for (size_t i = 0; i < count; i++)
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

char* strcat_my(char* dest, const char* src, size_t size_of_dest) // (modified by me) returns the pointer to the string dest, checks
{                                                               // for enough space and appends the copy of the string src
    size_t position_to_write = strlen_null_my(dest) - 1;

    if(size_of_dest >= (strlen_null_my(src) + strlen_null_my(dest))) 
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

