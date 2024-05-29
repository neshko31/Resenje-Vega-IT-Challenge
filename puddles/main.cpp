#include <iostream>

// 'A' - oznacava asfalt
// ' ' - oznacava vazduh
// 'V' - oznacava vodu

using namespace std;

const int redovi = 5;
const int kolone = 8;

int kolicina_vode(char (&barica)[redovi][kolone]) {
    int kolicina_vode = 0;

    int najvisi_nivo_asfalta = redovi - 1;
    for (int i = 0; i < redovi; i++) {
        bool trenutno_najvisi = true;
        for (int j = 0; j < kolone; j++) {
            if (barica[i][j] == ' ') {
                trenutno_najvisi = false;
                break;
            }
        }
        if (trenutno_najvisi) {
            najvisi_nivo_asfalta = i;
        }
    }

    
    for (int i = 0; i < najvisi_nivo_asfalta; i++) {
        for (int j = 0; j < kolone - 1; j++) {
            if (barica[i][j] == 'A') {
                // pronalazimo sledeci A
                int sledeci_a = -1;
                for (int k = j + 1; k < kolone; k++) {
                    if (barica[i][k] == 'A') sledeci_a = k;
                }
                // promenimo sve izmedju ta 2 A
                for (int k = j + 1; k < sledeci_a; k++) {
                    if (barica[i][k] == ' ') {
                        barica[i][k] = 'V';
                        kolicina_vode++;
                    }
                }
            }
        }
    }
    return kolicina_vode;
}

void ispis_matrice(char (&barica)[redovi][kolone], int kolicina_vode) {
    for (int i = 0; i < redovi; i++) {
        for (int j = 0; j < kolone; j++) {
            cout << barica[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Puddle can hold " << kolicina_vode << " squares of water without the water spilling over." << endl;
}

int main() {
    char barica_a[redovi][kolone] = {{'A', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                     {'A', ' ', ' ', 'A', ' ', ' ', ' ', 'A'},
                                     {'A', ' ', ' ', 'A', 'A', ' ', 'A', 'A'},
                                     {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
                                     {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}};
    int kolicina_vode_a = kolicina_vode(barica_a);
    ispis_matrice(barica_a, kolicina_vode_a);

    char barica_b[redovi][kolone] = {{'A', ' ', ' ', ' ', ' ', ' ', ' ', 'A'},
                                     {'A', ' ', ' ', 'A', ' ', ' ', ' ', 'A'},
                                     {'A', ' ', 'A', 'A', ' ', ' ', 'A', 'A'},
                                     {'A', 'A', 'A', 'A', ' ', ' ', 'A', 'A'},
                                     {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}};
    int kolicina_vode_b = kolicina_vode(barica_b);
    ispis_matrice(barica_b, kolicina_vode_b);
 
    return 0;
}