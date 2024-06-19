/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:38:30 by jsarda            #+#    #+#             */
/*   Updated: 2024/06/14 10:06:08 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	count_args(char **args)
{
	size_t	len;

	len = 0;
	while (args[len])
		len++;
	return (len);
}

int	count_cmds(t_node *nodes)
{
	int		count;
	t_node	*current;

	count = 0;
	current = nodes;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
