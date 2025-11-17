#include <iostream>
#include <string>
using namespace std;

class Sales {
protected:
    float sales[3];

public:
    Sales() {
        for (int i = 0; i < 3; i++) {
            sales[i] = 0.0;
        }
    }

    void getSalesData() {
        cout << "Введите стоимость продаж за последние 3 месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putSalesData() const {
        cout << "Продажи за последние 3 месяца: ";
        for (int i = 0; i < 3; i++) {
            cout << sales[i];
            if (i < 2) cout << ", ";
        }
        cout << " руб." << endl;
    }
};

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

class Book : public Publication, public Sales {
private:
    int pages;

public:
    void getdata() override {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
        Sales::getSalesData();
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
        Sales::putSalesData();
        cout << endl;
    }
};

class Type : public Publication, public Sales {
private:
    float time;

public:
    void getdata() override {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> time;
        Sales::getSalesData();
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Время записи: " << time << " мин." << endl;
        Sales::putSalesData();
        cout << endl;
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
