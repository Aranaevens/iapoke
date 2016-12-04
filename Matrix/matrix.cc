#include <fstream>
#include <sstream>
#include "matrix.hh"

void Matrix::print() const
{
   for (unsigned i = 0; i < rows_get(); i++)
   {
      for (unsigned j = 0; j < columns_get(); j++)
      {
         std::cout << m_[i][j];
         if (j == columns_get() - 1)
            std::cout << std::endl;
         else
            std::cout << " ";
      }
   }
}

bool Matrix::is_square() const
{
   if (rows_get() == columns_get())
      return true;
   else
      return false;
}

int Matrix::trace() const
{
   if (!is_square())
   {
      std::cerr << "Error: invalid matrix" << std::endl;
      exit(3);
   }
   else
   {
      int tr = 0;
      for (unsigned i = 0; i < rows_get(); i++)
         tr += m_[i][i];
      return tr;
   }
}

Matrix Matrix::transpose() const
{
   Matrix m = Matrix(columns_get(), rows_get());
   for (unsigned i = 0; i < columns_get(); i++)
   {
      for (unsigned j = 0; j < rows_get(); j++)
         m.m_[i][j] = this->m_[j][i];
   }
   return m;
}

void Matrix::parse_csv(std::string& path)
{
   std::ifstream csv(path.c_str());
   std::string line;
   if (csv.is_open())
   {
      int lnb = 0;
      while (std::getline(csv, line))
      {
         std::string item;
         int item_place = 0;
         std::istringstream to_parse(line);
         while (std::getline(to_parse, item, ','))
         {
            if (lnb != 0 && item_place != 0)
               value_set(lnb - 1, item_place - 1, std::atoi(item.c_str()));
            item_place++;
         }
         lnb++;
      }
      csv.close();
   }
}
