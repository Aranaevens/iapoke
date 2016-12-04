#include "pkmn.hh"

#include <sstream>
#include <fstream>

Pkmn::Pkmn()
   : id_(1)
   , level_(1)
   , name_("Bulbasaur")
   , type_("GRASS")
   , hp_(45)
   , hp_max_(45)
   , atk_(49)
   , def_(49)
   , spatk_(65)
   , spdef_(65)
   , spd_(45)
   , mvset_one_(1)
   , mvset_two_(2)
   , mvset_three_(3)
   , mvset_four_(4)
{}

Pkmn::Pkmn(const Pkmn& p)
   : id_(p.id_get())
   , level_(p.level_get())
   , name_(p.name_get())
   , type_(p.type_get())
   , hp_(p.hp_get())
   , hp_max_(p.hp_max_get())
   , atk_(p.atk_get())
   , def_(p.atk_get())
   , spatk_(p.spatk_get())
   , spdef_(p.spdef_get())
   , spd_(p.spd_get())
   , mvset_one_(p.mvset_one_get())
   , mvset_two_(p.mvset_two_get())
   , mvset_three_(p.mvset_three_get())
   , mvset_four_(p.mvset_four_get())
{}

Pkmn& Pkmn::operator=(const Pkmn& p)
{
   id_ = p.id_get();
   level_ = p.level_get();
   name_ = p.name_get();
   type_ = p.type_get();
   hp_ = p.hp_get();
   hp_max_ = p.hp_max_get();
   atk_ = p.atk_get();
   def_ = p.atk_get();
   spatk_ = p.spatk_get();
   spdef_ = p.spdef_get();
   spd_ = p.spd_get();
   mvset_one_ = p.mvset_one_get();
   mvset_two_ = p.mvset_two_get();
   mvset_three_ = p.mvset_three_get();
   mvset_four_ = p.mvset_four_get();
   return *this;
}

Pkmn::Pkmn(std::string& path, int i)
{
   level_ = 1;
   std::ifstream input(path.c_str());
   std::string line;
   int nb_line = 0;
   if (input.is_open())
   {
      while (std::getline(input, line))
      {
         nb_line++;
         if (nb_line == i + 1)
         {
            std::string item;
            int item_place = 1;
            std::istringstream to_parse(line);
            while (std::getline(to_parse, item, ','))
            {
               switch (item_place)
               {
                  case 1:
                     id_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 2:
                     name_set(item);
                     item_place++;
                     break;
                  case 3:
                     type_set(item);
                     item_place++;
                     break;
                  case 4:
                     hp_set(std::atoi(item.c_str()));
                     hp_max_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 5:
                     atk_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 6:
                     def_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 7:
                     spatk_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 8:
                     spdef_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 9:
                     spd_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 10:
                     mvset_one_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 11:
                     mvset_two_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 12:
                     mvset_three_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 13:
                     mvset_four_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
               }
            }
         }
      }
      input.close();
   }
}

Pkmn::~Pkmn()
{}

int Pkmn::id_get() const
{
   return id_;
}

int Pkmn::level_get() const
{
   return level_;
}

std::string Pkmn::name_get() const
{
   return name_;
}

std::string Pkmn::type_get() const
{
   return type_;
}

int Pkmn::hp_get() const
{
   return hp_;
}

int Pkmn::hp_max_get() const
{
   return hp_max_;
}

int Pkmn::atk_get() const
{
   return atk_;
}

int Pkmn::def_get() const
{
   return def_;
}

int Pkmn::spatk_get() const
{
   return spatk_;
}

int Pkmn::spdef_get() const
{
   return spdef_;
}

int Pkmn::spd_get() const
{
   return spd_;
}

int Pkmn::mvset_one_get() const
{
   return mvset_one_;
}

int Pkmn::mvset_two_get() const
{
   return mvset_two_;
}

int Pkmn::mvset_three_get() const
{
   return mvset_three_;
}

int Pkmn::mvset_four_get() const
{
   return mvset_four_;
}

void Pkmn::id_set(int i)
{
   id_ = i;
}

void Pkmn:: name_set(std::string& s)
{
   name_ = s;
}

void Pkmn::type_set(std::string& s)
{
   std::string s_cpy = s;
   std::transform(s_cpy.begin(), s_cpy.end(), s_cpy.begin(), ::toupper);
   type_ = s_cpy;
}

void Pkmn::hp_set(int i)
{
   hp_ = i;
}

void Pkmn::hp_max_set(int i)
{
   hp_max_ = i;
}

void Pkmn::atk_set(int i)
{
   atk_ = i;
}

void Pkmn::def_set(int i)
{
   def_ = i;
}

void Pkmn::spatk_set(int i)
{
   spatk_ = i;
}

void Pkmn::spdef_set(int i)
{
   spdef_ = i;
}

void Pkmn::spd_set(int i)
{
   spd_ = i;
}

void Pkmn::mvset_one_set(int i)
{
   mvset_one_ = i;
}

void Pkmn::mvset_two_set(int i)
{
   mvset_two_ = i;
}

void Pkmn::mvset_three_set(int i)
{
   mvset_three_ = i;
}

void Pkmn::mvset_four_set(int i)
{
   mvset_four_ = i;
}

void Pkmn::level_set(int level, int ev, int iv)
{
   level_ = level;
   int new_hp = ((2 * hp_max_get() + iv + (ev / 4))
                  / 100) + level_get() + 10;
   int new_atk = (((2 * atk_get() + iv + (ev / 4)) * level)
                   / 100) + 5;
   int new_def = (((2 * def_get() + iv + (ev / 4)) * level)
                   / 100) + 5;
   int new_spatk = (((2 * spatk_get() + iv + (ev / 4)) * level)
                   / 100) + 5;
   int new_spdef = (((2 * spdef_get() + iv + (ev / 4)) * level)
                   / 100) + 5;
   int new_spd = (((2 * spd_get() + iv + (ev / 4)) * level)
                   / 100) + 5;
   hp_ = new_hp;
   hp_max_ = new_hp;
   atk_ = new_atk;
   def_ = new_def;
   spatk_ = new_spatk;
   spdef_ = new_spdef;
   spd_ = new_spd;
}

void Pkmn::parse_pkmn(std::string& path, int i)
{
   std::ifstream input(path.c_str());
   std::string line;
   int nb_line = 0;
   if (input.is_open())
   {
      while (std::getline(input, line))
      {
         nb_line++;
         if (nb_line == i + 1)
         {
            std::string item;
            int item_place = 1;
            std::istringstream to_parse(line);
            while (std::getline(to_parse, item, ','))
            {
               switch (item_place)
               {
                  case 1:
                     id_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 2:
                     name_set(item);
                     item_place++;
                     break;
                  case 3:
                     type_set(item);
                     item_place++;
                     break;
                  case 4:
                     hp_set(std::atoi(item.c_str()));
                     hp_max_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 5:
                     atk_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 6:
                     def_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 7:
                     spatk_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 8:
                     spdef_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 9:
                     spd_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 10:
                     mvset_one_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 11:
                     mvset_two_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 12:
                     mvset_three_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 13:
                     mvset_four_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
               }
            }
         }
      }
      input.close();
   }
}
