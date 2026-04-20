#include <iostream>
using namespace std;

class Gadget
{
private:
    int code;
    char *name;
    bool isActive;
    static int gadgetCount;

    int strLength(const char *str)
    {
        int len = 0;
        while (str[len] != '\0')
            len++;
        return len;
    }

    void strCopy(char *dest, const char *src)
    {
        int i = 0;
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    Gadget() : code(0), name(nullptr), isActive(false)
    {
        name = new char[8];
        strCopy(name, "Unknown");
        gadgetCount++;
    }

    Gadget(int code, const char *name, bool isActive)
        : code(code), isActive(isActive)
    {
        int len = strLength(name);
        this->name = new char[len + 1];
        strCopy(this->name, name);
        gadgetCount++;
    }

    Gadget(const Gadget &other) : code(other.code), isActive(other.isActive)
    {
        int len = strLength(other.name);
        name = new char[len + 1];
        strCopy(name, other.name);
        gadgetCount++;
    }

    Gadget(Gadget &&other) : code(other.code), name(other.name), isActive(other.isActive)
    {
        other.name = nullptr;
        other.code = 0;
        other.isActive = false;
        gadgetCount++;
    }

    ~Gadget()
    {
        delete[] name;
        gadgetCount--;
    }

    Gadget &setCode(int c)
    {
        code = c;
        return *this;
    }

    Gadget &setName(const char *n)
    {
        delete[] name;
        int len = strLength(n);
        name = new char[len + 1];
        strCopy(name, n);
        return *this;
    }

    Gadget &setActive(bool status)
    {
        isActive = status;
        return *this;
    }

    inline int getCode() const { return code; }
    inline const char *getName() const { return name; }
    inline bool getActive() const { return isActive; }

    void display() const
    {
        cout << "Gadget ID: " << code
             << " | Name: " << (name ? name : "N/A")
             << " | Active: " << (isActive ? "Yes" : "No") << endl;
    }

    static int getGadgetCount()
    {
        return gadgetCount;
    }
};

int Gadget::gadgetCount = 0;

class VIPHuman
{
private:
    char *name;
    Gadget gadget;

    int strLength(const char *str)
    {
        int len = 0;
        while (str[len] != '\0')
            len++;
        return len;
    }

    void strCopy(char *dest, const char *src)
    {
        int i = 0;
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    VIPHuman() : name(nullptr), gadget()
    {
        name = new char[8];
        strCopy(name, "Unknown");
    }

    VIPHuman(const char *n, int code, const char *gName, bool isActive)
        : gadget(code, gName, isActive)
    {
        int len = strLength(n);
        name = new char[len + 1];
        strCopy(name, n);
    }

    ~VIPHuman()
    {
        delete[] name;
    }

    VIPHuman &setName(const char *n)
    {
        delete[] name;
        int len = strLength(n);
        name = new char[len + 1];
        strCopy(name, n);
        return *this;
    }

    VIPHuman &setGadget(int code, const char *gName, bool isActive)
    {
        gadget.setCode(code).setName(gName).setActive(isActive);
        return *this;
    }

    const char *getName() const { return name; }
    Gadget *getGadget() const { return const_cast<Gadget *>(&gadget); }

    void display() const
    {
        cout << "VIP Human: " << (name ? name : "N/A") << endl;
        cout << "Owned Gadget:" << endl;
        cout << "  ";
        gadget.display();
    }
};

class Human
{
private:
    char *name;
    Gadget *gadget;

    int strLength(const char *str)
    {
        int len = 0;
        while (str[len] != '\0')
            len++;
        return len;
    }

    void strCopy(char *dest, const char *src)
    {
        int i = 0;
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    Human() : name(nullptr), gadget(nullptr)
    {
        name = new char[8];
        strCopy(name, "Unknown");
    }

    Human(const char *n, Gadget *g) : gadget(g)
    {
        int len = strLength(n);
        name = new char[len + 1];
        strCopy(name, n);
    }

    ~Human()
    {
        delete[] name;
    }

    Human &setName(const char *n)
    {
        delete[] name;
        int len = strLength(n);
        name = new char[len + 1];
        strCopy(name, n);
        return *this;
    }

    Human &setGadget(Gadget *g)
    {
        gadget = g;
        return *this;
    }

    const char *getName() const { return name; }
    Gadget *getGadget() const { return gadget; }

    void display() const
    {
        cout << "Human: " << (name ? name : "N/A") << endl;
        cout << "Borrowed Gadget:" << endl;
        if (gadget)
        {
            cout << "  ";
            gadget->display();
        }
        else
        {
            cout << "  No gadget assigned." << endl;
        }
    }
};

class Robot
{
private:
    char *name;
    Gadget ownedGadgets[10];
    int ownedCount;
    Gadget *sharedGadgets[5];
    int sharedCount;

    int strLength(const char *str)
    {
        int len = 0;
        while (str[len] != '\0')
            len++;
        return len;
    }

    void strCopy(char *dest, const char *src)
    {
        int i = 0;
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    Robot() : name(nullptr), ownedCount(0), sharedCount(0)
    {
        name = new char[8];
        strCopy(name, "Unknown");
        for (int i = 0; i < 5; i++)
            sharedGadgets[i] = nullptr;
    }

    Robot(const char *n) : ownedCount(0), sharedCount(0)
    {
        int len = strLength(n);
        name = new char[len + 1];
        strCopy(name, n);
        for (int i = 0; i < 5; i++)
            sharedGadgets[i] = nullptr;
    }

    ~Robot()
    {
        delete[] name;
    }

    Robot &setName(const char *n)
    {
        delete[] name;
        int len = strLength(n);
        name = new char[len + 1];
        strCopy(name, n);
        return *this;
    }

    Robot &addOwnedGadget(int code, const char *gName, bool isActive)
    {
        if (ownedCount < 10)
        {
            ownedGadgets[ownedCount].setCode(code).setName(gName).setActive(isActive);
            ownedCount++;
        }
        else
        {
            cout << "Cannot add more owned gadgets (max 10)." << endl;
        }
        return *this;
    }

    Robot &addSharedGadget(Gadget *g)
    {
        if (sharedCount < 5)
        {
            sharedGadgets[sharedCount++] = g;
        }
        else
        {
            cout << "Cannot add more shared gadgets (max 5)." << endl;
        }
        return *this;
    }

    const char *getName() const { return name; }

    void display() const
    {
        cout << "Robot Name: " << (name ? name : "N/A") << endl;
        cout << "Owned Gadgets:" << endl;
        if (ownedCount == 0)
        {
            cout << "  None" << endl;
        }
        else
        {
            for (int i = 0; i < ownedCount; i++)
            {
                cout << "  - ";
                ownedGadgets[i].display();
            }
        }
        cout << "Shared Gadgets:" << endl;
        if (sharedCount == 0)
        {
            cout << "  None" << endl;
        }
        else
        {
            for (int i = 0; i < sharedCount; i++)
            {
                if (sharedGadgets[i])
                {
                    cout << "  - ";
                    sharedGadgets[i]->display();
                }
            }
        }
    }
};

int main()
{
    int n;
    cout << "How many gadgets would you like to create? ";
    cin >> n;

    Gadget *gadgets = new Gadget[n];

    for (int i = 0; i < n; i++)
    {
        int code;
        char name[100];
        char activeInput;
        bool isActive;

        cout << "\nGadget " << (i + 1) << ":" << endl;
        cout << "  Enter code: ";
        cin >> code;
        cout << "  Enter name: ";
        cin.ignore();
        cin.getline(name, 100);
        cout << "  Is active (y/n): ";
        cin >> activeInput;
        isActive = (activeInput == 'y' || activeInput == 'Y');

        gadgets[i].setCode(code).setName(name).setActive(isActive);
    }

    cout << "\n--- All Gadgets ---" << endl;
    for (int i = 0; i < n; i++)
    {
        gadgets[i].display();
    }

    cout << "\n--- Humans ---" << endl;
    Human h1("Shizuka", (n > 0 ? &gadgets[0] : nullptr));
    Human h2("Gian", (n > 1 ? &gadgets[1] : nullptr));
    h1.display();
    h2.display();

    cout << "\n--- VIP Human ---" << endl;
    VIPHuman nobita("Nobita", 101, "Bamboo Copter", true);
    nobita.display();

    cout << "\n--- Robots ---" << endl;
    Robot doraemon("Doraemon");
    doraemon.addOwnedGadget(301, "Translator Tool", true)
        .addOwnedGadget(302, "Time Freezer", false);
    if (n > 0)
        doraemon.addSharedGadget(&gadgets[0]);

    Robot dorami("Dorami");
    dorami.addOwnedGadget(401, "Mini Drone", true);
    if (n > 1)
        dorami.addSharedGadget(&gadgets[1]);

    doraemon.display();
    dorami.display();

    cout << "\nTotal Gadgets Created: " << Gadget::getGadgetCount() << endl;

    delete[] gadgets;

    return 0;
}