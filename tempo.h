#ifndef TEMPO_H_
#define TEMPO_H_


// ponto cpp. ou .cc é a mesma fucking coisa


class Time {
	int h,m,s;
public: //Usuário tem acesso;
	Time(int hour, int minute, int second);
	Time();// Construtor
	~Time(); // Destrutor
	void tick();
	void forma_universal() const;
	void forma_padrao() const;
private:
	void validate(); //Usuário NÃO tem acesso;
public:
	int hora() const;
	int minuto() const;
	int segundo() const;

};

#endif