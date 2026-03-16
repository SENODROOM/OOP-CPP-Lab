#include <iostream>
using namespace std;

class AnpanMedBot
{
private:
    char *name;
    int healingCapacity;

    static int totalBots;

    // Helper: get length of char array manually
    int myStrLen(const char *s) const
    {
        int len = 0;
        while (s[len] != '\0')
            len++;
        return len;
    }

    // Helper: copy src into dest manually
    void myStrCpy(char *dest, const char *src) const
    {
        int i = 0;
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    // Helper: validate healing capacity
    bool isValidCapacity(int h) const
    {
        return (h >= 0 && h <= 1000);
    }

public:
    // ─── Default Constructor ───────────────────────────────────────────────
    AnpanMedBot()
    {
        const char *defaultName = "UnknownBot";
        int len = myStrLen(defaultName);
        name = new char[len + 1];
        myStrCpy(name, defaultName);
        healingCapacity = 0;
        totalBots++;
    }

    // ─── Overloaded Constructor ────────────────────────────────────────────
    AnpanMedBot(const char *n, int h)
    {
        // Validate name
        if (n == nullptr || myStrLen(n) == 0)
        {
            const char *fallback = "UnknownBot";
            int len = myStrLen(fallback);
            name = new char[len + 1];
            myStrCpy(name, fallback);
        }
        else
        {
            int len = myStrLen(n);
            name = new char[len + 1];
            myStrCpy(name, n);
        }

        // Validate healing capacity
        if (isValidCapacity(h))
            healingCapacity = h;
        else
        {
            cout << "[Warning] Invalid healing capacity. Set to 0.\n";
            healingCapacity = 0;
        }

        totalBots++;
    }

    // ─── Copy Constructor (Deep Copy) ─────────────────────────────────────
    AnpanMedBot(const AnpanMedBot &other)
    {
        int len = myStrLen(other.name);
        name = new char[len + 1];
        myStrCpy(name, other.name);
        healingCapacity = other.healingCapacity;
        totalBots++;
    }

    // ─── Move Constructor ─────────────────────────────────────────────────
    AnpanMedBot(AnpanMedBot &&other)
    {
        name = other.name;    // steal pointer
        other.name = nullptr; // nullify source
        healingCapacity = other.healingCapacity;
        // Note: totalBots NOT incremented (no new bot created)
    }

    // ─── Destructor ───────────────────────────────────────────────────────
    ~AnpanMedBot()
    {
        delete[] name;
        name = nullptr;
    }

    // ─── Static Members ───────────────────────────────────────────────────
    static void showTotalBots()
    {
        cout << "Total Bots Created: " << totalBots << endl;
    }

    // ─── Cascading Setter: pointer return ─────────────────────────────────
    AnpanMedBot *setName(const char *n)
    {
        if (n == nullptr || myStrLen(n) == 0)
        {
            cout << "[Warning] Invalid name. Name unchanged.\n";
            return this;
        }
        delete[] name;
        int len = myStrLen(n);
        name = new char[len + 1];
        myStrCpy(name, n);
        return this;
    }

    // ─── Cascading Setter: reference return ───────────────────────────────
    AnpanMedBot &setHealingCapacity(int h)
    {
        if (isValidCapacity(h))
            healingCapacity = h;
        else
            cout << "[Warning] Invalid healing capacity (" << h << "). Value unchanged.\n";
        return *this;
    }

    // ─── Unary ++ Operator ────────────────────────────────────────────────
    void operator++()
    {
        if (healingCapacity + 50 <= 1000)
            healingCapacity += 50;
        else
            healingCapacity = 1000;
    }

    // ─── Binary + Operator ────────────────────────────────────────────────
    AnpanMedBot operator+(const AnpanMedBot &other)
    {
        int combined = healingCapacity + other.healingCapacity;
        if (combined > 1000)
            combined = 1000;
        return AnpanMedBot("CombinedBot", combined);
    }

    // ─── Assignment Operator ──────────────────────────────────────────────
    AnpanMedBot &operator=(const AnpanMedBot &other)
    {
        if (this == &other)
            return *this;
        delete[] name;
        int len = myStrLen(other.name);
        name = new char[len + 1];
        myStrCpy(name, other.name);
        healingCapacity = other.healingCapacity;
        return *this;
    }

    // ─── Getters ──────────────────────────────────────────────────────────
    const char *getName() const
    {
        return name;
    }

    int getHealingCapacity() const
    {
        return healingCapacity;
    }

    // ─── Display ──────────────────────────────────────────────────────────
    void display() const
    {
        cout << "Bot Name: " << (name ? name : "NULL") << endl;
        cout << "Healing Capacity: " << healingCapacity << endl;

        // Bot strength category
        cout << "Bot Strength: ";
        if (healingCapacity <= 100)
            cout << "Weak helper";
        else if (healingCapacity <= 400)
            cout << "Normal helper";
        else if (healingCapacity <= 800)
            cout << "Advanced helper";
        else
            cout << "Elite medical bot";
        cout << "\n--------------------------\n";
    }
};

// ─── Static member definition ─────────────────────────────────────────────────
int AnpanMedBot::totalBots = 0;

// ─── Main Function ────────────────────────────────────────────────────────────
int main()
{
    cout << "========================================\n";
    cout << "   Anpanman Medical Helper Bot System   \n";
    cout << "========================================\n\n";

    // 1. Ask user for number of bots
    int size = 0;
    do
    {
        cout << "Enter number of Medical Helper Bots: ";
        cin >> size;
        if (size <= 0)
            cout << "[Error] Number must be greater than 0. Try again.\n";
    } while (size <= 0);

    // 2. Create dynamic array of objects
    AnpanMedBot *bots = new AnpanMedBot[size];

    cin.ignore(); // clear newline from buffer

    // 3 & 4. Input data and store using cascading setters
    for (int i = 0; i < size; i++)
    {
        char tempName[200];
        int capacity;

        cout << "\n--- Bot " << (i + 1) << " ---\n";

        cout << "Enter bot name: ";
        cin.getline(tempName, 200);

        cout << "Enter healing capacity (0-1000): ";
        cin >> capacity;
        cin.ignore();

        bots[i].setName(tempName)->setHealingCapacity(capacity);
    }

    // 5. Display all bots
    cout << "\n========== All Bots ==========\n";
    for (int i = 0; i < size; i++)
    {
        bots[i].display();
    }

    // 6. Demonstrate operator overloading
    cout << "\n========== Operator Overloading Demo ==========\n";

    // Unary increment on first bot
    cout << "Before ++bots[0]:\n";
    bots[0].display();
    ++bots[0];
    cout << "After ++bots[0] (healingCapacity += 50):\n";
    bots[0].display();

    // Binary addition (only if at least 2 bots)
    if (size >= 2)
    {
        AnpanMedBot superBot;
        superBot = bots[0] + bots[1];
        cout << "superBot = bots[0] + bots[1]:\n";
        superBot.display();
    }

    // 7. Display total bots
    cout << "\n========== Static Member Demo ==========\n";
    AnpanMedBot::showTotalBots();

    // Cascading chaining demo
    cout << "\n========== Cascading Setter Demo ==========\n";
    AnpanMedBot demoBot;
    demoBot.setName("HeroBot")->setHealingCapacity(300).setHealingCapacity(600);
    cout << "After chained setters (HeroBot, 600):\n";
    demoBot.display();

    // Copy constructor demo
    cout << "\n========== Copy Constructor Demo (Deep Copy) ==========\n";
    AnpanMedBot original("CareHelper", 550);
    AnpanMedBot copyBot(original);
    cout << "Original:\n";
    original.display();
    cout << "Copy:\n";
    copyBot.display();
    cout << "(Both have separate memory for name)\n";

    // Move constructor demo
    cout << "\n========== Move Constructor Demo ==========\n";
    AnpanMedBot moveSource("SpeedBot", 750);
    AnpanMedBot moveTarget(move(moveSource));
    cout << "moveTarget after move:\n";
    moveTarget.display();
    cout << "moveSource.name is now: "
         << (moveSource.getName() == nullptr ? "nullptr (ownership transferred)" : moveSource.getName())
         << "\n";

    // Cleanup
    delete[] bots;

    cout << "\nFinal ";
    AnpanMedBot::showTotalBots();

    return 0;
}