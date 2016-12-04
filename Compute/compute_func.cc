#include <string>

#include "../Matrix/matrix.hh"
#include "../Pkmn/pkmn.hh"
#include "../Attack/attack.hh"

int type_iequ(std::string& type)
{
   if (type == "NORMAL")
      return 0;
   if (type == "FIRE")
      return 1;
   if (type == "WATER")
      return 2;
   if (type == "ELECTRIC")
      return 3;
   if (type == "GRASS")
      return 4;
   if (type == "ICE")
      return 5;
   if (type == "FIGHTING")
      return 6;
   if (type == "POISON")
      return 7;
   if (type == "GROUND")
      return 8;
   if (type == "FLYING")
      return 9;
   if (type == "PSYCHIC")
      return 10;
   if (type == "BUG")
      return 11;
   if (type == "ROCK")
      return 12;
   if (type == "GHOST")
      return 13;
   if (type == "DRAGON")
      return 14;
   else
      return 0;
}

int cmp_modifier(Matrix& m, std::string type_at, std::string type_de)
{
   int row = type_iequ(type_at);
   int col = type_iequ(type_de);
   return m.value_get(row, col);
}

void cmp_atk(Pkmn& at, Pkmn& de, std::string& path, int id, Matrix& m)
{
   Attack to_compute(path, id);
   if (to_compute.self_get() == false)
   {
      int modifier = cmp_modifier(m, to_compute.type_get(), de.type_get());
      if (at.type_get() == to_compute.type_get())
         modifier = modifier * 1.5;
      if (to_compute.category_get() == "PHYSICAL")
      {
         int def_def = de.def_get();
         if (def_def <= 0)
            def_def = 1;
         int dmg = (((2 * at.level_get() + 10) / 250)
                         * (at.atk_get() / def_def)
                         * to_compute.power_get()
                         + 2) * modifier;
         de.hp_set(de.hp_get() - dmg);
      }
      if (to_compute.category_get() == "SPECIAL")
      {
         int def_spdef = de.spdef_get();
         if (def_spdef <= 0)
            def_spdef = 1;
         int dmg = (((2 * at.level_get() + 10) / 250)
                         * (at.spatk_get() / def_spdef)
                         * to_compute.power_get()
                         + 2) * modifier;
         de.hp_set(de.hp_get() - dmg);
      }
      if (to_compute.category_get() == "STATUS")
      {
         if (to_compute.self_get() == true)
         {
            int new_hp = at.hp_get() + to_compute.power_get();
            if (new_hp > at.hp_max_get())
               at.hp_set(at.hp_max_get());
            else
               at.hp_set(new_hp);
            at.atk_set(at.atk_get() + to_compute.atk_get());
            at.def_set(at.def_get() + to_compute.def_get());
            at.spatk_set(at.spatk_get() + to_compute.spatk_get());
            at.spdef_set(at.spdef_get() + to_compute.spdef_get());
            at.spd_set(at.spd_get() + to_compute.spd_get());
         }
         else
         {
            int new_hp = de.hp_get() + to_compute.power_get();
            if (new_hp > de.hp_max_get())
               de.hp_set(de.hp_max_get());
            else
               de.hp_set(new_hp);
            de.atk_set(de.atk_get() + to_compute.atk_get());
            de.def_set(de.def_get() + to_compute.def_get());
            de.spatk_set(de.spatk_get() + to_compute.spatk_get());
            de.spdef_set(de.spdef_get() + to_compute.spdef_get());
            de.spd_set(de.spd_get() + to_compute.spd_get());
         }
      }
   }
}
