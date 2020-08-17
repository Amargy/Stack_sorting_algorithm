/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:01:56 by amargy            #+#    #+#             */
/*   Updated: 2020/03/10 11:58:13 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_result(t_ps *p)
{
	if (p->top_a != 0)
		return (0);
	while (p->i_last > 0)
	{
		if (p->a[p->i_last] < p->a[p->i_last - 1])
			return (0);
		p->i_last--;
	}
	return (1);
}

void	processing_commands(t_ps *p)
{
	p->tmp_c = p->c;
	while (p->tmp_c != NULL)
	{
		execute_command(p, p->tmp_c->com);
		p->tmp_c = p->tmp_c->next;
	}
}

int		is_valid_write_in_stack(char **argv, t_ps *p)
{
	if (!(check_arg_terminator(argv)))
		return (0);
	if (!(check_arg(argv, p)))
		return (0);
	if (!(com_valid_and_write(p)))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_ps *p;

	if (argc >= 2)
	{
		p = create_main_struct();
		if (is_valid_write_in_stack(argv, p))
		{
			if (p->ifnocom != 0)
				processing_commands(p);
			if (check_result(p))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			free_stacks_and_com(p);
		}
		else
		{
			free_stacks_and_com(p);
			write(1, "Error\n", 6);
		}
	}
	return (0);
}
