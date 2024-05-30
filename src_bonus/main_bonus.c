/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:02:18 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/30 14:08:28 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	generate_pipe(char *cmd, char **env);
static void	exec_cmd(char *cmd, char **env);
static void	here_doc(char **argv);
static void	here_doc_child(int *fd, char **argv);

int	main(int argc, char **argv, char **env)
{
	int		i;
	int		fd;

	if (argc < 5)
		print_error("./pipex file1 cmd cmd .. file2\n", 0, 2, NULL);
	i = 2;
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		if (argc < 6)
			print_error("./pipex here_doc LIMITER cmd cmd .. file2\n", \
			0, 2, NULL);
		i = 3;
		fd = open_file(argv[argc - 1], 0, NULL);
		here_doc(argv);
	}
	else
		fd = open_file(argv[argc - 1], 1, argv[1]);
	while (i < argc - 2)
		generate_pipe(argv[i++], env);
	if (dup2(fd, STDOUT_FILENO) == -1)
		print_error("error failed to redirect stdout", 1, 2, NULL);
	exec_cmd(argv[argc - 2], env);
	close(fd);
	return (0);
}

static void	generate_pipe(char *cmd, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
		print_error("error in pipe", 1, 2, NULL);
	pid = fork();
	if (pid == -1)
		print_error("error in fork", 1, 2, NULL);
	if (!pid)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			print_error("error failed to redirect stdout", 1, 2, NULL);
		exec_cmd(cmd, env);
	}
	if (pid)
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			print_error("error failed to redirect stdin\n", 1, 2, NULL);
	}
	wait(&status);
}

static void	exec_cmd(char *cmd, char **env)
{
	char	**cmd_l;
	char	*path;

	cmd_l = ft_split(cmd, ' ');
	if (!cmd_l)
		print_error("pipex: command not found: ", 0, 127, cmd);
	path = get_path(cmd_l[0], env);
	if (execve(path, cmd_l, env) == -1)
	{
		free_paths(cmd_l);
		print_error("pipex: command not found: ", 0, 127, cmd);
	}
	free_paths(cmd_l);
}

static void	here_doc(char **argv)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		print_error("error in pipe", 1, 2, NULL);
	pid = fork();
	if (pid == -1)
		print_error("error in fork", 1, 2, NULL);
	if (!pid)
		here_doc_child(fd, argv);
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

static void	here_doc_child(int *fd, char **argv)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
}
