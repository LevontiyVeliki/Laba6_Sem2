#include <iostream>
#include <list>
#include <string>

using namespace std;

class Bilet {
public:
    string end_reis;
    string name;
    string date;
    string prost;
    string num;
};

int main()
{
    setlocale(LC_ALL, "Rus");
    list<string> li{};
    Bilet x;
    int n;
    cin >> n;
    do 
    {
        switch (n) {
        case 1:
            cout << "Введите номер, место назначения, имя покупателя, дату прилета. Вводите по очереди через ентер." << endl;
            for (int i = 1; i <= 4; i++) {
                if (i == 1) {
                    cin >> x.num;
                    li.push_back(x.num);
                }
                if (i == 3) {
                    cin >> x.name;
                    li.push_back(x.name);
                }
                if (i == 4) {
                    cin >> x.date;
                    li.push_back(x.date);
                }
                if (i == 2) {
                    cin >> x.end_reis;
                    li.push_back(x.end_reis);
                }
            }
            cout << "Данные записаны." << endl;
            break;
        case 2:
            do {
                string num_n;
                cout << "Введите номер, чтобы удалить интересующий билет. ";
                cin >> num_n;
                list <string> li_2;
                int cnt = 4;
                for (auto it = li.begin(); it != li.end(); it++) {
                    if (cnt == 4) {
                        if ((*it) == num_n) {
                            cnt -= 1;
                        }
                        else
                        {
                            li_2.push_back((*it));
                        }
                    }
                    if (cnt == 0) {
                        li_2.push_back((*it));
                    }
                }
                li.clear();
                copy(li_2.begin(), li_2.end(), back_inserter(li));
                li_2.clear();
            } while (n != 2);
            cout << "Удалили.";
            cout << endl;
            break;

        case 3:
            do {
                string num_n;
                cout << "Введите номер, чтобы найти интересующий билет. ";
                cin >> num_n;
                for (auto it = li.begin(); it != li.end(); it++) {
                    if ((*it) == num_n) {
                        auto i = it;
                        int cnt = 1;
                        for (i; i != li.end(); i++) {
                            if (cnt <= 4) { cout << (*i) << " "; }
                            cnt += 1;
                        }
                    }
                }
            } while (n != 3);
            cout << endl;
            break;

        case 4:
            int cnt = 0;
            for (auto it = li.begin(); it != li.end(); it++) {
                cout << (*it) << " ";
                cnt += 1;
                if (cnt % 4 == 0) {
                    cout << "\n";
                }
            }
            break;
        }
    } while (cin >> n);
    
}
