#pragma once
#include "Node.h"

class Binary_tree {
private:
    Node* root;
    //cервисный метод для удаления дерева под узлом
    void remove(Node* node);

public:
    Binary_tree() : root(nullptr) {}

    Node* get_root() const { return root; }
    //поиск узла с минимальным значением
    Node* min(Node* node) const;
    //поиск узла с максимальным значением
    Node* max(Node* node) const;
    //следующий узел
    Node* next(Node* node) const;
    //предыдущий узел
    Node* prev(Node* node) const;
    //поиск узла по ключу
    Node* search(Node* node, int key) const;
    //показывает информацию о дереве
    void print(Node* node, int parametr = 0) const;
    //вставка узла
    void insert(int value, string offense);
    //удаление дерева от указанного узла
    void remove_tree(Node* node);
    //удаление узла
    void remove_node(Node*& node);

    ~Binary_tree() { remove(root); }
};
