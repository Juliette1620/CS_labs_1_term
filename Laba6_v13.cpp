#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <cstring>
#include <cctype>   
#include <sstream>
#include <string>
using namespace std;

void strInput(char*);
void findDividers(char*);
void wordsDivision(char*, char*, int&, int&, int&, char&, stringstream&);
void toLowerRegister(char*, char*, int&, int&, stringstream&);
void reverseIfOnlyNumbers(char*, char*, int&, int&, char&, stringstream&);
void ifNumbers(int&, int&, char*);
void ifLetters(int&, int&, char*);
void newStrOutput(stringstream&);

int main() {
	setlocale(LC_ALL, "Russian");
	stringstream newStr;
	char* str = new char[301], temporary;
	char* dividers = new char[257];
	int length = 0, isNumber = 0, isLetter = 0;
	strInput(str);
	findDividers(dividers);
	cout << endl;
	wordsDivision(str, dividers, length, isNumber, isLetter, temporary, newStr);
	newStrOutput(newStr);
	delete[] str;
	system("pause");
	return 0;
}

void strInput(char* str) {
	cout << "Ведите строку." << endl;
	cout << "Исходная строка: ";
	cin.getline(str, 301);
	while (strlen(str) == 0) {
		cout << "Пустая строка!\nВведите строку снова\n";
		cin.getline(str, 301);
	}
}

void wordsDivision(char *str, char *dividers, int &length, int &isNumber, int &isLetter, char &temporary, stringstream &newStr) {
	char* token = 0;
	token = strtok(str, dividers);
	while (token != NULL) {
		length = strlen(token);
		ifNumbers(length, isNumber, token);
		ifLetters(length, isLetter, token);
		if ((strlen(token) < 7) && isNumber == 1)
			reverseIfOnlyNumbers(dividers, token, isNumber, length, temporary, newStr);
		else
			toLowerRegister(dividers, token, isLetter, length, newStr);
		token = strtok(NULL, dividers);
		isNumber = 0;
	}
}

void findDividers(char *dividers) {
	dividers[255] = 'a';
	int i = 32;
	while (dividers[255] == 'a') {
		if ((i >= 0 && i <= 47) || (i >= 58 && i <= 64) || (i >= 91 && i <= 96) || (i >= 123 && i <= 255))
			dividers[i] = i;
		i++;
	}
	dividers[i] = '\0';
}

void toLowerRegister(char *dividers, char *token, int &isLetter, int &length, stringstream &newStr) {
	if (isLetter == 1) {
		if (length > 0) {
			for (int i = 0; i < length; i++) {
				newStr << (char)tolower(token[i]);
			}
		}
		/*newStr << " ";*/
	}
	else
		newStr << token;
		newStr << " ";
}

void reverseIfOnlyNumbers(char *dividers, char *token, int &isNumber, int &length, char &temporary, stringstream &newStr) {
		if (length > 0) {
			for (int i = 0; i < length - 1; i++, length--) {
				temporary = token[length - 1];
				token[length - 1] = token[i];
				token[i] = temporary;
			}
		}
		newStr << token;
		newStr << " ";

}
void ifNumbers(int &length, int &isNumber, char *token) {
	for (int i = 0; i < length; i++) {
		if (token[i] >= '0' && token[i] <= '9')
			isNumber = 1;
	}
}

void ifLetters(int &length, int &isLetter, char *token) {
	for (int i = 0; i < length; i++) {
		if (isalpha(token[i]))
			isLetter = 1;
	}
}

void newStrOutput(stringstream &newStr) {
	cout << "Новая строка: ";
	cout << newStr.str();
	cout << endl;
}
