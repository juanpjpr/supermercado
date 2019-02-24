#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "ARCHIVOS.h"

using namespace std;

struct item{
	int id;
	char desc[15];
	float pu;
	
	
	void setId();
	void setDesc();
	void setPu();
	int getId();
	void mostrar();
	string getDesc();
	float subT(int);
	float getPu();
};

struct itemTk{
	int id;
	int cant;
	
	int getCant();
	void mostrar();
	int getId();
	void setId();
	void setCant();

};

template <typename T>
struct Nodo {
T info;
Nodo<T>* sig;

Nodo(){
	sig=NULL;
}
};


template <typename T>
void agregar (Nodo<T>* &p, T v);
template <typename T>
bool haySig(Nodo<T>); 
template <typename T>
void mostrar(Nodo<T>*);
item createItem(int,string,float);
item createItem();
item buscar(Nodo<item>*,int);
itemTk createItemTk(int,int);
itemTk createItemTk();
void imprimeTk(Nodo<item>*,Nodo<itemTk>*);
bool existe(Nodo<item>*,int);
void clear();
void cargarInventario(FILE*,Nodo<item>*&);

int main(){
	Nodo<itemTk>*tk=NULL;
	Nodo<item>*inventario=NULL;
	FILE*f;
	cargarInventario(f,inventario);
	

	int op;

/*	do {
	clear();
	cout<<"1-NUEVA VENTA"<<endl;
	cout<<"2-AGREGAR ITEM"<<endl;
	cout<<"3-MOSTRAR INVENTARIO"<<endl;
	cout<<"4-BUSCAR ITEM"<<endl;
	cout<<"5-SALIR"<<endl<<endl;
	cout<<"Opcion:";
	cin>>op;
	
	switch(op){
		clear();
		case 2: agregar(inventario,createItem());
		break;
		case 3:
		clear();
		cout<<"ID\tDesc\tPU"<<endl;
		cout<<"---------------------"<<endl;
		mostrar(inventario);
		system("pause");
		break;
		case 4: 
			clear();
			item nuevo;
			nuevo.setId();
			clear();
			if(existe(inventario,nuevo.getId())){
				nuevo=buscar(inventario,nuevo.getId());
				cout<<"BUSCAR ITEM"<<endl;
				cout<<"-------------------"<<endl;
				cout<<"Id:"<<nuevo.getId()<<endl;
				cout<<"Desc:"<<nuevo.getDesc()<<endl;
				cout<<"Pu:"<<nuevo.getPu()<<endl;
				}
			else{
				cout<<"No hay ningun elemento con ese id"<<endl;
			}
			system("pause");
		break;
	}
	
}while(op!=5);*/
}

template <typename T>
void agregar (Nodo<T>* &p, T v){
Nodo<T>* aux=p;
Nodo<T>* nuevo = new Nodo<T>();
nuevo->info = v;

if (p == NULL)
p = nuevo;
else{
	while(aux->sig!=NULL){
		aux=aux->sig;
	}
	aux->sig=new Nodo<T>();
	aux->sig->info=v;
}
}

template <typename T>
 bool haySig(Nodo<T>*p){
 	return p->sig==NULL?1:0;
 }
 
template <typename T>
void mostrar(Nodo<T>*p){
	while(p){
		p->info.mostrar();
		p=p->sig;
	}
}

item createItem(int i,string n,float p){
	item nuevo;
	nuevo.id=i;
	strcpy(nuevo.desc, n.c_str());
	nuevo.pu=p;
	return nuevo;
}


itemTk createItemTk(int i,int c){
	itemTk nuevo;
	nuevo.id=i;
	nuevo.cant=c;
	return nuevo;
}

void item::mostrar(){
	cout<<id<<"\t"<<desc<<"\t"<<pu<<endl;
}

item buscar(Nodo<item>*lista,int id){

	while(lista->info.getId()!=id){
		lista=lista->sig;
	}
	return lista->info;
}

int item::getId(){
	return id;
}

void itemTk::mostrar(){
	cout<<id<<"\t"<<cant<<endl;
}

int itemTk::getId(){
	return id;
}

float item::subT(int cant){
	float sub=pu*cant;
	return sub;
}

int itemTk::getCant(){
	return cant;
}

void imprimeTk(Nodo<item>*inventario,Nodo<itemTk>*tk){
	item aux;
	float tot=0;
	float sub=0;
	cout<<"ID\tDESC\tPU\tSUB"<<endl;
	cout<<"-----------------------------"<<endl;
	while(tk){
	aux=buscar(inventario,tk->info.getId());
	sub=aux.subT(tk->info.getCant());
	cout<<tk->info.getId()<<"\t"<<aux.getDesc()<<"x"<<tk->info.getCant()<<"\t"<<aux.getPu()<<"\t"<<sub<<endl;
	tot=tot+sub;
	tk=tk->sig;
}
	cout<<endl<<"------------------>TOTAL: $"<<tot;
}

string item::getDesc(){
	string d=desc;
	return d;
}

float item::getPu(){
	return pu;
}

bool existe(Nodo<item>*lista,int v){
	while(lista && lista->info.getId()!=v)
	{
		lista=lista->sig;
	}
	return lista==NULL?0:1;
}

itemTk createItemTk(){
	itemTk nuevo;
	nuevo.setId();
	nuevo.setCant();
	return nuevo;
}

item createItem(){
	item nuevo;
	nuevo.setId();
	nuevo.setDesc();
	nuevo.setPu();
	return nuevo;
}

void itemTk::setId(){
	cout<<"Id:";
	cin>>id;
}

void itemTk::setCant(){
	cout<<"Cant:";
	cin>>cant;
}

void item::setId(){
	cout<<"Id:";
	cin>>id;
}

void item::setDesc(){
	cout<<"Desc:";
	cin>>desc;
}

void item::setPu(){
	cout<<"Pu:";
	cin>>pu;
}

void clear(){
	system("cls");
}


void cargarInventario(FILE*f,Nodo<item>*&inventario){
	item nuevo;
	abrirL(f);
	nuevo=leer<item>(f);
	while(!feof(f)){
		agregar(inventario,nuevo);
		nuevo=leer<item>(f);
	}
	cerrar(f);
}
