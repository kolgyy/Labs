#include <iostream>

using namespace std;

// ������
template <typename T>
class node
{
public:
    string key;
    T value;
    node* next;

    node(string key, T value) // �����������
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    node(node& obj) // ����������� �����������
    {
        this->key = obj.key;
        this->value = obj.value;
        this->next = NULL;
    }

    ~node() // ����������
    {
        node* head = this;
        while (head != NULL)
        {
            node* currNode = head;
            head = head->next;
            delete currNode;
        }
    }
};

// ���-�������
template <typename T>
class unordered_map
{
public:
    int numOfElements, capacity;
    node<T>** arr; // ������, � ������� �������� ��������� �� node<T>(��������� ������)

    unordered_map() // �����������
    {
        this->capacity = 1;
        this->numOfElements = 0;
        this->arr = new node<T> *[this->capacity];
        this->arr[0] = NULL;
    }

    int hashFunction(string key) // ���-������� ��� ����������� ������
    {
        int bucketIndex;
        long long int sum = 0, factor = 31;
        for (int i = 0; i < key.size(); i++)
        {
            // sum = sum + (ascii �������� ������� * (������� ����� ^ x)) % �� ������ ���������� �����
            // factor = factor * ������� �����, �.�. ������� ����� ^ x
            sum = ((sum % this->capacity) + ((int(key[i])) * factor) % this->capacity) % this->capacity;
            factor = ((factor % INT16_MAX) * (31 % INT16_MAX)) % INT16_MAX;
        }

        bucketIndex = sum;
        return bucketIndex;
    }

    float getLoadFactor()
    {
        // ���������� ��������� � ���-������� / ����� ���������� �����
        return (float)(this->numOfElements + 1) / (float)(this->capacity);
    }

    void rehashing()
    {
        int oldCapacity = this->capacity;
        node<T>** temp = this->arr; // temp �������� ������� ������

        this->capacity = oldCapacity * 2; // �������� ������� ������� �������
        this->arr = new node<T> *[this->capacity]; // ��������� �� ����� ������ ���������� �������

        for (int i = 0; i < this->capacity; i++)
        {
            arr[i] = NULL;
        }
        for (int i = 0; i < oldCapacity; i++) // ����������� ���� ���������� �������� � ����� ������
        {
            node<T>* currBucketHead = temp[i];
            while (currBucketHead != NULL) // ����������� ����� ������
            {
                this->insert(currBucketHead->key, currBucketHead->value); // ������� ������� ������ �������� ���-�������, ��� ��� ������� ���������
                currBucketHead = currBucketHead->next;
            }
        }
        delete[] temp; // �������� ������� ������� �� ���� ������
        return;
    }

    void insert(string key, T value)
    {
        while (this->getLoadFactor() > 0.5f) // ��� ������������ �������� > 0,5
        {
            this->rehashing();
        }

        int bucketIndex = this->hashFunction(key);
        if (this->arr[bucketIndex] == NULL) // ����� � ������ ��� ������
        {
            node<T>* newNode = new node<T>(key, value);
            arr[bucketIndex] = newNode;
        }
        else // ���������� � ������ �������� ������
        {
            node<T>* newNode = new node<T>(key, value);
            newNode->next = this->arr[bucketIndex];
            this->arr[bucketIndex] = newNode;
        }
        return;
    }

    int search(string key)
    {
        int bucketIndex = this->hashFunction(key); // ��������� ������� ������
        node<T>* bucketHead = this->arr[bucketIndex];
        while (bucketHead != NULL) // ����� � ������, ������� ������������ � ������ �� ��������� �����
        {
            if (bucketHead->key == key)
            {
                return bucketHead->value;
            }
            bucketHead = bucketHead->next; // ������� � ���������� node � ������
        }
        cout << "!Data not found!" << endl; // ����� ���� �� ��������
        return -1;
    }
};

int main()
{
    unordered_map<int> mp; // int - ��������, � ����� ������ key ���� string
    mp.insert("Vlad", 111);
    mp.insert("Anton", 14);
    mp.insert("Bogdan", 2);
    mp.insert("Stas", 8);
    mp.insert("Zhenya", 14);
    mp.insert("Artur", 64);

    cout << "Value of Vlad : " << mp.search("Vlad") << endl;
    cout << "Value of Anton : " << mp.search("Anton") << endl;
    cout << "Value of Bogdan : " << mp.search("Bogdan") << endl;
    cout << "Value of Stas : " << mp.search("Stas") << endl;
    cout << "Value of Zhenya : " << mp.search("Zhenya") << endl;
    cout << "Value of Artur : " << mp.search("Artur") << endl;

    // ������� Data not found and return -1
    mp.search("Ivan"); // ������, ����� � ���-������� ����������� ������ ����

    return 0;
}