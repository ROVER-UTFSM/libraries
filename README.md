Rover
======

Introducción
-------------

Rover es un proyecto estudiantil de la UTFSM. Se concentra en el armado, diseño y desarrollo de plataformas robóticas
autónomas y controladas remotamente.

Objetivo
----------

Generar librería estática con lo necesario para describir una nueva plataforma.


Objetivos corto plazo
----------------------

- Reimplementar plataformas desarrolladas con una arquitectura única para todas y documentada.
- Implementar sensores y actuadores (drivers y controladores(controllers)).
- Mediante sólo la descripción de una plataforma, o sea, al indicar que sensores, actuadores, controladores y
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



Descripciones
---------------------
---------------------

	- joystick produce un vector de velocidad polar normalizado enter -1 y 1
	- arduino.h: comunicacion entre fitpc y arduino
	- hbridge: define la señal que debera crear la arduino mas adelante
	- chassis.h: recibe vector polar de velocidad y calcula la velocidad especifica para cada rueda.
	- rover.h: agrupa todas las clases y adapta la cantidad de ruedas a cantidad de puentes H.
	- implementacion main: agregar elementos por medio un vector(arreglo) y tener la incializacion de los objetos en un archivo aparte (XML?) 


TODO
-----
-----

	- Makefiles
	- Documentación con objetivos corto plazo y presupuestos de *.cpp
