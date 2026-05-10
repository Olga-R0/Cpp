#include <iostream>
#include < stdio.h >

#include <list>
using namespace std;

class HashTable
{
    int capacity;
    list<int>* table;
    
public:
    HashTable(int count_);
    void insertItem(int key_, int data_);
    void deleteItem(int key_);
    int size() { return capacity; }

    int checkPrime(int number_)
    {
        int i;
        if (number_ == 1 || number_ == 0)
        {
            return 0;
        }
        for (i = 2; i < number_ / 2; i++)
        {
            if (number_ % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    int getPrime(int number_)
    {
        if (number_ % 2 == 0)
        {
            number_++;
        }
        while (!checkPrime(number_))
        {
            number_ += 2;
        }
        return number_;
    }

    int hashFunction(int key_)
    {
        return (key_ % capacity);
    }
    void displayHash();
    int findNode(int data_) {
        int index = 0;
        for (int index = 0; index < capacity; index++)
        {
            list<int>::iterator it;
            for (it = table[index].begin();
                it != table[index].end(); it++)
            {
                if (*it == data_)
                    return index;
            }
        }
        return -1;
    }
    void RandElem(int size_)
    {
        int size = capacity;
        
        for (int index = 0; index < size_; index++)
        {   
            int num = rand() % (size );
            int data = rand();
            table[num].push_back(data);
        }
    }
};
HashTable::HashTable(int number_)
{
    int size = getPrime(number_);
    this->capacity = size;
    table = new list<int>[capacity];
}
void HashTable::insertItem(int key_, int data_)
{
    int index = hashFunction(key_);
    table[index].push_back(data_);
}

void HashTable::deleteItem(int key_)
{
    int index = hashFunction(key_);

    list<int>::iterator it;
    for (it = table[index].begin();
        it != table[index].end(); it++)
    {
        if (*it == key_)
            break;
    }

    if (it != table[index].end())
        table[index].erase(it);
}

void HashTable::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "[" << i << "]"<<" : ";
        for (auto x : table[i])
            cout <<  x <<"," ;
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choice, key, data, n, loadFactor;
    int choice2 = 0;
    
    cout << "Ведите количество элементов таблицы" << endl;
    cin >> n;
    HashTable h(n);
    do
    {
        cout<<"1.Вставить элемент в хэш-таблицу"
            "\n2.Удалить элемент из хэш-таблицы"
            "\n3.Узнать размер хэш-таблицы"
            "\n4.Вывести хэш-таблицу"
            "\n5.Заполнить таблицу рандомными элементами"
            "\n6.Найти элемент"
            "\n\n Пожалуйста, выберите нужный вариант: "<<endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Введите ключ" << endl;
            cin >> key;
            cout << "Введите данные" << endl;
            cin >> data;
            h.insertItem(key,data);
            
            break;

        case 2:
            cout << "Введите ключ, который хотите удалить" << endl;
            cin >> key;
            h.deleteItem(key);
            break;

        case 3:

            n = h.size();
           
            cout << "Размер хеш-таблицы " <<n<< endl;
            break;

        case 4:

            h.displayHash();
            break;

        case 5:
            cout << "Введите кол-во элементов, которыми хотите рандомно заполнить таблицу" << endl;
            cin >> data;
            h.RandElem(data);
            break;
        case 6:
            cout << "Введите элемент, который хотите найти" << endl;
            cin >> data;
           key= h.findNode(data);
           cout << key<<endl;
            break;
        default:
            cout << "Неверно введены данные" << endl;
           
        }
        cout << "Продолжить? (Нажмите 1, если да): " << endl;
        cin >> choice2;
        
    } while (choice2 == 1);

}
