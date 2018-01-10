#include <iostream>

int recursiveS(int n){ // Ex. 5. Calculates the sum for i in 1 to n of i. \[\sum_{i=1}^{n} i \]
    if(n == 1){
        return 1;
    }else{
        return n + recursiveS(n-1);
    }
}

int recursiveT(int n){ // Ex. 6
    if(n == 0){
        return -1;
    }else if(n == 1){
        return 2;
    }else{
        return recursiveT(n-1) + 3 * recursiveT(n-2);
    }
}

int recursiveExp(int base, int exp){ // Ex. 7
    if(exp == 0){
        return 1;
    }else{
        return base * recursiveExp(base, exp-1);
    }
}

int recursiveSum(int n){
    //This is technically exercise 5. Just using it mapped. This does a pass-by-value.
    return recursiveS(n);
}

void towersOfHanoi(int n, char from, char to, char aux){
    if(n == 1){
        //Base Case.
        std::cout << "Move Disk " << n << " from " << from << " to " << to <<std::endl;
        return;
    }
    towersOfHanoi(n-1, from, aux, to);
    std::cout << "Move Disk " << n << " from " << from << " to " << to <<std::endl;
    towersOfHanoi(n-1, aux, to, from); // Move from aux to to rod with aux rod as the from.
}

int main() {
    std::cout << "Enter a program function" << std::endl;
    int callfunc = 0;
    std::cin >> callfunc;
    if(callfunc == 5 || callfunc == 8){
        std::cout << "Enter n" << std::endl;
        int n;
        std::cin >> n;
        int out = recursiveS(n);
        std::cout << "Output - " << out << std::endl;
    }else if(callfunc == 6){
        std::cout << "Enter n" << std::endl;
        int n;
        std::cin >> n;
        int out = recursiveT(n);
        std::cout << "Output - " << out << std::endl;
    }else if(callfunc == 7){
        std::cout << "Enter base" << std::endl;
        int base;
        std::cin >> base;
        std::cout << "Enter exp" << std::endl;
        int exp;
        std::cin >> exp;
        int out = recursiveExp(base,exp);
        std::cout << "Output - " << out << std::endl;
    }else if(callfunc == 9){
        std::cout << "Enter n" << std::endl;
        int n;
        std::cin >> n;
        towersOfHanoi(n, 'A', 'C', 'B');
    }else{
        std::cout << "Invalid Input" << std::endl;
    }
    return 0;
}