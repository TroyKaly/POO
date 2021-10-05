#include"tarjeta.hpp"

bool luhn(const Cadena& num);


//<<<<<<Class Numero>>>>>>

Numero::Numero(const Cadena& numero_)://Pendiente
{
	//Comprobamos si la cadena sin los espacios tiene la longitud correcta
	if(elimina_espacios(numero_).length() < 13 || elimina_espacios(numero_).lenght() >19)
		throw Incorrecto(Razon::LONGITUD);

	//Comprobamos que todos los elementos son digitos
	if()
		throw  Incorrecto(Razon::DIGITOS):

	// Comprobamos el algoritmo de luhn
	if(!luhn(elimina_espacios(numero_)))
		throw Incorrecto(Razon::NO_VALIDO);

	//Si cumple todo lo anterior y no se lanza ningun error el atributo se iguala al valor de numero_
	numero = numero_;





}

Numero::Cadena elimina_espacios(Cadena& nospace)
{
/*

BUSCAR ALGORITMO
	std::remove(nospce.begin(), nospace.end(), ' '); //eliminamos los espacios de la cadena

	return nospace;
*/
}

Numero::operator const char*() const // Operador de conversion a cadena de bajo nivel
{

	return num.c_str();

}

bool operator<(const Numero& num1, const Numero& num2)
{
	return strcmp(num1, num2) < 0;

}

//<<<Class Tarjeta>>>

//Constructor
Tarjeta::Tarjeta(const Numero &num_t_, const Usuario& user_, const Fecha& f_cad_):num_t(num_t_), user(user_), f_cad(f_cad_)
{
	//Comprobamos si la Fecha actual es mayor que la fecha de la caducidad de la tarjeta a crear
	if(f_cad_ < Fecha())
		throw Caducada(f_cad_);

	//Inicializamos el atributo tipo de la tarjeta 
	tipo = Tipo::Otro; //En caso que no cumpla las condiciones sera de tipo Otro
		

} 