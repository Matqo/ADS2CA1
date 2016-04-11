#include "Header.h"

/***************************************************************************************
*    Title: rot13
*    Author: stormy6161
*    Date: 27/03/2016
*    Code version: 1.0
*    Availability: http://www.cplusplus.com/forum/general/187630/
*	 Usage: Based On (Logic for modulus on char)
***************************************************************************************/

void rot13::performRotation() {
	ifstream poem;
	ofstream rotatedPoem;
	char cchar;
	poem.open("poem.txt");
	rotatedPoem.open("rotatedPoem.txt");
	while (poem.get(cchar)) {
		if (cchar >= 'A' && cchar <= 'Z') {
			char n = (cchar - 'A' + 13) % 26 + 'A';
			rotatedPoem << n;
		}
		else if (cchar >= 'a' && cchar <= 'z') {
			char n = (cchar - 'a' + 13) % 26 + 'a';
			rotatedPoem << n;
		}
		else {
			rotatedPoem << cchar;
		}
	}

}


// My implementation of the frequency analysis attack based on assignment in the CA
// However, upon finishing this I've found out that this requires much more than just an freq. analysis
void rot13::decodeSecretFile() {
	char cchar;
	ifstream secret;
	ofstream decodedSecret;
	secret.open("secretk3.txt");
	decodedSecret.open("decodedSecret.txt");
	while (secret.get(cchar)) {
		if ((cchar <= 'z' && cchar >= 'a') || (cchar <= 'Z' && cchar >= 'A')) {
			if (fileAlphabetFrequency[cchar] != -1) {
				fileAlphabetFrequency[cchar]++;
				//cout << " LETTER " << cchar << " FREQ " << fileAlphabetFrequency[cchar] << endl;
			}
			else {
				fileAlphabetFrequency[cchar, 0];
			}
		}
	}

	for (auto i = fileAlphabetFrequency.begin(); i != fileAlphabetFrequency.end(); i++) {
		orderedVector.push_back(i->second);
	}
	sort(orderedVector.begin(),orderedVector.end());

		for (auto i = orderedVector.begin(); i != orderedVector.end(); i++) {
			cout << " VALUE :: " << *i << endl;
		}

		for (int x = 0; x < 26; x++) {
		int largestOccurence = orderedVector.back();
		orderedVector.pop_back();
		//int currentOccurence = 0;
		for (auto i = fileAlphabetFrequency.begin(); i != fileAlphabetFrequency.end(); i++) {
			if (i->second == largestOccurence) {
				//for (auto n = decodedMap.begin(); n != decodedMap.end(); n++) {
					//if (n->second != frequencyArray[x]) {
				//if (largestOccurence == i->second) {
				//	largestOccurence = i->second-1;
				//}
				//else {
				//if (currentOccurence != i->second) {
					largestOccurence = i->second;
					//currentOccurence = largestOccurence;
					decodedMap[i->first] = frequencyVector.back();

				//}
				//else {
				//	largestOccurence = i->second;
				//	frequencyVector.pop_back();
				//	decodedMap[i->first] = frequencyVector.back();
				//}
				//}
					//}
				//}
				
				//cout << " MAP : " << i->first << " IS " << frequencyArray[x] << endl;
			}
		}frequencyVector.pop_back();
	}

	for (auto i = decodedMap.begin(); i != decodedMap.end(); i++) {
		cout << " CHAR : " << i->first << " IS " << i->second << endl;
	}

	secret.close();
	secret.open("secretk3.txt");
	while (secret.get(cchar)) {
		if ((cchar <= 'z' && cchar >= 'a') || (cchar <= 'Z' && cchar >= 'A')) {
			
			decodedSecret << decodedMap[cchar];
		}
		else {
			decodedSecret << cchar;
		}
	}

}