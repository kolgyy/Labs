#include <iostream>
#include <vector>
#include <string>

template <class T>
class IRepository
{
public:

    virtual void Add(T* item) = 0;
    virtual void Update(T* item) = 0;
    virtual void Delete(T* item) = 0;
    virtual std::vector<T*> Get(const std::string    where, const std::string    orderBy) = 0;
};

enum Gender { Male, Female };
std::string genderToString(Gender gender) {
    if (gender == Gender::Male) {
        return "Male";
    }
    else if (gender == Gender::Female) {
        return "Female";
    }
    else {
        return "Other";
    }
}
class User
{
private:

    int mId;
    std::string mName;
    std::string mEmail;
    std::string mPhone;
    std::string mCity;
    Gender mGender;
public:

    int getId() const { return mId; }

    void setId(int id) { mId = id; }

    std::string getName() const { return mName; }

    void setName(const std::string name) { mName = name; }

    std::string getEmail() const { return mEmail; }

    void setEmail(const std::string email) { mEmail = email; }

    std::string getPhone() const { return mPhone; }

    void setPhone(const std::string phone) { mPhone = phone; }

    std::string getCity() const { return mCity; }

    void setCity(const std::string city) { mCity = city; }

    Gender getGender() const { return mGender; }

    void setGender(Gender Gender) { mGender = Gender; }
};

class IUserRepository
{
public:

    virtual User* getById(int id) = 0;

    virtual User* getByName(const std::string name) = 0;

    virtual User* getByEmail(const std::string email) = 0;

    virtual std::vector<User*> getByCity(const std::string city) = 0;

    virtual std::vector<User*> getByGender(Gender Gender) = 0;
};

template <class T>
class MemoryRepository : public virtual IRepository<T>
{
protected:
    std::vector<T*> mItems;
public:
    void Add(T* item) override
    {
        mItems.push_back(item);
    }
    void Update(T* item) override
    {
        for (int i = 0; i < mItems.size(); i++)
        {
            if (mItems[i] == item)
            {
                mItems[i] = item;
                break;
            }
        }
    }
    void Delete(T* item) override
    {
        for (int i = 0; i < mItems.size(); i++)
        {
            if (mItems[i] == item)
            {
                mItems.erase(mItems.begin() + i);
                break;
            }
        }
    }
    std::vector<T*> Get(const std::string where, const std::string orderBy) override
    {
        return mItems;
    }
};

class MemoryUserRepository : public MemoryRepository<User>, public IUserRepository
{
public:
    User* getById(int id) override
    {
        for (User* user : mItems)
        {
            if (user->getId() == id)
            {
                return user;
            }
        }
        return nullptr;
    }

    User* getByName(const std::string name) override
    {
        for (User* user : mItems)
        {
            if (user->getName() == name)
            {
                return user;
            }
        }
        return nullptr;
    }

    User* getByEmail(const std::string email) override
    {
        for (User* user : mItems)
        {
            if (user->getEmail() == email)
            {
                return user;
            }
        }
        return nullptr;
    }

    std::vector<User*> getByCity(const std::string city) override
    {
        std::vector<User*> result;
        for (User* user : mItems)
        {
            if (user->getCity() == city)
            {
                result.push_back(user);
            }
        }
        return result;
    }
    std::vector<User*> getByGender(Gender Gender) override
    {
        std::vector<User*> result;
        for (User* user : mItems)
        {
            if (user->getGender() == Gender)
            {
                result.push_back(user);
            }
        }
        return result;
    }
};

int main() {
    MemoryUserRepository repo;


    User* user1 = new User();
    user1->setId(101);
    user1->setName("Maria");
    user1->setEmail("Maria@gmail.com");
    user1->setPhone("9583450193");
    user1->setCity("Saint-Petersburg");
    user1->setGender(Female);

    User* user2 = new User();
    user2->setId(102);
    user2->setName("Anna");
    user2->setEmail("Anny@gmail.com");
    user2->setPhone("4952401948");
    user2->setCity("Moscow");
    user2->setGender(Female);

    repo.Add(user1);
    repo.Add(user2);


    std::vector<User*> users = repo.Get("", "");
    std::cout << "All users:" << std::endl;
    for (User* user : users) {
        std::cout << user->getId() << " " << user->getName() << " " << user->getEmail() << " " << user->getPhone()
            << " " << user->getCity() << " " << genderToString(user->getGender()) << "";
        std::cout << std::endl;
    }
}