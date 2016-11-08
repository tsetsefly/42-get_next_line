# 42: get_next_line

## Functional components

### Storage between reads per file descriptor
The first thing done for this project is to check if there has been a prior read with this file descriptor and if so, what if any storage remains for processing in subsequent steps. If a prior read of that file descriptor does not exist, a struct is created and added to the linked-list to be used for this function call. The state is stored in a static linked-list that contains a custom struct that can store the file descriptor (```file->fd```) and the storage (```file->buffer```).
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

## key function calls

## key functions
