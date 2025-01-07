#pragma once
#include "Node.h"

class Binary_tree {
private:
    Node* root;
    //cервисный метод для удаления дерева под узлом
    void remove(Node* node)noexcept;

public:
    Binary_tree()noexcept : root(nullptr) {}

    Node* get_root() const noexcept { return root; }
    //поиск узла с минимальным значением
    Node* min(Node* node) const noexcept;
    //поиск узла с максимальным значением
    Node* max(Node* node) const noexcept;
    //следующий узел
    Node* next(Node* node) const noexcept;
    //предыдущий узел
    Node* prev(Node* node) const noexcept;
    //поиск узла по ключу
    Node* search(Node* node, int key) const noexcept;
    //показывает информацию о дереве
    void print(Node* node, int parametr = 0) const noexcept;
    //вставка узла
    void insert(int value, string offense) noexcept;
    //удаление дерева от указанного узла
    void remove_tree(Node* node) noexcept;
    //удаление узла
    void remove_node(Node*& node) noexcept;

    ~Binary_tree() { remove(root); }
};
