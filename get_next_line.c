/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarimov <bkarimov@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:38:44 by bkarimov          #+#    #+#             */
/*   Updated: 2025/07/26 12:39:24 by bkarimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char *leftover;
    ssize_t     bytes;
    char        *buffer;
    char        *buffer_compile;
    int         newline_status;
    int         buff_count;
    int         fd2;

    leftover = NULL;
    bytes = 0;
    fd2 = fd;
    buff_count = 1;
    newline_status = 1;
    buffer = malloc(BUFFER_SIZE + 1); //buffer is set to dynamic memory allocation with +1 for null character
    buffer_compile = malloc(number_of_chars(fd2) + 1);
    while (newline_status != 0)
    {
        while (read(fd, buffer, BUFFER_SIZE))
        {
            
        }
        bytes += read(fd, buffer, BUFFER_SIZE); //bytes variable is used to dynamically allocate a new var???
        newline_status = check_for_newline(buffer);
        printf("%d. Current buffer is: %s \n",buff_count, buffer);
        buff_count++;
        ft_strcat(buffer_compile, buffer);
        //after read(), buffer string should be checked for \n with a helper function.  
        //bytes += read(fd, buffer, BUFFER_SIZE);
        //newline_status = check_for_newline(buffer);
        //newline is found, exit the loop
    }
    
    ft_strcat(buffer_compile, buffer);
    ft_strcat(buffer_compile, leftover);
    ft_strcat(buffer_compile, "\0");
    printf("bytes: %ld and buffer compiled is %s: \n", bytes, buffer_compile);
    return (buffer);
    //buffer_compile = malloc(bytes + 1)

}

int main(void)
{
    char    *text;
    char    *line;
    int     fd;

    text = "emperor.txt";
    fd = open(text, O_RDONLY);
    if (fd == -1)
    {
        perror("\nError Opening File!!\n");
        exit (1);
    }
    else
    {
        printf("\nFile %s opened successfully!!!\n", text);
    }
    line = get_next_line(fd);
    printf("%s\n", line);

    return (0);
}
