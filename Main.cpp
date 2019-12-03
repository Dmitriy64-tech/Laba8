#include"Node.h"
#include<fstream>

using namespace std;

int main() {
	Node* current = NULL;
	string file;
	//file = "test.txt";
	cout << "Enter name of file to create list: " << endl;
	cin >> file;
	Node* first = opentext(file);
	cout << "\n===========Insert============\n";
	insert(first, 2, "Hello!");
	display(first);
	cout << "\n===========REMOVE======================\n";
	first = remove(first, 4);
	display(first);
	cout << "\n==============MAX===================\n";
	maxC(first, 'i');
	cout << "\n=====================================\n";
	display(first);
	cout << "\n===========COPYINSERT======================\n";
	first = copyInsert(first, 1, 4);
	display(first);
}