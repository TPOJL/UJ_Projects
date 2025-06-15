#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Character;

class Item {
protected:
    int Usage;
public:
    virtual bool use(Character& user, Character& target) {
        cout << "Using item on character." << endl;
        return true;
    }
};


class Character {
private:
    int health, stamina, damage;
    vector<Item*> backpack;

public:
    Character(int h, int s, int d) : health(h), stamina(s), damage(d) {}

   void display(){
       cout << "health: " << health << '\n'
            << "stamina: " << stamina << '\n'
            << "damage: " << damage << '\n';
    }

    void add2backpack(Item* item){
        if(backpack.size() < 16){
            backpack.push_back(item);
            cout << "added successfully" << endl;
        } else {
            cout << "the backpack is already full" << endl;
        }
    }

    void takeDamage(int dmg) {
        health -= dmg;
        cout << "Character took " << dmg << " damage. Current health: " << health << endl;
    }

    void takeEnergy(int stm) {
        stamina += stm;
        cout << "Character took " << stm << " stamina. Current stamina: " << stamina << endl;
    }

    void useItemFromBackpack(int index, Character& user, Character& target) {
        if (index >= 0 && index < backpack.size()) {
            if (!backpack[index]->use(user, target)) {
                delete backpack[index];
                backpack.erase(backpack.begin() + index);
                cout << "Deleted succesfully" << endl;
            }
        } else {
            cout << "Invalid index for item in backpack." << endl;
        }
    }
};

class Healer : public Item {
public:
    bool use(Character& user, Character& target) override {
        if(Usage < 1) {
            target.takeDamage(-10);
            Usage++;
            return true;
        } else {
            cout << "Out of item" << '\n';
            return false;
        }
    }
};

class LargeHealer : public Item{
   bool use(Character& user, Character& target) override {
        if(Usage < 2){
            target.takeDamage(-20);
            Usage++;
            return true;
        }else{
            cout << "Out of item" << '\n';
            return false;
        }
    }
};

class Energizer : public Item{
    bool use(Character& user, Character& target) override {
        if(Usage < 1) {
            target.takeEnergy(10);
            Usage++;
            return true;
        }else{
            cout << "Out of item" << '\n';
            return false;
        }
    }
};

class LargeEnergizer : public Item {
    bool use(Character& user, Character& target) override {
        if (Usage < 2) {
            target.takeEnergy(20);
            Usage++;
            return true;
        } else {
            cout << "Out of item" << '\n';
            return false;
        }
    }
};

    class Weapon : public Item {
    private:
        int damage, energy;
    public:
        Weapon(int dmg, int nrg) : damage(dmg), energy(nrg) {}

        bool use(Character& user, Character& target) override {
            if(Usage < 1) {
                user.takeEnergy(-energy);
                target.takeDamage(damage);
                cout << "Weapon used.\n";
                Usage++;
                return true;
            }else {
                cout << "Out of item" << '\n';
                return false;
            }
        }
    };

    int main() {

        Character player(100, 100, 20);
        Character enemy(80, 80, 10);

        player.add2backpack(new LargeHealer());
        player.add2backpack(new LargeEnergizer());
        player.add2backpack(new Weapon(15, 20));
        cout << endl;

        cout << "Player's statistics: " << endl;
        player.display();
        cout << endl;
        cout << "Enemy's statistics: " << endl;
        enemy.display();
        cout << endl;

        player.useItemFromBackpack(0, player, player);
        player.useItemFromBackpack(0, player, player);
        cout << endl;
        player.useItemFromBackpack(0, player, player);
        cout << endl;
        player.useItemFromBackpack(1, player, enemy);
        cout << endl;

        cout << "Player's statistics: " << endl;
        player.display();
        cout << endl;
        cout << "Enemy's statistics: " << endl;
        enemy.display();
        cout << endl;

        return 0;
    }
