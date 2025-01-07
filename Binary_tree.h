#pragma once
#include "Node.h"

class Binary_tree {
private:
    Node* root;
    //c�������� ����� ��� �������� ������ ��� �����
    void remove(Node* node);

public:
    Binary_tree() : root(nullptr) {}

    Node* get_root() const { return root; }
    //����� ���� � ����������� ���������
    Node* min(Node* node) const;
    //����� ���� � ������������ ���������
    Node* max(Node* node) const;
    //��������� ����
    Node* next(Node* node) const;
    //���������� ����
    Node* prev(Node* node) const;
    //����� ���� �� �����
    Node* search(Node* node, int key) const;
    //���������� ���������� � ������
    void print(Node* node, int parametr = 0) const;
    //������� ����
    void insert(int value, string offense);
    //�������� ������ �� ���������� ����
    void remove_tree(Node* node);
    //�������� ����
    void remove_node(Node*& node);

    ~Binary_tree() { remove(root); }
};
