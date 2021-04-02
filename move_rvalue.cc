#include <iostream>
#include <string>
#include <vector>
#include <map>

void showStdClassMove() {
    std::string orig = "orig words";
    std::string copied = orig;
    auto moved = std::move(orig);
    std::cout << "orig is " << orig << '\n'
            << "copied is " << copied << '\n'
            << "moved is " << moved << '\n';
}

class A {
public:
    explicit A() {};
    explicit A(int a): inner_(a) {};
    A(const A& a) = delete;
    A& operator=(const A& a) = delete;

    A(A&& a):
        inner_(0),
        strTitle_{}, 
        mapBasic_{} {
        *this = std::move(a);
    }

    A& operator=(A&& rrefa) {
        inner_ = rrefa.inner_;
        rrefa.inner_ = 0;

        strTitle_ = std::move(rrefa.strTitle_);
        mapBasic_ = std::move(rrefa.mapBasic_);

        return *this;
    }

    void show() {
        std::cout << "inner: " << inner_ << std::endl;
        std::cout << "strTitle: " << strTitle_ << std::endl;
        std::cout << "mapBasic: " << std::endl;
        for (const auto& p: mapBasic_) {
            std::cout << p.first << std::endl;
        }
    }

private:
    int inner_ = 10;
    std::string strTitle_{"empty title"};
    std::map<std::string, int> mapBasic_{{"k", 1}, {"kk", 2}};
};


int main() {
    A aaa;
    aaa.show();

    std::cout << "\nMoving...\n\n";
    auto bbb(std::move(aaa));
    aaa.show();
    bbb.show();
}