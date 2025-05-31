#include <bits/stdc++.h>
using namespace std;

//@ There are 4 types of Factory patterns
/*
1. Simple factory [Here]
2. Factory Method
3. Abstract Factory
4. Practical Factory
*/
enum PIZZA_TYPE { CHEESE, PEPPERONIA, VEGGIE };

class Pizza {
public:
  virtual void prepare() = 0;
  virtual void bake() = 0;
  virtual void cut() = 0;
  virtual void box() = 0;
  virtual void pizzaInfo() = 0;
};

class CheesePizza : public Pizza {
public:
  void prepare() { cout << "Preparing cheese pizza" << endl; }
  void bake() { cout << "Baking cheese pizza" << endl; }
  void cut() { cout << "Cutting cheese pizza" << endl; }
  void box() { cout << "Boxing cheese pizza" << endl; }
  void pizzaInfo() { cout << "Enjoy!! cheese pizza" << endl; }
  ~CheesePizza() {}
};

class PepperoniPizza : public Pizza {
public:
  void prepare() { cout << "Preparing Pepperoni pizza" << endl; }
  void bake() { cout << "Baking Pepperoni pizza" << endl; }
  void cut() { cout << "Cutting Pepperoni pizza" << endl; }
  void box() { cout << "Boxing Pepperoni pizza" << endl; }
  void pizzaInfo() { cout << "Enjoy!! Pepperoni pizza" << endl; }
  ~PepperoniPizza() {}
};

class VeggiePizza : public Pizza {
public:
  void prepare() { cout << "Preparing Veggie pizza" << endl; }
  void bake() { cout << "Baking Veggie pizza" << endl; }
  void cut() { cout << "Cutting Veggie pizza" << endl; }
  void box() { cout << "Boxing Veggie pizza" << endl; }
  void pizzaInfo() { cout << "Enjoy!! Veggie pizza" << endl; }
  ~VeggiePizza() {}
};
/*
class PizzaFactory {
public:
  static std::shared_ptr<Pizza> getPizza(PIZZA_TYPE pizzaType) {
    switch (pizzaType) {
    case CHEESE:
      return make_shared<CheesePizza>();
      break;
    case PEPPERONIA:
      return make_shared<PepperoniPizza>();
      break;
    case VEGGIE:
      return make_shared<VeggiePizza>();
      break;
    }

    throw std::runtime_error("Invalid Pizza type");
  }
};
*/
class PizzaStore {

  //@ user need not be aware of the pizza factory
  class PizzaFactory {
  public:
    static std::shared_ptr<Pizza> getPizza(PIZZA_TYPE pizzaType) {
      switch (pizzaType) {
      case CHEESE:
        return make_shared<CheesePizza>();
        break;
      case PEPPERONIA:
        return make_shared<PepperoniPizza>();
        break;
      case VEGGIE:
        return make_shared<VeggiePizza>();
        break;
      }

      throw std::runtime_error("Invalid Pizza type");
    }
  };

public:
  PizzaStore() {}

  std::shared_ptr<Pizza> orderPizza(PIZZA_TYPE pizzaType) {
    std::shared_ptr<Pizza> pizza = PizzaFactory::getPizza(pizzaType);
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    return pizza;
  }
};

int main() {
  PizzaStore ps; // PizzaStore can be signleton
  std::shared_ptr<Pizza> pizza = ps.orderPizza(CHEESE);
  pizza->pizzaInfo();
  cout << endl;
  std::shared_ptr<Pizza> pizza2 = ps.orderPizza(PEPPERONIA);
  pizza2->pizzaInfo();
  cout << endl;
  std::shared_ptr<Pizza> pizza3 = ps.orderPizza(VEGGIE);
  pizza3->pizzaInfo();
}