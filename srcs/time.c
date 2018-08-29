/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:38:01 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:38:05 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float	get_current_time(void)
{
	struct timeval	tv;
	struct timezone	tz;
	static time_t	local_time = 0;
	float			t;

	if (local_time == 0)
		local_time = time(NULL);
	gettimeofday(&tv, &tz);
	t = (float)(time(NULL) - local_time) + (float)tv.tv_usec / 1000000.0;
	return (t);
}
