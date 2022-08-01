// Below comments highlight the changes to the original code
#include <stdio.h>

class Rectangle {
// two member vars set as private
private:
    float length;
    float width;

public:
    // constructor added
    Rectangle(float length, float width){
        this->length = length;
        this->width = width;
    }

    // perimeter function transformed into member method
    float perimeter(){
        return 2.0 * (this->length + this->width);
    }

    // getter functions added
    float get_length(){
        return this->length;
    }

    float get_width(){
        return this->width;
    }
};

class Circle {
// member var set as private
private:
    float radius;

public:
    // constructor added
    Circle(float radius){
        this->radius = radius;
    }

    // circumference function transformed into member method
    float circumference(){
        return 2.0 * 3.14 * this->radius;
    }

    // getter function added
    float get_radius(){
        return this->radius;
    }
};

int main(int argc, char **argv) {
    // objects are now initialized using their respective constructors
    Rectangle r(10, 20);
    Circle c(1);

    // member variables are called using getters
    printf("Rectangle l: %f, w: %f, perimeter: %f\n",
            r.get_length(), r.get_width(), r.perimeter());
    // functions are now called using member methods
    printf("Circle r: %f, circumference: %f\n",
            c.get_radius(), c.circumference());

    return 0;
}
// Run the below command to check answers; The one on github is outdated
// Make sure you're in the same directory as this file when running the command
// check50 -l --log olivierpierre/comp26020-problems/2022-2023/week4-c++/02-encapsulation
