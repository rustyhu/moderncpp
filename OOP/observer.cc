#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class observer {
 public:
  virtual void notify(const std::string&) = 0;
};

class observerConcrete : public observer {
  std::string conc_name_;

 public:
  observerConcrete(const std::string& name) : conc_name_(name) {}
  virtual void notify(const std::string& info) override {
    std::cout << conc_name_ << " recv a notify: [" << info << "]\n";
  }
};

// 发布者publisher
class CPublisher {
 public:
  CPublisher(const std::string& name) : label_(name) {}
  void regi(observer* ob) { obsList_.push_back(ob); }
  void update(const std::string& info) {
    std::cout << label_ << " Get an update: [" << info << "]\n";
    for (auto&& ob : obsList_) {
      ob->notify(info);
    }
  };

 private:
  std::string label_;
  std::vector<observer*> obsList_;
};

int main(void) {
  CPublisher cdata("pub");
  observerConcrete ob1("ob1");
  observerConcrete ob2("ob2");
  observerConcrete ob3("ob3");
  cdata.regi(&ob1);
  cdata.regi(&ob2);
  cdata.regi(&ob3);

  cdata.update("30");
  cdata.update("44");
  cdata.update("!!!");
}
