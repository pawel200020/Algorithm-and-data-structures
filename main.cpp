#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    for (int j = 1; j < n; j++) {
        int i = j - 1;
        int elem = array[j];
        while (i >= 0 && array[i] > elem) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = elem;
    }
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
