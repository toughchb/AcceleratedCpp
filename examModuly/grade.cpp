//grade.cpp
#include <stdexcept>
#include <vector>
#include <list>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::list;
using std::vector;
//중간시험 점수, 기말시험 점수, 종합 과제 점수에서 학생의 종합 점수를 구함
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4;
};

//중간시험 점수, 기말시험 점수, 종합 과제 점수에서 학생의 종합 점수를 구함
//이 함수는 인수를 복사하지 않고 median 함수가 해당 작업을 함
double grade(double midterm, double final, const std::vector<double>& hw)// grade 오버로딩
{
	if (hw.size() == 0)
		throw std::domain_error("student has done no homework");
	   
	return grade(midterm, final, median(hw));
};
double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}
bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

//인덱스 대신 iterator를 사용하지만 여전히 성능 저하가 우려됨.
//vector<Student_info> extract_fails(vector<Student_info>& students)
//{
//	vector<Student_info> fail;
//	vector<Student_info>::iterator iter = students.begin();
//	while (iter != students.end()) {
//		if (fgrade(*iter)) {
//			fail.push_back(*iter);
//			iter = students.erase(iter);
//		}
//		else
//			++iter;
//	}
//	return fail;
//}

// 네 번째 버전: 벡터 대신 리스트를 사용
list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}