#ifndef _COMPARADOR_
#define _COMPARADOR_

#include "Changes.h"

using namespace std;

//os algoritmos base do funcionamento do programa sao tratados aqui
class Comparador{
private:
	int offset, ** matrix;  //offset - primeiras n linhas em comum desde o inicio dos dois ficheiros, matrix - matriz com valores através da qual podem ser calculadas diferencas/semelhanca entre dois vectores de strings
	bool offsetFlag; //indica se ja foram adicionadas a "offset" linhas a lcs
	string original, copia; //nomes dos ficheiros
	vector <string> lcs; //vector com as linhas semelhantes dos dois ficheiros
	vector <int> linesEquals; //numero das linhas semelhantes
	Changes* change; //objeto no qual são tratadas a informacao sobre as diferencas/semelhancas
public:
	Comparador(Changes *change); //recebe um objeto changes e guarda-o em change
	void menuInicial(); //o utilizador indica o nome do ficheiro original/copia
	void menuPrincipal(); //pequeno menu onde o utilizador por visualizar as diferencas/semelhancas ou pode sair do programa
	vector<string> sepLinhas(string nome); //dado um nome de um ficheiro, esta funcao retorna um vetor de strings em que cada posicao do vetor corresponde a uma linha do ficheiro respetivo
	void clearAttributes(); //coloca todos os atributos com valores nulos ou predefinidos a 0, lanca o clearAttributes de "change" também
	bool start_of_diff(); //returns true and sets the offset if the files are different
	void calcLCS(vector<string> original, vector<string> copia); //prenche a matrix comparando a diferencas/semelhancas entre dois vetores iniciais em relacao ao original
	void backTrack(vector<string> original, vector<string> copia, int i, int j); //determina as linhas semelhantes e guarda toda essa informacao em lcs, lineEquals
	void print_diff( vector<string> original, vector<string> copia, int i, int j); //calcula as diferencas entre dois vetores de strings em relacao ao original e vai guardando essa informacao no objeto change
	};

#endif
