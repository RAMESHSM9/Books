#include <bits/stdc++.h>
#include <memory>
using namespace std;

//! buidling Ice-cream ordering system
class icecream {
public:
  virtual string getIngredients() = 0;
  virtual double getPrice() = 0;
};

//@ add-ons implement the common interface
class orangecone : public icecream {
  std::shared_ptr<icecream> cone;

public:
  orangecone() {}
  orangecone(std::shared_ptr<icecream> cone) { this->cone = cone; }
  string getIngredients() {
    return "Orange cone " + ((cone) ? cone->getIngredients() : "");
  }
  double getPrice() { return 10.0 + ((cone) ? cone->getPrice() : 0); }
};

class greencone : public icecream {
  std::shared_ptr<icecream> cone;

public:
  greencone() {}
  greencone(std::shared_ptr<icecream> cone) { this->cone = cone; }
  string getIngredients() {
    return "Green cone " + ((cone) ? cone->getIngredients() : "");
  }
  double getPrice() {
    return 5.0 + ((cone) ? cone->getPrice() : 0);
    ;
  }
};

class chocchips : public icecream {
  std::shared_ptr<icecream> cone;

public:
  chocchips() {}
  chocchips(std::shared_ptr<icecream> cone) { this->cone = cone; }
  string getIngredients() {
    return "choco chips " + ((cone) ? cone->getIngredients() : "");
  }
  double getPrice() {
    return 5.0 + ((cone) ? cone->getPrice() : 0);
    ;
  }
};

class vanillascoop : public icecream {
  std::shared_ptr<icecream> cone;

public:
  vanillascoop() {}
  vanillascoop(std::shared_ptr<icecream> cone) { this->cone = cone; }
  string getIngredients() {
    return "vanilla scoop " + ((cone) ? cone->getIngredients() : "");
  }
  double getPrice() {
    return 10.0 + ((cone) ? cone->getPrice() : 0);
    ;
  }
};

class chocolatescoop : public icecream {
  std::shared_ptr<icecream> cone;

public:
  chocolatescoop() {}
  chocolatescoop(std::shared_ptr<icecream> cone) { this->cone = cone; }
  string getIngredients() {
    return "chocolate scoop " + ((cone) ? cone->getIngredients() : "");
  }
  double getPrice() {
    return 20.0 + ((cone) ? cone->getPrice() : 0);
    ;
  }
};

int main() {
  std::shared_ptr<icecream> orangecone_ = make_shared<orangecone>();
  cout << orangecone_->getIngredients() << " " << orangecone_->getPrice()
       << endl
       << endl;

  std::shared_ptr<icecream> oragneGreencone_ =
      make_shared<greencone>(make_shared<orangecone>());
  cout << oragneGreencone_->getIngredients() << " "
       << oragneGreencone_->getPrice() << endl
       << endl;

  std::shared_ptr<icecream> orangeconeVanillaScoop_ =
      make_shared<orangecone>(make_shared<vanillascoop>());
  cout << orangeconeVanillaScoop_->getIngredients() << " "
       << orangeconeVanillaScoop_->getPrice() << endl
       << endl;

  std::shared_ptr<icecream> greenconeorangeconeVanillaScoop_ =
      make_shared<greencone>(
          make_shared<orangecone>(make_shared<vanillascoop>()));
  cout << greenconeorangeconeVanillaScoop_->getIngredients() << " "
       << greenconeorangeconeVanillaScoop_->getPrice() << endl
       << endl;
}