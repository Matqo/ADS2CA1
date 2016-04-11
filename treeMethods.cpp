#include "Header.h"

void treeMethods::getOccurences() {
	ifstream textFile;
	textFile.open("test.txt");
	char tempChar;
	while (textFile.get(tempChar)) {
		if (charMap[tempChar] != -1) {
			charMap[tempChar]++;
		}
		else {
			charMap[tempChar, 0];
		}
	}
	textFile.close();
}

// Both of the references were used in order to get a deeper understanding of how the binary tree for huffman encoding functions.
/***************************************************************************************
*    Title: Priority Queue and Huffman Encoding Tree
*    Author: Hans Dulimarta
*    Date: 11/11/2014
*    Code version: 1.0
*    Availability: https://youtu.be/OSl-GpHA3Fs
*	 Usage: Based On
***************************************************************************************/
/***************************************************************************************
*    Title: huffman encoding
*    Author: Michaela Elise
*    Date: 30/09/2013
*    Code version: 1.0
*    Availability: http://www.cplusplus.com/forum/general/112141/
*	 Usage: Based On
***************************************************************************************/


void treeMethods::mapToQueue() {
	for (auto i = charMap.begin(); i != charMap.end(); i++) {
		cout << "'" << i->first << "': "; 
		cout << i->second << endl; // prints occurences
		huffmanNode* n = new huffmanNode;
		n->data = i->first;
		n->weight = i->second;
		n->left = n->right = NULL;
		huffmanQueue.push(n);
	}
}

huffmanNode* treeMethods::joinTrees() {
	while (huffmanQueue.size() > 1) {
		auto low1 = huffmanQueue.top();
		huffmanQueue.pop();
		auto low2 = huffmanQueue.top();
		huffmanQueue.pop();
		huffmanNode* b = new huffmanNode;
		b->data = -1;
		b->weight = low1->weight + low2->weight;
		b->left = low1;
		b->right = low2;
		huffmanQueue.push(b);
		//cout << low1->data;
	}
	return huffmanQueue.top();
}

void treeMethods::getEncLoc() { // Method to see Locaiton of each char
	for (auto i = enMap.begin(); i != enMap.end(); i++) {
		cout << "ENTRY: " << i->first << ": " << i->second << endl;
	}
}

void treeMethods::recurTree(huffmanNode* node) {
	char a;

	//cout << "\n" << node->weight;
	if (node->left != nullptr) {
		cout << "step: " << step++ << endl;
		cout << " " << node->left->weight;
		cout << node->left->data;
		recurTree(node->left);
	}
	if (node->right != nullptr) {
		cout << "step: " << step++ << endl;
		cout << " " << node->right->weight;
		cout << node->right->data;
		recurTree(node->right);
	}


	//return a;
};

void treeMethods::genCodes(huffmanNode* node, string bitsSoFar) {
	//char a;

	//cout << "\n" << node->weight;
	if (node->left != nullptr) {
		string bitsLeft = bitsSoFar;
		bitsLeft += "0";
		if (node->left->data != -1) {
			enMap[node->left->data] = bitsLeft;
		}
		/*cout << "step: " << step++ << endl;
		cout << " " << node->left->weight;
		cout << node->left->data;*/

		genCodes(node->left, bitsLeft);
	}
	if (node->right != nullptr) {
		std::string bitsRight = bitsSoFar;
		bitsRight += "1";
		if (node->right->data != -1) {
			enMap[node->right->data] = bitsRight;
		}
		//cout << "step: " << step++ << endl;
		//cout << " " << node->right->weight;
		//cout << node->right->data;

		genCodes(node->right, bitsRight);
	}
}

void treeMethods::writeCodes() {
	ofstream outputFile("encodedFile.txt");
	char cchar;
	ifstream textFile;
	textFile.open("test.txt");
	while (textFile.get(cchar)) {
		outputFile << enMap[cchar];
		//outputFile << ",";
	}
}

void treeMethods::deCode(huffmanNode* node) {
	char cchar;
	ofstream decodedFile;
	ifstream encodedFile;
	decodedFile.open("Decoded.txt");
	encodedFile.open("deCompressed.txt");
	string bits;
	huffmanNode* cPos = node;
	while (encodedFile.get(cchar)) {

		//encodedFile.get(cchar);
		//cout << cchar;
		if (cchar == '0') {
			cPos = cPos->left;
		}
		else {
			cPos = cPos->right;
		}
		if (cPos->data != -1) {
			decodedFile << cPos->data;
			cPos = node; // Back to root
		}

		//while(!=-1)


		// Initial solution after misreading the question.
		//if (cchar != ',') {
		//	bits += cchar;
		//	//cout << bits;
		//}
		//else {
		//	for (auto i = enMap.begin(); i != enMap.end(); i++) {
		//		if (i->second == bits) {
		//			decodedFile << i->first;
		//			bits = "";
		//		}
		//	}
		//}


	}
}


//while (huffmanQueue.top() != nullptr) {
//	cout << huffmanQueue.top()->data;
//	huffmanQueue.pop();
//}
/*huffmanNode* b = nullptr;*/

//huffmanNode* last = huffmanQueue.top();
//huffmanNode* root = new huffmanNode;

//root->data = '.';
//root->weight = b->weight + last->weight;
//root->left = b;
//root->right = last;
//cout << huffmanQueue.top()->right->left->data;

//cout << "DATA" << huffmanQueue.top()->weight;

//recurTree(huffmanQueue.top());
//code(huffmanQueue.top());
//cout << str_code;

void treeMethods::bitToChar() {
	char cchar;
	vector <char> cVec;
	//cout << cVec.size();
	ofstream charFile;
	ifstream encodedFile;
	charFile.open("compressed.txt");
	encodedFile.open("encodedFile.txt"); //input
	string bits;
	while (encodedFile.get(cchar)) {

		if (cVec.size() != 8) {
			//cout << cchar;
			cVec.push_back(cchar);
		}

		if (cVec.size() == 8) {
			string strBits;
			for (int i = 0; i < cVec.size(); i++) {
				strBits += cVec[i];
				//cout << "Position:: " << cVec[i] << endl;
				//cout << "StringBits::" << strBits << ", vector size: " << cVec.size() << endl;
			}
			cVec.clear();
			//cout << "BITS::::" << strBits << endl;
			bitset<8> myBits(strBits);
			charFile << char(myBits.to_ulong());
			bits = "";
		}



		if (encodedFile.peek() == EOF&& cVec.size() != 8 && cVec.size() != 0) {
			cout << "VEC SIZE " << cVec.size() << endl;
			int addition = 0; // Add one byte at the end of file to signify bits added. 
			while (cVec.size() != 8) {
				cVec.push_back('0');
				cout << "ADDED A BIT... ";
				addition++;
			}
			string strBits;
			for (int i = 0; i < cVec.size(); i++) {
				strBits += cVec[i];
			}
			cVec.clear();
			cout << "BITS::::" << strBits << endl;
			bitset<8> myBits(strBits);
			charFile << char(myBits.to_ulong());
			charFile << addition;
		}
		else if (encodedFile.peek() == EOF) {
			charFile << "0";
		}
	}
}


void treeMethods::charToBit() {
	char cchar;
	vector <char> cVec;
	cout << cVec.size();
	ofstream deCompressed, tempFile;
	ifstream charFile; //input
	deCompressed.open("deCompressed.txt");
	charFile.open("compressed.txt");
	tempFile.open("tempFile.txt");
	string bits;
	int addition = 0;
	char tempChar;
	while (charFile.get(cchar)) {
		if (charFile.peek() == EOF) {
			addition = cchar - '0';
			cout << "ADDITION : " << addition << endl;
		}
		else {
			tempFile << cchar;
		}
	}
	tempFile.close();
	charFile.close();
	charFile.open("tempFile.txt");
		while(charFile.get(cchar)) {
		
			//deCompressed << nChar;
			if (addition > 0 && charFile.peek() == EOF) {
				bitset<8> nChar(cchar);
				cout << "CURRENT :: " << nChar << endl;
				string tempChar = nChar.to_string();
				tempChar.erase(8 - addition, string::npos);
				//cout << "tchar" << tempChar;
				deCompressed << tempChar;	
			}
			else {
				bitset<8> nChar(cchar);
				cout << "CURRENT :: " << nChar << endl;
				deCompressed << nChar;
			}
		}
	
}

void treeMethods::cleanup() {
	remove("compressed.txt");
	remove("deCompressed.txt");
	remove("encodedFile.txt");
	remove("tempFile.txt");
	cout << " All temporary encoding/decoding & Compression/de-compression files deleted" << endl;
	cout << "Original file test.txt and de-coded & de-compressed Decoded.txt files remain" << endl;
}