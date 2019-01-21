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

	string::size_type maxlen = 0; //����� �̸��� ����
								  // �л��� ��� �����͸� �о� ����
								  //�Һ���: students�� ���ݱ��� ���� ��� �л� ������ ����
								  //maxlen�� students���� ���� �� �̸��� ����

	while (read(cin, record)) {
		//���̰� ���� �� �̸��� ã��.
		maxlen = max(maxlen, record.name.size());

		students.push_back(record);
	}
	sort(students.begin(), students.end(), compare);

	//�̸��� ������ ���
	for (vector<Student_info>::size_type i = 0;i != students.size();++i){
		// �̸��� ������ ������ �����Ͽ� maxlen+1�� ���ڸ� ���
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		//���� ������ ����Ͽ� ���
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
