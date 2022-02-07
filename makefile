# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 12:01:33 by saneveu            #+#    #+#              #
#    Updated: 2020/08/22 12:59:59 by brpinto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PURPLE	=	\033[35m
TUR		=	\033[36m
WHITE	=	\033[37m
END		=	\033[0m

UP 		=	\033[A
CUT 	=	\033[K

# project
NAME	=	doom-nukem

# compiler
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -pipe -Ofast -march=native

# directories
SRC_PATH	=	./srcs/
HEADER_PATH	=	./includes/
OBJ_PATH	=	./obj/
LIB_PATH	=	./libft/
SDL_PATH = ./libraries/include/SDL

# src / obj files
SRC		=	main.c \
			audio/audio.c \
			editor/editor.c \
			editor/editor_collisions.c \
			editor/editor_draw.c \
			editor/editor_event.c \
			editor/editor_refresh.c \
			editor/editor_sqr.c \
			editor/editor_sqr_wall.c \
			editor/editor_utils.c \
			editor/editor_save.c \
			ennemies/astar.c \
			ennemies/astar_list.c \
			ennemies/monsters.c \
			ennemies/nodes.c \
			ennemies/spawner.c \
			events/events.c \
			events/event_main_menu.c \
			events/exit.c \
			events/mouse_events.c \
			events/movements.c \
			events/movements_height.c \
			events/platform_event.c \
			events/swap_weapons.c \
			events/switch_event.c \
			gameplay/fire_weapon.c \
			gameplay/game_over.c \
			gameplay/get_weapon_skin.c \
			gameplay/get_weapon_skin_s.c \
			gameplay/hud.c \
			gameplay/hud_ammo.c \
			gameplay/reload_weapon.c \
			gameplay/shoot.c \
			gameplay/weapons.c \
			gameplay/items.c \
			init/datagame.c \
			init/get_weapon_data.c \
			init/init_data.c \
			init/init_forge.c \
			init/init_forge_strings.c \
			init/init_menu.c \
			init/init_sdl.c \
			menu/menu.c \
			minimap/minimap.c \
			minimap/minimap_monster.c \
			parsing/check_file.c \
			parsing/error.c \
			parsing/free_file.c \
			parsing/parse.c \
			raycasting/color.c \
			raycasting/draw_ray.c \
			raycasting/floor.c \
			raycasting/fog.c \
			raycasting/objects.c \
			raycasting/raycasting.c \
			raycasting/raycast_threader.c \
			render/display.c \
			render/platform.c \
			render/sdl_render.c \
			render/tool_render.c \
			ressources/sprites.c \
			ressources/sprites_weapons.c \
			ressources/texture.c \
			tools/tool_global.c \
			tools/tool_list.c \
			tools/tool_pixel.c \
			tools/tool_raycast.c \

INC		=	doom.h \
			key.h \
			editor.h

# LIBS = SDL2 SDL2_image SDL2_mixer SDL2_ttf
# LIB_DIR = ./libraries/lib/

# SDL_FILE = -L ./libraries/lib -lSDL2
# SDL_IMAGE = -L ./libraries/lib -lSDL2_image
# SDL_MIXER = -I $(SDL_PATH) $(SDL_FILE) -L ./libraries/lib -lSDL2_mixer
# SDL_TTF = -L ./libraries/lib -lSDL2_ttf
# FREETYPE = -L ./libraries/lib -lfreetype

ABSOLUTE_DIR = $(shell pwd)

LIB	=	$(addprefix $(LIB_PATH), libft.a)

OBJS	=	$(SRC:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJS))

HEADER	=	$(addprefix $(HEADER_PATH), $(INC))

# ft library	

all: 		 lib $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH)/raycasting
	@mkdir $(OBJ_PATH)/init
	@mkdir $(OBJ_PATH)/render
	@mkdir $(OBJ_PATH)/menu
	@mkdir $(OBJ_PATH)/gameplay
	@mkdir $(OBJ_PATH)/ennemies
	@mkdir $(OBJ_PATH)/events
	@mkdir $(OBJ_PATH)/minimap
	@mkdir $(OBJ_PATH)/ressources
	@mkdir $(OBJ_PATH)/audio
	@mkdir $(OBJ_PATH)/tools
	@mkdir $(OBJ_PATH)/editor
	@mkdir $(OBJ_PATH)/parsing

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "${TUR}compiling [$@] ...${END}"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH) -I $(LIB_PATH)includes/ -I $(SDL_PATH)
	@printf "$(UP)$(CUT)"

$(LIB):
	@make -C $(LIB_PATH)
	@echo "${GREEN}[LIBRARY COMPILED]${END}"

$(NAME):	$(LIB) $(OBJ_PATH) $(OBJ_EXEC) $(HEADER_PATH)
			@$(CC) $(CFLAGS) $(OBJ_EXEC) $(LIB) -lm -lpthread -o $@ -I $(HEADER_PATH) -lSDL2 -lSDL2_image -lSDL2_mixer -lfreetype -lSDL2_ttf
			@echo "${GREEN}[$@ COMPILED]${END}"

# lib: sdl image

# sdl:
# 	@if [ -d "./libraries/SDL2-2.0.8" ]; then \
# 		echo "${cyanfonce}SDL2 already installed ...${neutre}\r"; \
# 	else \
# 		echo "${cyanfonce}Installing SDL2 ...${neutre}\c" && \
# 		mkdir -p libraries && \
# 		curl -s https://www.libsdl.org/release/SDL2-2.0.8.tar.gz -o libraries/SDL2-2.0.8.tar.gz >> ./doom_lib_log 2>&1 && \
# 		tar -xf libraries/SDL2-2.0.8.tar.gz -C libraries >> ./doom_lib_log 2>&1 && \
# 		cd libraries/SDL2-2.0.8 && \
# 		./configure --prefix=$(shell pwd)/libraries >> ./doom_lib_log 2>&1 && \
# 		$(MAKE) >> ./doom_lib_log 2>&1 && \
# 		$(MAKE) install >> ./doom_lib_log 2>&1 && \
# 		echo "${cyanclair}DONE${neutre}"; \
# 	fi

# image: ttf
# 	@if [ -d "./libraries/SDL2_image-2.0.5/" ]; then \
# 		echo "${cyanfonce}SDL2 Image already installed ...${neutre}\r"; \
# 	else \
# 		echo "${cyanfonce}Installing SDL2_image ...${neutre}\c" && \
# 		mkdir -p libraries && \
# 		curl -s https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.5.tar.gz -o libraries/SDL2_image-2.0.5.tar.gz && \
# 		tar -xf libraries/SDL2_image-2.0.5.tar.gz -C libraries >> ./doom_lib_log 2>&1 && \
# 		cd libraries/SDL2_image-2.0.5 && \
# 		./configure --prefix=$(shell pwd)/libraries --with-sdl-prefix=$(shell pwd)/libraries  > /dev/null 2>&1 && \
# 		$(MAKE)  > /dev/null 2>&1  &&  \
# 		$(MAKE) install > /dev/null 2>&1  && \
# 		cp ./SDL_image.h $(shell pwd)/libraries/include/SDL2 && \
# 		echo "${cyanclair}DONE${neutre}"; \
# 	fi

# ttf: freetype
# 	@if [ -d "./libraries/SDL2_ttf-2.0.15/" ]; then \
# 		echo "${cyanfonce}SDL2 Ttf already installed ...${neutre}\r"; \
# 	else \
# 		echo "${cyanfonce}Installing SDL2_ttf ...${neutre}\c" && \
# 		mkdir -p libraries && \
# 		curl -s https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.15.tar.gz -o libraries/SDL2_ttf-2.0.15.tar.gz >>./doom_lib_log 2>&1 && \
# 		tar -xf ./libraries/SDL2_ttf-2.0.15.tar.gz -C libraries >>./doom_lib_log 2>&1 && \
# 		cd libraries/SDL2_ttf-2.0.15 && \
# 		FT2_CONFIG=$(shell pwd)/libraries/bin/freetype-config ./configure --prefix=$(shell pwd)/libraries >>./doom_lib_log && \
# 		$(MAKE) >>./doom_lib_log 2>&1 && \
# 		$(MAKE) install >>./doom_lib_log 2>&1 && \
# 		echo "${cyanclair}DONE${neutre}"; \
# 	fi

# freetype: mixer
# 	@if [ -d "./libraries/freetype-2.4.11/" ]; then \
# 		echo "${cyanfonce}Freetype2 already installed ...${neutre}\r"; \
# 	else \
# 		echo "${cyanfonce}Installing freetype2 ...${neutre}\c" && \
# 		mkdir -p libraries && \
# 		tar -xf ./libraries/freetype-2.10.4.tar.xz -C libraries >>./doom_lib_log 2>&1 && \
# 		cd libraries/freetype-2.10.4 && \
# 		./configure --prefix=$(shell pwd)/libraries >>./doom_lib_log && \
# 		$(MAKE) >>./doom_lib_log 2>&1 && \
# 		$(MAKE) install >>./doom_lib_log 2>&1 && \
# 		echo "${cyanclair}DONE${neutre}"; \
# 	fi

# mixer:
# 	@if [ -d "./libraries/SDL2_mixer-2.0.4/" ]; then \
# 		echo "${cyanfonce}SDL2 Mixer already installed ...${neutre}\r"; \
# 	else \
# 		echo "${cyanfonce}Installing SDL2_mixer ...${neutre}\c" && \
# 		mkdir -p libraries && \
# 		curl -s https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.4.tar.gz -o libraries/SDL2_mixer-2.0.4.tar.gz >>./doom_lib_log 2>&1 && \
# 		tar -xf ./libraries/SDL2_mixer-2.0.4.tar.gz -C libraries >>./doom_lib_log 2>&1 && \
# 		cd libraries/SDL2_mixer-2.0.4 && \
# 		./configure --prefix=$(shell pwd)/libraries >>./doom_lib_log 2>&1 && \
# 		$(MAKE) >>./doom_lib_log 2>&1 && \
# 		$(MAKE) install >>./doom_lib_log 2>&1 && \
# 		echo "${cyanclair}DONE${neutre}"; \
# 	fi
clean:
			@/bin/rm -rf $(OBJ_PATH)
			@$(MAKE) -C $(LIB_PATH) clean
			@echo "${PURPLE}[.o deleted]${END}"

fclean:		clean
			@/bin/rm -rf $(NAME)
			@$(MAKE) -C $(LIB_PATH) fclean
			@echo "${RED}[$(NAME) deleted]${END}"
			@echo "${RED}[$(LIB) deleted]${END}"

re:			fclean all

fcleansdl:
	@/bin/rm -rf libraries
	@echo "${RED}[SDL files deleted]${END}"

resdl: fcleansdl all

.PHONY:		all clean fclean re resdl fcleansdl lib
