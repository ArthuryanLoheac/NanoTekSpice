##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for program compilation
##

.PHONY: all clean fclean re unit_tests tests_run

NAME = nanotekspice

SRC	=	src/Parsing/Parse.cpp \
		src/Parsing/Parsing.cpp	\
		src/Run/Run.cpp	\
		src/Abstract/AComponent.cpp	\
		src/Abstract/AInput.cpp	\
		src/Abstract/ASingle.cpp \
		src/Abstract/AFourGates.cpp	\
		src/Component/Input/ComponentInput.cpp	\
		src/Component/Input/ComponentTrue.cpp	\
		src/Component/Input/ComponentFalse.cpp	\
		src/Component/Input/ComponentClock.cpp	\
		src/Component/Single/ComponentAnd.cpp	\
		src/Component/Single/ComponentNand.cpp	\
		src/Component/Single/ComponentNor.cpp	\
		src/Component/Single/ComponentOr.cpp	\
		src/Component/Single/ComponentXor.cpp	\
		src/Component/FourGates/Component4001.cpp	\
		src/Component/FourGates/Component4011.cpp	\
		src/Component/FourGates/Component4030.cpp	\
		src/Component/FourGates/Component4071.cpp	\
		src/Component/FourGates/Component4081.cpp	\
		src/Component/Advanced/4008/Component4008.cpp	\
		src/Component/Advanced/4008/ComponentCo.cpp	\
		src/Component/Advanced/4008/ComponentSum_l.cpp	\
		src/Component/Advanced/4008/ComponentSum.cpp	\
		src/Component/Other/ComponentOutput.cpp	\
		src/Component/Other/ComponentNot.cpp	\
		src/Component/Other/Component4069.cpp	\
		src/Component/Other/Circuit.cpp	\
		src/Factory/ComponentFactory.cpp \


TEST_FILES =	tests/Parsing/TestsParsing.cpp \
				tests/Component/Input/TestsComponentInput.cpp \
				tests/Component/Input/TestsComponentTrue.cpp \
				tests/Component/Input/TestsComponentFalse.cpp \
				tests/Component/Input/TestsComponentClock.cpp \
				tests/Component/Single/TestsComponentAnd.cpp \
				tests/Component/Single/TestsComponentNand.cpp \
				tests/Component/Single/TestsComponentNor.cpp \
				tests/Component/Single/TestsComponentOr.cpp \
				tests/Component/Single/TestsComponentXor.cpp \
				tests/Component/FourGates/TestsComponent4001.cpp \
				tests/Component/FourGates/TestsComponent4011.cpp \
				tests/Component/FourGates/TestsComponent4030.cpp \
				tests/Component/FourGates/TestsComponent4071.cpp \
				tests/Component/FourGates/TestsComponent4081.cpp \
				tests/Component/Advanced/TestsComponentSum.cpp \
				tests/Component/Other/TestsComponentOutput.cpp \
				tests/Component/Other/TestsComponentNot.cpp \
				tests/Component/Other/TestsComponent4069.cpp \
				tests/Component/Other/TestsComponentCircuit.cpp \
				tests/Factory/TestsComponentFactory.cpp \

INCLUDE = 	-I./include \
			-I./include/Interface \
			-I./include/Abstract \
			-I./include/Component/Input \
			-I./include/Component/Single \
			-I./include/Component/FourGates \
			-I./include/Component/Advanced/4008 \
			-I./include/Component/Other \
			-I./include/Factory \
			-I./include/Parsing \
			-I./include/Run \

OBJ	= $(SRC:.cpp=.o)

CC = g++ -g

CPPFLAGS = -std=c++20 -Wall -Wextra -Werror $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) Main.cpp

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests

re: fclean all

unit_tests: fclean
	$(CC) -o unit_tests $(SRC) $(TEST_FILES) \
	--coverage -lcriterion $(INCLUDE)

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/ --exclude include/
