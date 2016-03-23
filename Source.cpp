#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


/***************************************************************************************
*    Title: Priority Queue and Huffman Encoding Tree
*    Author: Hans Dulimarta
*    Date: 11/11/2014
*    Code version: 1.0
*    Availability: https://youtu.be/OSl-GpHA3Fs
*	 Usage: Based On
***************************************************************************************/

class huffmanNode {
public:
	char data;
	int count;
	huffmanNode *left, *right;
};

class compare {
public:
	bool operator()(const huffmanNode* one, const huffmanNode* two){
		return one->count > two->count;
	}
};



//https://youtu.be/OSl-GpHA3Fs
int main() {
	map <char, int> charMap;
	ifstream textFile;
	textFile.open("test.txt");
	char tempChar;
	
	while (!textFile.eof()) {
		textFile.get(tempChar);
		//cout << tempChar;
		if (charMap[tempChar] != '0') {
			charMap[tempChar]++;
		}
		else {
			charMap[tempChar,0];
		}
		//charMap[tempChar,tempInt];
	}

	priority_queue<huffmanNode*, vector<huffmanNode*>, compare> huffmanQueue;

	for (auto i = charMap.begin(); i != charMap.end(); i++) {
		cout << "'" << i->first << "': ";
		cout << i->second << endl;
		huffmanNode* n = new huffmanNode;
		n->data = i->first;
		n->count = i->second;
		n->left = n->right = NULL;
		huffmanQueue.push(n);
	}

	//while (huffmanQueue.top().first != NULL) {
	//	cout << huffmanQueue.top().first;
	//	huffmanQueue.pop();
	//}
	/*huffmanNode* b = nullptr;*/
	while (huffmanQueue.size() >= 2) {
		auto low1 = huffmanQueue.top();
		huffmanQueue.pop();
		auto low2 = huffmanQueue.top();
		huffmanQueue.pop();
		huffmanNode* b = new huffmanNode;
		b->data = '.';
		b->count = low1->count + low2->count;
		b->left = low1;
		b->left = low2;
		huffmanQueue.push(b);

	}
	//huffmanNode* last = huffmanQueue.top();
	//huffmanNode* root = new huffmanNode;

	//root->data = '.';
	//root->count = b->count + last->count;
	//root->left = b;
	//root->right = last;
	system("pause");
	return 0;
}