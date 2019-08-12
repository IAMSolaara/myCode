#include <iostream>
using namespace std;

int main() {
	int Q, pot, NumeroD, bin1, bin2, bin3, bin4, bin5, bin6, bin7, bin8;
	cout << "inserire\n";
	cin >> NumeroD;
	pot = 256;
	while ( NumeroD < pot) {
//		cout << pot << "\n";
		pot = pot / 2;
//		cout << pot << "\n";
	}
	while ( pot > 1 ) {
		bin1 = NumeroD / pot;
		Q = NumeroD % pot;
		pot = pot / 2;
		bin2 = Q / pot;
		Q = Q % pot;
		pot = pot / 2;
		bin3 = Q / pot;
		Q = Q % pot;
		pot = pot / 2;
		bin4 = Q / pot;
		Q = Q % pot;
		pot = pot / 2;
		bin5 = Q / pot;
		Q = Q % pot;
		pot = pot / 2;
		bin6 = Q / pot;
		Q = Q % pot;
		pot = pot / 2;
		bin7 = Q / pot;
		Q = Q % pot;
		pot = pot / 2;
		bin8 = Q / pot;
		Q = Q % pot;
		}
	cout << bin1 << bin2 << bin3 << bin4 << bin5 << bin6 << bin7 << bin8 << "\n";


}
