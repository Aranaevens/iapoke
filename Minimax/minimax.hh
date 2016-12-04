#pragma once

#include "../Matrix/matrix.hh"
#include "../Pkmn/pkmn.hh"
#include "../Team/team.hh"
#include "game_state.hh"


int heuristic_val(GameState gs);
int minimax (GameState node, int depth, bool max, Matrix& m,
             Team atq, Team def, std::string& path, int max_depth);
int id_best_move(Team atq, Team def, Matrix& m,
                 std::string& path, int max_depth);
