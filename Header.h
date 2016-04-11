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
#include <array>
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
	vector <char> frequencyVector = {'z','q','j','x','k','v','b','p','g','y','f','w','m','c','u','l','d','r','h','s','n','i','o','a','t','e'}; // Char vector ordered by freq.
	vector <int> orderedVector;
	map <char, int> fileAlphabetFrequency;
	map <char, char> decodedMap;
};


typedef array<pair<char, double>, 26> FreqArray;

class VigenereAnalyser{
public:
	VigenereAnalyser(const array<double, 26>& targetFreqs);
	VigenereAnalyser();
	pair<string, string> analyze(string input);
	void decypherSecret();
private:
	array<double, 26> targets;
	array<double, 26> sortedTargets;
	FreqArray freq;

	// Update the freqs array
	FreqArray& frequency(const string& input);

	double correlation(const string& input);


};