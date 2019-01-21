#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::string; using std::cout;
using std::cin; using std::equal;
bool is_palindrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
	string input;
	cout << "문자 입력하면 회문인지 알려줌 : " ;
	cin >> input;
	if (is_palindrome)
		cout << "회문\n";
	else
		cout << "아님\n";

	return 0;
}