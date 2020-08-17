/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:39 by amargy            #+#    #+#             */
/*   Updated: 2020/03/10 11:57:25 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_overflow_and_take_numb(char *arg, t_ps *p, int count_number)
{
	f_atoi(&arg[p->start_number], p);
	if (p->overflow >= -2147483648 && p->overflow <= 2147483647)
	{
		p->tmp_stack[count_number] = p->overflow;
		return (1);
	}
	else
		return (0);
}

int		check_arg_terminator(char **argv)
{
	int str;

	str = 1;
	while (argv[str] != NULL)
	{
		if (argv[str][0] == '\0')
			return (0);
		str++;
	}
	return (1);
}

int		check_arg(char **argv, t_ps *p)
{
	int str;

	str = 1;
	while (argv[str] != NULL)
	{
		check_arg_terminator(argv);
		if (!pars_arg(argv[str], p))
			return (0);
		str++;
		p->i = 0;
		p->find_number = 0;
		p->start_number = 0;
	}
	p->i_last--;
	if (!(check_duplicate(p)))
		return (0);
	create_stacks(p);
	return (1);
}

void	f_atoi(const char *str, t_ps *p)
{
	int			i;
	long long	at;
	long long	neg;

	i = 0;
	at = 0;
	neg = 1;
	if (str[i] == '-' && str[i + 1] >= 48 && str[i + 1] <= 57)
	{
		neg = -neg;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		at = at * 10 + str[i] - 48;
		i++;
	}
	p->overflow = at * neg;
}

int		check_duplicate(t_ps *p)
{
	int i1;
	int i2;

	i1 = 0;
	i2 = 0;
	while (i1 <= p->i_last)
	{
		while (i2 <= p->i_last)
		{
			if (i2 != i1 && p->tmp_stack[i1] == p->tmp_stack[i2])
				return (0);
			i2++;
		}
		i1++;
		i2 = 0;
	}
	return (1);
}
