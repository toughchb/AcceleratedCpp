//grade.cpp
#include <stdexcept>
#include <vector>
#include <list>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::list;
using std::vector;
//�߰����� ����, �⸻���� ����, ���� ���� �������� �л��� ���� ������ ����
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4;
};

//�߰����� ����, �⸻���� ����, ���� ���� �������� �л��� ���� ������ ����
//�� �Լ��� �μ��� �������� �ʰ� median �Լ��� �ش� �۾��� ��
double grade(double midterm, double final, const std::vector<double>& hw)// grade �����ε�
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

//�ε��� ��� iterator�� ��������� ������ ���� ���ϰ� �����.
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

// �� ��° ����: ���� ��� ����Ʈ�� ���
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