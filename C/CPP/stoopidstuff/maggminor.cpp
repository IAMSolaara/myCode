/* Monica Camba 21-09-2018
Scopo: riconoscere se una persona e' maggiorenne
Dati:
eta		I	int	eta >= 0 && eta < 110
risposta	O	string	eta >= 18 = "Maggiorenne", eta < 18 = "Minorenne" */

#include <iostream>
using namespace std;
//dichiarazione variabili

int main() {
//richiesta dell'eta' e error checking
	int eta;
	cout << "Dimmi l'eta' della persona\n";
	cin >> eta;
	while (eta < 0 || eta > 110) {
		cout << "Numero invalido\n";
		cout << "Dimmi l'eta' della persona\n";
		cin >> eta;
	}
//determinazione della maggiorennita' o minorennita' e risposta
	if (eta >= 18) {
		cout << "La persona e' maggiorenne\n";
	}
	else {
		cout << "La persona e' minorenne\n";
	}
	return 0;
}
