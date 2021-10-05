#ifndef USUARIO_HPP
#define USUARIO_HPP
 
#include<iostream>
#include<map>

#include"articulo.hpp"
#include"tarjeta.hpp"

using namespace std;

//<<<<<<Class Clave>>>>>>
class Clave
{
public:
	Clave(const char* contrasena);	//Constructor
	inline const Cadena& clave() const{return contrasena};    //Observador devuelve clave cifrada
	bool verifica(const char* contrasena); //Devuelve v o f si la contrasena corresponde con la  almacenada

	//<<<<Class Incorrecta>>>>
	class Incorrecta
	{
	public:
		enum Razon{CORTA, ERROR_CRYPT};	//Tipo enumerado con la razon del error
		Incorrecta(const Razon error_):error(error);//Ctr. Incorrecta
		inline Razon razon() const{return error};//Observador que devuelve la razon del error
	private:
		Razon error;
	}
private:
	Cadena contrasena;	//Cadena que almacena la contrasena(cifrada)

}


//<<<<<<Class Usuario>>>>>>






















#endif