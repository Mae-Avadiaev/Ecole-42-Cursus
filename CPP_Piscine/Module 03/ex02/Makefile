CPP			:=	clang++
CPPFLAGS	:=	-std=c++98 -g -MMD -Wall -Wextra -Werror
NAME		:=	a.out
SRCS		:=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp

OBJS		=	$(subst .cpp,.o,$(SRCS))
D_FILES		=	$(subst .cpp,.d,$(SRCS))

all:		$(NAME)

-include $(D_FILES)

$(NAME):	$(OBJS)
		$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< 

clean:
	rm -f $(OBJS) $(D_FILES)
	

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re


