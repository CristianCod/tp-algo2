/*
 * funcionesJuego.h
 *
 *  Created on: 3 abr. 2018
 *      Author: cristian
 */

#ifndef FUNCIONESJUEGO_H_
#define FUNCIONESJUEGO_H_


struct estadoJugador{
	int creditos;
	int cantidadSemillasA;
	int cantidadSemillasB;
	int cantidadSemillasC;
	int unidadesDeRiego;
	int turnosRestantes;

};

struct Parcela{
	char estadoParcela;
	bool estaSembrada;
	char tipoSiembra;
	bool estaSeca;
	bool estaPodrida;
	bool cosechar;
	int recuperacion;
	int turnosCosecha;
	bool regada;

};

struct semillas{
	int precio;//Mostrar precio
	int cantidad;
	int turnosCosecha;
	char tipoCaracter;
	int rentabilidad;
	int turnosRecuperacion;
//Mostrar cantidad
};

char elegirSemilla();
bool verificoCantSemillas(char tipoSemilla, estadoJugador *jugador);
void cambiarEstadoParcela(int fila, int columna, Parcela **parcelas, char estadoNuevo);
void agregarDatosParcela(Parcela **parcelas, int fila, int columna, char tipoSemilla);
void agregarTurnosCosecha(Parcela **parcelas, int fila, int columna);

void actualizarSemillas(estadoJugador *jugador, char tipoSemilla, semillas *tipoA, semillas *tipoB, semillas *tipoC);
bool verificarParcelaSecaVacia(int fila, int columna, Parcela **parcelas);
bool verificoSiembra(Parcela **parcelas,int  fila, int columna);

bool verificoCosechaParcela(Parcela **parcelas,int fila, int columna);
void rentabilidad(int fila,int columna, Parcela **parcelas,semillas *tipoA,semillas *tipoB, semillas *tipoC,
		estadoJugador *jugador);
void comprarSemillas(semillas *tipoA,semillas *tipoB,semillas *tipoC,estadoJugador *jugador);


void rutinaSembrar(int fila, int columna, estadoJugador *jugador, Parcela **parcelas,
		semillas *tipoA, semillas *tipoB, semillas *tipoC, char semillaElegida);
void parcelasSinCambios(Parcela **parcelas);



void agregarParcelaSeca(Parcela **parcelas);
void buscoParcelas(Parcela **parcelas, int fila, int columna);
void recuperarParcelaSecAnterior(Parcela **parcelas,int fila, int columna);
void verificarCosecha(Parcela**parcelas, semillas *tipoA, semillas *tipoB, semillas *tipoC);
void recuperarParcelasCosechadas(Parcela **parcelas, int fila, int columna);
void quitarTurnoSiembra(Parcela **parcelas,int  fila,int  columna);
void verCosechaPerdida(Parcela **parcelas, int fila, int columna, semillas *tipoA, semillas *tipoB, semillas *tipoC);
void agregoRecuperacionInicial(Parcela **parcelas, int fila, int columna, semillas *tipoA, semillas *tipoB, semillas *tipoC);
void contarTurnos(estadoJugador *jugador);
void borrarHeap(semillas *semillaTipoA, semillas *semillaTipoB, semillas *semillaTipoC
		,estadoJugador *jugador, Parcela **parcelas);










char comprobarTipoSemilla(char semillaElegida);
void mostrarTablero(Parcela **parcelas, estadoJugador *jugador);
void tirarDados(estadoJugador *jugador);
void valoresIniciales(estadoJugador *jugador, semillas *semillaTipoA
		,semillas *semillaTipoB, semillas *semillaTipoC);
void crearTablero(Parcela **parcelas);
int menu();
void elegirParcela(int *posicionParcela);
void valoresIniciales(estadoJugador *jugador, semillas *semillaTipoA,semillas *semillaTipoB
		,semillas *semillaTipoC);
void mostrarInfoSemillas(semillas *semillaTipoA, semillas *semillaTipoB,semillas *semillaTipoC);






#endif /* FUNCIONESJUEGO_H_ */
