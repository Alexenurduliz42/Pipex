/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:24:58 by ahiguera          #+#    #+#             */
/*   Updated: 2024/02/14 16:16:21 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* looks in the environment variables (PATH variable) to find the
full path to the given command */
char	*pp_find_path(char *cmd, char **envp)
{
	char	**route;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	route = ft_split(envp[i] + 5, ':');
	i = 0;
	while (route[i])
	{
		part_path = ft_strjoin(route[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (route[++i])
		free(route[i]);
	free(route);
	return (0);
}

/* Function that take the command and send it to find_path before
executing it. */
void	pp_execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = pp_find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		pp_error();
	}
	if (execve(path, cmd, envp) == -1)
		pp_error();
}

/* error control function. */
void	pp_error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}
