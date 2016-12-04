#pragma once

#include <string>
#include <algorithm>

class Pkmn
{
public:
   Pkmn();
   ~Pkmn();
   Pkmn(const Pkmn& p);
   Pkmn(std::string& path, int i);
   Pkmn& operator=(const Pkmn& p);
   int id_get() const;
   int level_get() const;
   std::string name_get() const;
   std::string type_get() const;
   int hp_get() const;
   int hp_max_get() const;
   int atk_get() const;
   int def_get() const;
   int spatk_get() const;
   int spdef_get() const;
   int spd_get() const;
   int mvset_one_get() const;
   int mvset_two_get() const;
   int mvset_three_get() const;
   int mvset_four_get() const;

   void id_set(int i);
   void name_set(std::string& s);
   void type_set(std::string& s);
   void hp_set(int i);
   void hp_max_set(int i);
   void atk_set(int i);
   void def_set(int i);
   void spatk_set(int i);
   void spdef_set(int i);
   void spd_set(int i);
   void mvset_one_set(int i);
   void mvset_two_set(int i);
   void mvset_three_set(int i);
   void mvset_four_set(int i);

   void level_set(int level, int EV = 256, int IV = 7);
   void parse_pkmn(std::string& path, int i);

protected:
   int id_;
   int level_;
   std::string name_;
   std::string type_;
   int hp_;
   int hp_max_;
   int atk_;
   int def_;
   int spatk_;
   int spdef_;
   int spd_;
   int mvset_one_;
   int mvset_two_;
   int mvset_three_;
   int mvset_four_;
};
