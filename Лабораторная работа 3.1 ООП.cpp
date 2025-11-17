#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Assembly;
class Detail {
protected:
    string name;
    double weight;
    Detail(const string& n, double w) : name(n), weight(w) {}
public:
    virtual ~Detail() = default;

    virtual void showInfo() const {
        cout << "Деталь: " << name << ", Вес: " << weight << " кг" << endl;
    }
    template<typename T>
    friend T* createObject(const string& name, double weight);
};
class Assembly : public Detail {
protected:
    vector<Detail*> components;
    Assembly(const string& n, double w) : Detail(n, w) {}
public:
    void addComponent(Detail* component) {
        components.push_back(component);
    }
    void showInfo() const override {
        cout << "Сборка: " << name << ", Общий вес: " << weight << " кг" << endl;
        cout << "Состав (" << components.size() << " компонентов):" << endl;
        for (const auto& component : components) {
            cout << "  ";
            component->showInfo();
        }
    }
    ~Assembly() {
        for (auto component : components) {
            delete component;
        }
    }
    template<typename T>
    friend T* createObject(const string& name, double weight);
};

template<typename T>
T* createObject(const string& name, double weight) {
    return new T(name, weight);
}
void createDetail(vector<Detail*>& storage) {
    string name;
    double weight;

    cout << "Введите название детали: ";
    cin >> name;
    cout << "Введите вес детали: ";
    cin >> weight;
    storage.push_back(createObject<Detail>(name, weight));
    cout << "Деталь создана!\n" << endl;
}

void createAssembly(vector<Detail*>& storage) {
    string name;
    double weight;
    cout << "Введите название сборки: ";
    cin >> name;
    cout << "Введите общий вес сборки: ";
    cin >> weight;
    Assembly* assembly = createObject<Assembly>(name, weight);
    int componentCount;
    cout << "Сколько деталей добавить в сборку? ";
    cin >> componentCount;
    for (int i = 0; i < componentCount; i++) {
        string compName;
        double compWeight;

        cout << "Деталь " << (i + 1) << " - название: ";
        cin >> compName;
        cout << "Деталь " << (i + 1) << " - вес: ";
        cin >> compWeight;
        assembly->addComponent(createObject<Detail>(compName, compWeight));
    }
    storage.push_back(assembly);
    cout << "Сборка создана!\n" << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
    vector<Detail*> storage;
    int choice;

    do {
        cout << "1. Создать деталь" << endl;
        cout << "2. Создать сборку" << endl;
        cout << "3. Показать все объекты" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1:
            createDetail(storage);
            break;
        case 2:
            createAssembly(storage);
            break;
        case 3:
            cout << "\n=== ВСЕ ОБЪЕКТЫ ===" << endl;
            for (const auto& item : storage) {
                item->showInfo();
                cout << endl;
            }
            cout << "===================\n" << endl;
            break;
        case 0:
            cout << "Выход..." << endl;
            break;
        default:
            cout << "Неверный выбор!\n" << endl;
        }
    } while (choice != 0);

    for (auto item : storage) {
        delete item;
    }
    return 0;
}
