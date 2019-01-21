#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::sort;
using std::cout; using std::streamsize;
using std::endl; using std::string;
using std::setprecision; using std::vector;

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
	double x;

	//�Һ���: homework�� ���ݱ��� �Է¹��� ���� ������ ����
	while (cin >> x)
		homework.push_back(x);
	
	//���� ������ �Է� ������ Ȯ��
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "You must enter your grades."
		"Please try again." << endl;
		return 1;
	}
	//������ ����
	sort(homework.begin(), homework.end());

	//���� ������ �߾Ӱ��� ����
	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

	//���� ������ ���ؼ� ���
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;
	return 0;


}
