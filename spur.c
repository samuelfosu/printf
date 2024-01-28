#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // to keep track of the number of characters printed

    while (*format) {
        if (*format == '%') {
            format++; // move past '%'
            switch (*format) {
                case 'c':
                    {
                        char c = va_arg(args, int);
                        putchar(c);
                        count++;
                        break;
                    }
                case 's':
                    {
                        const char *str = va_arg(args, const char*);
                        while (*str) {
                            putchar(*str);
                            str++;
                            count++;
                        }
                        break;
                    }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    // Ignore unsupported conversion specifiers
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Hello, %cWorld! %s\n", 'C', "This is a test");
    return 0;
}

