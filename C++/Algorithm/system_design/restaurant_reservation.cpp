#include <iostream>
#include <vector>
#include <utility>
using namespace std;


class Table
{
private:
  bool fixed;
  int table_id;
  int max_capacity;
public:
  Table(int table_id, int num, max_capacity);
  Table(Table *table_id1, Table *table_id2);
  ~Table(int table_id);
};

class Chair
{
private:
  int chair_count;
  int baby_chair_count;
  int chair_occupied;
  int chair_unoccupied;

public:
Chair(int count);
Chair(int chair_count, int baby_chair_count);
int recalculate_chairs(int chair_count );
int allocateChair(int chair);
};

class Party
{
private:
  int people;
  int baby;
  bool waiting;
  int table_id;

public:
  Party(int people, int baby);
  int allocatePeople(Party *party);// returns chairs

}
