#include <bits/stdc++.h>
#include <memory>
using namespace std;
//@ There are 4 types of Factory patterns
/*
1. Simple factory
2. Factory Method
3. Abstract Factory [Here]
4. Practical Factory
*/
/*Button*/
class Button {
public:
  virtual void paint() = 0;
};

class WindowsButton : public Button {
public:
  void paint() { cout << "Painting a Windows button." << endl; }
};

class LinuxButton : public Button {
public:
  void paint() { cout << "Painting a Linux button." << endl; }
};

class MacOsButton : public Button {
public:
  void paint() { cout << "Painting a MacOs button." << endl; }
};

/*TextBox*/
class TextBox {
public:
  virtual void paint() = 0;
};

class WindowsTextBox : public TextBox {
public:
  void paint() { cout << "Painting a Windows TextBox." << endl; }
};

class LinuxTextBox : public TextBox {
public:
  void paint() { cout << "Painting a Linux TextBox." << endl; }
};

class MacOsTextBox : public TextBox {
public:
  void paint() { cout << "Painting a MacOs TextBox." << endl; }
};

/*Label*/
class Label {
public:
  virtual void paint() = 0;
};

class WindowsLabel : public Label {
public:
  void paint() { cout << "Painting a Windows Label." << endl; }
};

class LinuxLabel : public Label {
public:
  void paint() { cout << "Painting a Linux Label." << endl; }
};

class MacOsLabel : public Label {
public:
  void paint() { cout << "Painting a MacOs Label." << endl; }
};

//@ each OS will create its own related objects
class GUIFactory {
public:
  virtual std::shared_ptr<Button> createButton() = 0;
  virtual std::shared_ptr<TextBox> createTextBox() = 0;
  virtual std::shared_ptr<Label> createLabel() = 0;
};

class WindowsGUIFactory : public GUIFactory {
public:
  std::shared_ptr<Button> createButton() {
    return make_shared<WindowsButton>();
  }

  std::shared_ptr<TextBox> createTextBox() {
    return make_shared<WindowsTextBox>();
  }

  std::shared_ptr<Label> createLabel() { return make_shared<WindowsLabel>(); }
};

class LinuxGUIFactory : public GUIFactory {
public:
  std::shared_ptr<Button> createButton() { return make_shared<LinuxButton>(); }

  std::shared_ptr<TextBox> createTextBox() {
    return make_shared<LinuxTextBox>();
  }

  std::shared_ptr<Label> createLabel() { return make_shared<LinuxLabel>(); }
};

class MacOsGUIFactory : public GUIFactory {
public:
  std::shared_ptr<Button> createButton() { return make_shared<MacOsButton>(); }

  std::shared_ptr<TextBox> createTextBox() {
    return make_shared<MacOsTextBox>();
  }

  std::shared_ptr<Label> createLabel() { return make_shared<MacOsLabel>(); }
};

class ApplicationUI {
private:
  shared_ptr<Button> button;
  shared_ptr<TextBox> textBox;
  shared_ptr<Label> label;

public:
  ApplicationUI(shared_ptr<GUIFactory> guiFactory) {
    button = guiFactory->createButton();
    textBox = guiFactory->createTextBox();
    label = guiFactory->createLabel();
  }

  void paint() {
    button->paint();
    textBox->paint();
    label->paint();
  }
};

int main() {
  shared_ptr<GUIFactory> windowsGUI = make_shared<WindowsGUIFactory>();
  ApplicationUI windowsAppUI(windowsGUI);
  windowsAppUI.paint();

  cout << endl;

  shared_ptr<GUIFactory> linuxGUI = make_shared<LinuxGUIFactory>();
  ApplicationUI linuxAppUI(linuxGUI);
  linuxAppUI.paint();

  cout << endl;

  shared_ptr<GUIFactory> macOSGUI = make_shared<MacOsGUIFactory>();
  ApplicationUI macOSAppUI(macOSGUI);
  macOSAppUI.paint();
}
