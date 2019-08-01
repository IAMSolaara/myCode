#include <iostream>
using namespace std;

int main() {
	int numero, pot, Q;
	pot = 128;
	numero = 130;
	Q = numero / pot;
	cout << Q << "\n";
	Q = numero % pot;
	cout << Q << "\n";
}
