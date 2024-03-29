#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function for Printf
 * @format: Printf format
 * Return: chars printed
 * printf
 */

int _printf(const char *format, ...)
{
    int i, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE - 1)
                print_buffer(buffer, &buff_ind);
            else
                printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            flags = get_flags(format, &i);
            width = get_width(format, &i, list);
            precision = get_precision(format, &i, list);
            size = get_size(format, &i);
            i++;
            printed = handle_print(format, &i, list, buffer,
                                   flags, width, precision, size);
            if (printed == -1)
            {
                va_end(list);
                return (-1);
            }
            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(list);

    return (printed_chars);
}

#include <unistd.h>

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, buffer, *buff_ind);

    *buff_ind = 0;
}
