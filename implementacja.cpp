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

int main() {
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

    return 0;
}
