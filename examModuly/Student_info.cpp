
//Student_info.c

#include "Student_info.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}


istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		//���� ������ ����
		hw.clear();

		//���� ������ ����.
		double x;

		while (in >> x)
			hw.push_back(x);
		//���� �л��� ���� �Է� �۾��� ����� ��Ʈ���� ����.
		in.clear();
	}
	return in;
}

istream& read(istream& is, Student_info& s)
{
	//�л��� �̸�, �߰����� ����, �⸻���� ������ �о� ����
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}