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
	cout << "���� �Է��ϸ� ȸ������ �˷��� : " ;
	cin >> input;
	if (is_palindrome)
		cout << "ȸ��\n";
	else
		cout << "�ƴ�\n";

	return 0;
}