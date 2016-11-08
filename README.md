# 42: get_next_line

## TL;DR


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

**Function call in main function**
```c
rtn_bytes = file_detective(&file, fd, &line);
```
## key function calls

## key functions

## Testing Suites

