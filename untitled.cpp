#include <iostream>
#include "tempo.h"
#include "tempo.cc"

using namespace std;

//try download eclipse.

int main(void) {
	 Time obj(10,34,00);
	for (int i = 0; i < 100000; i++) {
		obj.forma_padrao();
		obj.forma_universal();
		obj.tick();
		if (obj.hora() == 11) {
			cout << "sao onze horas!!" << endl;
			break;
		}
	}

	return 0;
}