#include <bits/stdc++.h>
#include <memory>
using namespace std;

//@ this is the thing that we are building and apply decorations on it
class Text {
public:
  virtual string getContent() = 0;
};

class PlainText : public Text {
  string st;

public:
  PlainText(string s) : st(s) {}
  string getContent() { return st; }
};

class BoldText : public Text {
  std::shared_ptr<Text> text;

public:
  BoldText(std::shared_ptr<Text> t) : text(t) {}
  string getContent() { return " <B> " + text->getContent() + " <B> "; }
};

class ItallicText : public Text {
  std::shared_ptr<Text> text;

public:
  ItallicText(std::shared_ptr<Text> t) : text(t) {}
  string getContent() { return " <i> " + text->getContent() + " <i> "; }
};

class lowerCaseText : public Text {
  std::shared_ptr<Text> text;

public:
  lowerCaseText(std::shared_ptr<Text> t) : text(t) {}
  string getContent() { return "lowerCase( " + text->getContent() + ")"; }
};

class upperCaseText : public Text {
  std::shared_ptr<Text> text;

public:
  upperCaseText(std::shared_ptr<Text> t) : text(t) {}
  string getContent() { return "upperCase( " + text->getContent() + ")"; }
};

int main() {
  std::shared_ptr<Text> t = make_shared<PlainText>("Decorator Pattern");
  cout << make_shared<BoldText>(
              make_shared<ItallicText>(make_shared<lowerCaseText>(t)))
              ->getContent()
       << endl
       << endl;
  cout << make_shared<BoldText>(
              make_shared<ItallicText>(make_shared<upperCaseText>(t)))
              ->getContent()
       << endl
       << endl;
  ;
}
