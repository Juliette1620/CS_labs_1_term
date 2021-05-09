#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string> 
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
using namespace std;

void fileCheck(ifstream&);
void wordDividing(istringstream&, string&, int&, int&, string&, int&, string&);
void findMax(int&, int&, string&, string&);
void findMin(int&, int&, string&, string&);
void replacement(string&, string&, string&, string&, string&);

int main() {
	setlocale(LC_ALL, "ru");
	ifstream fin("input.txt");
	string str, word, maxWord, minWord, MAX = " MAX ", MIN = " MIN ";
	int minLength = INT16_MAX, maxLength = 0, wordLength = 0;
	size_t rows = 0;
	fileCheck(fin);
	while (!fin.eof()) {
		for (string line; getline(fin, line);) {
			istringstream s(line);
			line = " " + line + " ";
			wordDividing(s, word, wordLength, maxLength, maxWord, minLength, minWord);
			replacement(minWord, maxWord, line, MIN, MAX);
			cout << line << endl;
			minLength = INT16_MAX;
			maxLength = 0;
		}
	}
	std::cout << endl;
	std::system("pause");
	return 0;
}

void wordDividing(istringstream &s, string &word, int &wordLength, int& maxLength,
	string& maxWord, int& minLength, string& minWord) {
	while (s >> word) {
		wordLength = word.length();
		findMax(maxLength, wordLength, maxWord, word);
		findMin(minLength, wordLength, minWord, word);
	}
}

void findMax(int &maxLength, int &wordLength, string &maxWord, string &word) {
	if (maxLength <= wordLength) {
		maxLength = wordLength;
		maxWord = word;
	}
}

void findMin(int& minLength, int& wordLength, string& minWord, string& word) {
	if (minLength >= wordLength) {
		minLength = wordLength;
		minWord = word;
	}
}

void replacement(string &minWord, string& maxWord, string& line, string& MIN, string& MAX) {
	minWord = " " + minWord + " ";
	maxWord = " " + maxWord + " ";
	line.resize(line.size() + 4);
	line.replace(line.find(minWord), minWord.length(), MAX);
	line.replace(line.find(maxWord), maxWord.length(), MIN);
	line.replace(line.find(MAX), MAX.length(), maxWord);
	line.replace(line.find(MIN), MIN.length(), minWord);
}

void fileCheck(ifstream &fin) {
	if (!fin){
		cout << "Ошибка при открытии файла input.txt" << endl;
		exit(1);
	}
	if ((fin.peek() == EOF)) {
		cout << "Файл пуст!" << endl;
		exit(1);
	}
}