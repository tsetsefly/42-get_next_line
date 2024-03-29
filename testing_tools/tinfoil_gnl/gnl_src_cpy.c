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

#include GNL_HEADER_CPY
#include <stdio.h> // REMOVE LATER!!!

static t_overflow	*content_detective(const int fd, t_list **file_list_ptr)
{
	t_list			*file_list;
	t_overflow		file_info;

	file_list = *file_list_ptr;
	while (file_list)
	{
		if (((t_overflow *)(file_list->content))->fd == fd)
			return (file_list->content);
		file_list = file_list->next;
	}
	file_info.fd = fd;
	if (!(file_info.buffer = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	if (!(file_list = ft_lstnew(&file_info, sizeof(t_overflow))))
		return (NULL);
	ft_lstadd(file_list_ptr, file_list);
	return ((*file_list_ptr)->content);
}

static void			memory_detective(t_list **begin_list, int fd)
{
	t_list			*t;
 
	if (*begin_list)
	{
		if (((t_overflow *)((*begin_list)->content))->fd == fd)
		{
			t = (*begin_list);
			(*begin_list) = (*begin_list)->next;
			free(((t_overflow *)(t->content))->buffer);
			free(t);
			memory_detective(begin_list, fd);
		}
		else
			memory_detective(&((*begin_list)->next), fd);
	}
}

static ssize_t		norm_sucks(t_overflow **file, char *buf, char ***line)
{
	*(*line) = ft_strjoin((*file)->buffer, buf);
	ft_bzero((*file)->buffer, ft_strlen((*file)->buffer));
	return (1);
}

static ssize_t		file_detective(t_overflow **file, const int fd, char ***line)
{
	char			*end;
	char			buf[BUFF_SIZE + 1];
	ssize_t			rtn_bytes;

	while ((rtn_bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rtn_bytes] = '\0';
		if (!(end = ft_strchr(buf, '\n')))
		{
			if (rtn_bytes < BUFF_SIZE && rtn_bytes > 0)
				return (norm_sucks(&(*file), buf, &(*line)));
			(*file)->buffer = (char *)ft_realloc((*file)->buffer,
				ft_strlen((*file)->buffer) + BUFF_SIZE + 1);
			(*file)->buffer = ft_strcat((*file)->buffer, buf);
		}
		else
		{
			*end = '\0';
			*(*line) = ft_strjoin((*file)->buffer, buf);
			(*file)->buffer = ft_strcpy((*file)->buffer, (end + 1));
			return (1);
		}
	}
	return (rtn_bytes);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*file_list;
	t_overflow		*file;
	ssize_t			rtn_bytes;
	char			*end;

	if (!line)
		return (-1);
	file = content_detective(fd, &file_list);
	if ((end = ft_strchr(file->buffer, '\n')))
	{
		*end = '\0';
		*line = ft_strdup(file->buffer);
		file->buffer = ft_strcpy(file->buffer, (end + 1));
		return (1);
	}
	rtn_bytes = file_detective(&file, fd, &line);
	if (ft_strlen(file->buffer) && rtn_bytes == 0)
	{
		*line = ft_strdup(file->buffer);
		ft_bzero(file->buffer, ft_strlen(file->buffer));
		return (1);
	}
	(rtn_bytes == 0) ? (memory_detective(&file_list, fd)) : (rtn_bytes);
	return (rtn_bytes);
}

// if (ft_strlen(buf) != (size_t)rtn_bytes) 
// 	return (-1);

/*
	*realloc = changes the size of allocation of a ptr to size, if not enough room will malloc again and 
		copy over as much as possible, free the original and return the new ptr (malloc and free)
	strncat = concatenates n characters of s2 to s1
	strncpy = copies len chars from src to dst, returns dst
	strnew = creates a 0 initialized string of size (malloc)
	strdel = deletes / frees a string via its pointer (free)
	strdup = mallocs for a new string and copies an inputed str (malloc)
	strjoin = mallocs for and concatenates two strings (malloc)
	strchr = locates the first occurance of char c in string s, returns pointer to that char
	strsub = returns fresh substr beginning at at indexstart and is of size len (malloc)
*/

// int main() // REMOVE LATER!!!!
// {
// 	size_t	line_count;
// 	char	*line;
// 	int		fd;

// 	line_count = 0;
// 	line = NULL;
// 	printf("Opening file... ");
// 	// fd = open("3_hello_world.txt", O_RDONLY);
// 	fd = open("12_test_basic_dino.txt", O_RDONLY);
// 	// fd = open("1_aaa_no_newline.txt", O_RDONLY);
// 	// fd = open("16_abcdefghijklmnop_newline.txt", O_RDONLY);
// 	// fd = open("one_big_fat_line.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf(ANSI_F_RED "Error opening %s.\n" ANSI_RESET, "test_basic_dino.txt");
// 		return (0);
// 	}
// 	printf("Done.\n");
// 	printf(ANSI_F_YELLOW "Reading Lines...\n" ANSI_RESET);
// 	printf("BUFF_SIZE = %d!\n", (int)BUFF_SIZE);
// 	while (get_next_line(fd, &line))
// 	{
// 		line_count++;
// 		printf(ANSI_F_CYAN "%zu" ANSI_RESET "\t|%s" ANSI_F_CYAN "$\n" ANSI_RESET, line_count, line);
// 		// printf("strcmp(line, \"abcdefghijklmnop\")->%d\n", strcmp(line, "abcdefghijklmnop"));
// 		free(line);
// 	}
// 	if (line_count != 12)
// 		printf(ANSI_F_RED "ERROR: test_basic(...) failed.\n" ANSI_RESET);
// 	else
// 		printf(ANSI_F_GREEN "Done.\n" ANSI_RESET);	
// 	printf(ANSI_F_YELLOW "[ Lines Expected: 12, Lines Read: %zu ]\n" ANSI_RESET, line_count);
// 	fd = close(fd);
// 	if (fd < 0)
// 	{
// 		printf(ANSI_F_BRED "Fatal Error: Could not close open file.\n" ANSI_RESET);
// 		exit(EXIT_FAILURE);
// 	}
// 	return (0);
// }

#include GNL_HEADER_CPY
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
