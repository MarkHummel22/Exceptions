// Mark Hummel
// CIS 1202
// 12/3/22

#include <iostream>
#include <string>
#include "Alphabet.h"

using namespace std;
class invalidRangeException {};
class invalidCharacterException{};
char character(char[], char, int);


int main() {
	char arr[52]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	try {
		cout << character(arr, 'A', 1) << endl;
	}
	catch(invalidRangeException){
		cout << "The offset is out of range" << endl;
	}
	catch (invalidCharacterException) {
		cout << "The character is out of range" << endl;
	}
	system("pause");

	return 0;
}


char character(char arr[52], char start, int offset) {
	int i = 0;
	bool found = false;
	char output;
	if (start >= 'A' && start <= 'z') {
		while (i < 52 && !found) {
			if (arr[i] == start) {
				found = true;
				output = i;
			}
			i++;
		}
		output = arr[(i - 1) + offset];
		if (output < 'A' || output > 'z') {
			throw invalidRangeException();
		}
	}
	else
		throw invalidCharacterException();
	return output;
}

