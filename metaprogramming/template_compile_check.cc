#include <iostream>
#include <vector>

template <typename T>
void showTemplateFunc(T&& t) {
    std::cout << "Running template func...\n";
    std::cout << "Counting: " << t.size() << "\n";
}

class Ta {
   private:
    std::vector<int> inner_{
        1,
        1,
        3,
        6,
    };

   public:
    int size() { return inner_.size(); }
};

class YY {
   private:
    std::string inner_{"Nodata"};

   public:
};

int main() {
    showTemplateFunc(Ta());
    YY y;
    showTemplateFunc(y);
}