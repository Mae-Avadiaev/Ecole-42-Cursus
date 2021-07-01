CC		:= gcc
CFLAGS		:= -Wall -Wextra -Werror
NAME		:= libftprintf.a
OBJS		:= ft_printf.o mod_ft_putchar_fd.o mod_ft_putnbr_fd.o mod_ft_putnbr_hex_low_fd.o mod_ft_putstr_fd.o mod_ft_putnbr_hex_up_fd.o mod_ft_putptr_fd.o ft_put_d.o ft_put_s.o ft_put_c.o ft_put_u.o ft_put_x.o ft_itoa_uns.o ft_put_x_up.o ft_put_p.o parse_sp.o

all: ft_printf

ft_printf: $(OBJS)
	cd libft/ && make && mv libft.a ../ 
	ar -rc libft.a $(OBJS)  
	mv libft.a $(NAME)

deps := $(patsubst %.o,%.d,$(OBJS))
-include $(deps)

DEPSFLAGS = -MMD -MF $(@:.o=.d)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPSFLAGS)  

clean:
	rm -f $(OBJS) $(deps)
	cd libft/ && make fclean

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
