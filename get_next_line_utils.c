#include "get_next_line.h"

int     check_for_newline(const char *buffer)
{
    int i;

    i = 0;
    while(buffer[i])
    {
        if (buffer[i] == 10)
        {
            return (0);
        }
        i++;
    }
    return (1);
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