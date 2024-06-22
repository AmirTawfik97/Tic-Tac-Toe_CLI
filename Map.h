#pragma once

#include "I_Printable.h"

#include  <string>
//using std::string;

#include <iostream>

class Map : public I_Printable 
{
  
private:
  char s_map[3][3];

public:
  Map();

  void updateMap(const int pos ,const char sym);
  void resetMap();
  char getPos(int pos) const;

  bool checkRowsComplete(char sym) const;
  bool checkColumnComplete(char sym) const;
  bool checkDiagonalComplete(char sym) const;
  bool checkEmptyCell() const;

  void I_Printable::print(std::ostream& os) const override;
  
  virtual ~Map();


};

