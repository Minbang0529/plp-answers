#include <stdio.h>

/* Class definition and member function implementation here */
class Vehicle {
    // protected variables are like private variables
    // but are also available to the subclasses
    protected:
        int _mileage;
    public:
        // we need a constructor that takes the vehicle's mileage
        Vehicle(int mileage){
            // we can direct access the protected variable within this class' scope
            _mileage = mileage;
        }

        int get_mileage(){
            return this->_mileage;
        }
};

// Car is declared as a subclass of Vehicle
class Car : public Vehicle {
    // no subclasses of car exist in this case, so no need for protected variables
    private:
        int _steering_wheels;

    public:
        // we need a constructor that takes the mileage and the steering wheels
        Car(int mileage, int steering_wheels) : Vehicle(mileage), _steering_wheels(steering_wheels) {
            _steering_wheels = steering_wheels;
            // we can access the _mileage member variable without declaring it
            // because it's already declared in the superclass as a protected var
            _mileage = mileage;
        }

        int get_steering_wheels(){
            return this->_steering_wheels;
        }
};

// Motorbike is declared as a subclass of Vehicle
class Motorbike : public Vehicle{
    // no subclasses of vehicle exist in this case, so no need for protected variables
    private:
        int _cc_class;

    public:
        // constructor that takes mileage and class
        Motorbike(int mileage, int cc_class) : Vehicle(mileage), _cc_class(cc_class) {
            _cc_class = cc_class;
            // we can access the _mileage member variable without declaring it
            // because it's already declared in the superclass as a protected var
            _mileage = mileage;
        }

        int get_cc_class(){
            return this->_cc_class;
        }
};

int main(int argc, char **argv) {
    Vehicle v(20000);  // a Vehicle with mileage = 20000 miles
    Car c1(10000, 2);  // a Car with mileage = 10000 miles and 2 steering wheels
    Car c2(5000, 4);   // a Car with mileage = 5000 miles and 4 steering wheels
    Motorbike m(50000, 500); // a Motorbike with mileage = 50000 miles and class 500cc

    printf("v's mileage is: %d\n", v.get_mileage());
    printf("c1's mileage is: %d, steering wheels: %d\n", c1.get_mileage(),
            c1.get_steering_wheels());
    printf("c2's mileage is: %d, steering wheels: %d\n", c2.get_mileage(),
            c2.get_steering_wheels());
    printf("m's mileage is:  %d, cc class: %d\n", m.get_mileage(),
            m.get_cc_class());

    return 0;
}
// Run the below command to check answers; The one on github is outdated
// Make sure you're in the same directory as this file when running the command
// check50 -l --log olivierpierre/comp26020-problems/2022-2023/week4-c++/05-inheritance
