#include <iostream>
#include <string>
using namespace std;

class Jovaun {
public:
    // --- Variables ---
    int happiness;
    int tiredness;
    int hoodieCount;
    int eyesight;
    bool putOnGlasses;
    bool listeningToVinyl;

    // --- Constructor ---
    Jovaun() {
        happiness = 70;       // starts out chill
        tiredness = 30;       // not too tired yet
        hoodieCount = 5;      // always black hoodies
        listeningToVinyl = false;
    }

    // --- Methods ---
    void putOnGlasses() {
        if (putOnGlasses == true) {
            cout << "jovaun can see better now.\n";
            happiness += 10;
            tiredness -= 5;
            eyesight += 15;

        }
        else {
            cout << "jovaun cant see that well now.\n";
            happiness -= 10;
            tiredness += 5;
            eyesight -= 15;
        }
    }

    void putOnHoodie() {
        if (hoodieCount > 0) {
            cout << "Jovaun puts on a black hoodie. He looks cooler instantly.\n";
            hoodieCount -= 1;
            happiness += 5;
        }
        else {
            cout << "No hoodies left? Impossible!\n";
        }
    }

    void listenToVinyl() {
        if (listeningToVinyl == true) {
            cout << "Spinning some vinyl... the vibes are immaculate.\n";
            happiness += 10;
            tiredness -= 5;

        }
        else {
            cout << "jovaun is okay with that.\n";
            happiness -= 10;
            tiredness += 5;
        }
    }

    void codeSession() {
        cout << "Jovaun is coding like a boss.\n";
        happiness += 7;
        tiredness += 10;
    }

    void beatJaydenAtRainbowSix() {
        cout << "Jovaun beats Jayden at Rainbow Six. Again.\n";
        happiness += 15;
    }

    void printStats() {
        cout << "\n--- Jovaun's Status ---\n";
        cout << "Happiness: " << happiness << "\n";
        cout << "Tiredness: " << tiredness << "\n";
        cout << "Hoodies: " << hoodieCount << "\n";
        cout << "Listening to vinyl: " << (listeningToVinyl ? "Yes" : "No") << "\n";
      
    }
};

// --- Demo ---
int main() {
    Jovaun j;

    j.putOnHoodie();
    j.listenToVinyl();
    j.codeSession();
    j.beatJaydenAtRainbowSix();
    

    j.printStats();
    return 0;
}

