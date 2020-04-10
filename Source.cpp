#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <locale.h>
#include <fstream>
using namespace std;

class Contact {
   public:
	string Name;
	string Surname;
	string MiddleName;
	int Age;
	long long Number;
	enum Field { surname, name, middle_name, age, number };
	enum SortOrder { up, down };
	Contact(string s, string n, string m,int a, long long num) {
		Surname = s;
		Name = n;
		MiddleName = m;
		Age = a;
		Number = num;
	}
	friend ostream& operator<<(ostream &out, const Contact &c) {
		out << c.Surname << " "<< c.Name << " "<< c.MiddleName << " " << c.Age << " " << c.Number << endl;
		return out;
	}
};
class AddressBook {
    private:
	   vector<Contact> Book;
    public:
	static AddressBook* getInstance() {
		static AddressBook instance;
		return &instance;
	}
    void Add(const Contact& c) {
		Book.push_back(c);
    }
	void Print() {
		for (auto k : Book) {
			cout << k;
		}
	}
    void Sort(Contact::Field field, Contact::SortOrder order) {
		if (field == Contact::surname && order== Contact::up) {
			sort(Book.begin(), Book.end(), [](const Contact& a, const Contact& b) {
				return (a.Surname < b.Surname);
				});
		}
		if (field == Contact::surname && order == Contact::down) {
			sort(Book.begin(), Book.end(), [](const Contact& a, const Contact& b) {
				return (a.Surname > b.Surname);
				});
		}
		if (field == Contact::name && order == Contact::up) {
			sort(Book.begin(), Book.end(), [](const Contact& a, const Contact& b) {
				return (a.Name < b.Name);
				});
		}
		if (field == Contact::name && order == Contact::down) {
			sort(Book.begin(), Book.end(), [](const Contact& a, const Contact& b) {
				return (a.Name > b.Name);
				});
		}
		if (field == Contact::middle_name && order == Contact::up) {
			sort(Book.begin(), Book.end(), [](const Contact& a, const Contact& b) {
				return (a.MiddleName < b.MiddleName);
				});
		}
		if (field == Contact::middle_name && order == Contact::down) {
			sort(Book.begin(), Book.end(), [](const Contact& a, const Contact& b) {
				return (a.MiddleName > b.MiddleName);
				});
		}
		if (field == Contact::number && order == Contact::up) {
			sort(Book.begin(), Book.end(), [](const Contact& a, const Contact& b) {
				return (a.Number < b.Number);
				});
		}
		if (field == Contact::number && order == Contact::down) {
			sort(Book.begin(), Book.end(), [](const Contact& a, const Contact& b) {
				return (a.Number > b.Number);
				});
		}
		if (field ==Contact::age && order== Contact::up) {
			sort(Book.begin(), Book.end(), [](const Contact& a, const Contact& b) {
				return (a.Age < b.Age);
				});
		}
		if (field == Contact::age && order== Contact::down) {
			sort(Book.begin(), Book.end(), [](const Contact& a, const Contact& b) {
				return (a.Age > b.Age);
				});
		}
    }

};
int main() {
	setlocale(LC_ALL, "Russian");

	cout << "�������� �������? [y/n]";
	char answer; cin >> answer;
	while (answer == 'y') {
		cout << "������� ���: "<<endl;
		string s,n,m; cin >>s >> n>>m;
		cout << "������� �������: "<<endl;
		int a; cin >> a;
		cout << "������� ����� ��������: "<<endl;
		long long num; cin >> num;
		Contact man(s,n,m, a, num);
		AddressBook::getInstance()->Add(man);
		cout << "�������� �������? [y/n]"<<endl;
		char an; cin >> an;
		answer = an;
	}
	system("cls");
	cout << "�� ������ ���� ������������� ������ ���������?"<<endl<<"1. �� �������"<<endl<<"2. �� �����"<<endl<<
		"3. �� ��������"<<endl<<"4. �� ��������"<<endl<<"5. �� ������ ��������"<<endl;
	int f; cin >> f;
	if(f==1||f==2||f==3)
	cout << "� ����� ������� �������������?" << endl << "1. � ����������" <<endl<< "2. � ��������"<<endl;
	if(f==4||f==5)
	cout << "� ����� ������� �������������?" << endl << "1. �� �����������" <<endl<< "2. �� ��������"<<endl;
	int order; cin >> order;
	f--; order--;
	AddressBook::getInstance()->Sort((Contact::Field) f, (Contact::SortOrder) order);
	AddressBook::getInstance()->Print();
	system("pause");
	return 0;
}
