#include<iostream>
using namespace std;

class pessoa{
	int altura;
public:
	pessoa(){
		altura=10;
	}
	void crescer(){
		altura++;
	}
	int qual_altura(){
		return altura;
	}
};

int main(){

	pessoa obj;
	pessoa *obj2 = new pessoa;
	//obj.altura=5;
	//caso seu objeto seja dinâmico, use seta, tipo ponteiro mesmo ->altura
	//objeto estático você usa ponto .blablabla
	
	/*
	ALOCAÇÃO DINÂMICA DE MEMÓRIA
	Caso não for vetor:  
	Alocação: new
	Desalocação: delete
	Caso seja vetor:
	Alocação: new blablaqbla[tamanho]
	Desalocação: delete[sem tamanho]
	*/
	cout << obj.qual_altura() << endl;
	obj.crescer();
	obj2->crescer();
	obj2->crescer();
	cout << obj.qual_altura() << endl;
	cout << obj2->qual_altura() << endl;

	cout << sizeof(pessoa) << " bytes" << endl;
	return 0;
}