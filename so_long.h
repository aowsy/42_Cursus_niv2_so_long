/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:29:23 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/23 13:51:03 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libc.h>
# include <stdlib.h>
# include <mlx.h>

# include "libft/libft.h"

# define WALLS "sprites/mur1.XPM"
# define GROUND "sprites/sol1.XPM"
# define COLLECTIBLE "sprites/cookie1.XPM"
# define EXIT "sprites/exit1.XPM"
# define HERO "sprites/mooncake1.XPM"

# define MAP_ARG "01CEP"

typedef struct s_elem
{
	int	elem_c;
	int	elem_e;
	int	elem_p;
}				t_elem;

typedef struct s_sprite
{
	void	*img;
	void	*img_p;
	void	*img_g;
	void	*img_e;
	int		img_size;
}	t_sprite;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		map_len;
	int		map_size;
	int		collect;
	int		moves;
}	t_data;

char	**ft_map_init(char *file);
void	ft_map_check(char **map);
int		ft_map_size(char **map);
void	ft_put_background(t_data *data, t_sprite *sprite);
void	ft_put_sprites(t_data *data, t_sprite *sprite);
void	ft_position(t_data *data);
int		ft_keyhook(int keycode, t_data *data, t_sprite *sprite);
void	ft_move_player(t_data *data, t_sprite *sprt, int x, int y);
void	ft_map_check_elem(char **map);
void	ft_check_exten(char *str);

int		ft_close(t_data *data);

void	ft_error(char *msg);
void	ft_error_tab_str(char *msg, char *str, char **map);
void	ft_map_error(char *msg, char **map);
void	ft_free_tab(char **tab, size_t i);

char	*get_next_line(int fd);

char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif
