#pragma once
#include "Node.h"

class Binary_tree {
private:
    Node* root;
    //c�������� ����� ��� �������� ������ ��� �����
    void remove(Node* node)noexcept;

public:
    Binary_tree()noexcept : root(nullptr) {}

    Node* get_root() const noexcept { return root; }
    //����� ���� � ����������� ���������
    Node* min(Node* node) const noexcept;
    //����� ���� � ������������ ���������
    Node* max(Node* node) const noexcept;
    //��������� ����
    Node* next(Node* node) const noexcept;
    //���������� ����
    Node* prev(Node* node) const noexcept;
    //����� ���� �� �����
    Node* search(Node* node, int key) const noexcept;
    //���������� ���������� � ������
    void print(Node* node, int parametr = 0) const noexcept;
    //������� ����
    void insert(int value, string offense) noexcept;
    //�������� ������ �� ���������� ����
    void remove_tree(Node* node) noexcept;
    //�������� ����
    void remove_node(Node*& node) noexcept;

    ~Binary_tree() { remove(root); }
};
