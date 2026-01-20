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

int main() {
    int A[] = {1, 130, 2, 5, 1, 1, 4, 4, 1, 3, 1, 1};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 10;

    vector<vector<int>> result;
    
    cout << "Brute force: ";
    result = brute_force(A, k, n);
    for (int i = 0; i < result.size(); i++){
        cout << "[";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Sliding window: ";
    result = sliding_window(A, k, n);
    for (int i = 0; i < result.size(); i++){
        cout << "[";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "] ";
    }
    cout << endl;



    return 0;
}
