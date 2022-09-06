#ifndef NODETYPE_H // trecho inserido para garantir que o nodetype não será definido mais de uma vez
#define NODETYPE_H

typedef char ItemType;

struct NodeType
{
    ItemType info;
    NodeType* next;
};

#endif