//
// Created by becca on 2/11/18.
//

#include <cstring> // for strcat
#include <cctype> // isalpha/isdigit
#include <iostream> // console IO
#include "InfixConvert.h"
#include "Stack.h"

int InfixConvert::priority(char symbol) {
    if(symbol == '*' || symbol == '/' || symbol == '%'){
        return 2; // Highest Priority
    }else if(symbol == '+' || symbol == '-'){
        return 1; //Middle Priority
    }else{
        return 0; //Low priority.
    }
}

void InfixConvert::convert(char *input) {
    int input_iter = 0;
    char temp = NULL;
    char item;
    item = input[input_iter];

    Stack *s = new Stack(); //This is a stack of chars, I need to store the operators in it.
    s->push('(');
    strcat(input, ")");//This is some setup to get it to spit out all of the rest of the operators at the end.
    while(item != NULL)
    {
        if(item == '(')
        {
            s->push(item);
        }
        else if(isdigit(item) || isalpha(item)) //It's symbolic!
        {
            std::cout<< item;
        }
        else if(isoperator(item))
        {
            temp= s->pop();
            while(isoperator(temp) && priority(temp) >= priority(item))
            {
                std::cout<< temp;
                temp = s->pop();
            }
            s->push(temp); // Push the temp back on
            s->push(item); // Push the recently encountered symbol.
        }
        else if(item == ')')
        {
            temp = s->pop();
            while(temp != '(')
            {
                std::cout << temp;
                temp = s->pop();
            }
        }
        else
        {
            std::cout << "Bad Input. Unexpected " << item << " at position " << input_iter+1 << std::endl;
        }
        input_iter++;


        item = input[input_iter];
    }
    std::cout << std::endl;

}

bool InfixConvert::isoperator(char oper) {
    return (oper == '*' || oper == '/' || oper == '%' || oper == '+' || oper == '-');
}
