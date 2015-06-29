
namespace rover{

    struct polar_vec_t{
        float r;
        float a;
    };
    
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