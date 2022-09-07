#include <Hash.h>
#include <iostream>
using namespace std;

Hash::Hash(int max) {
    length = 0;
    max_items = max;
    structure = new Aluno[max_items];
}
Hash::~Hash() {
    delete [] structure;
}
bool Hash::isFull() const {
    return (length == max_items);
}
bool Hash::getLength() const {
    return length;
}
void Hash::retrieveItem(Aluno& aluno, bool& found) {
    int location = getHash(aluno);
    Aluno aux = structure[location];
    if (aluno.getRA() != aux.getRA()) {
        found = false;
    } else {
        found = true;
        aluno = aux;
    }
}
void Hash::insertItem(Aluno aluno) {
    int location = getHash(aluno);
    structure[location] = aluno;
    length++;
}
void Hash::deleteItem(Aluno aluno) {
    int location = getHash(aluno);
    structure[location] = Aluno();
    length--;
}
void Hash::print() {
    for (int i = 0; i < max_items; i++)
    {
        cout << i << ":" <<
            structure[i].getRA() << ", " <<
            structure[i].getNome() << endl;
    }    
}
int Hash::getHash(Aluno aluno) {
    return aluno.getRA() % max_items;
}