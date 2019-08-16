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
#include <sstream>

#include "asalto.cpp"
#include "soporte.cpp"
using namespace std;
string token(string, string, int);
void cargar();

bool t = true;
int op;
int gana;
vector<soldado*> equipo1;
vector<soldado*> equipo2;
int atk, def, dmg; //posiciones y dano de la simulacion
int ronda;

int main(){
	srand(time(NULL));
	ofstream escribir;
	cargar();
	while(t){
		cout<<"Ingrese una opcion: "<<endl;
		cout<<"1) Listar soldados de ambos bandos"<<endl;
		cout<<"2) >>> Iniciar simulacion >>>"<<endl;
		cout<<"3) Salir"<<endl;
		cin>>op;
		switch(op){
			case 1://listar
				cout<<"EQUIPO 1: "<<endl;
				for(int i=0;i<equipo1.size();i++){
					equipo1[i]->print();
				}
				cout<<endl;
				cout<<"EQUIPO 2: "<<endl;
				for(int i=0;i<equipo2.size();i++){
					equipo2[i]->print();
				}
				cout<<endl;
				break;
			case 2://simular
				gana=1;
				ronda=0;
				
				while (equipo1.size()>0 && equipo2.size()>0) {
					if (ronda == 0) {
						atk = (rand()%equipo1.size());
						def = (rand()%equipo2.size());
						equipo2.at(def)->setVida( equipo2.at(def)->getVida()-equipo1.at(atk)->getFuerza() );
						//eliminar muertos
						if (equipo2.at(def)->getVida()<=0) {
							equipo2.erase(equipo2.begin()+def);
						}
						//cambio de turno
						ronda=1;
					}else{				
						atk = (rand()%equipo2.size());
						def = (rand()%equipo1.size());
						equipo1.at(def)->setVida( equipo1.at(def)->getVida()-equipo2.at(atk)->getFuerza() );
						//eliminar muertos
						if (equipo1.at(def)->getVida()<=0) {
							equipo1.erase(equipo1.begin()+def);
						}
						//cambio de turno
						ronda = 0;
					}			
				}
				if(equipo1.size()>equipo2.size()){
					gana=1;
				}else{
					gana=2;
				}
				//guardar ganador
				escribir.open("./ultimo_ganador.txt");
				if (gana==1){
					cout<<"Gana el equipo 1! Detalles en el archivo 'ultimo_ganador.txt'"<<endl;
					escribir<<"Ganador: EQUIPO 1"<<endl;
					escribir<<"Sobrevivientes del equipo ganador: "<<endl;
					for (int i=0; i<equipo1.size() ; i++){
						escribir<<equipo1.at(i)->getName()<<"| Vida restante: "<<equipo1.at(i)->getVida()<<endl;   
					}	
				}else{
					cout<<"Gana el equipo 2! Detalles en el archivo 'ultimo_ganador.txt'"<<endl;
					escribir<<"Ganador: EQUIPO 2"<<endl;
					escribir<<"Sobrevivientes del equipo ganador: "<<endl;
					for (int i=0; i<equipo2.size() ; i++){
						escribir<<equipo2.at(i)->getName()<<"| Vida restante: "<<equipo2.at(i)->getVida()<<endl;   
					}
				}
				cout<<"Simulacion finalizada, cerrando el programa..."<<endl;
				escribir.close();//close
				//// programa finalizado por la simulacion ////
				system("pause");
				return 0; //programa finalizado por la simulacion
				break;	
			case 3://salir
				system("pause");
				return 0;
				break;
		}
	}
	//
	return 0;
}

//metodo de cargar
void cargar(){
	fstream Leer;
	string linea;
	stringstream convert;
	bool team=true;
	Leer.open("./soldados.txt");
	while(!Leer.eof()){
		getline(Leer,linea);
		for(int i=1;i<=linea.size();i+=6){
			if(token(linea,"/",i)!="&" && token(linea,"/",i)!="" && team){
				if(token(linea,"/",i)=="Asalto"){
						convert<<token(linea,"/",i+4); 
						int velocidad=0; 
						convert>>velocidad;  
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+5)); 
						int fuerzaextra=0; 
						convert>>fuerzaextra; 
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+2)); 
						int puntosdevida=0; 
						convert>>puntosdevida; 
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+3)); 
						int puntosdefuerza=0; 
						convert>>puntosdefuerza; 
						equipo1.push_back(new asalto(token(linea,"/",i+1),puntosdevida,puntosdefuerza,velocidad,fuerzaextra));
				}else{
						convert<<token(linea,"/",i+4); 
						int blindaje=0; 
						convert>>blindaje;  
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+5)); 
						int camuflaje=0; 
						convert>>camuflaje; 
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+2)); 
						int puntosdevida=0; 
						convert>>puntosdevida; 
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+3)); 
						int puntosdefuerza=0; 
						convert>>puntosdefuerza; 
						equipo1.push_back(new soporte(token(linea,"/",i+1),puntosdevida,puntosdefuerza,blindaje,camuflaje));
				}
				}else if(!team && token(linea,"/",i)!=""){
					if(token(linea,"/",i)=="Asalto"){
						convert<<token(linea,"/",i+4); 
						int velocidad=0; 
						convert>>velocidad;  
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+5)); 
						int fuerzaextra=0; 
						convert>>fuerzaextra; 
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+2)); 
						int puntosdevida=0; 
						convert >> puntosdevida; 
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+3)); 
						int puntosdefuerza=0; 
						convert>>puntosdefuerza; 
						equipo2.push_back(new asalto(token(linea,"/",i+1),puntosdevida,puntosdefuerza,velocidad,fuerzaextra));
				}else{
						convert<<token(linea,"/",i+4); 
						int blindaje=0; 
						convert>>blindaje;  
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+5)); 
						int camuflaje=0; 
						convert>>camuflaje; 
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+2)); 
						int puntosdevida=0; 
						convert >> puntosdevida; 
						convert.str("");
						convert.clear();
						convert<<(token(linea,"/",i+3)); 
						int puntosdefuerza=0; 
						convert>>puntosdefuerza; 
						equipo2.push_back(new soporte(token(linea,"/",i+1),puntosdevida,puntosdefuerza,blindaje,camuflaje));
					}
			}else{
				team=false;
				i-=5;
			}
		}
	}
	Leer.close();
}

string token(string cadena, string divisor, int pos){
    if(cadena.size()>0){
        char oracion[cadena.size()]; 
        for (int i=0;i<=cadena.size();i++){
        	oracion[i]=cadena[i];
        }                    
        char *ptrtoken; 
        int num=1;
        const char* d=divisor.c_str();
        ptrtoken = strtok(oracion , d);             
        while(ptrtoken){
            if(num==pos){ 
                return ptrtoken;                    
            }       
            ptrtoken = strtok(NULL, d);
            num++;
        }
        return "";
    } else {
        return "";
    }
}

