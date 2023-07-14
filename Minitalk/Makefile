# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seroy <seroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 14:22:44 by seroy             #+#    #+#              #
#    Updated: 2023/07/14 15:48:13 by seroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#Library Name ----------------------------

NAME = server
NAME2 = client

#Dependencies -----------------------------

LIBFT = libft

#Command variables ------------------------

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MK = mkdir -p
RM = rm -rf
USER = $(shell whoami)

#Sources directories

INCDIR = inc
SRCDIR = src
SRCDIR2 = src2
LIBFT_A = libft.a
LIBFTDIR = libft
LIBFT = $(addprefix $(LIBFTDIR)/, $(LIBFT_A))
SRC = server.c
SRC2 = client.c
		
VPATH = ${SRCDIR} ${SRCDIR2}

#Object directories

OBJDIR = obj

OBJDIR2 = obj2

OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})

OBJS2 = $(addprefix ${OBJDIR2}/, ${SRC2:%.c=%.o})

${OBJDIR}/%.o : %.c
	${CC} ${FLAGS} -I${INCDIR} -Ilibft/inc -c $< -o $@ 

${OBJDIR2}/%.o : %.c
	${CC} ${FLAGS} -I${INCDIR} -Ilibft/inc -c $< -o $@ 
	
all: $(NAME) $(NAME2)

$(NAME): $(OBJDIR) $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) ${FLAGS} $(OBJS) -L$(dir $(LIBFT)) -lft -o $(NAME)

$(NAME2): $(OBJDIR2) $(OBJS2)
	make -C $(LIBFTDIR)
	$(CC) ${FLAGS} $(OBJS2) -L$(dir $(LIBFT)) -lft -o $(NAME2)

$(OBJDIR):
	$(MK) $(OBJDIR)

$(OBJDIR2):
	$(MK) $(OBJDIR2)

clean:
	$(RM) $(OBJDIR) $(OBJDIR2)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME2)
	make -C $(LIBFTDIR) fclean

re: fclean all