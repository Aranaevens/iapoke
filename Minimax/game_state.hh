#pragma once

#include "../Matrix/matrix.hh"
#include "../Pkmn/pkmn.hh"
#include "../Attack/attack.hh"
#include "../Team/team.hh"
#include "../Compute/compute_func.hh"

class GameState
{
public:
   GameState(Team t);
   ~GameState();

   bool is_over() const;
   int hp_left_get() const;

private:
   int pk_left_;
   int hp_left_;
};
