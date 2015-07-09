#ifndef __TYPEDEF_H_
#define __TYPEDEF_H_


namespace rover{

    // Enum types ###############################

    /**
     * Enumeración de los comandos aceptados
     */
    typedef enum {
        EXIT_COMMAND, VEL_R_COMMAND, VEL_A_COMMAND
    } command_type_t;



    // Struct types #############################

    /**
     * Descripción de punto coordenadas polares.
     */
    struct polar_vec_t{
        float r;
        float a;
    };

    /**
     * Descripción de punto coordenadas cartesianas.
     */
    struct carte_vec_t{
        float x;
        float y;
    };


    /**
     * Comando universal. Su valor 'value' debe trabajarse normalizado en [-1.0, 1.0].
     */
    struct command_t{
        command_type_t  type;
        float           value;
    };


    // Class types ############################

    /**
     * Uses the Command pattern to generate from each input equivalences to the Rover's instructions.
     */
    class command{

    public:
        command(){}
        virtual ~command(){}

        virtual bool get_command(command_t &c) = 0;     // False for no or incorrect command. True otherwise.
    };
    
    /**
     * Agrupa 3 estados: posición, velocidad y aceleración (vectores polares). Sobreescribe los operadores para operar intuitivamente con
     * otros 'vector2D'.
     */
    class vector2D{
    private:
        polar_vec_t pos;
        polar_vec_t spd;
        polar_vec_t acc;

    public:
        vector2D();
        ~vector2D(){}

        polar_vec_t get_pos();
        polar_vec_t get_spd();
        polar_vec_t get_acc();

        polar_vec_t operator+(polar_vec_t);
        polar_vec_t operator+(float);
        polar_vec_t operator-(polar_vec_t);
        polar_vec_t operator-(float);
        polar_vec_t operator*(float);
        polar_vec_t operator/(float);

    };
}


#endif // __TYPEDEF_H_