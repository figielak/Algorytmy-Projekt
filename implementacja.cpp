#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> brute_force(int A[], int k, int n) {
    int najdluzszy = 0;
    vector<int> starts;

    for(int i = 0; i < n; i++){
        int suma = 0;
        for(int j = i; j < n; j++){
            suma += A[j];

            if(suma < k){
              int aktualna_dlugosc = j - i + 1;

              if(aktualna_dlugosc > najdluzszy){
                najdluzszy = aktualna_dlugosc;
                starts.clear();
                starts.push_back(i);
              }
              else if(aktualna_dlugosc == najdluzszy){
                starts.push_back(i);
              }
            }
            else{
                break;
            }
        }
    }

    vector<vector<int>> result;
    for(int i = 0; i < starts.size(); i++){
        result.push_back(vector<int>(A + starts[i], A + starts[i] + najdluzszy));
    }

    return result;
}

vector<vector<int>> sliding_window(int A[], int k, int n) {
    int lewy = 0;
    int najdluzszy = 0;
    vector<int> starts;
    int suma = 0;

    for(int prawy = 0; prawy < n; prawy++){
        suma += A[prawy];

        while(suma >= k && lewy <= prawy){
            suma -= A[lewy];
            lewy++;
        }

        int aktualna_dlugosc = prawy - lewy + 1;
        if(aktualna_dlugosc > najdluzszy){
            najdluzszy = aktualna_dlugosc;
            starts.clear();
            starts.push_back(lewy);
        }
        else if(aktualna_dlugosc == najdluzszy){
            starts.push_back(lewy);
        }
    }

    vector<vector<int>> result;
    for(int i = 0; i < starts.size(); i++){
        result.push_back(vector<int>(A + starts[i], A + starts[i] + najdluzszy));
    }

    return result;
}

void generuj(int *tab, int n, int nmax) {
    for(int i = 0; i < n; i++){
        tab[i] = rand() % nmax;
    }
}

void wypisz_resultat(vector<vector<int>> result) {
    for (int i = 0; i < result.size(); i++){
        cout << "[";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "] ";
    }
    cout << endl;
}

int *tab;
float *czas1;
float *czas2;

clock_t start, finish;

int main() {
    // Niewygodne zestawy danych
    int A1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int A2[] = {10, 20, 30, 40, 50, 60};
    int A3[] = {7, -3, 6, -4, 9};
    int A4[] = {1, 100, 2, 90, 3, 80, 4, 70};

    int k1 = 4;
    int k2 = 5;
    int k3 = 10;
    int k4 = 50;

    int n1 = sizeof(A1) / sizeof(A1[0]);
    int n2 = sizeof(A2) / sizeof(A2[0]);
    int n3 = sizeof(A3) / sizeof(A3[0]);
    int n4 = sizeof(A4) / sizeof(A4[0]);

    cout << "Brute force: " << endl;
    cout << "Test 1: ";
    wypisz_resultat(brute_force(A1, k1, n1));
    cout << "Test 2: ";
    wypisz_resultat(brute_force(A2, k2, n2));
    cout << "Test 3: ";
    wypisz_resultat(brute_force(A3, k3, n3));
    cout << "Test 4: ";
    wypisz_resultat(brute_force(A4, k4, n4));

    cout << endl;

    cout << "Sliding window: " << endl;
    cout << "Test 1: ";
    wypisz_resultat(sliding_window(A1, k1, n1));
    cout << "Test 2: ";
    wypisz_resultat(sliding_window(A2, k2, n2));
    cout << "Test 3: ";
    wypisz_resultat(sliding_window(A3, k3, n3));
    cout << "Test 4: ";
    wypisz_resultat(sliding_window(A4, k4, n4));

    // Testowanie złożoności
    int N[] = {250000, 500000, 1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000};
    int liczba_testow = sizeof(N) / sizeof(N[0]);
    czas1 = (float *) malloc(liczba_testow * sizeof (float) );
    czas2 = (float *) malloc(liczba_testow * sizeof (float) );

    for(int i = 0; i < liczba_testow; i++){
        tab = (int *) malloc(N[i] * sizeof (int) );
        generuj(tab, N[i], 10000);

        start = clock();
        brute_force(tab, N[i]/2, N[i]);
        finish = clock();
        czas1[i] = ((float)(finish - start)) / CLOCKS_PER_SEC;

        start = clock();
        sliding_window(tab, N[i]/2, N[i]);
        finish = clock();
        czas2[i] = ((float)(finish - start)) / CLOCKS_PER_SEC;
        free(tab);
    }
    cout << endl << endl;
    printf(" L.p.      n     t1 [s]    t2 [s] \n ");
    for(int i = 0; i < liczba_testow; i++){
        printf("%2d %10d %6.6f %6.6f\n ", i+1, N[i], czas1[i], czas2[i]) ;
    }

    return 0;
}
