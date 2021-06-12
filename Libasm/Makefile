CC		:= gcc
CFLAGS		:= -Wall -Wextra -Werror
NAME		:= libasm.a
SRCS		:= ft_strlen.s ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_write.s
OBJS		:= $(SRCS:.s=.o)
NASMFLAGS	:= -fmacho64

all: $(NAME)

$(NAME): $(OBJS) 
	ar -rcs $@ $^

%.o: %.s
	nasm $(NASMFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
