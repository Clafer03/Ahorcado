
#include <iostream>
#include <sstream>
#include <string.h>
#include <iterator>
#include <stdlib.h>
#include <time.h>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

/*aun falta terminar*/

void intentos(int nroIntento){
	if(nroIntento < 8){
			cout << " _____\n";
		}
		if(nroIntento < 7){
			cout<<"\e[A";
			cout << " _____\n";
			cout << "      |\n";
		}
		if(nroIntento < 6){
			for(int i = 0; i<2; i++){
				cout<<"\e[A";
			}	
			cout << " _____\n";
			cout << "      |\n";
			cout << "      O\n";
		}
		if(nroIntento < 5){
			for(int i = 0; i<3; i++){
				cout<<"\e[A";
			}
			cout << " _____\n";
			cout << "      |\n";
			cout << "      O\n";
			cout << "      | \n";
		}
		if(nroIntento < 4){
			for(int i = 0; i<4; i++){
				cout<<"\e[A";
			}
			cout << " _____\n";
			cout << "      |\n";
			cout << "      O\n";
			cout << "      |\\\n";
		}
		if(nroIntento < 3){
			for(int i = 0; i<4; i++){
				cout<<"\e[A";
			}
			cout << " _____\n";
			cout << "      |\n";
			cout << "      O\n";
			cout << "     /|\\\n ";
		}
		if(nroIntento < 2){
			for(int i = 0; i<4; i++){
				cout<<"\e[A";
			}
			cout << " _____\n";
			cout << "      |\n";
			cout << "      O\n";
			cout << "     /|\\\n ";
			cout << "      \\\n ";	
		}
		if(nroIntento < 1){
			for(int i = 0; i<5; i++){
				cout<<"\e[A";
			}
			cout << "____\n";
			cout << "      |\n";
			cout << "      O\n";
			cout << "     /|\\\n ";
			cout << "    / \\\n ";	
		}
}


void proceso2(	char letra, 
				int obj, 
				vector<char> & palabras, 
				vector<int> & arrPos, 
				string seleccion, 
				vector<string> & guiones, int nroIntento){
	char pal;
	int pos;
	vector <int> k;
			
	for(int i = 0; i < arrPos.size(); i++){
		k.push_back(arrPos[i]);
	}
	cout << endl;
		
	for(int i = 1; i <= palabras.size(); i++) {		
	    pal = seleccion[i-1];
		if(toupper(letra) == pal){
			for(int i = 0; i<k.size(); i++){
				guiones[k[i]].erase();
				guiones[k[i]] = letra;
			}
		}
	}
	
	cout << endl;
	
	for(int i = 0; i < seleccion.size(); i++){
		cout << "   " <<guiones[i];
	}	
	cout << endl;
	
	arrPos.clear();
	k.clear();
	
	intentos(nroIntento);
	
	for(int i = 0; i < seleccion.size(); i++){
		
	}
		
}


void juego(	char letra, 
			vector<char> & palabras, 
			string seleccion, 
			char pal, 
			int obj, 
			vector<string> & guiones ){
	
	vector<int> arrPos;
	int pos;
	int nroIntento = 8;
	
	for(int i = 0; i < seleccion.size(); i++){
		cout <<"   "<<guiones[i];
	}
	
	cout << "\nIngrese una letra:\n";
	
	do{
		cout << " --- Posee " << nroIntento << " intentos ---\n";
		cout << "-->";
		cin >> letra;
		for(int i = 1; i <= seleccion.size(); i++) {
	    	pal = seleccion[i-1];
			if(toupper(letra) == pal){
				pos = i-1;
				arrPos.push_back(pos);
			}
	    }
	    if (count(palabras.begin(), palabras.end(), toupper(letra))) {
        	nroIntento;
	    }
	    else {
	        nroIntento--;
	    }
	    system("PAUSE()");
	    system("cls");
	    proceso2(letra, obj, palabras, arrPos, seleccion, guiones, nroIntento);
	    
	}while(nroIntento >= 1);
}


void proceso(string categoria[]){
	
	srand(time(NULL));
	string seleccion;
	char letra;
	vector<char> palabras;
	vector<string> guiones;
	string guion = "   -";
	char pal;
	int obj;
	
	obj = rand()%5; //selecciona un numero random del 0 al 5 - ELECCION DE OBJETO DE CATEGORIA
	seleccion = categoria[obj]; // se pasa como string
	
	for(int i = 0; i < seleccion.size(); i++){ // replicamos el tamaño de la palabra y la "convertimos" en guiones 
		guiones.push_back(guion); 
	}
	
	cout << endl;
	
    for(int i = 1; i <= seleccion.size(); i++) { // descomponemos la palabra en letras y las guardamos en un array
    	pal = seleccion[i-1];
    	palabras.push_back(pal);
    }

	juego(letra, palabras, seleccion, pal, obj, guiones);

}	


void select(int categoria){
	
	if(categoria == 1){
		string Deportes[5] = {"FUTBOL", "VOLEY", "RUGBY", "BASKET", "NATACION"};
		proceso(Deportes);
	}
	if(categoria == 2){
		string Alimentos[5] = {"PERA", "ATUN", "MANZANA", "PLATANO", "LECHE"};
		proceso(Alimentos);
	}
	if(categoria == 3){
		string Colores[5] = {"ROJO", "AZUL", "AMARILLO", "CELESTE", "NEGRO"};
		proceso(Colores);
	}
}


void menu(int o){
	
	switch(o){
		case 1: 
			system("cls");
			select(o);
			break;
		case 2: 
			system("cls");
			select(o);
			break;
		case 3: 
			system("cls");
			select(o);
			break;
		default:
			cout << "Ingrese una opción valida";
			break;
	}	
}


int main(){
	
	int opt;
	cout << "		\n\n		  <---||| A-H-O-R-C-A-D-O |||---> \n\n";
	cout << "			Ingrese una opcion: \n";
	cout << "			Deportes ... [1]\n";
	cout << "			Alimentos ... [2]\n";
	cout << "			Colores ... [3]\n";
	cin >> opt;
	system("cls");
	
	menu(opt);		
}
