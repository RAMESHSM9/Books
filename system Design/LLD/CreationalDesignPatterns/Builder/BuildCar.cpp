#include <bits/stdc++.h>
#include <string>
using namespace std;

//@ Builder Design Patter is used when we are constructing,
// 1. Complex class with lots of attributes
// 2. Would like to perform validation before constructing of the object
// 3. Constructing immutable class - i.e, after construction is done, user would
// not be allowed to change the state of the class

/*
This is complex class which must be constructed - customer would like construct
the car having set the attributes in any order*/
/*class car {
private:
  string make;
  string model;
  int year;
  string color;
};*/

/*Solutions:
1. Having constructor with all the permutations would have 2 issues
    a. constructor telescoping
    b. ambugity because of the attributes type being same
2. Having Seperate builder class which would construct the Class and return the
instance
*/

//@ solution 2:
class car {

private:
  string make;
  string model;
  int year;
  string color;

  car() = delete;

private:
  class carBuilder {
  private:
    string make;
    string model;
    int year;
    string color;

  public:
    carBuilder() {}

    //@ provides setter for each of the attribute
    //@ has to return the this pointer, so that attribute is possible at the
    // user
    // end

    carBuilder setMake(string make) {
      this->make = make;
      return *this;
    }

    carBuilder setModel(string model) {
      this->model = model;
      return *this;
    }
    carBuilder setYear(int year) {
      this->year = year;
      return *this;
    }
    carBuilder setColor(string color) {
      this->color = color;
      return *this;
    }

    string getMake() const { return make; }

    string getModel() const { return model; }

    string getColor() const { return color; }

    int getYear() const { return year; }

    car build() { return car(this); }
  };

private:
  car(const carBuilder *carbuilder) {
    make = carbuilder->getMake();
    model = carbuilder->getModel();
    color = carbuilder->getColor();
    year = carbuilder->getYear();
  }

public:
  static carBuilder getCarBuilder() { return carBuilder(); }

  string getMake() const { return make; }

  string getModel() const { return model; }

  string getColor() const { return color; }

  int getYear() const { return year; }

  void showCarInformation() {
    cout << "Make " << make << " Model " << model << " Color " << color
         << " Year " << year << endl;
  }
};

int main() {
  car carObj = car::getCarBuilder()
                   .setColor("Green")
                   .setMake("BMW")
                   .setYear(2025)
                   .setModel("X")
                   .build();
  carObj.showCarInformation();
}
