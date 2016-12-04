#include <algorithm>
#include <vector>
#include "../Matrix/matrix.hh"
#include "../Compute/compute_func.hh"
#include "../Pkmn/pkmn.hh"
#include "../Team/team.hh"
#include "game_state.hh"

int heuristic_val(GameState gs)
{
   return gs.hp_left_get();
}

int minimax (GameState node, int depth, bool max, Matrix& m,
             Team atq, Team def, std::string& path, int max_depth)
{
   if (depth == max_depth)
      return heuristic_val(node);
   if (node.is_over())
      return heuristic_val(node);
   if (max)
   {
      int best = -1000000;
      for (int i = 0; i < 4; i++)
      {
         Team at = atq;
         Team de = def;
         Pkmn p1 = *((at.v_get()).begin());
         Pkmn p2 = *((de.v_get()).begin());
         switch (i)
         {
            case 0:
            {
               cmp_atk(p1, p2, path, p1.mvset_one_get(), m);
               if (p2.hp_get() <= 0)
               {
                  de.pkmn_ko();
               }
               GameState gs1(de);
               int v = minimax(gs1, depth + 1, false, m, de, at, path, max_depth);
               best = std::max(v, best);
               break;
            }
            case 1:
            {
               cmp_atk(p1, p2, path, p1.mvset_two_get(), m);
               if (p2.hp_get() <= 0)
               {
                  de.pkmn_ko();
               }
               GameState gs2(de);
               int v = minimax(gs2, depth + 1, false, m, de, at, path, max_depth);
               best = std::max(v, best);
               break;
            }
            case 2:
            {
               cmp_atk(p1, p2, path, p1.mvset_three_get(), m);
               if (p2.hp_get() <= 0)
               {
                  de.pkmn_ko();
               }
               GameState gs3(de);
               int v = minimax(gs3, depth + 1, false, m, de, at, path, max_depth);
               best = std::max(v, best);
               break;
            }
            case 3:
            {
               cmp_atk(p1, p2, path, p1.mvset_four_get(), m);
               if (p2.hp_get() <= 0)
               {
                  de.pkmn_ko();
               }
               GameState gs4(de);
               int v = minimax(gs4, depth + 1, false, m, de, at, path, max_depth);
               best = std::max(v, best);
               break;
            }
         }
      }
      return best;
   }
   
   else
   {
      int best = 1000000;
      for (int i = 0; i < 4; i++)
      {
         Team at = atq;
         Team de = def;
         Pkmn p1 = *((at.v_get()).begin());
         Pkmn p2 = *((de.v_get()).begin());
         switch (i)
         {
            case 0:
            {
               cmp_atk(p1, p2, path, p1.mvset_one_get(), m);
               if (p2.hp_get() <= 0)
               {
                  de.pkmn_ko();
               }
               GameState gs1(de);
               int v = minimax(gs1, depth + 1, true, m, de, at, path, max_depth);
               best = std::min(v, best);
               break;
            }
            case 1:
            {
               cmp_atk(p1, p2, path, p1.mvset_two_get(), m);
               if (p2.hp_get() <= 0)
               {
                  de.pkmn_ko();
               }
               GameState gs2(de);
               int v = minimax(gs2, depth + 1, true, m, de, at, path, max_depth);
               best = std::min(v, best);
               break;
            }
            case 2:
            {
               cmp_atk(p1, p2, path, p1.mvset_three_get(), m);
               if (p2.hp_get() <= 0)
               {
                  de.pkmn_ko();
               }
               GameState gs3(de);
               int v = minimax(gs3, depth + 1, true, m, de, at, path, max_depth);
               best = std::min(v, best);
               break;
            }
            case 3:
            {
               cmp_atk(p1, p2, path, p1.mvset_four_get(), m);
               if (p2.hp_get() <= 0)
               {
                  de.pkmn_ko();
               }
               GameState gs4(de);
               int v = minimax(gs4, depth + 1, true, m, de, at, path, max_depth);
               best = std::min(v, best);
               break;
            }
         }
      }
      return best;
   }
}

int id_best_move(Team atq, Team def, Matrix& m,
                 std::string& path, int max_depth)
{
   GameState gs(atq);
   int move = minimax(gs, 0, false, m, atq, def, path, max_depth);
   for (int i = 0; i < 4; i++)
   {
      Team at = atq;
      Team de = def;
      Pkmn p1 = *((at.v_get()).begin());
      Pkmn p2 = *((de.v_get()).begin());
      switch (i)
      {
         case 0:
         {
            cmp_atk(p1, p2, path, p1.mvset_one_get(), m);
            if (p2.hp_get() <= 0)
               de.pkmn_ko();
            GameState gs1(de);
            if (gs1.hp_left_get() == move)
               return p1.mvset_one_get();
            break;
         }
         case 1:
         {
            cmp_atk(p1, p2, path, p1.mvset_two_get(), m);
            if (p2.hp_get() <= 0)
               de.pkmn_ko();
            GameState gs2(de);
            if (gs2.hp_left_get() == move)
               return p1.mvset_two_get();
            break;
         }
         case 2:
         {
            cmp_atk(p1, p2, path, p1.mvset_three_get(), m);
            if (p2.hp_get() <= 0)
               de.pkmn_ko();
            GameState gs3(de);
            if (gs3.hp_left_get() == move)
               return p1.mvset_three_get();
            break;
         }
         case 3:
         {
            cmp_atk(p1, p2, path, p1.mvset_four_get(), m);
            if (p2.hp_get() <= 0)
               de.pkmn_ko();
            GameState gs4(de);
            if (gs4.hp_left_get() == move)
               return p1.mvset_four_get();
            break;
         }
      }
   }
   return (*((atq.v_get()).begin())).mvset_three_get();
}
