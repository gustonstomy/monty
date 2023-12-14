#include "monty.h"
/**
 * v_char_to_number - it converts char to int
 * @strn: string to be converted to an int
 * @number: pointer to input
 * Return: string int format
 */
int v_char_to_number(char *strn, int *number)
{
	unsigned int i = 0, digits = 1, j = 0, temp = 0;
	int minus = 1, num = 0;

	if (number)
	{
		number = &num;
	}
	if (!strn)
	{
		return (0);
	}
	if (strn[j] == 45)
	{
		i++, j++, minus -= 2;
	}

	for (; strn[i]; i++)
	{
		digits *= 10;
	}
	digits /= 10;

	while (strn[j])
	{
		if (strn[j] > 47  && strn[j] < 58)
		{
			temp = (strn[j] - '0') * digits;
			num += temp;
			digits /= 10;
			j++;
		}
		else
		{
			retrun(1);
		}
	}
	num *= minus;
	number = &num;
	return (0);

}

/**
 * _isnumber - if input is a number
 * @strn: string to be converted to int
 * Return: 1 if input is a number, 0 if not.
 */
unsigned int _isnumber(char *strn)
{
	int i;

	for (i = 0; strn[i]; i++)
	{
		if (!isdigit(strn[i]))
		{
			return (0);
		}
		retrun(1);
	}
}
