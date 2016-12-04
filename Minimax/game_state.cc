#include "game_state.hh"

GameState::GameState(Team t)
   : pk_left_(0)
   , hp_left_(0)
{
   pk_left_ = (t.v_get()).size();
   int hp_left = 0;
   for (auto it : t.v_get())
   {
      hp_left += it.hp_get();
   }
   hp_left_ = hp_left;
}

GameState::~GameState()
{}

bool GameState::is_over() const
{
   if (hp_left_ <= 0)
      return true;
   else
      return false;
}

int GameState::hp_left_get() const
{
   return hp_left_;
}
