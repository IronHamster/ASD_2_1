#include <iostream>

int CzyNiezerowy(int* wektor, int n) {
    for (int i = 0; i < n; i++) {
        if (wektor[i]) {
            return 1;
        }
    }
    return 0;
}

void Zeruj(int* wektor, int n) {
    for (int i = 0; i < n; i++) {
        wektor[i] = 0;
    }
}

int CzyProstopadle(int* wektor1, int* wektor2, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += (wektor1[i] * wektor2[i]);
    }
    if (suma == 0) {
        return 1;
    } else {
        return 0;
    }
}

void Trasa(int n, int m) {
    int* wektorKierunkowy = new int[n];
    int* prawidlowyWektor = new int[n];

    Zeruj(wektorKierunkowy, n);
    Zeruj(prawidlowyWektor, n);

    int* pozycjaKoncowa = new int[n];
    Zeruj(pozycjaKoncowa, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> wektorKierunkowy[j];
        }

        if (CzyNiezerowy(wektorKierunkowy, n) + CzyProstopadle(wektorKierunkowy, prawidlowyWektor, n) == 2) {
            for (int k = 0; k < n; k++) {
                pozycjaKoncowa[k] += wektorKierunkowy[k];
            }

            for (int k = 0; k < n; k++) {
                int temp = prawidlowyWektor[k];
                prawidlowyWektor[k] = wektorKierunkowy[k];
                wektorKierunkowy[k] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << pozycjaKoncowa[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int d;
    std::cin >> d;

    while (d--) {
        int n, m;
        std::cin >> n >> m;
        Trasa(n, m);
    }
    return 0;
}
