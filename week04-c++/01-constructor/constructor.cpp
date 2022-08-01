// Below comments highlight the changes to the original code
#include <stdio.h>

class Pair{
    public:
        int x;
        int y;
        // definition of constructor - takes two int parameters
        Pair(int x, int y){
            // assigns each parameter to corresponding member vars
            this->x = x;
            this->y = y;
        }
};

int main(int argc, char **argv){
    // uses the new constructor instead of manual per-member initialization
    Pair p(10, 20);

    printf("p.x is %d, p.y is %d\n", p.x, p.y);

    return 0;
}
// Run the below command to check answers; The one on github is outdated
// Make sure you're in the same directory as this file when running the command
// check50 -l --log olivierpierre/comp26020-problems/2022-2023/week4-c++/01-constructor
