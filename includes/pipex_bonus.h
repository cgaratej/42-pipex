/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:25:05 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/30 10:40:43 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/wait.h> //wait
# include <unistd.h> //fork
# include <stdlib.h> //malloc
# include <stdio.h> //perror
# include <fcntl.h> //Opne
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

void	print_error(char *str, int per, int ex, char *cmd);
int		open_file(char *file, int option, char *file2);
char	*get_path(char *cmd, char **env);
void	free_paths(char **path);

#endif