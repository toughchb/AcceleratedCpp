#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector; using std::string;
using std::search;

bool not_url_char(char c)
{
	// URL�� �� �� �ִ� ���ĺ��� ���� �̿��� ����
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

	// c�� URL�� �� �� �ִ� �������� Ȯ���ϸ� ������ ��ȯ
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";
	typedef string::const_iterator iter;

	// i�� ���� ��ȣ�� �߰��� ��ġ�� ǥ��
	iter i = b;

	while ((i = search(i, e, sep.begin(), sep.end())) != e) {
		// ���� ��ȣ�� ���� Ž�� ������ ó�� �Ǵ� �������� �ִ��� Ȯ��
		if (i != b && i + sep.size() != e) {
			// beg�� �������� �̸��� ���� ��ġ�� ǥ��
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
				--beg;
			// ���� ��ȣ �յڷ� URL�� �Ϻο��� ��ȿ�� ���ڰ� �ϳ��� �ִ��� Ȯ��
			if (beg != i && !not_url_char(i[sep.size()]))
		}
			
	}
}
string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
	return std::find_if(b, e, not_url_char);
}
vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	//�μ��� ���޹��� ���ڿ� ��ü�� Ž��
	while (b != e) {
		// ://�� ���ʿ��� �ϳ� �̻��� ���ڸ� Ž��
		b = url_beg(b, e);
		if (b != e) {
			// �ش� ���ڸ� ã�Ҵٸ� URL�� ������ �κ��� Ž��
			iter after = url_end(b, e);

			// URL�� ����
			ret.push_back(string(b, after));

			//�μ��� ���޹��� ���ڿ����� �� �ٸ� URL�� ã�� ���� b�� ����
			b = after;
		}
	}
	return ret;

}
