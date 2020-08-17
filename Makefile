# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amargy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/10 19:40:13 by amargy            #+#    #+#              #
#    Updated: 2020/03/10 19:40:15 by amargy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

CC = gcc
FLAGS = -O3
LIBRARIES = -L $(LIBFT_DIRECTORY) -lft
INCLUDES = -I $(HEADERS_DIRECTORY)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/

HEADERS_LIST = 	push_swap.h

HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./src/
SOURCES_LIST = 	check_arg.c			\
	check_exec_com.c				\
	chunk_operations.c				\
	create_data.c					\
	create_data2.c					\
	find_mid.c						\
	free_delete_data.c				\
	free_delete_data2.c				\
	move_chunks.c					\
	pars_arg.c						\
	quick_sorty.c					\
	ra_rb_rr.c						\
	sa_sb_rra_rrb_ss_rrr_pa_pb.c	\
	sort_two_and_three.c			\
	find_value_to_send_it.c			\

SOURCES_LIST_PS = push_swap_main.c
SOURCES_LIST_CH = checker_main.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
SOURCES_PS = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_PS))
SOURCES_CH = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_CH))

OBJECTS_DIRECTORY = obj/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_LIST_PS = $(patsubst %.c, %.o, $(SOURCES_LIST_PS))
OBJECTS_LIST_CH = $(patsubst %.c, %.o, $(SOURCES_LIST_CH))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))
OBJECTS_PS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_PS))
OBJECTS_CH = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_CH))

.PHONY: all clean fclean re

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(OBJECTS_PS) $(LIBRARIES) -o $(NAME_PS)

$(NAME_CH): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_CH)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(OBJECTS_CH) $(LIBRARIES) -o $(NAME_CH)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME_PS)
	@rm -f $(NAME_CH)

re:
	@$(MAKE) fclean
	@$(MAKE) all
	
