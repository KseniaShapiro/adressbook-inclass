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

	cout << "Добавить контакт? [y/n]";
	char answer; cin >> answer;
	while (answer == 'y') {
		cout << "Введите ФИО: "<<endl;
		string s,n,m; cin >>s >> n>>m;
		cout << "Введите возраст: "<<endl;
		int a; cin >> a;
		cout << "Введите номер телефона: "<<endl;
		long long num; cin >> num;
		Contact man(s,n,m, a, num);
		AddressBook::getInstance()->Add(man);
		cout << "Добавить контакт? [y/n]"<<endl;
		char an; cin >> an;
		answer = an;
	}
	system("cls");
	cout << "По какому полю отсортировать список контактов?"<<endl<<"1. По фамилии"<<endl<<"2. По имени"<<endl<<
		"3. По отчеству"<<endl<<"4. По возрасту"<<endl<<"5. По номеру телефона"<<endl;
	int f; cin >> f;
	if(f==1||f==2||f==3)
	cout << "В каком порядке отсортировать?" << endl << "1. В алфавитном" <<endl<< "2. В обратном"<<endl;
	if(f==4||f==5)
	cout << "В каком порядке отсортировать?" << endl << "1. По возрастанию" <<endl<< "2. По убыванию"<<endl;
	int order; cin >> order;
	f--; order--;
	AddressBook::getInstance()->Sort((Contact::Field) f, (Contact::SortOrder) order);
	AddressBook::getInstance()->Print();
	system("pause");
	return 0;
}
