#pragma once

//grade.h
#include <vector>
#include "Student_info.h"

//�߰����� ����, �⸻���� ����, ���� ���� �������� �л��� ���� ������ ����
double grade(double midterm, double final, double homework);
//�߰����� ����, �⸻���� ����, ���� ���� �������� �л��� ���� ������ ����
//�� �Լ��� �μ��� �������� �ʰ� median �Լ��� �ش� �۾��� ��
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& s);