/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:37:15 by dtse              #+#    #+#             */
/*   Updated: 2016/10/12 16:37:16 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // REMOVE LATER!!!

int			get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	size_t	len;
	size_t	i;

	// if (!line || !fd)
	// 	return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * (BUFF_SIZE))))
		return (-1);
	// zero-ing out the line passed via a pointer into the function to store buf
	*line = ft_memset(*line, 0, BUFF_SIZE);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		// len = -1;
		i = 0;
		buf[BUFF_SIZE] = '\0';
		while (buf[i])
		{
			if (buf[i++] == '\n')
			{
				len = i;
			}
		}
		*line = strncpy(*line, buf, BUFF_SIZE);
		return (1);
		// if (len == -1) // use strchr here?
		// printf("LEN = %lu\n", len);
		// printf("*****\nLINE->%s<-END OF LINE\n*****\n", buf);

		// look for \n... 1) if no new line needed to add to variable and continue forward 2) if newline... need to end, save the rest beyond the newline
		// probably need realloc as well
		/* SCENARIOS while reading through BUF
		1) no newline in or EOF in buf
		2) one newline and no EOF in buf
		3) one newline and EOF in buf
		4) multiple newlines and no EOF in buf
		5) multiple newlines and EOF in buf

		strchr = locates the first occurance of char c in string s, returns pointer to that char
		*realloc = changes the size of allocation of a ptr to size, if not enough room will malloc again and copy over as much as possible, free the original and return the new ptr
		strncat = concatenates n characters of s2 to s1
		strncpy = copies len chars from src to dst, returns dst
		strnew = creates a 0 initialized string of size
		strdel = deletes / frees a string via its pointer
		strdup = mallocs for a new string and copies an inputed str
		strjoin = mallocs for and concatenates two strings
		strsub = 

		need to count the bytes read?
		
		EOL determined by behavior of read function (-1 or 0)
		*/
	}
	printf("END OF FUNCTION!!!\n");
	return (0);
}
// MANDATORY
// return value... 1: has been read, 0: reading has been completed, -1: error
// needs to handle redirections, from files, from the standard output
// allowed to use read, malloc, free

// BONUS
// need to accomplish with one static variable
// need to be able to handle multiple file descriptors with interleaved calls of get_next_line

// first check for errors with fd and line
// create a buffer of buff_size + 1 (for the terminator)... for reading in chunks
// malloc for the right size of the current buffer... and zero out?
// read on the stdin to the buffer... read the buffer into the line variable 
// detect on the buffer EOF or \n... add info until \n to line variable... save the rest for the next line as needed
// store information? ...list? static var? static list?
// end with EOF

// what is the best way to test? moulitest + prateek's test
// I don't understand the line part yet

int main() // REMOVE LATER!!!!
{
	size_t	line_count;
	char	*line;
	int		fd;

	line_count = 0;
	line = NULL;
	printf("Opening file... ");
	fd = open("test_basic_dino.txt", O_RDONLY);
	if (fd < 0)
	{
		printf(ANSI_F_RED "Error opening %s.\n" ANSI_RESET, "test_basic_dino.txt");
		return (0);
	}
	printf("Done.\n");
	printf(ANSI_F_YELLOW "Reading Lines...\n" ANSI_RESET);
	while (get_next_line(fd, &line))
	{
		line_count++;
		printf(ANSI_F_CYAN "%zu" ANSI_RESET "\t|%s" ANSI_F_CYAN "$\n" ANSI_RESET, line_count, line);
		free(line);
	}
	if (line_count != 12)
		printf(ANSI_F_RED "ERROR: test_basic(...) failed.\n" ANSI_RESET);
	else
		printf(ANSI_F_GREEN "Done.\n" ANSI_RESET);	
	printf(ANSI_F_YELLOW "[ Lines Expected: 12, Lines Read: %zu ]\n" ANSI_RESET, line_count);
	fd = close(fd);
	if (fd < 0)
	{
		printf(ANSI_F_BRED "Fatal Error: Could not close open file.\n" ANSI_RESET);
		exit(EXIT_FAILURE);
	}
	return (0);
}

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

// int     main(void)
// {
//   char  *line;
//   int   fd;

//   if ((fd = open("file", O_RDONLY)) == -1)
//     return (-1);
//   while (get_next_line(fd, &line) != 0)
//   {
//     printf("%s\n", line);
//     free(line);
//   }
//   if (close(fd) == -1)
//     return (-1);
//   return (0);
// }
