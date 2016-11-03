/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:37:22 by dtse              #+#    #+#             */
/*   Updated: 2016/10/12 16:37:24 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 16

// comment out when running tinfoil test suite
# define ANSI_RESET "\033[0m"

# define ANSI_F_RED "\033[31m"
# define ANSI_F_BRED "\033[31;1m"
# define ANSI_F_GREEN "\033[32m"
# define ANSI_F_BGREEN "\033[32;1m"
# define ANSI_F_YELLOW "\033[33m"
# define ANSI_F_BYELLOW "\033[33;1m"
# define ANSI_F_BLUE "\033[34m"
# define ANSI_F_BBLUE "\033[34;1m"
# define ANSI_F_MAGENTA "\033[35m"
# define ANSI_F_BMAGENTA "\033[35;1m"
# define ANSI_F_CYAN "\033[36m"
# define ANSI_F_BCYAN "\033[36;1m"
# define ANSI_F_BLACK "\033[30m"
# define ANSI_F_BBLACK "\033[30;1m"
# define ANSI_F_WHITE "\033[37m"
# define ANSI_F_BWHITE "\033[37;1m"

# define ANSI_B_RED "\033[41m"
# define ANSI_B_BRED "\033[41;1m"
# define ANSI_B_GREEN "\033[42m"
# define ANSI_B_BGREEN "\033[42;1m"
# define ANSI_B_YELLOW "\033[43m"
# define ANSI_B_BYELLOW "\033[43;1m"
# define ANSI_B_BLUE "\033[44m"
# define ANSI_B_BBLUE "\033[44;1m"
# define ANSI_B_MAGENTA "\033[45m"
# define ANSI_B_BMAGENTA "\033[45;1m"
# define ANSI_B_CYAN "\033[46m"
# define ANSI_B_BCYAN "\033[46;1m"
# define ANSI_B_BLACK "\033[40m"
# define ANSI_B_BBLACK "\033[40;1m"
# define ANSI_B_WHITE "\033[47m"
# define ANSI_B_BWHITE "\033[47;1m"

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h" // for moulitest... remember to remove the space at the end of the file path
// # include "libft.h" // for prateek's tests

typedef struct	s_overflow
{
	int					fd;
	char				*buffer;
}				t_overflow;

int get_next_line(const int fd, char **line);

#endif