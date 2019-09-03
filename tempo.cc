#include <iostream>
#include "tempo.h"
using namespace std;


Time::Time(int hour, int minute, int second):
			h { hour }, m { minute }, s { second } {
		
		validate();
		forma_universal();

	}
	Time::Time() {
		h = 12;
		m = 0;
		s = 0;

	}
	Time::~Time(){
		cout << "done" << endl;
	}
	void Time::tick() {
		s++;
		if (s == 60) {
			m++;
			s = 0;
		}
		if (m == 60) {
			h++;
			m = 0;
		}
		if (h == 24) {
			h = 0;
		}
	}
	void Time::forma_universal() const {
		cout << h << ":" << m << ":" << s << endl;
	}
	void Time::forma_padrao() const {

		if (h > 12) {
			cout << (h - 12) << ":" << m << ":" << s << "PM" << endl;
		} else {
			cout << h << ":" << m << ":" << s << "AM" << endl;
		}
	}


	void Time::validate() {
		if (h >= 24 || h < 0) {
			h = 0;
		}
		if (m >= 60 || m < 0) {
			m = 0;
		}
		if (s >= 60 || s < 0) {
			s = 0;
		}
	}


	int Time::hora() const {
		return h;
	}
	int Time::minuto() const {
		return m;
	}
	int Time::segundo() const {
		return s;
	}

//Só um destrutor pode aparecer aqui;