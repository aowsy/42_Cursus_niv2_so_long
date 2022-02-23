/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:41:17 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/23 13:35:38 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	s'assurer qu'il ne prend bien que des .ber (peut-etre les inclure au makefile...)

void	ft_struct_init(t_data *data, t_sprite *sprite)
{
	data->map_len = 0;
	data->map_size = 0;
	data->collect = 0;
	data->moves = 0;
	sprite->img_size = 0;
}

int	main(int ac, char **av)
{
	t_data		data;
	t_sprite	sprite;

	if (ac < 2)
		ft_error("Please provide the map as argument");
	else if (ac > 2)
		ft_error("Please provide only one argument");
	else
	{
		ft_check_exten(av[1]);
		data.map = ft_map_init(av[1]);
		data.mlx = mlx_init();
		data.map_len = ft_strlen(data.map[0]);
		data.map_size = ft_map_size(data.map);
		data.win = mlx_new_window(data.mlx, data.map_len * 32,
				data.map_size * 32, "so_long");
		ft_put_background(&data, &sprite);
		ft_put_sprites(&data, &sprite);
		ft_position(&data);
		mlx_key_hook(data.win, ft_keyhook, &data);
		mlx_hook(data.win, 17, 1L << 0, ft_close, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
