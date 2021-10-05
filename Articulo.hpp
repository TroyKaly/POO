//Articulo.hpp
#ifndef ARTICULO_HPP
#define ARTICULO_HPP

#include<iostream>
#include"Fecha.hpp"//COMPROBAR
#include"Cadena.hpp"


using namespace std;

class Articulo
{
public:

	// Constructor con stock valor 0 por defecto 
	Articulo(const Cadena& codigo_, const Cadena& titulo_, const Fecha& f_publi_, const double precio_, const unsigned stock_=0):
			codigo(codigo_), titulo(titulo_), f_publi(f_publi_), precio(precio_), stock(stock_);

	// Metodos observadores
	Cadena codigo() const;
	Cadena titulo() const;
	Fecha  f_publi() const;
	double precio() const;
	unsigned stock() const;

	// Sobrecarga de observadores con referencia al objeto para ser modificado(left value)
	double& precio();	//
	unsigned& stock();

private:
	Cadena codigo;
	Cadena titulo;
	Fecha f_publi;	//Fecha de publicacion
	double precio;
	unsigned stock; //No tiene signo (no puede haber stock negativo)
}

ostream& operator<<(ostream& os, const Articulo& articulo) noexcept;

inline Cadena Articulo::codigo() const {return codigo;}
inline Cadena Articulo::titulo() const {return  titulo;}
inline Fecha Articulo::f_publi() const {return f_publi;}
inline double Articulo::precio() const {return precio;}
inline unsigned Articulo::stock() const{return stock;} 

inline double& Articulo::precio() const{return precio;}
inline unsigned& Articulo:stock() const{return stock; }


#endif