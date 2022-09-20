#include "avl_search_tree.h"

void AVLSearchTree::destroyTree(NodeType*& tree) {
    if(tree != NULL) {
        destroyTree(tree->esquerda);
        destroyTree(tree->direita);
        delete tree;
    }
}
bool AVLSearchTree::isEmpty() const {
    return root == NULL;
}
bool AVLSearchTree::isFull() const {
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }    
}
void AVLSearchTree::retrieveAluno(NodeType* tree, Aluno &aluno, bool &found) const {
    if (tree == NULL)
        found = false;
    else if (aluno.getRa() < tree ->aluno.getRa())
        retrieveAluno(tree->esquerda, aluno, found);
    else if (aluno.getRa() > tree ->aluno.getRa())
        retrieveAluno(tree->direita, aluno, found);
    else {
        aluno = tree -> aluno;
        found = true;
    }
}
void AVLSearchTree::insertAluno(NodeType*& tree, Aluno aluno, bool &isTaller)  {
    if (tree == NULL) {
        tree = new NodeType;
        tree->direita = NULL;
        tree->esquerda = NULL;
        tree->aluno = aluno;
        tree->fatorB = 0;
        isTaller = true;
        return;
    }
    else if (aluno.getRa() < tree->aluno.getRa()) {
        insertAluno(tree->esquerda, aluno, isTaller);
        if (isTaller)
            tree->fatorB = tree->fatorB - 1;
    } else {
        insertAluno(tree->direita, aluno, isTaller);
        if (isTaller)
            tree->fatorB = tree->fatorB + 1;
    }
    
    performRotations(tree);

    if (isTaller && tree->fatorB == 0) {
        isTaller = false;
    }
}
void AVLSearchTree::deleteAluno(NodeType*& tree, int aluno) {
    if (aluno < tree->aluno.getRa())
        deleteAluno(tree->esquerda, aluno);
    else if (aluno > tree->aluno.getRa())
        deleteAluno(tree->direita, aluno);
    else if (aluno == tree->aluno.getRa())
        deleteNode(tree);
}
void AVLSearchTree::deleteNode(NodeType*& tree) {
    Aluno data;
    NodeType* tempPtr;
    tempPtr = tree;
    if (tree->esquerda == NULL) {
        tree = tree->direita;
        delete tempPtr;
    }
    else if (tree->direita == NULL) {
        tree = tree->esquerda;
        delete tempPtr;
    }
    else {
        getSuccessor(tree, data);
        tree->aluno = data;
        deleteAluno(tree->direita, data.getRa());
    }
}
void AVLSearchTree::getSuccessor(NodeType* tree, Aluno& data) {
    tree = tree->direita;
    while (tree->esquerda != NULL)
        tree = tree->esquerda;
    data = tree->aluno;
}
void AVLSearchTree::printPreOrder(NodeType *tree) const {
    if (tree != NULL) {
        std::cout << tree->aluno.getNome() << " , ";
        printPreOrder(tree->esquerda);
        printPreOrder(tree->direita);
    }
}
void AVLSearchTree::printInOrder(NodeType *tree) const {
    if (tree != NULL) {
        printInOrder(tree->esquerda);
        std::cout << tree->aluno.getNome() << " , ";
        printInOrder(tree->direita);
    }
}
void AVLSearchTree::printPostOrder(NodeType *tree) const {
    if (tree != NULL) {
        printPostOrder(tree->esquerda);
        printPostOrder(tree->direita);
        std::cout << tree->aluno.getNome() << " , ";
    }
}