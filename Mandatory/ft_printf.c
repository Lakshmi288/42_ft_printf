/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:45:02 by lps               #+#    #+#             */
/*   Updated: 2023/08/02 13:56:42 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_check(char s, va_list *args, int *len, int *i)
{
	if (s == 's')
		ft_string(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_printf_check(string[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *str = "Lakshmi";
// 	int rollno = 15;
// 	char grade = 'p';
//     int *rno;
// 	rno = &rollno;

// 	int result = ft_printf("\n name = %s \n rollno in int = %d\n rollno unsigned = %u\n rollno hex uppercase = %X\n rollno hex lowercase = %x \n grade = %c \n rollno ptr = %p  \n printing  %% \n", 
//                             str, rollno, rollno, rollno, rollno, grade, rno);

    
//     printf("\n number of characters printed: %d\n", result);
    
//     return (0);
// }
