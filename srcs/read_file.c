/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:36:46 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:36:49 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char	*read_file(char *filepath)
{
	struct stat	stats;
	int			ret_stat;
	int			fd;
	char		*s;

	fd = open(filepath, O_RDONLY);
	printf("path = %s\n", filepath);
	if (fd < 0)
	{
		printf("could not open file\n");
		die(NULL);
	}
	s = NULL;
	ret_stat = fstat(fd, &stats);
	if ((s = (char *)malloc(sizeof(char) * (stats.st_size + 1))) == NULL)
		die(NULL);
	bzero(s, sizeof(char) * stats.st_size);
	read(fd, s, stats.st_size);
	s[stats.st_size] = '\0';
	close(fd);
	return (s);
}
