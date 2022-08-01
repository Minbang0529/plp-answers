// Below comments highlight the changes to the original code
#include <stdio.h>

class Pair {
private:
    int x;
    int y;
public:
    Pair(int x, int y);
    void print();
    // destructor declaration
    ~Pair();
};

Pair::Pair(int x, int y) {
    this->x = x;
    this->y = y;
}

// destructor implementation
// does nothing, as the class Pair itself does not dynamically allocate memory
Pair::~Pair(){};

void Pair::print() {
    printf("Pair x: %d, y: %d\n", x, y);
}

class TopLevel {
private:
    Pair *p;
    int val;
public:
    TopLevel(int x, int y, int val);
    void print();
    // destructor declaration
    ~TopLevel();
};

TopLevel::TopLevel(int x, int y, int val) {
    this->val = val;
    this->p = new Pair(x, y);
}

// destructor implementation
// deletes the dynamically allocated memory for private member variable p
// see constructor of TopLevel for when memory was allocated
TopLevel::~TopLevel(){
    delete this->p;
};

void TopLevel::print() {
    printf("Toplevel val: %d, with pair:\n", val);
    p->print();
}

int main(int argc, char **argv) {
    TopLevel t(10, 20, 30);
    t.print();
    return 0;
}
// Run the below command to check answers; The one on github is outdated
// Make sure you're in the same directory as this file when running the command
// check50 -l --log olivierpierre/comp26020-problems/2022-2023/week4-c++/03-destructor
