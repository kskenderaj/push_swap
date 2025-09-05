# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kskender <kskender@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 18:29:18 by kskender          #+#    #+#              #
#    Updated: 2025/05/29 16:38:08 by kskender         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := push_swap
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
INCD := include
SRCD := src
OBJD := obj
LIBFT_DIR := $(INCD)/libft
LIBFT := $(LIBFT_DIR)/libft.a

# Colors
GREEN := \033[0;32m
YELLOW := \033[0;33m
RED := \033[0;31m
NC := \033[0m # No Color

SRCS =  $(SRCD)/error_handling.c \
		$(SRCD)/main.c \
		$(SRCD)/rotate_operators.c \
        $(SRCD)/sort_small.c \
		$(SRCD)/swap_operators.c \
		$(SRCD)/ft_atol.c \
		$(SRCD)/parsing.c \
        $(SRCD)/reverse_rotate_operators.c \
		$(SRCD)/sort_big.c \
		$(SRCD)/stack_utils.c \
		$(SRCD)/push_operators.c \
		$(SRCD)/sort_small_utils.c\

OBJS := $(SRCS:$(SRCD)/%.c=$(OBJD)/%.o)

all: $(NAME)

$(LIBFT):
	@printf "$(YELLOW)Building libft library...$(NC)\n"
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJD)/%.o: $(SRCD)/%.c|  $(OBJD)
	@printf "$(YELLOW)Compiling $<...$(NC)\n"
	@$(CC) $(CFLAGS) -I $(INCD) -c $< -o $@
	@printf "$(GREEN)Compiled $< successfully!$(NC)\n"

$(OBJD):
	mkdir -p $(OBJD)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@printf "$(GREEN)Executable $(NAME) built successfully!$(NC)\n"

clean:
	@printf "$(RED)Cleaning object files...$(NC)\n"
	rm -rf $(OBJD)
	@printf "$(GREEN)Object files cleaned!$(NC)\n"
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@printf "$(RED)Cleaning library and executable...$(NC)\n"
	rm -f $(NAME)
	@printf "$(GREEN)Executable cleaned!$(NC)\n"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re