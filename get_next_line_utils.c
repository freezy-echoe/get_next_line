#include "get_next_line.h"

int     check_for_newline(const char *buffer)
{
    int i;

    i = 0;
    while(buffer[i])
    {
        if (buffer[i] == '\n')
        {
            return (i);
        }
        i++;
    }
    return (-1);
}

int pos_new_line(const char *buffer)
{
    int pos;
    pos = 0;
    while (buffer[pos])
    {
        
        if (buffer[pos] != '\n')
        {
            continue ;
        }
        else
        {
            break ;
        }
        pos++;
    }
    

    return pos;
}

int     ft_strlen(const char *str)
{
    int count;

    count = 0;
    if (!str)
    {
        return (count);
    }
    while(str[count])
    {
        count++;
    }
    return (count);
}

char    *ft_strcat(char *s1, const char *s2)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (!s2)
    {
        return (s1);
    }
    while (s1[i])
    {
        i++;
    }
    while (s2[j])
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    return (s1);
}

char    *ft_strlcat(char *s1, const char *s2, int l)
{
    int i;
    int j;
    implement strclat for split function
}

int     number_of_chars(int fd)
{
    ssize_t bytes;
    char    *text_read;

    bytes = 0;
    text_read = malloc(1);
    while (text_read[0] != '\n')
    {
        bytes += read(fd, text_read, 1);
    }
    return (bytes);
}

char    *ft_strdup(const char *s)
{
    size_t	size;
	size_t	n;
	char	*s_dub;

	n = 0;
	size = ft_strlen((char *)s);
	s_dub = (char *)malloc(size + 1);
	if (!s_dub)
	{
		return (NULL);
	}
	while (n < size)
	{
		s_dub[n] = s[n];
		n++;
	}
	s_dub[n] = '\0';
	return (s_dub);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
    int     len;
    char    *new_str;

    if (!s1 || !s2)
    {
        return (NULL);
    }
    len = (ft_strlen(s1) + ft_strlen(s2) + 1);
    new_str = malloc(len);
    if (!new_str)
        return (NULL);
    new_str[0] = '\0';
    ft_strcat(new_str, s1);
    ft_strcat(new_str, s2);
    return (new_str);
}

char    *split_newline(char *buffer, int size)
{
    int count;
    char    *leftover;
    char    *pre_newline;

    pre_newline = malloc(size + 1);
    leftover = malloc(ft_strlen(buffer - size) + 1);
    count = 0;
    while(buffer[count])
    {
        pre_newline[count] = buffer[count];//strlcat is a good option
    }
}