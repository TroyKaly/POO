//tarjeta.hpp
#ifndef TARJETA_HPP
#define TARJETA_HPP 
#include"cadena.hpp"
#include"fecha.hpp"
#include"usuario.hpp"
#include<iostream>


using namespace std;

//<<<<<<Class Numero>>>>>>
class Numero
{
public:
	Numero(const Cadena& numero_);	//Ctr
	operator const char*() const; // Operador de conversion a cadena de bajo nivel
	friend bool operator<(const Numero& num1, const Numero& num2); //Operador < para dos objetos Numero

	//<<<Class Incorrecto>>
	class Incorrecto
	{
	public:
		enum Razon{LONGITUD, DIGITOS, NO_VALIDO};
		Incorrecto(const Razon error_):error(error_){};
		inline Razon razon() const{return error};//Observador que devuelve la razon del error
	private:
		Razon error;

	}

private:
	Cadena numero;
	Cadena elimina_espacios(); //Elimina espacios de la cadena numero 
}
#endif

//<<<<<<Class Tarjeta>>>>>>

//Una Tarjeta solo se relaciona con un Usuario necesariamente

class Tarjeta
{
public:
	enum Tipo{Otro, VISA, Mastercard, Maestro, JCB, AmericanExpress}; //Tipo de tarjeta
	Tarjeta(const Numero& num_t_, const Usuario& user_,const Fecha& f_cad_):activa(true);
	Tarjeta(const Tarjeta& t) = delete;//Comprueba?
	//Observadores
	Numero numero() const;
	Usuario* titular() const;
	Fecha caducidad() const;
	bool activa()const;
	Tipo tipo() const;
	bool activa(bool estado = true);

	void anula_titular();
	~Tarjeta();

	//<<<Class Desactivada>>>
	class Desactivada
	{}

	//<<<Class Num_duplicado>>>
	 class Num_duplicado
    {
    public:
        Num_duplicado(const Numero& n_dupli_): n_dupli(n_dupli_){};
        const Numero que() const {return n_;};
    private:
        Numero n_dupli;
    };




private:
	Numero num_t;
	const Usuario* user; 
	Fecha f_cad;
	bool activa;
	Tipo tipo;
}

//Observadores
inline Numero numero() const {return num_t};
inline Usuario* titular() const {return usr};
inline Fecha caducidad() const {return f_cad};
inline bool activa() const {return activa};
inline Tipo tipo() const {return tipo};

//Operadores de flujo de salida
ostream& operator << (ostream& o, const Tarjeta::Tipo& tipo_) ;
ostream& operator << (ostream& o, const Tarjeta& tarjeta) ;
//Operador menor-que para ordenar tarjetas
bool operator< (const Tarjeta& t1, const Tarjeta& t2); //Con los observadores podemos acceder a los atributos privado no es necesario declararla amiga de la clase Tarjeta