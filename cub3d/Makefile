CC		:= gcc
CFLAGS		:= -Wall -Wextra -Werror
NAME		:= cub3D
SRCS_DIR	:= srcs/
MAIN_DIR	:= main/
ENGINE_DIR	:= engine/
PARSER_DIR	:= parser/
OTHERS_DIR	:= others/
OBJS		:= \
			${MAIN_DIR}main.o \
			${MAIN_DIR}main_utils.o \
			\
			${ENGINE_DIR}engine.o \
			${ENGINE_DIR}move_utils.o \
			${ENGINE_DIR}cast_rays_utils.o \
			${ENGINE_DIR}cast_rays_utils2.o \
			${ENGINE_DIR}sort_sprites.o \
			${ENGINE_DIR}cast_sprites_utils.o \
			\
			${PARSER_DIR}parser.o \
			${PARSER_DIR}parser_utils.o \
			${PARSER_DIR}parser_utils2.o \
			${PARSER_DIR}map_validator.o \
			${PARSER_DIR}parametr_validators.o \
			${PARSER_DIR}r_no_so_we_ea_checkers.o \
			${PARSER_DIR}s_c_f_checkers.o \
 			\
			${OTHERS_DIR}initializer.o \
			${OTHERS_DIR}initializer2.o \
			${OTHERS_DIR}bitmap.o \
			${OTHERS_DIR}mlx_utils.o \
			${OTHERS_DIR}all_utils_and_extras.o \

OBJS := 		$(addprefix ${SRCS_DIR}, ${OBJS})


deps 		:= $(patsubst %.o,%.d,$(OBJS))

all:		$(NAME)

$(NAME):	$(OBJS)
		cd Libft/ && make && make clean
		cd mlx/ && make && mv libmlx.dylib .. && make clean
		gcc $(CFLAGS) $? -o $(NAME) -LLibft/ -lft -L. -lmlx -framework OpenGL -framework Appkit


-include $(deps)

DEPSFLAGS 	= -MMD -MF $(@:.o=.d)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPSFLAGS) -O2 -o $(<:.c=.o)

clean:
	rm -f $(OBJS) $(deps)
	

fclean: clean 
	rm -f $(NAME)
	cd Libft/ && make fclean
	rm -f libmlx.dylib

re: fclean all

.PHONY: all, clean, fclean, re
