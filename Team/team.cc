#include <vector>
#include <sstream>

#include "team.hh"
#include "../Pkmn/pkmn.hh"

Team::Team(const std::string& poke, std::string& path)
   : v_(std::vector<Pkmn>())
{
   std::istringstream in(poke);
   std::string token;
   while (std::getline(in, token, ' '))
   {
      std::istringstream in_in(token);
      std::string item;
      Pkmn p;
      for (int n = 0; n < 2; n++)
      {
         std::getline(in_in, item, ':');
         if (n == 0)
         {
            Pkmn p2(path, std::atoi(item.c_str()));
            p = p2;
         }
         if (n == 1)
         {
            p.level_set(std::atoi(item.c_str()), 256, 7);
         }
      }
      v_.push_back(p);
   }
}

Team::~Team()
{}

bool Team::is_out() const
{
   if (v_.size() == 0)
      return true;
   else
      return false;
}

void Team::pkmn_ko()
{
   v_.erase(v_.begin());
}

std::vector<Pkmn> Team::v_get() const
{
   return v_;
}
