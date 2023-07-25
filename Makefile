# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seroy <seroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 14:22:44 by seroy             #+#    #+#              #
#    Updated: 2023/07/25 08:46:10 by seroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#Library Name ----------------------------

NAME = server
NAME2 = client
NAME_BONUS = server_bonus
NAME_BONUS2 = client_bonus

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
SRCDIRB = srcb
SRCDIRB2 = srcb2
LIBFT_A = libft.a
LIBFTDIR = libft
LIBFT = $(addprefix $(LIBFTDIR)/, $(LIBFT_A))
SRC = server.c utils.c
SRC2 = client.c
SRCB = server_bonus.c utils_bonus.c
SRCB2 = client_bonus.c
		
VPATH = ${SRCDIR} ${SRCDIR2} ${SRCDIRB} ${SRCDIRB2}

#Object directories

OBJDIR = obj

OBJDIR2 = obj2

OBJDIRB = objb

OBJDIRB2 = objb2

OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})

OBJS2 = $(addprefix ${OBJDIR2}/, ${SRC2:%.c=%.o})

OBJSB = $(addprefix ${OBJDIRB}/, ${SRCB:%.c=%.o})

OBJSB2 = $(addprefix ${OBJDIRB2}/, ${SRCB2:%.c=%.o})

${OBJDIR}/%.o : %.c
	${CC} ${FLAGS} -I${INCDIR} -Ilibft/inc -c $< -o $@ 

${OBJDIR2}/%.o : %.c
	${CC} ${FLAGS} -I${INCDIR} -Ilibft/inc -c $< -o $@ 

${OBJDIRB}/%.o : %.c
	${CC} ${FLAGS} -I${INCDIR} -Ilibft/inc -c $< -o $@

${OBJDIRB2}/%.o : %.c
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

$(NAME_BONUS): $(OBJDIRB) $(OBJSB)
	make -C $(LIBFTDIR)
	$(CC) $(FLAGS) $(OBJSB) -L$(dir $(LIBFT)) -lft -o $(NAME_BONUS)

$(NAME_BONUS2): $(OBJDIRB2) $(OBJSB2)
	make -C $(LIBFTDIR)
	$(CC) $(FLAGS) $(OBJSB2) -L$(dir $(LIBFT)) -lft -o $(NAME_BONUS2)
	
$(OBJDIRB):
	$(MK) $(OBJDIRB)

$(OBJDIRB2):
	$(MK) $(OBJDIRB2)

bonus: $(NAME_BONUS) $(NAME_BONUS2)

clean:
	$(RM) $(OBJDIR) $(OBJDIR2) $(OBJDIRB) $(OBJDIRB2)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME2) $(NAME_BONUS) $(NAME_BONUS2)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY:
	fclean re bonus all