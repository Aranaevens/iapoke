#include <string>
#include <cstdlib>

class Options
{
public:
   Options(char *argv[]);
   ~Options();
   void parse_cmd_line(char *argv[]);

   const std::string& ip_get() const;
   int port_get() const;
   const std::string& attacks_get() const;
   const std::string& pokemons_get() const;
   const std::string& types_get() const;

   /*void ip_set(std::string& s);
   void port_set(int& p);
   void attacks_set(std::string& s);
   void pokemons_set(std::string& s);
   void types_set(std::string& s);*/

private:
   std::string ip_;
   int port_;
   std::string attacks_;
   std::string pokemons_;
   std::string types_;
};
