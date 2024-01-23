/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:20:33 by ahiguera          #+#    #+#             */
/*   Updated: 2024/01/23 19:32:03 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * @param argc: The number of command-line arguments passed to the program.
 * @param argv: An array of strings containing the command-line arguments.
 * @param envp: An array of strings representing the environment variables.

 used to set up and execute a child process in a pipe, where the
output of one command is redirected to the input of another command. */
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

/* The parent_process function is used to set up and execute a parent process
in a pipe scenario, where the output of the child process (from the pipe's
read end) is redirected to a specified output file.
*/
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
