#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <regex.h>
#include <project.h>
#include <unistd.h>
#include <string.h>
#include <fw.h>
#include <mt.h>
#include <test.h>
#include <signal.h>
#include <locale.h>
#include "project.h"

PROTOTYPES


int main()
{
	t_mt	*mt = mt_create("ft_ls");
	// mt->desc = "ft_ls description";

	setbuf(stdout, NULL);

	ADD_TESTS

	mt_exec(mt);
	return(0);
}
