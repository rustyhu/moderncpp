#include <iostream>
#include <string>

// Static binding interface
// Notice: instantiation of this interface should be usefuless and forbidden.
class IBase {
 protected:
  IBase() = default;
  ~IBase() = default;

 public:
  // Methods that must be implemented by the derived class
  void behaviorA();
  void behaviorB();

  void behaviorC() {
    std::cout << "This is an interface default implementation of bC().\n";
  };
};

class CCom : public IBase {
  std::string name_;

 public:
  void behaviorA() { std::cout << "CCom bA called.\n"; };
};

class CDept : public IBase {
  int ele_;

 public:
  void behaviorB() { std::cout << "CDept bB called.\n"; };
  void behaviorC() {
    // Overwrite the interface default implementation
    std::cout << "CDept bC called.\n";
    IBase::behaviorC();
  };
};

int main(void) {
  // Forbid the instantiation of the interface type itself.
  // GCC error: ‘constexpr IBase::IBase()’ is protected within this context
  // IBase o;

  CCom acom;
  // If you want to use these interface methods, you need to implement them in
  // your derived class. This is controled by the interface definition.
  acom.behaviorA();
  // ld: undefined reference to `IBase::behaviorB()'
  // acom.behaviorB();
  acom.behaviorC();

  CDept adept;
  // adept.behaviorA();
  adept.behaviorB();
  adept.behaviorC();
  // adept.IBase::behaviorC();
}
