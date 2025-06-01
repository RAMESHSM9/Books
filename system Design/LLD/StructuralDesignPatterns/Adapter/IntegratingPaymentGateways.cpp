#include <bits/stdc++.h>
#include <memory>
using namespace std;

//@ App which has the payment fetaure, where the user can choose to go with
//[PayPal, Strip, RazorPay]

//@ common interface for all the payment gateways
class PaymentGateway {
public:
  virtual void processPayment(double amount) = 0;
};

//@ Adapters for each of the payment gateways
class PayPalAdapter : public PaymentGateway {
  //@ has-a relationship with the PayPaly API - 3rd party API provided by PayPal
public:
  void processPayment(double amount) {
    cout << " PayPal Adapter : Processing payment: " << amount << endl;
    //@ calling PayPal API
  }
};

class StripeAdapter : public PaymentGateway {
  //@ has-a relationship with the Stripe API - 3rd party API provided by Stripe
public:
  void processPayment(double amount) {
    cout << " Stripe Adapter : Processing payment: " << amount << endl;
    //@ calling Stripe API
  }
};

class RazorPayAdapter : public PaymentGateway {
  //@ has-a relationship with the RazorPay API - 3rd party API provided by
  // RazorPay
public:
  void processPayment(double amount) {
    cout << " RazorPay Adapter : Processing payment: " << amount << endl;
    //@ calling RazorPay API
  }
};

//@ our App using payment gateways
class Application {
  // has-a relation with PaymentGateways
  std::shared_ptr<PaymentGateway> paymentGateway;

public:
  Application(const std::shared_ptr<PaymentGateway> &paymentGateway) {
    this->paymentGateway = paymentGateway;
  }

  void makePayment(double amount) { paymentGateway->processPayment(amount); }
};

int main() {

  std::shared_ptr<PaymentGateway> paymentGateway = make_shared<PayPalAdapter>();
  Application app(paymentGateway);
  app.makePayment(100);
}