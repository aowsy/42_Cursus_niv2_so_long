/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:09:52 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/23 14:09:32 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_free_tab(data->map, ft_map_size(data->map));
	exit(0);
	return (0);
}

void	ft_move_player(t_data *data, t_sprite *sprt, int x, int y)
{
	sprt->img_p = mlx_xpm_file_to_image(data->mlx, HERO, &sprt->img_size,
			&sprt->img_size);
	sprt->img_g = mlx_xpm_file_to_image(data->mlx, GROUND, &sprt->img_size,
			&sprt->img_size);
	sprt->img_e = mlx_xpm_file_to_image(data->mlx, EXIT, &sprt->img_size,
			&sprt->img_size);
	if (data->map[y][x] == 'C')
		data->collect--;
	if (data->map[y][x] == 'E')
		data->map[y][x] = 'G';
	else
		data->map[y][x] = 'P';
	mlx_put_image_to_window(data->mlx, data->win, sprt->img_p, x * 32, y * 32);
	mlx_put_image_to_window(data->mlx, data->win, sprt->img_g, data->x * 32,
		data->y * 32);
	if (data->map[data->y][data->x] == 'G')
	{
		mlx_put_image_to_window(data->mlx, data->win, sprt->img_e,
			data->x * 32, data->y * 32);
		data->map[data->y][data->x] = 'E';
	}
	data->x = x;
	data->y = y;
	data->moves++;
	return ;
}

int	ft_keyhook(int keycode, t_data *data, t_sprite *sprite)
{
	int	past_moves;

	past_moves = data->moves;
	if (keycode == 53)
		ft_close(data);
	else if (keycode == 13 && data->map[data->y - 1][data->x] != '1')
		ft_move_player(data, sprite, data->x, data->y - 1);
	else if (keycode == 0 && data->map[data->y][data->x - 1] != '1')
		ft_move_player(data, sprite, data->x - 1, data->y);
	else if (keycode == 1 && data->map[data->y + 1][data->x] != '1')
		ft_move_player(data, sprite, data->x, data->y + 1);
	else if (keycode == 2 && data->map[data->y][data->x + 1] != '1')
		ft_move_player(data, sprite, data->x + 1, data->y);
	if (data->map[data->y][data->x] == 'G' && data->collect == 0)
		ft_close(data);
	if (past_moves != data->moves)
		printf("Mooncake has done %d moves\n", data->moves);
	return (0);
}

void	ft_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->y = i;
				data->x = j;
			}
			else if (data->map[i][j] == 'C')
				data->collect++;
			j++;
		}
		i++;
	}
	return ;
}
