#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int key;
    string offense;

    Node* left;
    Node* right;
    Node* parent;

    Node(int key_P, string offense_p) : key(key_P), offense(offense_p), left(nullptr), right(nullptr), parent(nullptr) {}
};

