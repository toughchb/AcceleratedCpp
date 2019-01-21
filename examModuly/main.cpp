#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>

using std::cin; using std::sort;
using std::cout; using std::streamsize;
using std::endl; using std::string;
using std::setprecision; using std::vector;
using std::domain_error; using std::istream;
struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};


//vector<double> �� �߾Ӱ��� ����.
//�Լ��� ȣ���ϸ� �μ��� ������ ���͸� ��°�� ����
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0)
		throw domain_error("median of and emprty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];

};

//�߰����� ����, �⸻���� ����, ���� ���� �������� �л��� ���� ������ ����
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4;
};

//�߰����� ����, �⸻���� ����, ���� ���� �������� �л��� ���� ������ ����
//�� �Լ��� �μ��� �������� �ʰ� median �Լ��� �ش� �۾��� ��
double grade(double midterm, double final, const vector<double>& hw)// grade �����ε�
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");

	return grade(midterm, final, median(hw));
};
double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
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

int main()
{
	//�л��� �̸��� ���� �Է¹���
	cout << "Please enter your first name :";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	//�߰������ �⸻������ ������ ���� �Է� ����
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	//���� ������ ���� �Է� ����
	cout << "Enter all your homework grades, ";
	"followed by end-of-file: ";
	vector<double> homework;
	
	//���� ������ ����
	read_hw(cin, homework);

	//���� ������ ����� �ۼ�
	try {
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
			<< final_grade << setprecision(prec) << endl;
	}
	catch (domain_error) {
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;
		return 1;
	}
	   
	return 0;
}
