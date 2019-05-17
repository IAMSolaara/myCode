#include <iostream>
using namespace std;
int main() {
float R, S, C;
const float Pi = 3.14;
cout << "Dimmi il raggio\n";
cin >> R;
C = 2 * Pi * R;
S = Pi * R * R;
cout << "La circonferenza vale " << C;
cout << "\nLa superficie vale " << S;
cout << "\n";
}
