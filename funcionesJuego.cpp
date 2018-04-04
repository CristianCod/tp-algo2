/*
 * funcionesJuego.cpp
 *
 *  Created on: 3 abr. 2018
 *      Author: Cristian
 */

#include "funcionesJuego.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void valoresIniciales(estadoJugador *jugador, semillas *TipoA,semillas *TipoB
		,semillas *TipoC){
	(*jugador).creditos=50;
	(*jugador).unidadesDeRiego=0;
	(*jugador).turnosRestantes=10;
	(*TipoA).precio=1;
	(*TipoA).turnosCosecha=2;
	(*TipoA).cantidad=0;
	(*TipoA).tipoCaracter=(char)65;
	(*TipoA).rentabilidad=10;
	(*TipoA).turnosRecuperacion=1;
	(*TipoB).precio=3;
	(*TipoB).turnosCosecha=4;
	(*TipoB).cantidad=0;
	(*TipoB).tipoCaracter=(char)66;
	(*TipoB).rentabilidad=30;
	(*TipoB).turnosRecuperacion=2;
	(*TipoC).precio=2;
	(*TipoC).turnosCosecha=1;
	(*TipoC).cantidad=0;
	(*TipoC).tipoCaracter=(char)67;
	(*TipoC).rentabilidad=5;
	(*TipoC).turnosRecuperacion=0;



}
char comprobarTipoSemilla(char semillaElegida){
	char tipoSemilla;

	if(toupper(semillaElegida)==(char)65){
		tipoSemilla=65;

	   }
	else if(toupper(semillaElegida)==(char)66){
		tipoSemilla=66;
	    }
    else if(toupper(semillaElegida)==(char)67){
    	tipoSemilla=67;
	    }
   return tipoSemilla;
}


char elegirSemilla(){
	char semillaElegida=64;
	cout<<"Que tipo de semilla va a sembrar? \n";
	cin>>semillaElegida;

	char tipoSemilla=comprobarTipoSemilla( semillaElegida);
    return tipoSemilla;
}


bool verificoCantSemillas(char tipoSemilla, estadoJugador *jugador){
	bool haySemilla;

	if ((((*jugador).cantidadSemillasA)==0)&&(toupper(tipoSemilla)==(char)65)){
        haySemilla=false;
		cout<<"Le faltan semillas tipo 'a', comprelas en el menú \n";

		}
	else if((((*jugador).cantidadSemillasB)==0)&&(toupper(tipoSemilla)==(char)66)){
		haySemilla=false;
		cout<<"Le faltan semillas tipo 'b', comprelas en el menú \n";

		}
	else if((((*jugador).cantidadSemillasC)==0)&&(toupper(tipoSemilla)==(char)67)){
		haySemilla=false;
		cout<<"Le faltan semillas tipo 'c', comprelas en el menú \n";
		}
	else {
		haySemilla=true;
	}
	cout<<"\n";

	return haySemilla;
}
void cambiarEstadoParcela(int fila, int columna, Parcela **parcelas, char tipoSemillaMostrar){
	(*(*(parcelas+fila)+columna)).estadoParcela=tipoSemillaMostrar;
	cout<<"Se cambio el estado de la parcela correctamente.\n";


}
void agregarDatosParcela(Parcela **parcelas, int fila, int columna,
		char tipoSemilla){

	(*(*(parcelas+fila)+columna)).tipoSiembra=tipoSemilla;

	(*(*(parcelas+fila)+columna)).estaSembrada=true;
	(*(*(parcelas+fila)+columna)).cosechar=false;

}

void agregarTurnosCosecha(Parcela **parcelas, int fila, int columna){

	switch(    ((*(*(parcelas+fila)+columna)).tipoSiembra)   ){
	case ((char)65):
			{

		((*(*(parcelas+fila)+columna)).turnosCosecha)=2;

			}break;
	case ((char)66):
			{
		((*(*(parcelas+fila)+columna)).turnosCosecha)=4;

			}break;
	case ((char)67):
			{
		((*(*(parcelas+fila)+columna)).turnosCosecha)=1;

			}break;
	}
}

void actualizarSemillas(estadoJugador *jugador, char tipoSemilla,
		semillas *tipoA, semillas *tipoB, semillas *tipoC){

	if(tipoSemilla==((*tipoA).tipoCaracter)){

		((*jugador).cantidadSemillasA)-=1;

	}
	else if(tipoSemilla==((*tipoB).tipoCaracter)){

		((*jugador).cantidadSemillasB)-=1;

	}
	else if(tipoSemilla==((*tipoC).tipoCaracter)){
		((*jugador).cantidadSemillasC)-=1;
	}
}

bool verificarParcelaSecaVacia(int fila, int columna, Parcela **parcelas){
	bool noSecayNoVacia=NULL;
	if (  ((*(*(parcelas+fila)+columna)).estaSeca)==false   ){
		if(   ((*(*(parcelas+fila)+columna)).estaSembrada)==false      ){
			noSecayNoVacia=true;
		}
		else{
			cout<<"La parcela elegida esta sembrada. "<<endl;
			noSecayNoVacia=false;
		}
	}else{
		cout<<"La parcela elegida esta seca. Espere un turno. "<<endl;
		noSecayNoVacia=false;
	}
	return noSecayNoVacia;
}


bool verificoSiembra(Parcela **parcelas,int  fila, int columna){
	bool estaSembrada=NULL;
	if ( (*(*(parcelas+fila)+columna)).estaSembrada  ){
		estaSembrada=true;

	}else{
		cout<<"La parcela no esta sembrada, elija otra."<<endl;
		estaSembrada=false;}

	return estaSembrada;
}
bool verificoCosechaParcela(Parcela **parcelas,int fila, int columna){
	bool sePuedeCosechar=NULL;

	if( ((*(*(parcelas+fila)+columna)).cosechar)==true   ){
		if(  ((*(*(parcelas+fila)+columna)).estaPodrida)==false ){
			sePuedeCosechar=true;

		}else{
			sePuedeCosechar=false;
			cout<<"La parcela esta Podrida, espere su recuperacion. "<<endl;
		}

	}else{
		sePuedeCosechar=false;
		cout<<"La parcela no esta lista para cosechar, espere los turnos indicados. "<<endl;
	}
	return sePuedeCosechar;

}

void rentabilidad(int fila,int columna, Parcela **parcelas,semillas *tipoA,
		semillas *tipoB, semillas *tipoC,estadoJugador *jugador){

	if(  ((*(*(parcelas+fila)+columna)).tipoSiembra)== ((*tipoA).tipoCaracter) ){
		((*jugador).creditos)+=(*tipoA).rentabilidad;

	}else if(   ((*(*(parcelas+fila)+columna)).tipoSiembra)== ((*tipoB).tipoCaracter)   ){
		((*jugador).creditos)+=(*tipoB).rentabilidad;

	}
	else if (  ((*(*(parcelas+fila)+columna)).tipoSiembra)== ((*tipoC).tipoCaracter)  ){
		((*jugador).creditos)+=(*tipoC).rentabilidad;
	}

}




void comprarSemillas(semillas *tipoA,semillas *tipoB,semillas *tipoC,
		estadoJugador *jugador){
    int cantComprar;
    cout<<"a- tipo a "<<"La cosecha necesita "<<(*tipoA).turnosCosecha<<" turnos."<<"$"<<(*tipoA).precio;
    cout<<"\n"<<endl;
    cout<<"b- tipo b "<<"La cosecha necesita "<<(*tipoB).turnosCosecha<<" turnos."<<"$"<<(*tipoB).precio;
    cout<<"\n"<<endl;;
    cout<<"c- tipo c "<<"La cosecha necesita "<<(*tipoC).turnosCosecha<<" turnos."<<"$"<<(*tipoC).precio;
    cout<<"\n"<<endl;;
    //cout<<"Que tipo de semilla va a sembrar? \n";
    //cin>>semillaElegida;
    char semillaElegida=elegirSemilla();
	cout<<"¿Cuantas semillas quiere comprar?"<<endl;
	cin>>cantComprar;

	if (semillaElegida==((*tipoA).tipoCaracter)){
		(*jugador).cantidadSemillasA+=cantComprar;
		(((*jugador).creditos))-=((*tipoA).precio)*cantComprar;

	}
	else if(semillaElegida==((*tipoB).tipoCaracter)){
		(*jugador).cantidadSemillasB+=cantComprar;
		(((*jugador).creditos))-=((*tipoB).precio)*cantComprar;

	}
	else if(semillaElegida==((*tipoC).tipoCaracter)){
		(*jugador).cantidadSemillasC+=cantComprar;
		(((*jugador).creditos))-=((*tipoC).precio)*cantComprar;

	}

	cout<<"Se compro exitosamente...\n"<<endl;

}


void mostrarInfoSemillas(semillas *semillaTipoA, semillas *semillaTipoB,
		semillas *semillaTipoC){
	cout<<"_______________________________________________________________________________\n";
	cout<<"a- tipo a "<<"La cosecha necesita "<<(*semillaTipoA).turnosCosecha<<" turnos"<<endl;
	cout<<"b- tipo b "<<"La cosecha necesita "<<(*semillaTipoB).turnosCosecha<<" turnos"<<endl;
	cout<<"c- tipo c "<<"La cosecha necesita "<<(*semillaTipoC).turnosCosecha<<" turnos"<<endl;
	cout<<"\n";
	cout<<"_______________________________________________________________________________";


}


void crearTablero(Parcela **parcelas){
	 for(int i=0;i<5;i++){
    	parcelas[i]=new Parcela[4];
	    }

	 for(int i=0;i<5;i++){
	   	for(int j=0;j<5;j++){
    		//cout<<"\nIngrese estado: ";
    		//cin>>(*(*(parcelas+i)+j));
    		//cin>>((*(*(parcelas+i)+j)).estadoParcela);
    		((*(*(parcelas+i)+j)).estadoParcela)=64;
    		((*(*(parcelas+i)+j)).cosechar)=false;
    		((*(*(parcelas+i)+j)).estaPodrida)=false;
    		((*(*(parcelas+i)+j)).estaSeca)=false;
	    	}
	    }
}

void tirarDados(estadoJugador *jugador){
    int numero;
	cout<<"Ingrese un numero del 1 al 6!!! \n";
    cin>>numero;
	unsigned short int unidadesRiego= 1+rand()%6;
	unidadesRiego=5*unidadesRiego;

	if(((*jugador).unidadesDeRiego)>=25){
		cout<<"El tanque esta lleno espere a vaciarlo.\n";
		((*jugador).unidadesDeRiego)=25;

	}
	else{
		cout<<"Obtuvo "<<unidadesRiego<<" unidades de riego!!!\n";
	    (*jugador).unidadesDeRiego=(*jugador).unidadesDeRiego+unidadesRiego;
	}

}
/*INgreso fila y columna, casteo para que lo tome el tablero y si no existe
 *  vuelvo a solicitar ingreso de datos*/
void elegirParcela(int *direccionParcela){
    int fila, columna;
	cout<<"Ingrese la posicion de la parcela(solo fila):"<<endl;
	cin>>fila;
	fila=(fila-1);
	cout<<"Ingrese la posicion de la parcela(solo columna):"<<endl;
	cin>>columna;
	columna=(columna-1);

	*(direccionParcela)=fila;
	*(direccionParcela+1)=columna;
	//cout<<*(direccionParcela);
	//cout<<*(direccionParcela+1);

	while((fila>5)||(columna>5)){
		cout<<"Ingrese la posicion de la parcela(solo fila):"<<endl;
		cin>>fila;
		fila=(fila-1);
		cout<<"Ingrese la posicion de la parcela(solo columna):"<<endl;
		cin>>columna;
		columna=(columna-1);

		*(direccionParcela)=fila;
		*(direccionParcela+1)=columna;

	}
}


void mostrarTablero(Parcela **parcelas, estadoJugador *jugador){
	cout<<"\nBienvenido a granjeros!!!"<<endl;

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			//cout<<(*(*(parcelas+i)+j));
			cout<<"||\t"<<((*(*(parcelas+i)+j)).estadoParcela)<<"\t";
		}
		cout<<"||";
		cout<<"\n";
	}
	cout<<"____________________________________________________________________________"<<endl;
	cout<<"Tiene "<<(*jugador).creditos<<" creditos disponibles.\n";
	cout<<"Tiene "<<(*jugador).unidadesDeRiego<< " unidades de agua para regar sus cultivos.\n";
	cout<<"Le quedan "<<(*jugador).turnosRestantes<<" turnos restantes\n";
	cout<<"\n";
	cout<<"Tiene "<<(*jugador).cantidadSemillasA<<" semillas tipo A para cosechar.\n";
	cout<<"Tiene "<<(*jugador).cantidadSemillasB<<" semillas tipo B para cosechar.\n";
	cout<<"Tiene "<<(*jugador).cantidadSemillasC<<" semillas tipo C para cosechar.\n";
	cout<<"____________________________________________________________________________"<<endl;
	cout<<"\n";
	cout<<"\n";
}

/////////////////////////////////////////////////////////Funciones que se aplican al pasar turno

/*Si parcela no esta regada y esta sembrada, se seca cambiando icono
 *  correspondiente en tablero*/
void buscoParcelas(Parcela **parcelas, int fila, int columna){
	char iconoSeca=(char)83;//icono r
	if( ((*(*(parcelas+fila)+columna)).estaSembrada)==true
	){
		if(  ((*(*(parcelas+fila)+columna)).regada)==false

		){
			//La parcela se seca
			//cambiarEstadoParcela(fila, columna, parcelas, iconoSeca);
			(*(*(parcelas+fila)+columna)).estadoParcela=iconoSeca;


			(*(*(parcelas+fila)+columna)).estaSeca=true;
		}
	}
}
/* Recupera una parcela que tenga el icono correspondiente en tablero y
 *  tenga valor bool estaSeca verdadero*/
void recuperarParcelaSecAnterior(Parcela **parcelas,int fila, int columna){
	char iconoDisponible=(char)64;
	if( ((*(*(parcelas+fila)+columna)).estaSeca)==true){
			if(  ((*(*(parcelas+fila)+columna)).estadoParcela)==(char)83  ){
				//La parcela se seca
				//cambiarEstadoParcela(fila, columna, parcelas, iconoDisponible);
				(*(*(parcelas+fila)+columna)).estadoParcela=iconoDisponible;
				(*(*(parcelas+fila)+columna)).estaSeca=false;
				(*(*(parcelas+fila)+columna)).estaSembrada=false;//Con esta condicion no entraria en la busqueda de parcelas a secarse
				(*(*(parcelas+fila)+columna)).estaPodrida=false;
				//(*(*(parcelas+fila)+columna)).regada=false;
			}
		}else if( ((*(*(parcelas+fila)+columna)).estaSeca)==false   ){
			if(  ((*(*(parcelas+fila)+columna)).estaSembrada)==false ){
				(*(*(parcelas+fila)+columna)).estadoParcela=iconoDisponible;

			}

		}
}


/* Usa llamados a funciones anteriores para agregar y quitar parcelas secas*/
/* Recibe un struct doble puntero 'parcelas' del tipo parcela*/
void agregarParcelaSeca(Parcela **parcelas){
	for(int fila=0; fila<5;fila++){
		for(int columna=0; columna<5; columna++){
			recuperarParcelaSecAnterior(parcelas, fila, columna);
			buscoParcelas(parcelas, fila, columna);
		}
	}

}
///////////////////////////////////////////////////////////////

/*Recibe doble puntero parcelas siendo el tablero*/
/* Sabiendo que esta podrida la parcela, agrega turnos de recuperacion de acuerdo al tipo de siembra que tenia*/
void agregoRecuperacionInicial(Parcela **parcelas, int fila, int columna,
		semillas *tipoA, semillas *tipoB, semillas *tipoC){
	if (   ((*(*(parcelas+fila)+columna)).tipoSiembra) == ((*tipoA).tipoCaracter)  ){
		((*(*(parcelas+fila)+columna)).recuperacion)=(*tipoA).turnosRecuperacion;

	}
	else if(  ((*(*(parcelas+fila)+columna)).tipoSiembra) == ((*tipoB).tipoCaracter)    ){
		((*(*(parcelas+fila)+columna)).recuperacion)=(*tipoB).turnosRecuperacion;
	}
	else if( ((*(*(parcelas+fila)+columna)).tipoSiembra) == ((*tipoC).tipoCaracter)  ){
		((*(*(parcelas+fila)+columna)).recuperacion)=(*tipoC).turnosRecuperacion;

	}
}

/* Si los turnos necesarios para cosechar son menores a cero
 * (se inicio con los necesarios y se fue descontando), la cosecha
 * se pierde y se le asigna el tiempo de recuperacion correspondiente */

void verCosechaPerdida(Parcela **parcelas, int fila, int columna,
		semillas *tipoA, semillas *tipoB, semillas *tipoC){
	char iconoCosecha=(char)35;
	if( ((*(*(parcelas+fila)+columna)).turnosCosecha)<0  ){
		(*(*(parcelas+fila)+columna)).estaPodrida=true;
		agregoRecuperacionInicial(parcelas, fila, columna, tipoA, tipoB, tipoC);


	}else if( (*(*(parcelas+fila)+columna)).turnosCosecha==0   ){
		cambiarEstadoParcela(fila, columna, parcelas, iconoCosecha);
		(*(*(parcelas+fila)+columna)).estaPodrida=false;
		(*(*(parcelas+fila)+columna)).cosechar=true;
		cambiarEstadoParcela(fila, columna, parcelas, iconoCosecha);

	}

}
/*Si la parcela esta regada, esta sembrada,
 * se le quita un turno necesario para cosechar*/
void quitarTurnoSiembra(Parcela **parcelas,int  fila,int  columna){

	if(((*(*(parcelas+fila)+columna)).regada) ){

		((*(*(parcelas+fila)+columna)).turnosCosecha)-=1;
	}
}

void parcelasSinCambios(Parcela **parcelas)
{
	char iconoSinCambio=(char)64;
	for(int fila=0; fila<5; fila++){
			for(int columna=0; columna<5; columna++){
				if ((*(*(parcelas+fila)+columna)).estaSembrada==false){
					(*(*(parcelas+fila)+columna)).estadoParcela=iconoSinCambio;
					(*(*(parcelas+fila)+columna)).cosechar=false;
					(*(*(parcelas+fila)+columna)).estaSeca=false;
					(*(*(parcelas+fila)+columna)).regada=false;

				}


			}

	}


}




/*Recupera las parcelas que ya pasaron por los turnos de
 * recuperacion correspondientes, sino quita un turno de recuperacion*/
void recuperarParcelasCosechadas(Parcela **parcelas, int fila, int columna){
	char sePuedeSembrar=(char)64;
	if( (*(*(parcelas+fila)+columna)).estaPodrida==true ){
		if( ((*(*(parcelas+fila)+columna)).recuperacion)==0 ){
			((*(*(parcelas+fila)+columna)).estaPodrida)=false;
			((*(*(parcelas+fila)+columna)).estaSembrada)=false;
			((*(*(parcelas+fila)+columna)).estaSeca)=false;
			cambiarEstadoParcela(fila, columna, parcelas, sePuedeSembrar);

		}
		else if( ((*(*(parcelas+fila)+columna)).recuperacion)>0  ){
			((*(*(parcelas+fila)+columna)).recuperacion)-=1;
			((*(*(parcelas+fila)+columna)).cosechar)=false;
			((*(*(parcelas+fila)+columna)).estaSeca)=true;//para verificar que no se utilice

		}else{
			cout<<"Error no controlado, sobre si la recuperacion se supero"
					" sin quedar disponible la parcela luego de una cosecha buena"<<endl;
		}
	}
}

/*Verifica las cosechas y consulta a subrutinas si se pudrieron
 * o si ya se pueden cosechar*/

void verificarCosecha(Parcela**parcelas, semillas *tipoA,
		semillas *tipoB, semillas *tipoC){
	for(int fila=0; fila<5; fila++){
		for(int columna=0; columna<5; columna++){
			quitarTurnoSiembra(parcelas, fila, columna);
			verCosechaPerdida(parcelas, fila, columna,tipoA, tipoB, tipoC);
			recuperarParcelasCosechadas(parcelas, fila, columna);
		}
	}

}


void contarTurnos(estadoJugador *jugador){

((*jugador).turnosRestantes)=(((*jugador).turnosRestantes)-1);
	tirarDados(jugador);

}

void borrarHeap(semillas *semillaTipoA, semillas *semillaTipoB,
		semillas *semillaTipoC,estadoJugador *jugador, Parcela **parcelas){
	delete semillaTipoA;
	delete semillaTipoB;
	delete semillaTipoC;
	delete jugador;
	for(int i=0;i<2;i++){
	   	delete[] parcelas[i];
		        }
    delete[] parcelas;
}


void rutinaSembrar(int fila, int columna, estadoJugador *jugador,
		Parcela **parcelas,semillas *tipoA, semillas *tipoB,
		semillas *tipoC, char tipoSemilla){

	cambiarEstadoParcela(fila, columna, parcelas, tipoSemilla);
	agregarDatosParcela(parcelas, fila, columna, tipoSemilla);
	agregarTurnosCosecha(parcelas, fila, columna);
	actualizarSemillas(jugador, tipoSemilla,tipoA,tipoB,tipoC );


}




////////////////////////////////////////////////////////////////
int menu(){
    int opcion;
	cout<<"1- Sembrar parcela: "<<endl;
	cout<<"2- Regar parcela: "<<endl;
	cout<<"3- Cosechar Parcela: "<<endl;
	cout<<"4- Comprar Semillas: "<<endl;
	cout<<"5- Mostrar Tablero: "<<endl;
	cout<<"6- Pasar turno(no se puede revertir): "<<endl;
	cout<<"7-Salir del juego..."<<endl;
	cout<<"Seleccione una opcion: "<<endl;
	cin>>opcion;
	//cout<<"_____________________________________"<<endl;

	if (opcion>7){
		opcion=0;
		cout<<"Ingreso una opcion Incorrecta...\n";
		cout<<"\n";
	}
    return opcion;
}
