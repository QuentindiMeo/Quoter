##
## PERSONAL PROJECT, 2020
## quoter
## File description:
## Makefile
##

SRC	=	src/Tools.cpp	\
		src/Listing.cpp	\
		src/Format.cpp	\
		src/Display.cpp	\
		src/Seeking.cpp	\
		src/Core.cpp	\
		src/Setup.cpp	\
		src/Help.cpp	\
		src/Quoter.cpp	\

OBJ	=	$(SRC:.cpp=.o)

INCLUDE	=	include/

CC	=	@g++

CFLAGS	=	-Wall -Werror -Wreorder -Wextra --pedantic

NAME	=	quoter

RGDG	=	quoter.sav

CPPFLAGS	=	-I $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME) $(RGDG)
	@echo Cleaned \'$(NAME)\'

re: fclean all

.PHONY: clean fclean re quoter
