//usuario.cpp

#include"usuario.hpp"
#include<iostream>
#include<unistd.h>
#include<random>
#include<ctime>
#include<iomanip>

usign namespace std;

//<<<<<<Class Clave>>>>>>
Clave::Clave(const char* contrasena_)
{
	if(strlen(contrasena_) < 5)
		throw Incorrecta(Razon::CORTA);

	char const set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./" 
				//El argumeto *salt es un string escogido de este set
	
	//Solo los primeros dos caracteres del string generado (salt) se usaran para cifrar
	char *salt = new char[2]; 

	//Rellenamos salt con dos caracteres aleatorio del set de 64 caracteres
	salt[0] = set[rand() % 64];
	salt[1] = set[rand() % 64];

	if(crypt(contrasena_, salt) == nullptr )
		throw Incorrecta(Razon::ERROR_CRYPT);

	contrasena = crypt(contrasena_, salt);
} 

bool Clave::verifica(const char* v)
{
	return strcmp(crypt(v, contrasena.c_str()), contrasena.c_str()); 
	//Recordemos que c_str() es un operador de conversion de Cadena a un char*  de bajo nivel
}