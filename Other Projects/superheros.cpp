#include <iostream>
#include <ctime>

using namespace std;

class Superpower{
private:
    string name;
    string description;
    int maxI;
public:
void SetSuperpower(){
    cout << "\tGive a name to the SUPERPOWER: ";
    cin >> name;
    cout << "\tDescribe it: ";
    cin >> description;
}
void SetMaxI(){
    srand(time(NULL));
    maxI = (rand() % 51) + 100;
}

int DetermineAttackIntensity(){
    int attack;
    srand(time(NULL));
    attack = (rand() % maxI) + 1;
    return attack;
}
string getName(){return name;}
};


class Character{
private:
    string name;
    int levelOfResistance, nOfPowers = (rand() % 5) + 1;
    Superpower sp[5];
public:
void setSuperpowers(Superpower super[], int total){
    for(int i = 0; i < nOfPowers; i++){
        Superpower s;
        srand(time(NULL));
        s = super[rand() % total];
        sp[i] = s;
    }
}
void SetName(){
    cout << "\t\tGive a name to your character: ";
    cin >> name;

}
void initializeLevelOfResistance(){
    srand(time(NULL));
    levelOfResistance = (rand() % 900)+100;
}
void Damaged(int d){
    levelOfResistance -= d;
}
void Attack(Character* c){
    srand(time(NULL));
    Superpower super = sp[rand()%nOfPowers];
    c->Damaged(super.DetermineAttackIntensity());
    cout << "\t" << name << " just attacked " << c->getName() << " with " << super.getName() << endl;
    cout << "\t" << c->getName() << "'s health is " << c->getLevelOfResistance() << endl;
}
int getLevelOfResistance(){
    return levelOfResistance;
}
string getName(){return name;}
};


class Hero : public Character{
};
class Villain : public Character{
};

class Battle{
private:
    Villain v;
    Hero h;
    int turn = 1;
    Character winner;
public:
void SetFighters(Hero hero, Villain vil){
    v = vil;
    h = hero;
}
Character setWinner(){
    if(v.getLevelOfResistance() <= 0)
    return h;
    else
    return v;
}
void TakeBattle(){
    do
    {
        if(turn == 1){
            h.Attack(&v);
        }
        else{
            v.Attack(&h);
        }
        turn *= -1;
    } while(h.getLevelOfResistance() > 0 && v.getLevelOfResistance() > 0);
    winner = setWinner();
}
Character getWinner(){return winner;}
};

void DisplayListC(Character ch[], int l, string label);
void DisplayListS(string st[], int l);

void DisplayMenu(){
    cout << "[MENU]" << endl;
    cout << "1. Add Character" << endl;
    cout << "2. Add Superpower" << endl;
    cout << "3. Play Battle" << endl;
    cout << "4. Display Winners" << endl;
    cout << "5. Display Heros" << endl;
    cout << "6. Display Villains" << endl;
    cout << "7. Remove Character" << endl;
    cout << "8. Exit" << endl;
    cout << "Select an action: ";
}
int main(){
    const static int MAX_LIST = 100;
    Battle battles[MAX_LIST];
    Villain villains[MAX_LIST];
    Hero heros[MAX_LIST];
    Superpower superPowers[MAX_LIST];
    string winners[MAX_LIST];
    int nB = 0, nV = 0, nH = 0, nS = 0, nW = 0, accion;

    do {
        DisplayMenu();
        cin >> accion;
        switch (accion)
        {
        case 1:
            if(nV < MAX_LIST && nH < MAX_LIST){
            int choice;
            srand(time(NULL));
            cout << "\t1. Hero" << endl;
            cout << "\t2. Villain" << endl;
            cout << "\tEnter an option: ";
            cin >> choice;
            if(choice == 1){
                Hero h;
                h.SetName();
                h.setSuperpowers(superPowers, nS);
                h.initializeLevelOfResistance();
                heros[nH] = h;
                nH ++;
            }else if(choice == 2){
                Villain v;
                v.SetName();
                v.setSuperpowers(superPowers, nS);
                v.initializeLevelOfResistance();
                villains[nV] = v;
                nV++;
            }
            }else{
                cout << "\tYou have too many Heros or Villains" << endl;
            }
            break;
        case 2:
            if(nS < MAX_LIST){
            Superpower sp;
            sp.SetSuperpower();
            sp.SetMaxI();
            superPowers[nS] = sp;
            nS++;
            }else{
                cout << "\tThere are too many Superpowers" << endl;
            }
            break;
        case 3:
            if(nB < MAX_LIST){
                Battle b;
                srand(time(NULL));
                b.SetFighters(heros[rand()%nH],villains[rand()%nV]);
                b.TakeBattle();
                battles[nB] = b;
                nB++;
                winners[nW] = b.getWinner().getName();
                nW++;
                cout << "\t\tThe battle is over and the winner is " << b.getWinner().getName() << endl;
            }else{
                int choice;
                cout << "\tToo many battles, do you want to clear the lists?" << endl;
                cout << "\t\t1. Yes" << endl;
                cout << "\t\t2. No\n\t\t";
                cin >> choice;
                if(choice == 1){
                    nB = 0;
                    nW = 0;
                }else{cout<< "\t\t\tOk, your choice"<< endl;}
            }
            break;
        case 4:
            DisplayListS(winners, nW);
            break;
        case 5:
            DisplayListC(heros, nH, "hero");
            break;
        case 6:
            DisplayListC(villains, nV, "villain");
            break;
        case 7:
            int choice;
            cout << "\t1. Hero" << endl;
            cout << "\t2. Villain" << endl;
            cout << "\tEnter an option: ";
            cin >> choice;
            if(choice == 1){
                int index;
                DisplayListC(heros, nH, "hero");
                cout << "Type the index from the one you want to remove: ";
                cin >> index;
                heros[index - 1] = heros[nH - 1];
                nH--;
            }else if(choice == 2){
                int index;
                DisplayListC(villains, nV, "villain");
                cout << "Type the index from the one you want to remove: ";
                cin >> index;
                villains[index - 1] = villains[nV - 1];
                nV--;
            }
            break;
        case 8:
            break;
        default:
            cout << "That action is not in the list of actions, please type a valid number" << endl;
            break;
        }
    } while(accion != 8);
}

void DisplayListC(Character ch[], int l, string label){
    cout << "\tThese are the " << label << "s: " << endl;
    for(int i = 0; i < l; i++){
    cout << "\t\t" << (i+1) << ". " << ch[i].getName() << endl;
    }
}
void DisplayListS(string st[], int l){
    cout << "\tThese are the winners: " << endl;
    for(int i = 0; i < l; i++){
        cout << "\t\t" <<(i+1) << ". " << st[i] << endl;
    }
}
