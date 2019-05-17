/* Lorenzo Cauli 21-09-2018
Scopo: trasformare un numero N minore/uguale di 255 in binario tramite metodo delle potenze e metodo della base, per poi scriverlo
dati:
NumeroD	I	int	NumeroD>0 && NumeroD<=255	*/

#include <iostream>
using namespace std;

//dichiarazione variabili
int NumeroD, NumeroB, bin1, bin2, bin3, bin4, bin5, bin6, bin7, bin8,  Q;

int main() {
//richiesta di un numero e error checking
	cout << "Immettere un numero\n";
	cin >> NumeroD;
	while ( NumeroD < 0 ) {
		cout << "Numero non valido\n";
		cout << "Immettere un numero\n";
		cin >> NumeroD;
	}
	while ( NumeroD > 255 ) {
		cout << "Numero non valido\n";
		cout << "Immettere un numero\n";
		cin >> NumeroD;
	}
//	cout << NumeroD << "\n";
//conversione
	Q = NumeroD / 2;
	bin1 = Q % 2;
	bin2 = Q % 2;
	Q = Q / 2;
	bin3 = Q % 2;
	Q = Q / 2;
	bin4 = Q % 2;
	Q = Q / 2;
	bin5 = Q % 2;
	Q = Q / 2;
	bin6 = Q % 2;
	Q = Q / 2;
	bin7 = Q % 2;
	Q = Q / 2;
	bin8 = Q % 2;
//output del numero binario risultante;
	cout << bin8 << bin7 << bin6 << bin5 << bin4 << bin3 << bin2 << bin1 << "\n";
}

