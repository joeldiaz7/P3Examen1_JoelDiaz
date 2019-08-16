#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <fstream>

using namespace std;

#ifndef SOLDADO_CPP
#define SOLDADO_CPP

class soldado{
	private:
		string name;
		int vida;
		int fuerza;
	public:
		soldado(){}
		soldado(string name, int vida, int fuerza){
			this->name=name;
			this->vida=vida;
			this->fuerza=fuerza;
		}
		string getName(){
			return name;
		}
		int getVida(){
			return vida;
		}
		void setVida(int v){
			vida=v;
		}
		int getFuerza(){
			return fuerza;
		}
	    virtual atacar(soldado s){}
		virtual defender(soldado s,int p){}
		print(){
		 	cout<<"Nombre: "<<name<<"| Vida: "<<vida<<"| Fuerza: "<<fuerza<<endl;
		}
		~soldado(){}
};

#endif

