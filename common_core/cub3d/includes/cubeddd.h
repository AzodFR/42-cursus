/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubeddd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:10:32 by azod              #+#    #+#             */
/*   Updated: 2021/01/05 14:37:17 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBEDDD_H
#define CUBEDDD_H
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "ft_printf.h"
#define ESC 53
#define LEFT 123
#define RIGHT 124
#define UP 126
#define DOWN 125
#define W 13
#define A 0
#define S 1
#define D 2
#define SHIFT 257
#define CTRL 256
#define SPEED 0.20
#define SENSIVITY 30
#define HUD 4

/*
** STRUCTURE FOR PARAMETERS
*/
typedef struct s_params
{
	int win_x;
	int win_y;
	char *text_no;
	char *text_so;
	char *text_we;
	char *text_ea;
	char *text_sprite1;
	char *text_sprite2;
	char *text_sprite3;
	char *map;
	int f[3];
	int c[3];
	int screen;
} t_params;
/*
** STRUCTURE FOR MLX
*/
typedef struct s_mlx
{
	void *ptr;
	void *win;
} t_mlx;
/*
** STRUCTURE FOR IMAGES (DESTRUCTIBLE)
*/
typedef struct s_img
{
	void *img;
	int x;
	int y;
	int pos_x;
	int pos_y;
} t_img;
/*
** STRUCTURE FOR ALL THE RENDERING
*/
typedef struct s_display
{
	double pos_x;
	double pos_y;
	double pos_z;
	float cam_z;
	double pitch;
	int p;
	double rowdist;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
	double camera_x;
	double raydir_x;
	double raydir_y;
	int map_x;
	int map_y;
	double sidedist_x;
	double sidedist_y;
	double deltadist_x;
	double deltadist_y;
	double perpwall_dist;
	int hit;
	int step_x;
	int step_y;
	int side;
	int lineheight;
	int draw_start;
	int draw_end;
	double tex_pos;
	int tex_x;
	int tex_y;
	double step;
	double wall_x;
	double zbuff[3660];
	double invdet;
	double transform_x;
	double transform_y;
	double spritex;
	double spritey;
	int spritescreen_x;
	int spriteheight;
	int drawstart_y;
	int drawend_y;
	int spritewidth;
	int drawstart_x;
	int drawend_x;
	int stripe;
	int y;
	int sprite_tex_x;
	int sprite_tex_y;
	double sprite_color;
} t_display;
/*
** STRUCTURE FOR TEXTURES
*/
typedef struct s_texture
{
	void *ptr;
	int *array;
	int info[4];
} t_texture;
/*
** STRUCTURE FOR ACTIVE KEYS
*/
typedef struct s_key
{
	int w;
	int a;
	int s;
	int d;
	int hud;
	int right;
	int left;
} t_key;
/*
** STRUCTURE FOR SPRITES
*/
typedef struct s_sprite
{
	int x;
	int y;
	int type;
} t_sprite;
/*
** STRUCTURE FOR MAP PARAMS
*/
typedef struct s_map
{
	char p_facing;
	int pos[2];
	int error;
	char **map;
	int **worldmap;
	t_sprite *sprite;
	int nbsprite;
	int win;
} t_map;
/*
** STRUCTURE FOR BMP SAVING
*/
typedef struct s_bmp
{
	char header[54];
	int fd;
	int w;
	int height;
	int bytes_number;
	int width_bytes;
	int image_s;
	int bytes_s;
	int file_s;
	int header_s;
	int biplanes;
} t_bmp;
/*
** STRUCTURE FOR EVERY OTHER STRUCT
*/
typedef struct s_all
{
	t_params p;
	t_mlx mlx;
	t_map map;
	t_img img;
	t_display d;
	t_key key;
	t_texture text[7];
	t_bmp *bmp;
	void *main;
	void *life_txt;
	double sprint;
	int keys;
	int life;
} t_all;

void free_line_exit(char **l, int er, char *r, t_params *p);
t_all parser(char *file, int ret);

/*
** SETTER
*/
void set_rgb(char *line, t_params *p, int floor, int i);
void set_texture(char *line, t_params *p, int face);
void set_map(int *n, char *line, t_params *p);
void set_resolution(char *line, t_params *p);
/*
** CHECKER
*/
t_map check_map(t_map map, t_params *p);
void check_sprites(t_params *p);
void check_walls(t_params *p);
void check_state(t_all *all);
void check_trap(t_all *a);
/*
** GETTER
*/
t_map get_map(t_params p);
char *get_path(int i, t_params p);
int get_type(t_all *all, t_display *d, int i);
/*
** UTILS
*/
t_sprite *sort_sprite(t_sprite *sprite, int max, t_all *all);
void ft_init_bmp(t_all *a, int width, int height, int *array);
void ft_exit(int status, char *reason, t_params *p, t_all *a);
int is_sprite(char c);
int is_wall(int i);
int lx(int life);
/*
** INITER
*/
double get_rotation(char c);
t_map treat_sprite(t_map map, int i, int j);
void init_variables(t_display *d, t_params *p, int x);
t_all init_texture(t_params p, t_all a, int i);
t_all init_key(t_all all);
t_display init_display(t_map map);
t_all init_all(t_all all);
/*
** KEYBOARD CONTROLS
*/
int key_press(int keycode, t_all *a);
int key_release(int keycode, t_all *a);
void check_move(t_all *a);
void move_forward(t_all *a);
void move_back(t_all *a);
void move_right(t_all *a);
void move_left(t_all *a);
void turn_right(t_all *a);
void turn_left(t_all *a);
/*
** ENGINE
*/
void draw_sprite(t_all *all, t_display *d, int type, int *array);
void print_floor(int *array, t_display *d, t_params *p, int x);
void print_ceil(int *array, t_display *d, t_params *p, int x);
void print_img(t_display *d, t_params *p, t_all *a, int *ar);
void print_sprite(int *array, t_all *all, t_display *d);
void print_wall(int *array, t_all *all, int x, int or);
void print_life(int *array, t_all *all, int x);
void check_start_end(t_all *all, t_display *d);
void render_hud(t_all *all);
#endif
