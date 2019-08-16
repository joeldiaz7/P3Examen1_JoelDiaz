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

#include "soldado.cpp"
using namespace std;

#ifndef ASALTO_CPP
#define ASALTO_CPP

class asalto : public soldado{
	private:
		int velocidad;
		int fuerzaExtra;
	public:
		asalto(string name, int vida, int fuerza, int velocidad, int fuerzaExtra):soldado(name, vida, fuerza){
			this->velocidad=velocidad;
			this->fuerzaExtra=fuerzaExtra;
		}
		int getVelocidad(){
			return velocidad;
		}
		int getFuerzaExtra(){
			return fuerzaExtra;
		}
		void setVelocidad(int v){
			velocidad=v;
		}
		void setFuerzaExtra(int fe){
			fuerzaExtra=fe;
		}
	    atacar(soldado soldado){
	    	if(typeid(soldado)==typeid(asalto)){
	    		return soldado::getFuerza()*10;
			}else{
				return soldado::getFuerza()*(10+(velocidad*2));
			}
		}
		defender(soldado soldado,int p){
			if(typeid(soldado)==typeid(asalto)){
	    		return soldado::getVida()-p;
			}else{
				return soldado::getVida()-(p/fuerzaExtra);
			}
		}
		~asalto(){}
};

#endif

