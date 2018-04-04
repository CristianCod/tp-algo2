//============================================================================
// Name        : tpentregar.cpp
// Author      : Cristian Alarcon
// Version     : 1.2
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "funcionesJuego.h"
using namespace std;


int main() {
	Parcela **parcelas;
    parcelas=new Parcela *[4];
    estadoJugador *jugador=new estadoJugador;
    semillas *tipoA=new semillas;
    semillas *tipoB=new semillas;
    semillas *tipoC=new semillas;
/////////////////////////////////////////
    valoresIniciales(jugador, tipoA,tipoB
        		,tipoC);
    crearTablero(parcelas);
/////////////////////////////////////////
	tirarDados(jugador);

	bool comenzar=true;
while(comenzar){
	mostrarTablero(parcelas, jugador);
	int *posicionParcela= new int [1];
	int opcion=menu();


	switch(opcion){

	case 1:
	{	//sembrar
		elegirParcela(posicionParcela);
		int fila=(*(posicionParcela));
		int columna=(*(posicionParcela+1));
		mostrarInfoSemillas(tipoA, tipoB,tipoC);
		char tipoSemilla=elegirSemilla();
		bool haySemillas=verificoCantSemillas(tipoSemilla, jugador);
		bool noSecayVacia=verificarParcelaSecaVacia(fila, columna, parcelas);
		if((haySemillas) &&(noSecayVacia)){
			rutinaSembrar(fila,columna, jugador,parcelas,tipoA,tipoB, tipoC,tipoSemilla);
			comenzar=true;

			/*cambiarEstadoParcela(fila, columna, parcelas, tipoSemilla);
			agregarDatosParcela(parcelas, fila, columna, tipoSemilla);
			agregarTurnosCosecha(parcelas, fila, columna);
			actualizarSemillas(jugador, tipoSemilla,tipoA,tipoB,tipoC );*/
		}
		else{delete[] posicionParcela;
        opcion=menu();
		comenzar=true;
		}
		delete[] posicionParcela;
		comenzar=true;

        //opcion=menu();

	}break;

	case 2:
	{	//Regar
		elegirParcela(posicionParcela);
		int fila=(*(posicionParcela));
		int columna=(*(posicionParcela+1));
		bool estaSembrada= verificoSiembra(parcelas, fila, columna);
		if(estaSembrada){
			((*jugador).unidadesDeRiego)-=1;
			((*(*(parcelas+fila)+columna)).regada)=true;
			cout<<"Se rego la parcela correctamente"<<endl;
		}
		else{ delete[] posicionParcela;
        opcion=menu();
		comenzar=true;
		}
        //opcion=menu();
		delete[] posicionParcela;
		comenzar=true;

	}break;

	case 3:{
		//Cosechar
		elegirParcela(posicionParcela);
		int fila=(*(posicionParcela));
		int columna=(*(posicionParcela+1));
        bool cosecharNoPodrida= verificoCosechaParcela(parcelas, fila, columna);
        if (cosecharNoPodrida ){
        	rentabilidad(fila, columna, parcelas, tipoA,tipoB,tipoC, jugador);
        }
        else{delete[] posicionParcela;
        opcion=menu();}
        opcion=menu();
        delete[] posicionParcela;

	}break;

	case 4:
	{		//Comprar Semillas
		comprarSemillas(tipoA, tipoB, tipoC,jugador);
		comenzar=true;

		//opcion=menu();
	}break;

	case 5:
	{		//Mostrar Tablero
		mostrarTablero(parcelas, jugador);
        //opcion=menu();
		comenzar=true;

	}break;

	case 6:
	{
			//Pasar turno
		cout<<"Paso de turno.."<<endl;
		parcelasSinCambios(parcelas);
		agregarParcelaSeca(parcelas);
		verificarCosecha(parcelas,tipoA,tipoB,tipoC);
		contarTurnos(jugador);
		if((*jugador).turnosRestantes==0){
			cout<<"Termino el juego.\n"<<endl;
			//opcion=7;
			comenzar=false;

		}
		else{mostrarTablero(parcelas, jugador);
			comenzar=true;
		}
        //opcion=menu(); }
	}break;

	case 7:{
		//salir
		cout<<"Saliendo del programa..."<<endl;
		comenzar=false;

        //menu=false;
	}break;
	case 0:
	{cout<<"Opcion Incorrecta..."<<endl;
	comenzar=true;}break;
	}
	/*default:
	{	delete[] posicionParcela;
		mostrarTablero(parcelas, jugador);
		comenzar=true;
	}*/
		//opcion=menu();

	}//Fin switch

//}//Fin while
	//Borrado de memoria dinmica
borrarHeap(tipoA, tipoB,tipoC
				,jugador, parcelas);


	return 0;

}//Fin de la funcion main








