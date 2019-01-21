//FinalMain.cpp


#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include "grade.h"
#include "Student_info.h"

using std::cin; using std::sort;
using std::cout; using std::streamsize;
using std::endl; using std::string;
using std::setprecision; using std::vector;
using std::domain_error; using std::istream;
using std::max;

int main()
{

	vector<Student_info> students;
	Student_info record;

	string::size_type maxlen = 0; //가장긴 이름의 길이
								  // 학생의 모든 데이터를 읽어 저장
								  //불변성: students는 지금까지 읽은 모든 학생 정보가 있음
								  //maxlen은 students에서 가장 긴 이름의 길이

	while (read(cin, record)) {
		//길이가 가장 긴 이름을 찾음.
		maxlen = max(maxlen, record.name.size());

		students.push_back(record);
	}
	sort(students.begin(), students.end(), compare);

	//이름과 점수를 출력
	for (vector<Student_info>::size_type i = 0;i != students.size();++i){
		// 이름과 오른쪽 공백을 포함하여 maxlen+1개 문자를 출력
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		//최종 점수를 계산하여 출력
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	return 0;
}
