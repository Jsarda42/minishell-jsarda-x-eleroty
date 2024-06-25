/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:00:11 by jsarda            #+#    #+#             */
/*   Updated: 2024/06/25 09:30:08 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(t_minishell *data, t_node *node, char **args)
{
	(void)args;
	(void)node;
	if (!data->env)
		return ;// parsing need to add the shlvl // and mange the error
	print_env(data->env);
}
