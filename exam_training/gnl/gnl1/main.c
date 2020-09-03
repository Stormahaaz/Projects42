/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:24:36 by gupatric          #+#    #+#             */
/*   Updated: 2020/08/25 15:24:52 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	(void)ac;
    char *line;
    int fd = open(av[1], O_RDONLY);
    while (get_next_line(fd, &line) > 0)
	{
        printf("%s", line);
		free(line);
	}
}