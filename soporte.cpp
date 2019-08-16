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

#ifndef SOPORTE_CPP
#define SOPORTE_CPP

class soporte : public soldado{
	private:
		int blindaje;
		int camuflaje;
	public:
		soporte(string name, int vida, int fuerza, int blindaje, int camuflaje):soldado(name, vida, fuerza){
			this->blindaje=blindaje;
			this->camuflaje=camuflaje;
		}
		int getBlindaje(){
			return blindaje;
		}
		int getCamuflaje(){
			return camuflaje;
		}
		void setBlindaje(int b){
			blindaje=b;
		}
		void setCamuflaje(int c){
			camuflaje=c;
		}
	    atacar(soldado soldado){
	    	if(typeid(soldado)==typeid(soporte)){
	    		return soldado::getFuerza()*(10);
			}else{
				return soldado::getFuerza()*(15+camuflaje);
			}
		}
		defender(soldado soldado,int p){
			if(typeid(soldado)==typeid(soporte)){
	    		return soldado::getVida()-p;
			}else{
				return soldado::getVida()-(p/(blindaje*2));
			}
		}
		~soporte(){}
};

#endif
