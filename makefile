CCC = g++
CCFlags = -std=c++0x -Wall -g -pedantic
NAME = MealCounter.x
INCLUDES = -I.

all: clean test

clean:
	rm -f ~.o *~
test:
	$(CCC) $(CCFlags) -o $(NAME) mealCounter.cpp
run:
	./$(NAME)
