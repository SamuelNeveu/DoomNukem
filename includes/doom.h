/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:48:08 by saneveu           #+#    #+#             */
/*   Updated: 2020/08/01 21:14:52 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include <time.h>
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
# include <math.h>
# include "../lib/SDL/SDL.h"
# include "../lib/SDL/SDL_mixer.h"
# include "../lib/SDL/SDL_ttf.h"
# include "../lib/SDL/SDL_image.h"

# include "../libft/includes/libft.h"
# include "key.h"
# include "editor.h"
# include "parser.h"

# define W_WIDTH	1280
# define W_HEIGHT	720

# define BUTTON_MARGE 6

# define MENU 0
# define GAME 1
# define PAUSE 2
# define FORGE 3
# define END 4

# define NB_THREAD 6

# define FPS		60

# define CUBE_SIZE 100
# define FLOOR 0
# define WALL 1
# define PLAYER 2
# define PLANT 3
# define CAGE 4
# define TABLE 5
# define SPAWNER 6
# define WALL1 10
# define WALL2 11
# define AMMO 15
# define HEAL 16

# define WIN 14

# define SNB		29
# define SITEMS		7
# define WPS_NB		33

# define WP_NB		5
# define WP_FISTS	0
# define WP_PISTOL	1
# define WP_SMG		2
# define WP_SHOTGUN	3
# define WP_BFG		4

typedef struct	s_rgba
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_rgba;

typedef union	s_rsqrt
{
	float		f;
	uint32_t	i;
}				t_rsqrt;

typedef struct	s_sprite
{
	SDL_Surface	*img;
}				t_sprite;

typedef struct	s_sound
{
	Mix_Music	*ingmusic;
	Mix_Music	*pausemusic;
	Mix_Chunk	*gun;
	Mix_Chunk	*shotgun;
	Mix_Chunk	*fusil;
	Mix_Chunk	*hand;
	Mix_Chunk	*nmihit;
	Mix_Chunk	*nmideath;
	Mix_Chunk	*nmispawn;
	Mix_Chunk	*nmiatk;
	Mix_Chunk	*playerhit;
	Mix_Chunk	*playerdeath;
	Mix_Chunk	*playerspawn;
	Mix_Chunk	*switchgun;
	Mix_Chunk	*tic;
	Uint8		token;
}				t_sound;

typedef struct	s_objdata
{
	int			column;
	uint32_t	zpixel;
	float		angle;
	float		mid;
	float		ratio;
	float		dst_fromplayer;
	float		ceiling;
	float		floor;
	float		height;
	float		width;
	float		samplex;
	float		sampley;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			spritewidth;
	int			drawstarty;
	int			drawendy;
	int			drawendx;
	int			drawstartx;
	int			vmove;
}				t_objdata;

typedef struct	s_object
{
	int				dead;
	int				delay;
	int				hp;
	int				hp_max;
	int				i;
	int				si;
	int				type;
	float			speed;
	float			x;
	float			y;
	float			vx;
	float			vy;
	float			depth;
	t_sprite		sprite;
	t_objdata		data;
	struct s_object	*next;
	struct s_object	*prev;
}				t_object;

typedef struct	s_rect
{
	int				x;
	int				y;
	int				h;
	int				w;
}				t_rect;

/*
** Weapon data structure ; holds stats of one weapon per structure.
** NB : column = offset for weapon to be centered ?
*/

typedef struct	s_wdata
{
	int			damage;
	int			delay;
	int			range;
	int			clip_max;
	int			clip_cur;
	int			clip_rld;
	int			ammo_cur;
	int			ammo_max;
	int			si;
	int			hor_off;
	int			vert_off;
	uint32_t	zpixel;
	float		height;
	float		width;
	char		*name;
}				t_wdata;

/*
** Player structure ; holds stats of the player.
*/

typedef struct	s_player
{
	int				game_over;
	double			pitch;
	double			posz;
	int				health;
	int				health_max;
	int				pos;
	int				weapon;
	int				gbl_delay;
	int				fist_side;
	int				charging;
	int				reloading;
	char			*hud_text1;
	char			*hud_text2;
	float			angle;
	float			fov;
	float			ms;
	float			speed;
	float			x;
	float			y;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	t_wdata			wdata[WP_NB];
	unsigned int	platform;
	void			(*f[6])(void *);
}				t_player;

typedef struct	s_ray
{
	int			wallside;
	int			wallhit;
	int			walltop;
	int			wallbot;
	double		wallx;
	double		perpwalldist;
	double		distwall;
	int			maposx;
	int			maposy;
	double		dirx;
	double		diry;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	double		camera;
	int			stepx;
	int			stepy;
	int			height;
	int			tex;
	int			wtx;
	int			wty;
	double		floorwallx;
	double		floorwally;
	double		currentfloorx;
	double		currentfloory;
	double		distcurrent;
	double		weight;
	int			cellx;
	int			celly;
	float		camz;
}				t_ray;

typedef struct	s_map
{
	int			len;
	int			height;
	int			width;
	int			**map;
	float		depth;
	float		depth_buffer[W_WIDTH];
	int			sc_x;
	int			posx;
	int			posy;
}				t_map;

typedef struct	s_node
{
	int				bobstacle;
	int				bvisited;
	int				i;
	int				x;
	int				y;
	float			globalgoal;
	float			localgoal;
	struct s_node	*ngbhr[4];
	struct s_node	*parent;
}				t_node;

typedef struct	s_alst
{
	t_node			*node;
	struct s_alst	*next;
}				t_alst;

typedef struct	s_pf
{
	t_node		*start;
	t_node		*end;
	t_node		*list;
	t_alst		*alst;
}				t_pf;

typedef struct	s_menu
{
	SDL_Surface		*button;
	SDL_Surface		*text;
	SDL_Rect		button1pos;
	SDL_Rect		button2pos;
	SDL_Rect		textpos;
	SDL_Color		textcolor;
	SDL_Surface		*menu1;
	SDL_Surface		*menu2;
	SDL_Surface		*menu3;
	TTF_Font		*font;
	t_map			map;
}				t_menu;

typedef	struct	s_font
{
	TTF_Font		*police;
	TTF_Font		*police2;
	TTF_Font		*police3;
	TTF_Font		*policep;
}				t_font;

typedef struct	s_thread
{
	void			*env;
	pthread_t		thread;
	int				start;
	int				end;
	int				i;
	int				id;
}				t_thread;

typedef struct	s_doom
{
	t_point					end;
	int						game;
	char					*strgame;
	int						style;
	int						floorstyle;
	int						fps;
	int						kill_score;
	int						sdl_on;
	int						shoot;
	int						global_time;
	int						wx;
	int						wy;
	int						key[KEY_NB];
	char					*str;
	float					cdst;
	float					frametime;
	float					oldtime;
	float					time;
	double					mv_speed;
	double					rot_speed;
	double					obj_intens;
	int						fog;
	t_pf					pfdata;
	t_player				player;
	t_ray					ray;
	t_object				*monster;
	t_object				*object;
	t_object				*end_flag;
	t_object				*items;
	t_sprite				sprite[SNB];
	t_sprite				sp_items[SNB];
	t_sprite				wp_sprite[WPS_NB];
	t_rgba					rgb;
	t_font					font;
	SDL_Point				*point;
	t_sound					sound;
	SDL_MouseMotionEvent	mouse;
	SDL_Event				event;
	SDL_Renderer			*renderer;
	SDL_Surface				*screen;
	t_map					map;
	SDL_Texture				*window;
	SDL_Window				*pwindow;
	SDL_MouseButtonEvent	clicks;
	t_menu					menu;
	t_editor				ed;
	TTF_Font				*police;
	TTF_Font				*police2;
	TTF_Font				*police3;
	TTF_Font				*policep;
}				t_doom;

void			check_sprites_weapons(t_doom *data);
void			display(t_doom *data);
void			deal_damage_tomonster(t_doom *data, t_object *list, int damage);
void			events(t_doom *data);
void			fire_weapon(t_doom *data);
void			game_over(t_doom *data);
void			get_fists_data(t_doom *data);
void			get_pistol_data(t_doom *data);
void			get_smg_data(t_doom *data);
void			get_shotgun_data(t_doom *data);
void			get_bfg_data(t_doom *data);
int				get_weapon_skin_s(t_doom *data);
int				get_weapon_skin(t_doom *data);
void			load_datagame(t_doom *data);
void			monsters(t_doom *data);
void			mouse_events(t_doom *data);
void			mouse_motion(t_doom *data);
void			player_height(t_doom *data);
void			movements(t_doom *data);
void			objects(t_doom *data, t_object *list);
void			object_actions(t_doom *data, t_object *list);
void			reload_weapon(t_doom *data);
void			shoot(t_doom *data);
void			spawner(t_doom *data);
void			sprites(t_doom *data);
void			sprites_textures(t_doom *data);
void			swap_weapons(t_doom *data);
void			switch_floor(t_doom *d);
void			sprites_melee(t_doom *data);
void			sprites_pistol(t_doom *data);
void			sprites_smg(t_doom *data);
void			sprites_items(t_doom *data);
void			sprites_shotgun(t_doom *data);
void			sprites_bfg(t_doom *data);
void			sprites_weapons_hud(t_doom *hud);
void			weapons(t_doom *data);
void			draw_stat(t_doom *data, int stat_id, int s_x, int s_y);
void			change_weapon(t_doom *data);
t_doom			*minimap_alloc(t_doom *data);
void			get_blockside(t_doom *data, int testx, int testy);
void			*raycasting(void *thread);
void			draw_wall(t_doom *d, int x, t_ray *ray);
void			get_tex(t_ray *ray);
void			raycast_threader(t_doom *d);

void			minimap(t_doom *data);
void			free_minimap(t_doom *d);

float			distance(float x1, float y1, float x2, float y2);
float			distance_calc(float x1, float y1, float x2, float y2);
int				get_objhp(t_doom *data, t_object *list);
uint32_t		get_pixel(t_doom *data, int si, float samplex, float sampley);
uint32_t		get_pxl_wp(t_doom *data, int si, float samplex, float sampley);
SDL_Surface		*new_surface(int w, int h);
void			put_pixel(SDL_Surface *surface, int x, int y, uint32_t color);
Uint32			light_shade(Uint32 hexa, float distance);

void			draw_fps(t_doom *data);
void			add_sc_x(t_doom *data);
void			clean_exit(t_doom *data, char *str, int token);
void			lst_free(t_object *list);
int				lst_len(t_object *list);
t_object		*lst_pushback(t_object *list, t_object *node);

void			get_nodes(t_doom *data);
void			astar(t_doom *data);

void			alst_free(t_alst *list);
int				alst_len(t_alst *list);
void			alst_pushback(t_alst *list, t_node *node);
void			alst_sort(t_alst *list);

void			set_rect_to_screen(t_doom *data, SDL_Rect *rect, int color);
SDL_Color		ft_hex_to_rgb(int hexa);
void			set_write_to_screen(t_doom *data,
					SDL_Rect rect, int color, char *str);
void			object_minimap(t_doom *data, t_object *list);

uint32_t		get_pixel_obj(t_object *l, int texx, int texy);
uint32_t		get_pixel_ray(t_doom *data, int si, int coord[2], t_ray *ray);
uint32_t		get_pixel_floor(t_doom *data, int si, int coord[2], t_ray *ray);
void			draw_floor_ceilling(t_doom *d, int x, t_ray *ray);
void			mouse(t_doom *data, Sint16 xrel, int dir);

void			audio_init(t_doom *data);
void			free_sound(t_doom *data);
void			play_sound(t_doom *data, Mix_Chunk *chunk, int channel);
void			play_music(t_doom *data, Mix_Music *music);

void			cursor(t_doom *data);
void			health(t_doom *data);
void			ammo(t_doom *data);
void			help_pause(t_doom *data);

t_rgba			fill_rgb(int c);
int				rgb_to_hsv(int r, int g, int b);
int				fog(t_doom *d, Uint32 pixel, float distance);
void			switch_fog(t_doom *d);
void			free_surfaces(t_doom *data);
void			set_end_pt(t_doom *d, t_object *list, int i, int j);
void			end_screen(t_doom *d);
void			check_item_pos(t_doom *d);
void			free_ttf(t_doom *data);
void			writeonscreen(t_doom *data, char *quote, SDL_Color color);

void			menu_start(void *data);
void			menu_pause(void *data);
void			gameplay(void *data);
void			init_data(t_doom *data);
void			init_sdl(t_doom *data);
void			init_menu(t_doom *data);
void			init_forge(t_doom *data);
void			main_menu(t_doom *data);
void			main_forge(t_doom *data);
void			event_main_menu(t_doom *data);
void			pause_menu(t_doom *data);
void			sdl_render(t_doom *data);

void			editor(t_doom *e);
t_string		create_texture(t_doom *e, t_point pos, t_string to_copy);
void			draw_line(SDL_Renderer *renderer, t_point start, t_point end);
void			reset(t_doom *e);
void			draw_grid(t_doom *e);
void			refresh_map(t_doom *e);
void			init_string(t_doom *e);
void			set_player(t_doom *e);
void			forge(void *data);
void			set_win(t_doom *e);
void			set_wall(t_doom *e);
void			set_spawner(t_doom *e);
void			set_floor(t_doom *e);
void			draw_sqr(SDL_Renderer *renderer, t_point start, t_point end);
void			editor_event(t_doom *d);
void			scan_events(t_doom *data);
void			init_editor_grid(t_doom *e);
void			platform_event(t_doom *data);
int				button_collide(t_doom *e, t_point pos, t_point size);
void			set_objects(t_doom *e);
void			obj_add(t_obj **link, t_obj *new);

void			game_win(t_doom *data);
void			game_ending(t_doom *data);
void			game_end(void *data);
int				parse(t_doom *e, char *av);
int				check_line_length(char *line, t_map *map, t_list **list);
int				check_line(char *line);
int				check_wall_surround(t_map *map);
int				check_player(t_map *map);
int				check_win(t_map *map);
void			check_collision(t_doom *e, int fd);
void			free_list(t_list *list);
void			free_split(char **split);
void			free_map(t_map *map);
int				display_error(t_doom *e, char *reason);
int				**ft_tab_new_int(int x, int y);
size_t			ft_countcwords(const char *s, char c);
void			ft_lstadd_end(t_list **aslt, t_list *new);
int				create_file(t_doom *e, int fd);
void			get_list_bis(t_doom *d, int i, int j, t_object *list);
void			help_get_list(t_doom *data, t_object *list, int i, int j);
void			help_get_list_items(t_doom *data, t_object *list, int i, int j);
void			wall_detect(t_doom *d, t_ray *ray);
void			free_int(int **map, int width);

#endif
