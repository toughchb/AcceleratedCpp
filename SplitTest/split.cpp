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
//	// 지금까지 [원래의 i 현재의 i) 범위에 있는 문자들을 처리
//
//	while (i != s.size()) {
//		//선행하는 공백들을 무시
//
//		// [원래의 i 현재의 i) 범위에 있는 문자들은 모두 공백
//		while (i != s.size() && isspace(s[i]))
//			++i;
//		//순서상 다음 단어의 끝을 찾음.
//		string_size j = i;
//
//		// [원래의 j 현재의 j) 범위에 있는 문자들은 공백이 아님
//		while (j != s.size() && !isspace(s[j]))
//			j++;
//		//공백이 아닌 문자들을 찾았을 때
//		if (i != j) {
//			//i 에서 j-1개의 문자들을 s에 복사
//			ret.push_back(s.substr(i, j - i));
//			i = j;
//		}
//	}
//	return ret;
//}
// 인수가 공백일 때는 true, 아닐때는 false 반환
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
		//선행 공백을 무시
		i = std::find_if(i, str.end(), not_space);

		//다음 단어의 끝을 찾음.
		iter j = std::find_if(i, str.end(), space);

		// [i,j] 범위의 문자를 복사
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

	//상단 테두리 추가
	ret.push_back(border);

	// 양 끝이 별표와 공백으로 둘러싸인 문자열들을 각각 추가
	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}

	//하단 테두리 추가
	ret.push_back(border);
	return ret;
}
vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
	//위쪽 문자 그림을 복사
	vector<string> ret = top;

	//아래쪽 문자 그림을 복사
	for(vector<string>::const_iterator it = bottom.begin(); )
}

int main()
{
	string s;

	//문자열을 한 행씩 입력 받아 분할
	while (getline(cin,s))
	{
		vector<string> v = split(s);

		//벡터 v에 저장한 단어를 각각 출력
		for (vector<string>::size_type i = 0; i != v.size(); i++)
			cout << v[i] << endl;
	}
	return 0;
}