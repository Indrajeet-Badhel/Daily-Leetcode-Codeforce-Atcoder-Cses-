#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;  // height of pyramid
    for (int i = n; i >0; i--) {
        // print spaces
        for (int s = 0; s < n - i - 1; s++) {
            cout << " ";
        }
        for (int j = 0; j<; j--) {
            cout << "*";
        }
            cout << "\n";
    }
    return 0;
}
