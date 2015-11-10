Propuesta
----------

Se han usado los fitPC y rpi para implementar los programas principales (generación de comandos, comunicación, autómatas).
La idea es en un programa/clase realizar las configuraciones para la plataforma a construir (cargador, explorador, recolector, ...).
Esto implica que tal descripción necesite una mínima diferencia entre conectar el sensor a traves de GPIOs de la rpi o del arduino/(uC+placa) conectado al PC.

El diseño elegido en este branch es crear una clase Contructor_Plataformas(main()), clase Arduino, una clase GPIO y una clase XXX_sensor.


	-Arduino(una clase padré y herencias para cada modelo (cantidad de pines por ahora)) tendrá un constructor y métodos que implementen el protocolo. Require especificar sólo los pines de conexión. Si son varios, una vez leido todos se enviará la información.
	-GPIO tendrá un constructor y métodos para implementar la configuración de los pines. Pedirá número de pines y si son IN o OUT. Método para leer de X sensor y para que Y sensor actue.
	-Tanto para GPIO como para Arduino se puede ir avanzando en autamitación de lecturas y escrituras según frecuencias (ampliando las congifuraciones), etc..
	-XXX_sensor debe implementar AMBAS clases, para que funcione en cualquier caso.
	-XXX_sensor debe de convertir cualquier valor que devuelva a SI.
	-En cualquiera de los casos el constructore debe ser minimalista. Cualquier parametro opcional al funcionamiento debe ser seteablo por el método (función en una clase, OO) correspondiente.

Tanto Arduino como GPIO se desarrollarían en communications. Esto significa que para cualquier otro método de comunación, sólo en el caso que se envie información de un sensor "crudamente" (sin procesamiento previo), éste sensor heredará la clase preocupada de manejar la comunicación.

La clase Contructor_Plataformas no es importante aquí.
