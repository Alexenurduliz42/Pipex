/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:20:33 by ahiguera          #+#    #+#             */
/*   Updated: 2024/01/22 19:56:16 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Child process that run inside a fork, take the infile, put the output inside
 a pipe and then close with the exec function */
void	child_process(char **argv, char **envp, int *fd)
{
	int		infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		error();
	dup2(fd[WRITE_FD], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[READ_FD]);
	execute(argv[2], envp);
}

/* Parent process that take the data from the pipe, change the output for the
 outfie and also close with the exec function */
void	parent_process(char **argv, char **envp, int *fd)
{
	int		outfie;

	outfie = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfie == -1)
		error();
	dup2(fd[READ_FD], STDIN_FILENO);
	dup2(outfie, STDOUT_FILENO);
	close(fd[WRITE_FD]);
	execute(argv[3], envp);
}

/* Main function that run the child and parent process or display an error
 message if arguments are wrong */
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(argv, envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <infile> <cmd1> <cmd2> <outfie>\n", 1);
	}
	return (0);
}
