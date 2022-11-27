#include <stdio.h>
#include <stdlib.h>

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

char* fgets_my(char* buffer, size_t count, FILE* stream); // reads the data from the file and writes to the output string

char* strdup_my(const char* str1); // dynamically allocates memory for the string and makes the identical copy of it, returns the pointer 

size_t getline_my(char* lineptr, size_t* n, FILE* stream); // getline() reads an entire line from stream, storing the address
                                                           // of the buffer containing the text into *lineptr.

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
    char buffer[50] = "";
    
    FILE* test_file = fopen("test_file.txt", "a+b");
    fputs("Alan Turing\n", test_file);
    rewind(test_file);
    char* test_string = fgets_my(buffer, sizeof(buffer), test_file);

    printf("\nResult of fgets: %s \n", test_string);
    printf("Result of puts(copy): ");
    puts_my(copy);
    printf("\n");
    printf("Length without 0: %ld\n\n", strlen_no_null_my(copy));
    printf("Length with 0: %ld\n\n", strlen_null_my(copy));
    printf("Character found: %c\n\n", *strchr_my(copy, 'H'));
    printf("New string 'copy': %s\n\n", strcpy_my(copy, sizeof(copy), string));
    printf("Result of strcat(text1, text2): %s\n\n", strcat_my(text1, text2, sizeof(text1)));
    printf("Result of strncat(text3, text4): %s\n\n", strncat_my(text3, text4, 5));
    printf("Result of strncopy(text5, text6): %s\n\n", strncpy_my(text5, text6, 6));

    char* str_dup_string = strdup_my(text2);
    printf("Result of strdup_my(text2): %s\n", str_dup_string);
    printf("Address of text2: %p\n", text2);
    printf("Address of strdup_my(text2): %p\n\n", str_dup_string);
    free(str_dup_string);

    rewind(test_file);

    size_t n = 10;
    char * test10 = (char*)calloc(n, sizeof(char));    
    printf("Number of chars read by getline_my: %ld\n", getline_my(test10, &n, test_file));

    free(test10);
    fclose(test_file);
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

char* fgets_my(char* buffer, size_t count, FILE* stream) // reads the data from the file and writes to the output string
{   
    char* str = nullptr;
    if(stream != nullptr)
    {
        for(size_t i = 0; i < count; i++)
        {
            buffer[i] = (char)fgetc(stream);
        }
        buffer[count] = '\0';
        str = buffer;
        return str;
    }
    else
    {
        return str;
    }
}

char* strdup_my(const char* str1) // dynamically allocates memory for the string and makes the identical copy of it, returns the pointer 
{
    size_t length_of_str1 = strlen_null_my(str1);
    char* str2 = (char*)calloc(length_of_str1, sizeof(char));
    
    for(size_t i = 0; i < length_of_str1; i++)
    {
        str2[i] = str1[i];
    }

    return str2;
}

size_t getline_my(char* lineptr, size_t* n, FILE* stream) // getline() reads an entire line from stream, storing the address
{                                                          // of the buffer containing the text into *lineptr.   
    if(lineptr == nullptr)
    {   
        rewind(stream);
        size_t number_of_char_read = 0;
        size_t control = 0;
        while(control == 0) 
        {   
            int char_read = fgetc(stream); 
            if((char)char_read == '\n')
            {
                number_of_char_read++;
                control = 1;
                break;
            }
            else if(char_read == EOF)
            {
                control = 1;
                break;
            }
            else
            {
                number_of_char_read++;
            }
        }
        rewind(stream);
        char* lineptr_new = (char*)calloc(number_of_char_read + 1, sizeof(char));

        for(size_t i = 0; i < number_of_char_read; i++)
        {
            lineptr_new[i] = (char)getc(stream);
        }
        rewind(stream);
        lineptr_new[number_of_char_read] = '\0';

        // printf("Sizeof buffer: %ld\n", sizeof(lineptr_new));
        // printf("String: %s\n", lineptr_new);
        // printf("Length of string: %ld\n", strlen_null_my(lineptr_new));

        lineptr = lineptr_new;
        return number_of_char_read;
    }
    else if(lineptr != nullptr)
    {   

        rewind(stream);
        size_t number_of_char_read = 0;
        size_t size_buffer = *n;

        size_t control = 0;
        while(control == 0) 
        {   
            int char_read = fgetc(stream);        
            if((char)char_read == '\n')
            {
                number_of_char_read++;
                control = 1;
                break;
            }
            else if(char_read == EOF)
            {
                control = 1;
                break;
            }
            else
            {
                number_of_char_read++;
            }
        }
        rewind(stream);

        if(size_buffer >=number_of_char_read + 1)
        {   
            // printf("BUFFER OK\n");
            for(size_t i = 0; i < number_of_char_read; i++)
            {
                lineptr[i] = (char)getc(stream);
            }
            rewind(stream);
            lineptr[number_of_char_read] = '\0';

            // printf("String: %s\n", lineptr);
            // printf("Length of string: %ld\n", strlen_null_my(lineptr));

            return  number_of_char_read;
        }
        else
        {   
            // printf("REALOC\n");
            lineptr = (char*)realloc(lineptr, (size_buffer + number_of_char_read + 1) * sizeof(char));

            for(size_t i = 0; i < number_of_char_read; i++)
            {
                lineptr[i] = (char)getc(stream);
            }
            rewind(stream);
            lineptr[number_of_char_read] = '\0';

            // printf("String: %s\n", lineptr);
            // printf("Length of string: %ld\n", strlen_null_my(lineptr));

            return  number_of_char_read;
        }
    }
    else
    {
        return -1;
    }
}