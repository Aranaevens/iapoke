CXX= g++
CXXFLAGS= -Werror -Wextra -Wall -pedantic -std=c++14

ATQSRC= src/Attack/attack.cc
COMPSRC= src/Compute/compute_func.cc
MATSRC= src/Matrix/matrix.cc
MMAXSRC= src/Minimax/minimax.cc src/Minimax/game_state.cc
OPTSRC= src/Options/options.cc
PKMNSRC= src/Pkmn/pkmn.cc
TEAMSRC= src/Team/team.cc

SRC= $(ATQSRC) $(COMPSRC) $(MATSRC) $(MMAXSRC) $(OPTSRC) $(PKMNSRC) $(TEAMSRC)
SRCOBJ= $(SRC:.cc=.o)
MAIN= src/main.cc

NAME= epifight

all: $(SRCOBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:
	rm $(SRCOBJ)

.PHONY: all clean
