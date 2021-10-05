//Articulo.cpp lprobando

#include"Articulo.hpp"

using namespace std;

ostream& operator<<(const ostream& o, const Articulo& articulo)
{
	o << "[" << articulo.codigo() << "] \"" << articulo.titulo() << "\", " << articulo.f_publi().anno() << ". " << art.precio() << "€" ;
}


