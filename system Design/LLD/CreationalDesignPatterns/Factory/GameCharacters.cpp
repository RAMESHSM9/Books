#include <bits/stdc++.h>
using namespace std;

//@ There are 4 types of Factory patterns
/*
1. Simple factory
2. Factory Method [Here]
3. Abstract Factory
4. Practical Factory
*/

class Character {
protected:
  string name;
  int health;
  int strength;
  int agility;
  int intelligence;

public:
  Character(string name, int health, int strength, int agility,
            int intelligence) {
    this->name = name;
    this->agility = agility;
    this->health = health;
    this->name = name;
    this->intelligence = intelligence;
  }

  virtual void display() = 0;
  virtual void attack() = 0;
  virtual ~Character() { cout << "Character Destructor" << endl; }
};

class Warrior : public Character {
public:
  Warrior(string name, int health, int strength, int agility, int intelligence)
      : Character(name, health, strength, agility, intelligence) {}

  void display() { cout << " I am warrior name " + name << endl; }
  void attack() { cout << " I swing my sword" << endl; }

  ~Warrior() { cout << "Warrior Destructor" << endl; }
};

class Mage : public Character {
public:
  Mage(string name, int health, int strength, int agility, int intelligence)
      : Character(name, health, strength, agility, intelligence) {}

  void display() { cout << " I am Mage name " + name << endl; }
  void attack() { cout << " I casr spell" << endl; }

  ~Mage() { cout << "Mage Destructor" << endl; }
};

class Rouge : public Character {
public:
  Rouge(string name, int health, int strength, int agility, int intelligence)
      : Character(name, health, strength, agility, intelligence) {}

  void display() { cout << " I am Rouge name " + name << endl; }
  void attack() { cout << " I strike from shadows" << endl; }
  ~Rouge() { cout << "Rouge Destructor" << endl; }
};

class CharacterFactory {
public:
  virtual std::shared_ptr<Character> creatCharacter(string name) = 0;
};

class WarriorFactory : public CharacterFactory {
public:
  std::shared_ptr<Character> creatCharacter(string name) {
    return make_shared<Warrior>(name, 100, 10, 5, 5);
  }
};

class MageFactory : public CharacterFactory {
public:
  std::shared_ptr<Character> creatCharacter(string name) {
    return make_shared<Mage>(name, 50, 5, 5, 10);
  }
};

class RougeFactory : public CharacterFactory {
public:
  std::shared_ptr<Character> creatCharacter(string name) {
    return make_shared<Rouge>(name, 75, 7, 10, 3);
  }
};

int main() {
  std::unique_ptr<CharacterFactory> warriorCharacterFactory =
      make_unique<WarriorFactory>();

  std::unique_ptr<CharacterFactory> mageCharacterFactory =
      make_unique<MageFactory>();

  std::unique_ptr<CharacterFactory> rougeCharacterFactory =
      make_unique<RougeFactory>();

  std::shared_ptr<Character> warrior =
      warriorCharacterFactory->creatCharacter("Thor");

  std::shared_ptr<Character> mage =
      mageCharacterFactory->creatCharacter("Gandlf");

  std::shared_ptr<Character> rouge =
      rougeCharacterFactory->creatCharacter("Legolas");

  warrior->display();
  warrior->attack();

  mage->display();
  mage->attack();

  rouge->display();
  rouge->attack();
}