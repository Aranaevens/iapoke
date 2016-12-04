#pragma once

#include <string>
#include <algorithm>

class Attack
{
public:
   Attack();
   ~Attack();
   Attack(const Attack& p);
   Attack(std::string& path, int i);
   Attack& operator=(const Attack& p);
   int id_get() const;
   std::string name_get() const;
   std::string type_get() const;
   std::string category_get() const;
   int power_get() const;
   bool self_get() const;
   int atk_get() const;
   int def_get() const;
   int spatk_get() const;
   int spdef_get() const;
   int spd_get() const;

   void id_set(int i);
   void name_set(std::string& s);
   void type_set(std::string& s);
   void category_set(std::string& s);
   void power_set(int i);
   void self_set(bool i);
   void atk_set(int i);
   void def_set(int i);
   void spatk_set(int i);
   void spdef_set(int i);
   void spd_set(int i);

   void parse_atk(std::string& path, int i);


protected:
   int id_;
   std::string name_;
   std::string type_;
   std::string category_;
   int power_;
   bool self_;
   int atk_;
   int def_;
   int spatk_;
   int spdef_;
   int spd_;
};
