# FT_PRINTF - A 42 SCHOOL PROJECT
### In this project I recreated the classic C printf function supporting limited conversions:
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.

It also supports any combination of the following flags and the field minimum width under all conversions:
* '-' which left-justify the output within the specified field width and the field minimum width under all conversions.
* '0' which zero-padds the output. When the '0' flag is used along with the width specifier, it pads the output with leading zeros if the number of characters in the output is less than the specified width.
* '.' which specifies precision for certain specifiers.

As well as managing the following flags:
* '+' which ensures that a signed numeric value is preceded with a plus sign if its positive or a minus sign if its negative.
* '#' which is used with different specifiers to change the output format. For example, with %x or %X it will prefix hexadecimal numbers with "0x" or "0X" respectively.

### To test the program:
Enter the directory and type `make` to activate the Makefile and an archive file named `libftprintf.a ` will be created.
