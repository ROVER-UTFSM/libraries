Rover
======

Introducción
-------------

Rover es un proyecto estudiantil de la UTFSM. Se concentra en el armado, diseño y desarrollo de plataformas robóticas
autónomas y controladas remotamente.

Objetivos corto plazo
----------------------

Reimplementar plataformas desarrolladas con una arquitectura única para todas y documentada.
Implementar sensores y actuadores (drivers y controladores(controllers)).
Mediante sólo la descripción de una plataforma, o sea, al indicar que sensores, actuadores, controladores y
comunicaciónes se utilizarán, obtener robótica funcional.


Bibliotecas desarrolladas
--------------------------

common_types
	Agrupa todos los tipos comunes a las bibliotecas Rover.

	Incluye:
			- command_list_t	: enumeración de los comandos aceptados
			- polar_vec_t		: coordenadas 2D polares
			- carte_vec_t		: coordenadas 2D cartesianas
			- command_t 		: identifica que comando es y su valor normalizado en el intervalo [-1.0,1.0]
			- command 			: clase virtual que describe funcionalidad mínima de un comando
			- vector_state		: estado de posición, velocidad y aceleración vectorial y sus operaciones

sensors
	joystick
		Genera 'command_t' a partir de la API joystick.h de linux.	(sólo linux)


miscellaneous
	Varias funciones multipropósito.

	Incluye:
		- wait(useconds)	(sólo linux)

