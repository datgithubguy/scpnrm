/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 06:07:36 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 06:08:29 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_READER_H
# define BMP_READER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_header
{
	unsigned char	file_marker1;
	unsigned char	file_marker2;
	unsigned int	bf_size;
	short			unused1;
	short			unused2;
	unsigned int	image_data_offset;
	unsigned int	bi_size;
	int				width;
	int				height;
	short			planes;
	short			bit_pix;
	unsigned int	bi_compression;
	unsigned int	bi_size_image;
	int				bi_xpels_per_meter;
	int				bi_ypels_per_meter;
	unsigned int	bi_clrused;
	unsigned int	bi_clr_important;
}					t_header;

char				*init_image(t_header *fh);
void				reader(t_header *fh, int fd_img);
char				*get_bmp_img(int *height, int *width);

#endif
