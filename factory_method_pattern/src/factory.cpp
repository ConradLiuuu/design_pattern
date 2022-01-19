#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;
using std::string;

class Product
{
 public:
  virtual void introduceMyself() = 0;
};

class Tea : public Product
{
 public:
  Tea() 
  {
    // default product is black tea.
    this->name_ = "black";
  }

  Tea(const string& name) : name_(name) {}

  void introduceMyself() override
  {
    cout << "I'm a " << this->name_ << " tea." << endl;
  }

 private:
  string name_;
};

class Factory
{
 public:
  virtual unique_ptr<Product> getProduct() = 0;
};

class DrinkShop : public Factory
{
 public:
  unique_ptr<Product> getProduct() override
  {
    return make_unique<Tea>();
  }

  unique_ptr<Product> getProduct(const string& name)
  {
    return make_unique<Tea>(name);
  }
};

int main()
{
  DrinkShop drink_shop;

  unique_ptr<Product> drink1 = drink_shop.getProduct();
  drink1->introduceMyself();

  unique_ptr<Product> drink2 = drink_shop.getProduct("green");
  drink2->introduceMyself();

  unique_ptr<Product> drink3 = drink_shop.getProduct("oolong");
  drink3->introduceMyself();

  return 0;
}
