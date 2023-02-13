/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:47:30 by cpollito          #+#    #+#             */
/*   Updated: 2022/02/24 14:46:22 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_full_path(char **cmd_path, char **arr_cmd)
{
	char	*full_cmd_path;
	int		true_path;
	int		i;
	char	*tmp;

	i = 0;
	true_path = -1;
	while (cmd_path[i] && (true_path == -1))
	{
		full_cmd_path = (ft_strjoin(cmd_path[i], "/"));
		tmp = full_cmd_path;
		full_cmd_path = ft_strjoin(full_cmd_path, arr_cmd[0]);
		free(tmp);
		tmp = full_cmd_path;
		true_path = access(full_cmd_path, F_OK);
		free(tmp);
		i++;
	}
	if (true_path == -1)
	{
		ft_free_arr(cmd_path);
		ft_free_arr(arr_cmd);
		ft_perror("pipex: command not found:");
	}
	return (full_cmd_path);
}

char	*ft_find_path(char **env, char **arr_cmd)
{
	int		i;
	char	*path;
	char	**cmds_path;
	char	*full_cmd_path;

	i = 0;
	while (env[i] && (ft_strncmp(env[i], "PATH", 4)))
		i++;
	if (!env[i])
	{
		ft_free_arr(arr_cmd);
		ft_perror("ERROR: PATH does not exist");
	}
	path = env[i] + 5;
	cmds_path = ft_split(path, ':');
	full_cmd_path = ft_full_path(cmds_path, arr_cmd);
	return (full_cmd_path);
}

void	ft_child_one(int fd[2], char **argv, char **env)
{
	char	**arr_cmd1;
	char	*full_path_cmd;
	int		fd_infile;

	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		ft_perror("open error argv1");
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	arr_cmd1 = ft_split(argv[2], ' ');
	full_path_cmd = ft_find_path(env, arr_cmd1);
	if (execve(full_path_cmd, arr_cmd1, env) == -1)
		ft_perror("execve error");
}

void	ft_child_two(int fd[2], char **argv, char **env)
{
	char	**arr_cmd2;
	char	*full_path_cmd;
	int		fd_outfile;

	fd_outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_outfile == -1)
		ft_perror("open error argv4");
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	arr_cmd2 = ft_split(argv[3], ' ');
	full_path_cmd = ft_find_path(env, arr_cmd2);
	if (execve(full_path_cmd, arr_cmd2, env) == -1)
		ft_perror("execve error");
}

void	ft_start_fork(char **argv, int fd[2], char **env)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
		ft_perror("Fork 1 failed");
	if (pid1 == 0)
		ft_child_one(fd, argv, env);
	pid2 = fork();
	if (pid2 == -1)
		ft_perror("Fork 2 failed");
	if (pid2 == 0)
		ft_child_two(fd, argv, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
