## Makefile for  in /home/maret_a/Projets/AbstractVM/cpp_abstractvm/sources
## 
## Made by Adrien Maret
## Login   <maret_a@epitech.net>
## 
## 
## Started on  19/02/2014 15:26
##

CXX	=	g++

SRCS	=	Chromosome.cpp \
		Crossover.cpp \
		Population.cpp \
		Matingpool.cpp \
		main.cpp \

CXXFLAGS=	-Wall -W -Wextra -Imuparser/include

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	genetics

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
