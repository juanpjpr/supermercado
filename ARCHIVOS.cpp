#include <iostream>
#include <string.h>

using namespace std;

void abrirL(FILE*&);
void abrirE(FILE*&);
template<typename T>T leer(FILE*);
template<typename T>void escribir(FILE*,T);
void cerrar(FILE*);

void abrirL(FILE*& f){
	f=fopen("archivo.bin","r+b"); 
}

void abrirE(FILE*& f){
	f=fopen("archivo.bin","w+b"); 
}

template<typename T>T leer(FILE* f){
	T nuevo;
	fread(&nuevo,sizeof(T),1,f);
	return nuevo;
}

template<typename T>void escribir(FILE*f,T v){
	fwrite(&v,sizeof(T),1,f);
}

void cerrar(FILE* f){
	fclose(f);
}




