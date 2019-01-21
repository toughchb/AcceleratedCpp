#pragma once

//grade.h
#include <vector>
#include "Student_info.h"

//중간시험 점수, 기말시험 점수, 종합 과제 점수에서 학생의 종합 점수를 구함
double grade(double midterm, double final, double homework);
//중간시험 점수, 기말시험 점수, 종합 과제 점수에서 학생의 종합 점수를 구함
//이 함수는 인수를 복사하지 않고 median 함수가 해당 작업을 함
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& s);