CC		:= gcc
CFLAGS		:= -Wall -Wextra -Werror
NAME		:= libft.a
OBJS		:= ft_memset.o ft_memccpy.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o ft_strlcpy.o ft_strlcat.o ft_strrchr.o ft_strncmp.o ft_strnstr.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_strchr.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_strmapi.o ft_itoa.o ft_split.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o get_next_line.o ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

all: $(NAME)

$(NAME): $(OBJS) 
	ar -rc $@ $^

deps := $(patsubst %.o,%.d,$(OBJS))
-include $(deps)
bonus_deps := $(patsubst %.o,%.d,$(BONUS_OBJS))
-include $(bonus_deps)
DEPSFLAGS = -MMD -MF $(@:.o=.d)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPSFLAGS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(deps) $(bonus_deps)

fclean: clean 
	rm -f $(NAME)
re: fclean all

bonus: $(BONUS_OBJS)
	ar -rc $(NAME) $^

.PHONY: all, clean, fclean, re
