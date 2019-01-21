#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>

using std::vector; using std::string; using std::isspace; 
using std::getline; using std::cin; using std::cout; using std::endl;
using std::max;

//vector<string> split(const string& s)
//{
//	vector<string> ret;
//	typedef string::size_type string_size;
//	string_size i = 0;
//
//	// ���ݱ��� [������ i ������ i) ������ �ִ� ���ڵ��� ó��
//
//	while (i != s.size()) {
//		//�����ϴ� ������� ����
//
//		// [������ i ������ i) ������ �ִ� ���ڵ��� ��� ����
//		while (i != s.size() && isspace(s[i]))
//			++i;
//		//������ ���� �ܾ��� ���� ã��.
//		string_size j = i;
//
//		// [������ j ������ j) ������ �ִ� ���ڵ��� ������ �ƴ�
//		while (j != s.size() && !isspace(s[j]))
//			j++;
//		//������ �ƴ� ���ڵ��� ã���� ��
//		if (i != j) {
//			//i ���� j-1���� ���ڵ��� s�� ����
//			ret.push_back(s.substr(i, j - i));
//			i = j;
//		}
//	}
//	return ret;
//}
// �μ��� ������ ���� true, �ƴҶ��� false ��ȯ
bool space(char c)
{
	return isspace(c);
}
bool not_space(char c)
{
	return isspace(c);
}
vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i = str.begin();

	while (i != str.end()) {
		//���� ������ ����
		i = std::find_if(i, str.end(), not_space);

		//���� �ܾ��� ���� ã��.
		iter j = std::find_if(i, str.end(), space);

		// [i,j] ������ ���ڸ� ����
		if (i != str.end())
			ret.push_back(string(i, j));

		i = j;
	}
	return ret;
}

string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
		maxlen = max(maxlen, v[i].size());
	return maxlen;
}
vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	//��� �׵θ� �߰�
	ret.push_back(border);

	// �� ���� ��ǥ�� �������� �ѷ����� ���ڿ����� ���� �߰�
	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}

	//�ϴ� �׵θ� �߰�
	ret.push_back(border);
	return ret;
}
vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
	//���� ���� �׸��� ����
	vector<string> ret = top;

	//�Ʒ��� ���� �׸��� ����
	for(vector<string>::const_iterator it = bottom.begin(); )
}

int main()
{
	string s;

	//���ڿ��� �� �྿ �Է� �޾� ����
	while (getline(cin,s))
	{
		vector<string> v = split(s);

		//���� v�� ������ �ܾ ���� ���
		for (vector<string>::size_type i = 0; i != v.size(); i++)
			cout << v[i] << endl;
	}
	return 0;
}