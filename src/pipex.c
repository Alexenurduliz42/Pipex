/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:20:33 by ahiguera          #+#    #+#             */
/*   Updated: 2024/01/11 15:21:40 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	int		outfile;

	outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		perror("error en el proceso");
	}
	else if (pid == 0)
	{
		printf("caso 1, hijo: %d \n", getpid());
		close(fd[READ_FD]);
		dup2(fd[WRITE_FD], STDOUT_FILENO);
		close(fd[WRITE_FD]);
		printf("fd: %d \n", fd);
		execve("/bin/ls", "ls", "-l", NULL);
	}
	else
	{
		printf("caso 2, padre: %d \n", getpid());
		close(fd[WRITE_FD]);
		dup2(fd[READ_FD], STDOUT_FILENO);
		close(fd[READ_FD]);
		execve("/usr/bin/wc", "wc", "-l", NULL);
	}
}
