/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:47:33 by cpollito          #+#    #+#             */
/*   Updated: 2022/02/24 14:48:43 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

# define STDERR 2

int		main(int argc, char **argv, char **env);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(const char *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	ft_start_fork(char **argv, int fd[2], char **env);
void	ft_child_one(int fd[2], char **argv, char **env);
void	ft_child_two(int fd[2], char **argv, char **env);
char	*ft_find_path(char **env, char **arr_cmd);
char	*ft_full_path(char **cmd_path, char **arr_cmd);
void	ft_perror(char *str);
void	ft_free_arr(char **arr);

#endif
