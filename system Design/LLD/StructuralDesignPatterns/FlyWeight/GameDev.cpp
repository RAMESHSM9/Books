#include <bits/stdc++.h>
#include <cmath>
#include <ostream>
#include <string>
#include <unordered_map>
using namespace std;

//@ flyweight object - shared across all the bullet objects
enum BulletType { _5MM = 0, _10MM = 1 };

std::string bulletTypeToString(BulletType bt) {
  switch (bt) {
  case _5MM:
    return "5MM";
  case _10MM:
    return "10MM";
  default:
    return "Unknown";
  }
}
class Bullet {
private:
  string image;
  BulletType bt;

public:
  Bullet(BulletType bt, string image) {
    this->image = image;
    this->bt = bt;
  }

  friend ostream &operator<<(ostream &os, const Bullet &b) {
    return os << "Bullet details " << "address " << &b << " " << b.image << " "
              << bulletTypeToString(b.bt);
  }
};

// # which would be used produce(returns the exisiting ones or creats new one,
// if it does not exists) the flyweight object, in this case Bullet
class flyweightFactory {
  std::unordered_map<BulletType, Bullet *> bulletsMap;

public:
  ~flyweightFactory() {
    for (auto &pair : bulletsMap) {
      delete pair.second; // Clean up allocated memory
    }
  }
  void addBullet(BulletType bt) {
    Bullet *bullet =
        new Bullet(bt, "BulletImage"); //@ images can be loaded from the file
    bulletsMap.insert(make_pair(bt, bullet));
  }

  Bullet &getBullet(BulletType bt) {
    if (!bulletsMap.contains(bt)) {
      addBullet(bt);
    }

    return *bulletsMap[bt];
  }
};

//@ Extrinsic properties, which change with the context
class flyingBullet {
private:
  double x;
  double y;
  double z;
  double radius;
  double speed;
  double direction;
  int status;
  int type;

  Bullet &bulletImage; // intrinsic property- which is common for all the
                       // bullets, and this takes more memory
public:
  flyingBullet(Bullet &b) : bulletImage(b) {}
};

class GameDev {
  // has-a flyweight factor
  flyweightFactory fwfactory;

public:
  void displayBullet(BulletType btype) {
    cout << " display bullet" << endl;
    Bullet &b = fwfactory.getBullet(btype);
    cout << b << endl;
  }
};

int main() {

  GameDev game;
  game.displayBullet(BulletType::_10MM);

  game.displayBullet(BulletType::_5MM);
  game.displayBullet(BulletType::_10MM); //_10MM would be reused
  game.displayBullet(BulletType::_5MM);  //_5MM would be reused
}