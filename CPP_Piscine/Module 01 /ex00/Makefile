CPP			:=	clang++
CPPFLAGS	:=	-std=c++98 -g -Wall -Wextra -Werror
NAME		:=	zombies
SRCS		:=	main.cpp \
				Zombie.cpp \
				newZombie.cpp \
				randomChump.cpp \


OBJS		=	$(subst .cpp,.o,$(SRCS))

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< 

clean:
	rm -f $(OBJS)
	

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
