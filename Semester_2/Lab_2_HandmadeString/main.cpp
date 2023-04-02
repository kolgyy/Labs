#include <iostream>
#include <typeinfo>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

int strLEN(char* str) { // Handmade strlen
    int counter = 0;
    while (str[counter] != '\0')
        counter++;
    return counter;
}



class MyString
{
public:
    MyString() {
        str = nullptr;
        length = 0;
    }
    MyString(char* str) {
        length = strLEN(str);
        this->str = new char[length + 1]; // Add ONE 'cause of a non-printing null '\0'
        for (int i = 0; i < length; i++) {
            this->str[i] = str[i];
        }
        this->str[length] = '\0';

    };
    ~MyString() {
        delete[] this->str;
    };

    MyString(const MyString& other) {

        length = strLEN(other.str);
        this->str = new char[length + 1]; // Add ONE 'cause of a non-printing null '\0'

        for (int i = 0; i < length; i++) {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';

    }

    MyString operator+(const MyString& other) {

        MyString newStr; // Creating a new object for the concatenation

        int thisLength = strLEN(this->str);
        int otherLength = strLEN(other.str);

        newStr.length = thisLength + otherLength;

        newStr.str = new char[thisLength + otherLength + 1]; //Add ONE for a non-printing null '\0'

        int i = 0;
        for (; i < thisLength; i++) {
            newStr.str[i] = this->str[i];
        }
        for (int j = 0; j < otherLength; j++, i++) {
            newStr.str[i] = other.str[j];
        }
        newStr.str[thisLength + otherLength] = '\0';

        return newStr;
    }
    MyString operator+=(const MyString& other) {

        MyString newStr; // Creating a new object for the concatenation

        int thisLength = strLEN(this->str);
        int otherLength = strLEN(other.str);

        newStr.length = thisLength + otherLength;

        newStr.str = new char[thisLength + otherLength + 1]; //Add ONE for a non-printing null '\0'

        int i = 0;
        for (; i < thisLength; i++) {
            newStr.str[i] = this->str[i];
        }
        for (int j = 0; j < otherLength; j++, i++) {
            newStr.str[i] = other.str[j];
        }
        newStr.str[thisLength + otherLength] = '\0';

        return newStr;
    }

    MyString& operator=(const MyString& other) {
        if (this->str != nullptr)
            delete[] str; 
        length = strLEN(other.str);
        this->str = new char[length + 1]; // Add ONE 'cause of a non-printing null '\0'
        for (int i = 0; i < length; i++) {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';

        return *this;
    }

    void Print() {
        cout << str;
        cout << endl;
    } 

    char* c_str() {
        return str;

    }
    int find(const char& str) {
        int i = 0;
        for (; i < (this->length); i++) {
            if (this->str[i] == str) {
                return i;
            }
        }

    }



    int Length() {
        return length;
    }

    bool operator == (const MyString& other) {
        if (this->length != other.length) {
            return false;
        }
        for (int i = 0; i < this->length; i++) {
            if (this->str[i] != other.str[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator> (const MyString& other) {
        if (this->length == other.length) {
            return false;
        }
        else {
            if (this->length > other.length) {
                return true;
            }
            else {
                return false;
            }
        }
        
    }

    bool operator< (const MyString& other) {
        if (this->length == other.length) {
            return false;
        }
        else {
            if (this->length < other.length) {
                return true;
            }
            else {
                return false;
            }
        }

    }

    
    bool operator != (const MyString& other) {
        return !(this->operator==(other));
    }

    char& operator[](int index) {
        return this->str[index];
    }

    char& at(int index) {
        if (index > this->length) 
            throw std::out_of_range("the length was exceeded");
        return this->str[index];
        

    }


    MyString(MyString&& other) { // Move constructor 
        // It's used to use a created object instead of using the Copy Constructor, it's much more effective for the concatenation 

        this->length = other.length;
        this->str = other.str;

        other.str = nullptr; // We do so to forbid the program to delete another object. 

    }



private:
    char* str;

    int length;

};

std::ostream& operator << (std::ostream& os, MyString& str) {
    return os << str.c_str() << endl;
}

std::istream& operator >> (std::istream& in, MyString& str) {
    char* tmp = new char[LONG_MAX];
    in >> tmp;
    str = tmp;
    delete[] tmp;
    return in;



    
}

int main() {
    MyString str("HELLO, ");
    MyString str2("WORLD!");
    //////////////////////////////
    cout << "Length str: " << str.Length() << endl;
    cout << "Length str2: " << str2.Length() << endl;
    //////////////////////////////
    MyString result;

    result = str + str2;
    cout << result;


    result = (str2 += str);
    cout << result;

    cout << "Length result: " << result.Length() << endl;
    ///////////////////////////////
    str = str2;
    cout << str;
    ///////////////////////////////
    cout << "Length str: " << str.Length() << endl;
    cout << "Length str2: " << str2.Length() << endl;
    //////////////////////////////
    cout << "str == str2 : " << (str == str2) << endl;;
    cout << "str != str2 : " << (str != str2) << endl;
    //////////////////////////////
    str2[0] = 'H';
    str2.Print();
    //////////////////////////////
    MyString a("Haha");
    MyString b("Wow");
    cout << "a > b : " << (a > b) << endl;
    cout << "a < b : " << (a < b) << endl;
    //////////////////////////////

    MyString bow("algebraically");
    cout << bow.find('l') << endl;
    cout << bow[3] << endl;
    cout << bow.at(3) << endl;
    // cout << bow.at(22) << endl; It's gonna be an error!
    //////////////////////////////
    cout << typeid(bow.c_str()).name() << endl;
    bow.c_str()[2] = 'h';
    cout << bow;
    cout << typeid(bow).name() << endl;
    cin >> bow;
    cout << bow;

    return 0; 
}