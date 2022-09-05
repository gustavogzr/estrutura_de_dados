/*
Linhas de código para executar o programa:

g++ stack_alinhamento.cpp stack.cpp -o stack
.\stack
*/

#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    ItemType character;
    Stack stack;
    ItemType stackItem;

    cout << "Insira uma String." << endl;
    cin.get(character);

    bool isMatched = true;
    while (isMatched && character != '\n')
    {
        if (character=='{' || character=='(' || character=='[') {
            stack.push(character);            
        }
        if (character=='}' || character==')' || character==']') {
            if (stack.isEmpty()) {
                isMatched = false;
            } else {
                stackItem = stack.pop();
                isMatched = (
                    (character == '}' && stackItem == '{') ||
                    (character == ')' && stackItem == '(') ||
                    (character == ']' && stackItem == '[')
                );
            }
        }
        cin.get(character);

    }
    
    if (isMatched && stack.isEmpty()) {
        cout << "Bem formada \n";
    } else {
        cout << "Mal formada \n";
    }
}