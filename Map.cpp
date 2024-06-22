#include "Map.h"

Map::Map()
{
  for (int i = 0; i < 3; i++)
  {
	for (int j = 0; j < 3; j++)
	{
	  s_map[i][j] = ' ';
	}
  }
}

void Map::updateMap(const int pos,char sym)
{
  switch (pos)
  {
  case 1: s_map[0][0] = sym; break;
  case 2: s_map[0][1] = sym; break;
  case 3: s_map[0][2] = sym; break;
  case 4: s_map[1][0] = sym; break;
  case 5: s_map[1][1] = sym; break;
  case 6: s_map[1][2] = sym; break;
  case 7: s_map[2][0] = sym; break;
  case 8: s_map[2][1] = sym; break;
  case 9: s_map[2][2] = sym; break;
  }
}

void Map::resetMap()
{
  for (int i = 0; i < 3; i++)
  {
	for (int j = 0; j < 3; j++)
	{
	  s_map[i][j] = ' ';
	}
  }
}

bool Map::checkRowsComplete(char sym) const
{
  if (
	(s_map[0][0] == sym && s_map[0][1] == sym && s_map[0][2] == sym) ||
	(s_map[1][0] == sym && s_map[1][1] == sym && s_map[1][2] == sym) ||
	(s_map[2][0] == sym && s_map[2][1] == sym && s_map[2][2] == sym)
	)
  {
	return true;
  }
  else
	return false;
}

bool Map::checkColumnComplete(char sym) const
{
  if (
	(s_map[0][0] == sym && s_map[1][0] == sym && s_map[2][0] == sym) ||
	(s_map[0][1] == sym && s_map[1][1] == sym && s_map[2][1] == sym) ||
	(s_map[0][2] == sym && s_map[1][2] == sym && s_map[2][2] == sym)
	)
  {
	return true;
  }
  else
	return false;
}

bool Map::checkDiagonalComplete(char sym) const
{
  if (
	(s_map[0][0] == sym && s_map[1][1] == sym && s_map[2][2] == sym) ||
	(s_map[0][2] == sym && s_map[1][1] == sym && s_map[2][0] == sym)
	)
  {
	return true;
  }
  else
	return false;

}

bool Map::checkEmptyCell() const
{
  for (int i = 0; i < 3; i++)
  {
	for (int j = 0; j < 3; j++)
	{
	  if (s_map[i][j] == ' ')
		return true;
	}
  }
  return false;
}

void Map::print(std::ostream& os) const
{
  os <<
	   "     |     |     \n"
	<< "  " << s_map[0][0] << "  |  " << s_map[0][1] << "  |  " << s_map[0][2] << " \n"
	<< "_____|_____|_____\n"
	<< "     |     |     \n"
	<< "  " << s_map[1][0] << "  |  " << s_map[1][1] << "  |  " << s_map[1][2] << " \n"
	<< "_____|_____|_____\n"
	<< "     |     |     \n"
	<< "  " << s_map[2][0] << "  |  " << s_map[2][1] << "  |  " << s_map[2][2] << " \n"
	<< "     |     |     ";
}

char Map::getPos(const int pos)const
{
  switch (pos)
  {
  case 1: return s_map[0][0];  break;
  case 2: return s_map[0][1];  break;
  case 3: return s_map[0][2];  break;
  case 4: return s_map[1][0];  break;
  case 5: return s_map[1][1];  break;
  case 6: return s_map[1][2];  break;
  case 7: return s_map[2][0];  break;
  case 8: return s_map[2][1];  break;
  case 9: return s_map[2][2];  break;
  default: return '?'; break;
  }
}

Map::~Map() { }