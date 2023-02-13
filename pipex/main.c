/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:06:08 by cpollito          #+#    #+#             */
/*   Updated: 2022/02/18 19:19:07 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	fd[2];

	if (argc == 5)
	{
		if (pipe(fd) != (-1))
			ft_start_fork(argv, fd, env);
		else
			ft_perror("error pipe");
	}
	else
		ft_perror("invalid number of arguments\n");
	return (0);
}
