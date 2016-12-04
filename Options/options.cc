#include "options.hh"

Options::Options(char *argv[])
{
   ip_ = argv[1];
   port_ = std::atoi(argv[2]);
   attacks_ = argv[3];
   pokemons_ = argv[4];
   types_ = argv[5];
}

Options::~Options()
{}

void Options::parse_cmd_line(char *argv[])
{
   ip_ = argv[1];
   port_ = std::atoi(argv[2]);
   attacks_ = argv[3];
   pokemons_ = argv[4];
   types_ = argv[5];
}

const std::string& Options::ip_get() const
{
   return ip_;
}

int Options::port_get() const
{
   return port_;
}

const std::string& Options::attacks_get() const
{
   return attacks_;
}

const std::string& Options::pokemons_get() const
{
   return pokemons_;
}

const std::string& Options::types_get() const
{
   return types_;
}
