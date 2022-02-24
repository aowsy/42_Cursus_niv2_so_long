/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:19:17 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/24 13:41:02 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_sprites(t_data *data, t_sprite *sprite)
{
	data->y = 0;
	while (data->y < data->map_size)
	{
		data->x = 0;
		while (data->x < data->map_len)
		{
			if (data->map[data->y][data->x] == 'C' || data->map[data->y]
				[data->x] == 'E' || data->map[data->y][data->x] == 'P')
			{
				if (data->map[data->y][data->x] == 'C')
					sprite->img = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE,
							&sprite->img_size, &sprite->img_size);
				else if (data->map[data->y][data->x] == 'E')
					sprite->img = mlx_xpm_file_to_image(data->mlx, EXIT,
							&sprite->img_size, &sprite->img_size);
				else
					sprite->img = mlx_xpm_file_to_image(data->mlx, HERO,
							&sprite->img_size, &sprite->img_size);
				mlx_put_image_to_window(data->mlx, data->win, sprite->img,
					data->x * sprite->img_size, data->y * sprite->img_size);
			}
			data->x++;
		}
		data->y++;
	}
}

void	ft_put_background(t_data *data, t_sprite *sprite)
{
	data->moves = 0;
	data->collect = 0;
	data->y = 0;
	while (data->y < data->map_size)
	{
		data->x = 0;
		while (data->x < data->map_len)
		{
			if (data->map[data->y][data->x] == '1')
				sprite->img = mlx_xpm_file_to_image(data->mlx, WALLS,
						&sprite->img_size, &sprite->img_size);
			else
				sprite->img = mlx_xpm_file_to_image(data->mlx, GROUND,
						&sprite->img_size, &sprite->img_size);
			mlx_put_image_to_window(data->mlx, data->win, sprite->img,
				data->x * sprite->img_size, data->y * sprite->img_size);
			data->x++;
		}
		data->y++;
	}
}
