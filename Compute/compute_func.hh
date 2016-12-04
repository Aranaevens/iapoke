#pragma once

#include "../Matrix/matrix.hh"
#include "../Pkmn/pkmn.hh"
#include "../Attack/attack.hh"

int type_iequ(std::string& type);
int cmp_modifier(Matrix& m, std::string& type_at, std::string& type_de);
void cmp_atk(Pkmn& at, Pkmn& de, std::string& path, int id, Matrix& m);
