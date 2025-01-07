#include "Binary_tree.h"

void Binary_tree::remove(Node* node) 
{
    if (node) 
    {
        remove(node->left);
        remove(node->right);
        delete node;
    }
}

Node* Binary_tree::min(Node* node) const 
{
    while (node && node->left)
    {
        node = node->left;
    }
    return node;
}

Node* Binary_tree::max(Node* node) const 
{
    while (node && node->right)
    {
        node = node->right;
    }
    return node;
}

Node* Binary_tree::next(Node* node) const 
{
    //���������� ������, ���� node ����
    if (!node)
    {
        return nullptr;
    }

    Node* parent = nullptr;

    if (node->right) 
    {
        return min(node->right);
    }

    parent = node->parent;

    while (parent && node == parent->right) 
    {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

Node* Binary_tree::prev(Node* node) const 
{
    //���������� ������, ���� node ����
    if (!node)
    {
        return nullptr;
    }

    Node* parent = nullptr;

    if (node->left) 
    {
        return max(node->left);
    }

    parent = node->parent;

    while (parent && node == parent->left) 
    {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

Node* Binary_tree::search(Node* node, int key) const
{
    while (node)
    {
        if (key == node->key)
        {
            return node;
        }
        //������� � ����� �����, ���� ������� ���� ������ �������� � ������� ����, � � ������ - ���� ������
        node = (key < node->key) ? node->left : node->right;
    }

    return nullptr;
}

void Binary_tree::print(Node* node, int parametr) const
{
    //���������� ������, ���� node ����
    if (!node)
    {
        return;
    }
    //�������� ����������, ��� ��������. ���� �� �� ����� 0, �� ��������� ��������� ������ �� ����� �������
    if (parametr != 0)
    {
        cout << node->key << " " << node->offense;
    }

    else
    {
        print(node->left);

        cout << node->key << " " << node->offense << "\n";

        print(node->right);
    }

}

void Binary_tree::insert(int value, string offense)
{
    Node* new_node = new Node(value, offense);
    Node* current = root;
    Node* parent = nullptr;

    if (!root) 
    {
        root = new_node;
        return;
    }

    if (search(root, value) != nullptr)
    {
        search(root, value)->offense.append(new_node->offense);
    }

    else
    {
        while (current)
        {
            parent = current;

            if (value < current->key)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        new_node->parent = parent;

        if (value < parent->key)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }
    }

}

void Binary_tree::remove_tree(Node* node) 
{
    if (!node)
    {
        return;
    }

    if (node == root) 
    {
        remove(root);
        root = nullptr;
    }
    else 
    {
        if (node->parent->left == node) 
        {
            node->parent->left = nullptr;
        }
        else 
        {
            node->parent->right = nullptr;
        }
        remove(node);
    }
}

void Binary_tree::remove_node(Node*& node)
{

    if (!node)
    {
        return;
    }

    //�������� ����� � ����� �������� ��� ������ ��� ��������
    if (!node->left)
    {
        Node* temp = node->right;

        if (temp)
        {
            //y�������� �� �������� ������ ����� ����������� ����� �������� ���������� ����
            temp->parent = node->parent;
        }
        delete node;
        //����������� ��������� ����� ������ ����
        node = temp;
    }
    else if (!node->right)
    {
        Node* temp = node->left;

        if (temp)
        {
            //y�������� �� �������� ����� ����� ����������� ����� �������� ���������� ����
            temp->parent = node->parent;
        }
        delete node;
 
        node = temp;
    }
    else
    {
        //���� � ���� ��� �������, �� ������� ��� ����������, ������� ��������� �������
        Node* next_node = next(node);

        //����������� ���������� �� ���������� ���� � �������
        node->key = next_node->key;
        node->offense = next_node->offense;

        remove_node(next_node);
    }
}