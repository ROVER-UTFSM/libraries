#ifndef __CHASSIS_H_
#define __CHASSIS_H_


namespace rover{

	struct control_state_t{

	};

	class Wheel{
	private:
		int ID;
		float radius;
		float power;
	public:
		wheel(int id, float r, float p): ID(id), radius(r), power(p){}

		float operator=(float p){
			power = p;
		}
	};

	class Chassis{
	private:
		std::vector<Wheel> wheels;

	public:
		Chassis(){}
		virtual ~Chassis();

		virtual update(control_vec_t) =0;
	};

}

#endif // __CHASSIS_H_