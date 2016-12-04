#include "attack.hh"

#include <fstream>
#include <sstream>

Attack::Attack()
   : id_(1)
   , name_("Acid")
   , type_("GRASS")
   , category_("SPECIAL")
   , power_(20)
   , self_(false)
   , atk_(0)
   , def_(0)
   , spatk_(0)
   , spdef_(0)
   , spd_(0)
{}

Attack::Attack(const Attack& p)
   : id_(p.id_get())
   , name_(p.name_get())
   , type_(p.type_get())
   , category_(p.category_get())
   , power_(p.power_get())
   , self_(p.self_get())
   , atk_(p.atk_get())
   , def_(p.atk_get())
   , spatk_(p.spatk_get())
   , spdef_(p.spdef_get())
   , spd_(p.spd_get())
{}

Attack& Attack::operator=(const Attack& p)
{
   id_ = p.id_get();
   name_ = p.name_get();
   type_ = p.type_get();
   category_ = p.category_get();
   power_ = p.power_get();
   self_ = p.self_get();
   atk_ = p.atk_get();
   def_ = p.atk_get();
   spatk_ = p.spatk_get();
   spdef_ = p.spdef_get();
   spd_ = p.spd_get();
   return *this;
}

Attack::~Attack()
{}

Attack::Attack(std::string& path, int i)
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
                     category_set(item);
                     item_place++;
                     break;
                  case 5:
                     power_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 6:
                     if (std::atoi(item.c_str()) == 1)
                        self_set(true);
                     else
                        self_set(false);
                     item_place++;
                     break;
                  case 7:
                     atk_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 8:
                     def_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 9:
                     spatk_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 10:
                     spdef_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 11:
                     spd_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
               }
            }
         }
      }
      input.close();
   }
}

int Attack::id_get() const
{
   return id_;
}

std::string Attack::name_get() const
{
   return name_;
}

std::string Attack::type_get() const
{
   return type_;
}

std::string Attack::category_get() const
{
   return category_;
}

int Attack::power_get() const
{
   return power_;
}

bool Attack::self_get() const
{
   return self_;
}

int Attack::atk_get() const
{
   return atk_;
}

int Attack::def_get() const
{
   return def_;
}

int Attack::spatk_get() const
{
   return spatk_;
}

int Attack::spdef_get() const
{
   return spdef_;
}

int Attack::spd_get() const
{
   return spd_;
}

void Attack::id_set(int i)
{
   id_ = i;
}

void Attack:: name_set(std::string& s)
{
   name_ = s;
}

void Attack::type_set(std::string& s)
{
   std::string s_cpy = s;
   std::transform(s_cpy.begin(), s_cpy.end(), s_cpy.begin(), ::toupper);
   type_ = s_cpy;
}

void Attack::category_set(std::string& s)
{
   std::string s_cpy = s;
   std::transform(s_cpy.begin(), s_cpy.end(), s_cpy.begin(), ::toupper);
   category_ = s_cpy;
}

void Attack::power_set(int i)
{
   power_ = i;
}

void Attack::self_set(bool i)
{
   self_ = i;
}

void Attack::atk_set(int i)
{
   atk_ = i;
}

void Attack::def_set(int i)
{
   def_ = i;
}

void Attack::spatk_set(int i)
{
   spatk_ = i;
}

void Attack::spdef_set(int i)
{
   spdef_ = i;
}

void Attack::spd_set(int i)
{
   spd_ = i;
}

void Attack::parse_atk(std::string& path, int i)
{
   std::ifstream input(path.c_str());
   std::string line;
   int nb_line = 0;
   if (input.is_open())
   {
      while (getline(input, line))
      {
         nb_line++;
         if (nb_line == i + 1)
         {
            std::string item;
            std::istringstream to_parse(line);
            int item_place = 1;
            while (getline(to_parse, item, ','))
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
                     category_set(item);
                     item_place++;
                     break;
                  case 5:
                     power_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 6:
                     if (std::atoi(item.c_str()) == 1)
                        self_set(true);
                     else
                        self_set(false);
                     item_place++;
                     break;
                  case 7:
                     atk_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 8:
                     def_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 9:
                     spatk_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 10:
                     spdef_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
                  case 11:
                     spd_set(std::atoi(item.c_str()));
                     item_place++;
                     break;
               }
            }
         }
      }
      input.close();
   }
}
