#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    Publication() : title(""), price(0.0) {}

    virtual void getdata() {
        cout << "Введите название: ";
        cin.ignore();
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
    }

    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }
};

class Book : public Publication {
private:
    int pages;
public:
    void getdata() override {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl << endl;
    }
};

class Type : public Publication {
private:
    float time;
public:
    void getdata() override {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> time;
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Время записи: " << time << " мин." << endl << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Publication* publications[10];
    int count = 0;
    char choice;
    do {
        cout << "\nВыберите тип публикации:" << endl;
        cout << "1 - Книга" << endl;
        cout << "2 - Аудиозапись" << endl;
        cout << "Ваш выбор: ";
        int type;
        cin >> type;

        if (type == 1) {
            publications[count] = new Book();
        }
        else if (type == 2) {
            publications[count] = new Type();
        }
        else {
            cout << "Неверный выбор!" << endl;
            continue;
        }

        cout << "\nВведите данные:" << endl;
        publications[count]->getdata();
        count++;

        cout << "\nДобавить еще одну публикацию? (y/n): ";
        cin >> choice;

    } while ((choice == 'y' || choice == 'Y') && count < 10);

    cout << " Список публикаций: " << endl;
    for (int i = 0; i < count; i++) {
        cout << "\nПубликация #" << i + 1 << ":" << endl;
        publications[i]->putdata();
    }

    for (int i = 0; i < count; i++) {
        delete publications[i];
    }
    return 0;
}
