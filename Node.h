#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Node
{
	string row;
	Node* next;
};

Node* opentext(string a);
void insert(Node* first, int index, string str);
Node* remove(Node* first, int index);
void display(Node* first);
Node* copyInsert(Node* first, int index, int target);
void maxC(Node* first, char c);
void writetext(Node* first);
