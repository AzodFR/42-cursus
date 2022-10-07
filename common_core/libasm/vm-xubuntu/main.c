/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 00:14:48 by azod              #+#    #+#             */
/*   Updated: 2020/12/28 12:55:01 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	/*
	**	STRLEN (const char *s)
	*/
	printf("=============\n| FT_STRLEN |\n=============\n");
	printf("ft_strlen of 'salut a tous' [%ld]\n", ft_strlen("salut a tous"));
	printf("strlen of 'salut a tous' [%ld]\n", strlen("salut a tous"));

	/*
	**	STRCPY (char *dest, const char *src)
	*/
	printf("\n=============\n| FT_STRCPY |\n=============\n");
	char test[3];
	char test2[3];
	ft_strcpy(test, "yo");
	printf("ft_strcpy: %s\n", test);
	strcpy(test2, "yo");
	printf("strcpy: %s\n", test2);

	/*
	**	STRCMP (const char *s1, const char *s2)
	*/
	printf("\n=============\n| FT_STRCMP |\n=============\n");
	printf("ft_strcmp of 'salut' & 'salaud' [%d]\n", ft_strcmp("salut", "salaud"));
	printf("strcmp of 'salut' & 'salaud' [%d]\n", strcmp("salut", "salaud"));

	/*
	**	READ (int fd, char *buffer, int buff_size)
	*/
	printf("\n============\n| FT_READ |\n============\n");
	int fd;
	fd = open("main.c", O_RDONLY);
	char buffer[11];
	int ret = ft_read(fd, buffer, 10);
	buffer[10] = 0;
	close(fd);

	fd = open("main.c", O_RDONLY);
	char buffer2[11];
	int ret2 = read(fd, buffer2, 10);
	buffer2[10] = 0;
	close(fd);

	printf("ft_read: |%s| %d\n", buffer, ret);
	printf("read: |%s| %d\n", buffer2, ret2);

	/*
	**	WRITE (int fd, char *buffer, int buff_size)
	*/
	printf("\n=============\n| FT_WRITE |\n=============\n");
	char buffer3[11];
	char buffer4[11];
	fd = open("ft_write.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_write(fd, "test1,2,3", 10);
	close(fd);
	fd = open("ft_write.txt", O_RDONLY);
	ret = ft_read(fd, buffer3, 10);
	buffer3[10] = 0;
	close(fd);

	fd = open("write.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, "test1,2,3", 10);
	close(fd);
	fd = open("write.txt", O_RDONLY);
	ret2 = ft_read(fd, buffer4, 10);
	buffer4[10] = 0;
	close(fd);
	printf("ft_write: |%s| %d\n", buffer3, ret);
	printf("write: |%s| %d\n", buffer4, ret2);

	/*
	**	DUP (const char *src)
	*/
	printf("\n==============\n| FT_STRDUP |\n==============\n");
	char *dup = strdup("Coucou");
	char *dup1 = ft_strdup("Coucou");
	printf("ft_strdup: |%s|\n", dup1);
	printf("strdup: |%s|\n", dup);
	free(dup);
	free(dup1);
	return (0);
}
