#include <iostream>
using namespace std;

class Animal
{
public:
  void virtual print_type(){};
};



class Dog: public Animal
{
public:
  void print_type();
};

void Dog::print_type()
{
cout<<"I am a dog"<<endl;
}

class Cat : public Animal
{
public:
  void print_type();
};

void Cat::print_type()
{
cout<<"I am a cat"<<endl;
}

int main()
{
  Animal* animal = new Cat();
animal->print_type();
  return 0;
}
