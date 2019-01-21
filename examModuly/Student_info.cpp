
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
		//이전 내용을 제거
		hw.clear();

		//과제 점수를 읽음.
		double x;

		while (in >> x)
			hw.push_back(x);
		//다음 학생의 점수 입력 작업을 고려해 스트림을 지움.
		in.clear();
	}
	return in;
}

istream& read(istream& is, Student_info& s)
{
	//학생의 이름, 중간시험 점수, 기말시험 점수를 읽어 저장
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}