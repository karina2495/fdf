/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:42:55 by vfearles          #+#    #+#             */
/*   Updated: 2019/10/18 12:43:26 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#define BUFF_SIZE 100

static char		*get_content(char *str, int len)
{
	char	*tmp;
	int		i;
	int		k;

	k = 0;
	while (str[k] != '\n' && str[k])
		k++;
	if ((tmp = (char *)malloc(sizeof(char) * (len + 1))))
	{
		i = 0;
		while (++k < len && str[k])
		{
			tmp[i] = str[k];
			i++;
		}
		tmp[i] = '\0';
		free(str);
		return (tmp);
	}
	return (NULL);
}

static char		*get_line(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	tmp = ft_strsub(str, 0, i);
	if (str[i] == '\n')
		str = str + i + 1;
	else
		str = str + i;
	return (tmp);
}

static t_list	*get_num(t_list **file, int fd)
{
	t_list	*temp;

	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	if (file)
	{
		temp->next = *file;
		*file = temp;
		return (*file);
	}
	return (temp);
}

static	void	condition(t_list *current, char *buff)
{
	char	*str;

	if (current->content == NULL)
		current->content = ft_strdup(buff);
	else
	{
		str = current->content;
		current->content = ft_strjoin(current->content, buff);
		free(str);
	}
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_list	*file;
	t_list			*current;
	int				byte;

	if (fd < 0 || !line || (byte = read(fd, buff, 0)) < 0)
		return (-1);
	current = get_num(&file, fd);
	while ((byte = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[byte] = '\0';
		condition(current, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (byte == 0 && (!(current->content) || !ft_strlen(current->content)))
		return (0);
	*line = get_line((char *)current->content);
	current->content = get_content((char *)current->content,
	ft_strlen((char *)current->content));
	return (1);
}
