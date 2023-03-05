# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 14:39:21 by ayakoubi          #+#    #+#              #
#    Updated: 2023/03/05 11:58:44 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	push_swap
INC	=	inc
BNS		=	checker
SRC	=	push_swap.c imp_stack.c sort.c handling_err.c utils_stack.c utils.c\
		push_ab.c swap_stack.c retate.c reverse_retate.c \

OBJDIR	= obj
_OBJ	=	$(SRC:.c=.o)
OBJ		=	$(patsubst %,$(OBJDIR)/%,$(_OBJ))

B_SRC	=	checker.c \
		imp_stack.c sort.c handling_err.c utils_stack.c utils.c\
		push_ab.c swap_stack.c retate.c reverse_retate.c \

_B_OBJ	= $(B_SRC:.c=.o)
B_OBJ	=	$(patsubst %,$(OBJDIR)/%, $(_B_OBJ))

C_LIBFT		=	make -C libft
AR_LIBFT	=	libft/libft.a

C_GNL		=	make -C gnl
AR_GNL		=	gnl/get_next_line

CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror

#########################
#	colors		#
#########################

GREEN	= \033[0;32m
RED 	= \033[0;31m
C_END	= \033[0m
BOLD	= \x1b[1m
B_END	= \x1b[0m

all		:	$(NAME)

$(OBJDIR)/%.o: src/%.c
	@echo "Compiling >>>>>> $^"
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -I $(INC) -o $@

$(NAME)	:	$(OBJ)
	@$(C_LIBFT)
	@$(CC) $(CFLAGS) $^ $(AR_LIBFT) -I $(INC) -o $@
	@echo "	 $(GREEN) $(BOLD) <<<<<< Done successful! >>>>>>$(B_END) $(C_END)"

bonus:	$(BNS)

$(BNS):	$(B_OBJ)
	@$(C_GNL)
	@$(C_LIBFT)
	@$(CC) $(CFLAGS) $^ $(AR_LIBFT) $(AR_GNL) -I $(INC) -o $@
	@echo "	 $(GREEN) $(BOLD) <<<<<< Done successful! >>>>>>$(B_END) $(C_END)"

clean	:
	@echo "$(RED)$(BOLD)removed objects$(B_END)$(C_END)"
	@$(C_LIBFT) clean
	@$(C_GNL) clean
	@rm -rf $(OBJDIR)

fclean	:	clean
	@rm -rf $(NAME)
	@rm -rf checker
	@$(C_LIBFT) fclean
	@$(C_GNL) fclean
	@echo "$(RED)$(BOLD)removed executable $(B_END)$(C_END)"

re		:	fclean all

.PHONY	:	all clean fclean re
