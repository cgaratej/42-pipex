/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:02:18 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/15 16:25:28 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ps lf || ps lp id
//kill -9
#include "../includes/pipex.h"

static void	son(char **argv, int *fd, char **env);
static void	father(char **argv, int *fd, char **env);
static void	exec_cmd(char *cmd, char **env);

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (argc != 5)
		print_error("./pipex file1 cmd cmd file2\n", 0, 2);
	if (pipe(fd) == -1)
		print_error("error in pipe", 1, 2);
	pid = fork();
	if (pid == -1)
		print_error("error in fork", 1, 2);
	if (!pid)
		son(argv, fd, env);
	wait(&status);
	if (pid)
		father(argv, fd, env);
	return (0);
}

static void	son(char **argv, int *fd, char **env)
{
	int	fd_c;

	close(fd[0]);
	fd_c = open_file(argv[1], 1);
	if (dup2(fd_c, STDOUT_FILENO) == -1)
		print_error("error failed to redirect stdout\n", 1, 2);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		print_error("error failed to redirect stdin", 1, 2);
	exec_cmd(argv[2], env);
	close(fd_c);
}

static void	father(char **argv, int *fd, char **env)
{
	int	fd_p;

	close(fd[1]);
	fd_p = open_file(argv[4], 0);
	if (dup2(fd_p, STDOUT_FILENO) == -1)
		print_error("error failed to redirect stdout\n", 1, 2);
	if (dup2(fd[0], STDOUT_FILENO) == -1)
		print_error("error failed to redirect stdin", 1, 2);
	exec_cmd(argv[3], env);
	close(fd_p);
}

static void	exec_cmd(char *cmd, char **env)
{
	char	**cmd_l;
	char	*path;

	(void)env;
	cmd_l = ft_split(cmd, ' ');
	if (!cmd_l)
		print_error("command not found\n", 0, 127);
	path = get_path(cmd_l[0], env);
}
