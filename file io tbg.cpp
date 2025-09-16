#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int room = 0;   // 0,1,2 = three rooms
    int hp = 100;
    int money = 0;
    string items[5];
    char ans;

    // -------- LOAD OR NEW ----------
    cout << "Load game from file? (y/n): ";
    cin >> ans;
    if (ans == 'y' || ans == 'Y') {
        ifstream in("save.txt");
        if (in) {
            in >> room >> hp >> money >> items[0] >> items[1] >> items[2] >> items[3] >> items[4];
            cout << "Loaded. Room=" << room << " HP=" << hp << " Money=" << money << " Items=" << items[0] << "\n";
        }
        else {
            cout << "No save found. Starting new.\n";
        }
    }

    bool running = true;
    while (running) {
        string inventoryList = "";
        for (string item : items) {
            inventoryList += "[" + item + "] ";
        }
        cout << "\n------------------------------\n";
        cout << "HP: " << hp << " | Room: " << room << " | Money: " << money << " | Inventory: " << inventoryList << "\n";

        switch (room) {
        case 0:
            cout << "Room 0: A quiet hallway. (+2 HP)\n";
            hp += 2; if (hp > 100) hp = 100;
            cout << "Options: (e = east to Room 1, q = quit)\n";
            cin >> ans;
            if (ans == 'e') room = 1;
            else if (ans == 'q') running = false;
            else cout << "Invalid move.\n";
            break;

        case 1:
            cout << "Room 1: A dusty library. Sneeze! (-3 HP)\n";
            hp -= 3;
            cout << "Options: (w = west to Room 0, e = east to Room 2, q = quit)\n";
            cin >> ans;
            if (ans == 'w') room = 0;
            else if (ans == 'e') room = 2;
            else if (ans == 'q') running = false;
            else cout << "Invalid move.\n";
            break;

        case 2:
            cout << "Room 2: A cold cellar. Brrr… (-5 HP)\n";
            hp -= 5;
            cout << "Options: (w = west to Room 1, e = east to Room 3, q = quit)\n";
            cin >> ans;
            if (ans == 'w') room = 1;
            else if (ans == 'e') room = 3;
            else if (ans == 'q') running = false;
            else cout << "Invalid move.\n";
            break;


        case 3:
            cout << "Room 3: A cold cellar. Brrr… (-5 HP)\n";
            hp -= 5;
            cout << "Options: (w = west to Room 2, e = east to Room 4, q = quit)\n";
            cin >> ans;
            if (ans == 'w') room = 2;
            else if (ans == 'e') room = 4;
            else if (ans == 'q') running = false;
            else cout << "Invalid move.\n";
            break;


        case 4:
            cout << "Room 4: A warm room\n";
            hp += 1;
            cout << "Options: (w = west to Room 3, e = east to Room 5, q = quit)\n";
            cin >> ans;
            if (ans == 'w') room = 3;
            else if (ans == 'e') room = 5;
            else if (ans == 'q') running = false;
            else cout << "Invalid move.\n";
            break;


        

        case 5:
            cout << "Room 5: A warm room with money for some reason (+10 money)\n";
            hp += 1;
            money += 10;
            cout << "Options: (w = west to Room 4, e = east to Room 6, q = quit)\n";
            cin >> ans;
            if (ans == 'w') room = 4;
            else if (ans == 'e') room = 6;
            else if (ans == 'q') running = false;
            else cout << "Invalid move.\n";
            break;



        case 6:
            cout << "Room 6: A warm room\n";
            hp += 1;
            cout << "Options: (w = west to Room 5, e = east to Room 7, q = quit)\n";
            cin >> ans;
            if (ans == 'w') room = 5;
            else if (ans == 'e') room = 7;
            else if (ans == 'q') running = false;
            else cout << "Invalid move.\n";
            break;

        case 7:
            cout << "Room 7: A warm room with a key\n";
            hp += 1;
            items[0] = "key";
            cout << "Options: (w = west to Room 6, e = east to Room 8, q = quit)\n";
            cin >> ans;
            if (ans == 'w') room = 6;
            else if (ans == 'e') room = 8;
            else if (ans == 'q') running = false;
            else cout << "Invalid move.\n";
            break;

        case 8:
            cout << "Room 8: A normal room with potion\n";
            hp += 1;
            items[3] = "potion";
            cout << "Options: (w = west to Room 7, e = east to Room 9, q = quit)\n";
            cin >> ans;
            if (ans == 'w') room = 7;
            else if (ans == 'e') room = 9;
            else if (ans == 'q') running = false;
            else cout << "Invalid move.\n";
            break;



        case 9:
            cout << "Room 9: A room near the end\n";
            hp += 1;
            cout << "Options: (w = west to Room 8, e = east to Room 10, q = quit)\n";
            cin >> ans;
            if (ans == 'w') room = 8;
            else if (ans == 'e') room = 10;
            else if (ans == 'q') running = false;
            else cout << "Invalid move.\n";
            break;



        case 10:
            cout << "Room 10:the final room!!\n";
            hp += 1;
            cout << "Options: (w = west to Room 9, q = quit)\n";
            cin >> ans;
            if (ans == 'w') room = 9;
            else if (ans == 'q') running = false;
            else cout << "Invalid move.\n";
            break;
        }


        if (hp <= 0) {
            cout << "You fainted! Game over.\n";
            running = false;
        }
    }

    // -------- SAVE ----------
    ofstream out("save.txt");
    if (out) {
        out << room << " " << hp << " " << money << " " << items[0] << " " << items[1] << " " << items[2] << " " << items[3] << " " << items[4] << "\n";
        cout << "Game saved (room=" << room << ", hp=" << hp << ", money=" << money << "items=" << items[0] << ")\n";
    }
    cout << "Goodbye!\n";
    return 0;
}
