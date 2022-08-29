#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

// returns count of non-overlapping occurrences of 'sub' in 'str'

int countSubstring(const string& str, const string& sub)

{
	if (sub.length() == 0) return 0;
	int count = 0;
	for (int offset = str.find(sub); offset != string::npos; offset = str.find(sub, offset + sub.length()))
	{
		++count;
	}
	return count;

}

int count(string s, char c)
{
	int wc;

	wc = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == c) wc++;
	}
	return wc;
}

int uniquewordcount(string s)
{
	map<string, int> words;

	char *b = (char *)malloc(s.length());
	strcpy(b, s.c_str());

	b = strtok(b, " ");
	while (b != NULL) {
		words[b] = 0;
		b = strtok(NULL, " ");
	}
	return words.size() - 2;
}

int lexicaldensity(string s)
{
	return (int)((uniquewordcount(s)/(float)count(s, ' ')) * 100.0 + 0.5);
}

int main()
{
	string source = ("I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo. "
			 "I got the ramblin fever. Said goodbye to ma and pa. Crossed that ol red river and this is "
			 "what I saw. I saw miles and miles of Texas 1000 stars up in the sky. I saw miles and miles of Texas gonna live here till I die.");

	int wordcount = count(source, ' ');
	int sentencecount = count(source, '.');

	/* Count occurrences of the word 'is'.  */
	cout << "substring count: " << countSubstring(source, "is") << endl;
	cout << "word count: " << wordcount << endl;
	cout << "Unique word count: " << uniquewordcount(source) << endl;
	cout << "Lexical density: " << lexicaldensity(source) << "%" << endl;
	return 0;
}
