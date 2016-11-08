# 42: get_next_line

## TL;DR

"The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor."

[PDF for assignment](https://github.com/tsetsefly/42-get_next_line/blob/master/get_next_line.en.pdf)

1. 

## Functional components

### Storage between reads per file descriptor
The first thing done for this project is to check if there has been a prior read with this file descriptor and if so, what if any storage remains for processing in subsequent steps. If a prior read of that file descriptor does not exist, a struct is created and added to the linked-list to be used for this function call. The state is stored in a static linked-list that contains a custom struct (```t_overflow```) that can store the file descriptor (```file->fd```) and the storage (```file->buffer```). The return value from ```file_detective``` is ```file``` which is of type ```t_overflow```.

**Function call in main function**
```c
file = content_detective(fd, &file_list);
```
**Struct inside of static linked-list**
```c
typedef struct	s_overflow
{
	int					fd;
	char				*buffer;
}				t_overflow;
```
**Searching, creating, returning storage for file descriptor**
```c
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
```

### Storage processing (```file->buffer```)
After checking for prior file descriptor reads and storage, this code processes the storage for any new lines. If any are found, the text up to the newline is transferred to the provided line and the rest is stored back in storage. This will repeate until there are no more newlines left or the EOF is reached.

```c
if ((end = ft_strchr(file->buffer, '\n')))
{
	*end = '\0';
	*line = ft_strdup(file->buffer);
	file->buffer = ft_strcpy(file->buffer, (end + 1));
	return (1);
}
```

### Reading from the file
This function call will start a loop of reads with the file descriptor of ```BUFF_SIZE``` as described in the ```.h``` file. It will do one of two things:
1. **If there is no newline** it will store what is read in storage and loop again. There is an additional bit of code in here to deal with the situation where the bytes returned are less than the buffer size (meaning its the EOF) and if there are no newlines it will copy the remaining text read into the line, clear the storage and return 1 (see more below on this).
2. **If there is a newline**, ```ft_strchr``` will find the first newline character and replace it with a ```\0``` and copy this text to the line and copy the text afterwards to storage and return 1.

**Function call in main function**
```c
rtn_bytes = file_detective(&file, fd, &line);
```
**Loop with read**
```c
while ((rtn_bytes = read(fd, buf, BUFF_SIZE)) > 0)
```
**If no newline**
```c
if (!(end = ft_strchr(buf, '\n')))
{
	if (rtn_bytes < BUFF_SIZE && rtn_bytes > 0)
		return (norm_sucks(&(*file), buf, &(*line)));
	(*file)->buffer = (char *)ft_realloc((*file)->buffer,
		ft_strlen((*file)->buffer) + BUFF_SIZE + 1);
	(*file)->buffer = ft_strcat((*file)->buffer, buf);
}
```
**If newline in read**
```c
else
{
	*end = '\0';
	*(*line) = ft_strjoin((*file)->buffer, buf);
	(*file)->buffer = ft_strcpy((*file)->buffer, (end + 1));
	return (1);
}
```

### Dealing with EOF
The next part of the function deals with how to handle when an EOF is reached. EOF will be indicated by either 1) returning less bytes than the ```BUFF_SIZE``` or 2) ```read``` returns ```0```. There are two pieces of code that handle these situations. One piece of code is for if the EOF is found during the while loop is reading the file and there are no more newlines. The other is for outside of this while loop. In both cases the remaining storage and/or ```buf```-read is copied to the line and the storage is zero'd out. This will allow for a subsequent read of ```0``` to trigger memory cleanup.

**If EOF is reached and there are no newlines read**
```c
static ssize_t		norm_sucks(t_overflow **file, char *buf, char ***line)
{
	*(*line) = ft_strjoin((*file)->buffer, buf);
	ft_bzero((*file)->buffer, ft_strlen((*file)->buffer));
	return (1);
}
```
**If EOF is reached and there is still storage remaining for that file descriptor**
```c
if (ft_strlen(file->buffer) && rtn_bytes == 0)
{
	*line = ft_strdup(file->buffer);
	ft_bzero(file->buffer, ft_strlen(file->buffer));
	return (1);
}
```

### Memory cleanup
This function will be called during the final read (when ```read``` produces a ```0``` and there is nothing left in storage for that file descriptor). It frees the ```t_overflow``` buffer storage and the linked-node that it is stored within. This deals with all malloc'd memory on the heap outside of line (which should be free'd by the program that passes in line).

**Function call in main function**
```c
(rtn_bytes == 0) ? (memory_detective(&file_list, fd)) : (rtn_bytes);
```
**Frees and removes struct and linked-node on final read after EOF**
```c
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
```

## New libft function: Realloc
Changes the size of allocation of a ```ptr``` to ```size```, if there is not enough room the function will malloc again and copy over as much as possible, free the original, and return the new ptr.

```c
char		*ft_realloc(char *old_str, size_t len)
{
	char	*new_str;

	new_str = (char*)malloc(sizeof(char) * len);
	ft_bzero(new_str, len);
	ft_memcpy(new_str, old_str, ft_strlen(old_str) + 1);
	free(old_str);
	return (new_str);
}
```

## Testing Suites

