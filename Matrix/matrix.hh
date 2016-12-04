#pragma once

#include <iostream>
#include <stdlib.h>

class Matrix
{
public:
   Matrix(unsigned rows, unsigned columns)
   {
      if (rows <= 0)
      {
         std::wcerr << "Error: invalid argument " << rows
                  << std::endl;
         exit(2);
      }
      if (columns <= 0)
      {
         std::wcerr << "Error: invalid argument " << columns
                  << std::endl;
         exit(2);
      }
      rows_ = rows;
      columns_ = columns;
      int **m = new int*[rows];
      for (unsigned i = 0; i < rows; i++)
         m[i] = new int[columns];
      m_ = m;
   }

   ~Matrix()
   {
      for (unsigned i; i < rows_; i++)
         delete m_[i];
      delete m_;
   }
   
   unsigned rows_get() const
   {
      return rows_;
   }

   unsigned columns_get() const
   {
      return columns_;
   }
   
   int value_get(unsigned row, unsigned column) const
   {
      if (row >= rows_get())
      {
         std::wcerr << "Error: invalid argument " << row
                  << std::endl;
         exit(2);
      }
      if (column >= columns_get())
      {
         std::wcerr << "Error: invalid argument " << column
                  << std::endl;
         exit(2);
      }
      return m_[row][column];
   }
   
   void value_set(unsigned row, unsigned column, int val)
   {
      if (row >= rows_get())
      {
         std::cerr << "Error: invalid matrix" << std::endl;
         exit(2);
      }
      if (column >= columns_get())
      {
         std::cerr << "Error: invalid matrix" << std::endl;
         exit(2);
      }
      m_[row][column] = val;
   }

   void fill(int val)
   {
      for (unsigned i = 0; i < rows_get(); i++)
      {
         for (unsigned j = 0; j < columns_get(); j++)
            m_[i][j] = val;
      }
   }

   void print() const;
   void parse_csv(std::string& path);
   bool is_square() const;
   int trace() const;
   Matrix transpose() const;


private:
   int** m_;
   unsigned rows_;
   unsigned columns_;
};
