#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    for (int i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++; // Move to the next character after '%'

            switch (format[i])
            {
                case 'c':
                    // Print character
                    printed_chars += putchar(va_arg(args, int));
                    break;

                case 's':
                    // Print string
                    printed_chars += printf("%s", va_arg(args, char *));
                    break;

                case '%':
                    // Print '%'
                    printed_chars += putchar('%');
                    break;

                default:
                    // Unknown specifier, print as is
                    printed_chars += putchar('%') + putchar(format[i]);
            }
        }
        else
        {
            // Print non-format characters
            printed_chars += putchar(format[i]);
        }
    }

    va_end(args);

    return printed_chars;
}

int main()
{
    _printf("This is a simple _printf function.\n");
    _printf("Character: %c, String: %s, Percent: %%\n", 'A', "Hello");
    return 0;
}

