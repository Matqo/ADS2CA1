#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#include <algorithm>
using namespace std;

class huffmanNode {
public:
	char data;
	int weight;
	huffmanNode *left, *right;
private:

};

class compare {
public:
	bool operator()(const huffmanNode* one, const huffmanNode* two) {
		return one->weight > two->weight;
	}
};

class treeMethods {
public:
	void getOccurences();
	void mapToQueue();
	huffmanNode* joinTrees();
	void getEncLoc(); // Just prints binary location - informative
	void recurTree(huffmanNode* node);
	void genCodes(huffmanNode* node, string bitsSoFar);
	void writeCodes();
	void deCode(huffmanNode* node);
	void bitToChar();
	void charToBit();
	void cleanup();
private:
	map <char, int> charMap;
	priority_queue<huffmanNode*, vector<huffmanNode*>, compare> huffmanQueue;
	huffmanNode* node;
	map <char, string> enMap;
	int step; // Only used to display traversal
};

class rot13 {
public :
	void performRotation();
	void decodeSecretFile();
private:
	//map <char, int> alphabetFrequencyMap;
	char frequencyArray[26] = {'e','t','a','o','i','n','s','h','r','d','l','u','c','m','w','f','y','g','p','b','v','k','x','j','q','z'}; // Char array ordered by freq.
	vector <int> orderedVector;
	map <char, int> fileAlphabetFrequency;
	map <char, char> decodedMap;
};