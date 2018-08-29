/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 06:01:46 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 06:01:50 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_reader.h"

void	reader(t_header *fh, int fd_img)
{
	read(fd_img, &(fh->file_marker1), sizeof(unsigned char));
	read(fd_img, &(fh->file_marker2), sizeof(unsigned char));
	read(fd_img, &(fh->bf_size), sizeof(unsigned int));
	read(fd_img, &(fh->unused1), sizeof(short));
	read(fd_img, &(fh->unused2), sizeof(short));
	read(fd_img, &(fh->image_data_offset), sizeof(unsigned int));
	read(fd_img, &(fh->bi_size), sizeof(unsigned int));
	read(fd_img, &(fh->width), sizeof(int));
	read(fd_img, &(fh->height), sizeof(int));
	read(fd_img, &(fh->planes), sizeof(short));
	read(fd_img, &(fh->bit_pix), sizeof(short));
	read(fd_img, &(fh->bi_compression), sizeof(unsigned int));
	read(fd_img, &(fh->bi_size_image), sizeof(unsigned int));
	read(fd_img, &(fh->bi_xpels_per_meter), sizeof(int));
	read(fd_img, &(fh->bi_ypels_per_meter), sizeof(int));
	read(fd_img, &(fh->bi_clrused), sizeof(unsigned int));
	read(fd_img, &(fh->bi_clr_important), sizeof(unsigned int));
}

char	*init_image(t_header *fh)
{
	char	*img;

	img = (char *)malloc(sizeof(char) * fh->bf_size);
	return (img);
}

char	*get_bmp_img(int *height, int *width)
{
	t_header	fh;
	int			fd_img;
	char		*ret;

	fd_img = open("./resources/licorn.bmp", O_RDONLY);
	if (fd_img < 0)
		return ((void *)0);
	reader(&fh, fd_img);
	ret = init_image(&fh);
	if (!ret)
		return (ret);
	read(fd_img, ret, fh.bf_size);
	*height = fh.height;
	*width = fh.width;
	return (ret);
}
