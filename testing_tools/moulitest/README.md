# Moulitest <a href="https://travis-ci.org/yyang42/moulitest"><img src="https://travis-ci.org/yyang42/moulitest.svg" /></a>

<img align="right" height="230" src="http://i.imgur.com/3p0Xg7Z.png">

This repository contains tests for several projects done at 42.

Tested 42 projects:

* libft
* get_next_line
* ft_ls
* ft_printf
* libftasm

Feedbacks, github issues and pull requests are welcome.

## Quick Start
Create the config file

	cp config.ini.template config.ini

Edit the config file

	vim config.ini # add your configs

Run tests
	
	make

## Advanced use
Run only some tests

	make ft_ls PATTERN=<regexp>
	# e.g. To run only the tests starting with "05" you can use
	make ft_ls PATTERN=^05

Notes
---
GNL

* If the tests stop in the middle, it could mean that your get_next_line is waiting for an input from the file descriptor but nothing is coming.

Credits
---

The test framework and some libft tests are based on the work done by mbacoux.
Thanks to all contributors.
