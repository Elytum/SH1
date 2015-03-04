# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by achazal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -O3 -g
#--------------Name-------------------------#
NAME = ft_minishell1

#--------------Sources----------------------#
FILES_CORE =	main.c	\
	ft_dup_environ.c	\
	ft_exec_bin.c		\
	ft_parse_input.c	\
	ft_get_args.c		\
	ft_cd.c				\
	ft_cd2.c			\
	ft_editenv.c		\
	ft_envtools.c		\
	ft_envtools2.c		\
	ft_tools.c

FILES_INPUTS =	ft_arrows.c	\
	ft_arrows2.c			\
	ft_special.c			\
	ft_charmanage.c			\
	ft_cursor.c				\
	ft_delete.c				\
	ft_env.c				\
	ft_imputs.c				\
	ft_clean.c				\
	ft_lstrmanage.c			\
	ft_managechar.c			\
	ft_put.c				\
	ft_moves.c

FILES_SIGNALS =	ft_init.c

OBJECT =	$(patsubst %.c,%.o,$(FILES_CORE))	\
			$(patsubst %.c,%.o,$(FILES_INPUTS))	\
			$(patsubst %.c,%.o,$(FILES_SIGNALS))
BASEDIR_CORE = srcs/core
BASEDIR_INPUTS = srcs/inputs
BASEDIR_SIGNALS = srcs/signals

CURRENT_DIR = $(shell pwd)/$(NAME)
#--------------Actions----------------------#

all:$(NAME)

$(NAME):
	@make -C includes/libft
	@$(CC) -c $(CFLAGS)	$(addprefix $(BASEDIR_CORE)/, $(FILES_CORE)) \
						$(addprefix $(BASEDIR_INPUTS)/, $(FILES_INPUTS)) \
						$(addprefix $(BASEDIR_SIGNALS)/, $(FILES_SIGNALS))
	@$(CC) -o $(NAME) $(OBJECT) -L ./includes/libft -l ft -L /usr/lib -ltermcap
	@bash -c "sh setIcon.sh icon/gladosh_icon.png ft_minishell1"
	@bash -c "touch auteur && echo \"achazal\" > auteur"
	@bash -c "sh setIcon.sh icon/auteur_icon.png auteur"
	echo $(CURRENT_DIR)

clean :
		rm -Rf $(OBJECT)

fclean: clean
		rm -Rf $(NAME)

re: fclean all

.PHONY: all, fclean, clean, re 
