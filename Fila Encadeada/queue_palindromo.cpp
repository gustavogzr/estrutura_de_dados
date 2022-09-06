/* 
código para gerar o executável: g++ queue_palindromo.cpp queue.cpp stack.cpp -o queue_palindromo
*/

#include "queue.h"
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    bool palindromo = true;

    char character;
    char stackChar;
    char queueChar;

    Stack stack;
    Queue queue;

    cout << "Adiciona uma string para verificar se ela e um palindromo:" << endl;
    cin.get(character);
    while (character != '\n') {
        stack.push(character);
        queue.enqueue(character);
        cin.get(character);
    }
    while (palindromo && !queue.isEmpty()) {
        stackChar = stack.pop();
        queueChar = queue.dequeue();
        if (stackChar != queueChar)
            palindromo = false;
    }
    if (palindromo)
        cout << "A string e um palindromo" << endl;
    else
        cout << "A string nao e um palindromo" << endl;
    return 0;
}