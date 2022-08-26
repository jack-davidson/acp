#include <iostream>

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

int main()

{
	string source = ("I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo. "
			 "I got the ramblin fever. Said goodbye to ma and pa. Crossed that ol red river and this is "
			 "what I saw. I saw miles and miles of Texas 1000 stars up in the sky. I saw miles and miles of Texas gonna live here till I die.");
	cout << "substring count: " << countSubstring(source, "is") << '\n';
	return 0;
}
