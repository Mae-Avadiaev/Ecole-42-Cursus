CC		:= gcc
CFLAGS		:=	-g -pthread -Wall -Wextra -Werror
NAME		:=	philo_bonus
SRCS_DIR	:=	srcs/
OBJS		:=	main.o	\
				main_funcs.o \
				ft_atoi.o \
				thread_func.o \
				philo_struct_init.o \
				utils.o \
				eat.o \
				kill_or_wait.o \
				ft_isdigit.o
				
OBJS		:=	$(addprefix ${SRCS_DIR}, ${OBJS})

deps 		:= $(patsubst %.o,%.d,$(OBJS))

all:		$(NAME)

$(NAME):	$(OBJS)
		gcc $(CFLAGS) $(OBJS) -o $(NAME)
		
-include $(deps)

DEPSFLAGS 	= -MMD -MF $(@:.o=.d)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPSFLAGS) -o $(<:.c=.o)

clean:
	rm -f $(OBJS) $(deps)
	

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
