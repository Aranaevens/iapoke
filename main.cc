#include "Options/options.hh"
#include "Pkmn/pkmn.hh"
#include "Minimax/minimax.hh"
#include "Compute/compute_func.hh"
#include "Team/team.hh"
#include "network-api/client-network-api.hh"
#include <iostream>

int main(int argc, char *argv[])
{
   Options opt(argv);
   ClientNetworkAPI serv(opt.ip_get(), opt.port_get());
   serv.acknowledge("eisenb_n");
   Matrix m(14, 14);
   m.parse_csv(opt.types_get());
   auto own_p = serv.get_own_pokemons();
   auto opp_p = serv.get_opponent_pokemons();
   Team own(own_p, opt.pokemons_get());
   Team opponent(opp_p, opt.pokemons_get());
   while (own.is_out() == false && opponent.is_out() == false)
   {
      Pkmn& poke_own = (own.v_get()).begin();
      Pkmn& poke_opp = (opponent.v_get()).begin();
      if (poke_own.spd_get() > poke_opp.spd_get())
      {
         while (poke_own.hp_get() > 0 && poke_opp.hp_get() > 0)
         {
            int attack = id_best_move(own, opponent, m, opt.attack_get(), 9);
            serv.transfer_attack(attack);
            cmp_atk(poke_own, poke_opp, opt.attacks_get(), attack, m);
            if (poke_opp.hp_get() > 0)
            {
               auto opp_atk = std::atoi(serv.get_opponent_attack().c_str());
               cmp_atk(poke_opp, poke_own, opt.attacks_get(), opp_atk, m);
            }
            else
               opponent.pkmn_ko();
            if (poke_own.hp_get() <= 0)
               own.pkmn_ko();
         }
      }
      else if (poke_own.spd_get() < poke_opp.spd_get())
      {
         while (poke_own.hp_get() > 0 && poke_opp.hp_get() > 0)
         {
            auto opp_atk = std::atoi(serv.get_opponent_attack().c_str());
            cmp_atk(poke_opp, poke_own, opt.attacks_get(), opp_atk, m);
            if (poke_own.hp_get() > 0)
            {
               int attack = id_best_move(own, opponent, m, opt.attack_get(), 9);
               serv.transfer_attack(attack);
               cmp_atk(poke_opp, poke_own, opt.attacks_get(), attack, m);
            }
            else
               own.pkmn_ko();
            if (poke_opp.hp_get() <= 0)
               opponent.pkmn_ko();
         }
      }
      else
      {
         while (poke_own.hp_get() > 0 && poke_opp.hp_get() > 0)
         {
            int attack = id_best_move(own, opponent, m, opt.attack_get(), 9);
            serv.transfer_attack(attack);
            cmp_atk(poke_own, poke_opp, opt.attacks_get(), attack, m);
            auto opp_atk = std::atoi(serv.get_opponent_attack().c_str());
            cmp_atk(poke_opp, poke_own, opt.attacks_get(), opp_atk, m);
            if (poke_own.hp_get() <= 0)
               own.pkmn_ko();
            if (poke_opp.hp_get() <= 0)
               opponent.pkmn_ko();
         }
      }
   }
}
