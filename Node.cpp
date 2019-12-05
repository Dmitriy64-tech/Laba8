#include"Node.h"


void insert(Node* first, int index, string str)
{
	if (index >= 0)
	{
		Node* current = first;
		for (int i = 0; i < index-1; i++)
		{
			current = current->next;
		}
		Node* newNode = new Node();
		newNode->row = str;
		newNode->next = current->next;
		current->next = newNode;
	}
}

Node* opentext(string filePath)
{
	Node* first = new Node();
	Node* current = first;
	string str;
	ifstream inf(filePath);
	getline(inf, str);
	current->row = str;
	while (getline(inf, str))
	{
		Node* newNode = new Node();
		newNode->row = str;
		current->next = newNode;
		current = current->next;
	}
	current->next = nullptr;
	current = first;
	while (current != NULL)
	{
		cout << current->row << endl;
		current = current->next;
	}
	cout << endl;
	inf.close();
	return first;
}


Node* remove(Node* first, int index)
{
	if (index >= 0)
	{
		Node* current = first;
		for (int i = 0; i < index-2; i++)
		{
			if (current != NULL)
			{
				current = current->next;
			}
		}
		current->next = current->next->next;
		return first;
	}
}


void display(Node* first)
{
	Node* current = first;
	while (current)
	{
		cout << current->row << endl;
		current = current->next;
	}

}


void maxC(Node* first, char c)
{
	int k = 0, i = 1, j = 0, max = 0, pos = 0;
	string line;
	Node* current = first;

	while (current != NULL)
	{
		line = current->row;
		j = line.find(c);
		if (line.find(c) != std::string::npos)
		{
			break;
		}

		current = current->next;
		i++;
	}
	cout << "first " << c << " in:" << i << " line, " << j + 1 << " posision" << endl;

	current = first;
	i = 1;
	while (current != NULL)
	{
		line = current->row;
		for (int j = 0; j < line.size(); j++)
		{
			if (line[j] == c)
			{
				k++;
			}
		}
		if (max < k)
		{
			max = k;
			pos = i;
		}
		k = 0;
		i++;
		current = current->next;
	}
	cout << "max " << c << " in line:" << pos << endl;
}


Node* copyInsert(Node* first, int index, int target)
{
	Node* current = first;
	int tar = target;
	string str;
	if (index >= 0)
	{
		for (int i = 0; i < index-1; i++)
		{
			if (current != NULL)
			{
				current = current->next;
			}
		}
	}
	str = current->row;
	insert(first, tar, str);
	return first;
}

void writetext(Node* first)
{
	ofstream outf("../out.txt");
	if (!outf)
	{
		cout << "error!";
	}
	Node* current = first;
	while (current != NULL)
	{
		outf << current->row<< endl;
		current = current->next;
	}

	cout << "file writed!";
	outf.close();
}

