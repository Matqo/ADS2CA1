#include "Header.h"


//https://youtu.be/OSl-GpHA3Fs
int main() {
	huffmanNode* pointer;
	treeMethods t1;
	t1.getOccurences();
	t1.mapToQueue();
	pointer = t1.joinTrees();
	
	//t1.recurTree(pointer);
	t1.genCodes(pointer, ""); // Just prints binary location - informative
	t1.getEncLoc();
	t1.writeCodes();
	t1.bitToChar();
	t1.charToBit();
	t1.deCode(pointer);
	t1.cleanup(); // Comment this line to keep the temporary compression & en/decoding files

	rot13 r13;
	r13.performRotation();
	r13.decodeSecretFile();
	VigenereAnalyser v1;
	v1.decypherSecret();

	system("pause");
	return 0;
}
//http://www.cplusplus.com/forum/general/112141/

