#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Base {
protected:
    Base() = default;

public:
    virtual ~Base() = default;
    virtual void showType() const {
        cout << "Base class" << endl;
    }
    virtual Base* clone() const {
        return new Base(*this);
    }

    friend Base* createBase();
};

class Derived : public Base {
protected:
    Derived() = default;

public:
    void showType() const override {
        cout << "Derived class" << endl;
    }
    virtual Base* clone() const override {
        return new Derived(*this);
    }

    friend Derived* createDerived();
};

Base* createBase() {
    return new Base();
}

Derived* createDerived() {
    return new Derived();
}

vector<Base*> storage;

void add(Base* obj) {
    if (obj) {
        storage.push_back(obj->clone());
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));

    cout << "СОЗДАНИЕ ОБЪЕКТОВ" << endl;
    for (int i = 0; i < 8; i++) {
        Base* newObj = nullptr;

        if (rand() % 2 == 0) {
            newObj = createBase();
            cout << "Создан Base" << endl;
        }
        else {
            newObj = createDerived();
            cout << "Создан Derived" << endl;
        }

        add(newObj);
        delete newObj;
    }

    cout << "\nДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА" << endl;
    for (size_t i = 0; i < storage.size(); i++) {
        cout << "Объект " << i + 1 << ": ";
        storage[i]->showType();
    }
    for (auto obj : storage) {
        delete obj;
    }
    storage.clear();
    return 0;
}
