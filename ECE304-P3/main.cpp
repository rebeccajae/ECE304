#include <iostream>
#include "InfixConvert.h"

int main() {
    char infix[200];

    InfixConvert* ic = new InfixConvert();
    std::cout << "Convert from infix to postfix. The input may contain single letter variables, numbers, and ()*+-/." <<std::endl;
    std::cout << "Enter infix expression: ";
    gets(infix);
    std::cout << "Postfix Expression: ";
    ic->convert(infix);

    return 0;
}

