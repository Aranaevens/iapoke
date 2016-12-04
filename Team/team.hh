#pragma once

#include <vector>
#include "../Pkmn/pkmn.hh"

class Team
{
public:
   Team(const std::string& poke, std::string& path);
   ~Team();

   bool is_out() const;
   void pkmn_ko();
   std::vector<Pkmn> v_get() const;

private:
   std::vector<Pkmn> v_;
};
