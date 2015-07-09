#include "typedef.h"

namespace rover{

	vector_state::vector_state():
		pos.r(0.),
		pos.a(0.),
		spd.r(0.),
		spd.a(0.),
		acc.r(0.),
		acc.a(0.){}
	}

	vector_state& vector_state::operator+(vector_state &v){
		this->pos += v.pos;
		this->vel += v.vel;
		this->acc += v.acc;
		return this;
	}
	vector_state& vector_state::operator+(polar_vec_t &v){
		this->pos += v;
		this->vel += v;
		this->acc += v;
		return this;
	}
    vector_state& vector_state::operator+(float e){
    	this->pos += e;
		this->vel += e;
		this->acc += e;
		return this;
    }
    vector_state& vector_state::operator-(vector_state &v){
    	this->pos -= v.pos;
		this->vel -= v.vel;
		this->acc -= v.acc;
		return this;
    }
    vector_state& vector_state::operator-(polar_vec_t &v){
    	this->pos -= v;
		this->vel -= v;
		this->acc -= v;
		return this;
    }
    vector_state& vector_state::operator-(float e){
    	this->pos -= e;
		this->vel -= e;
		this->acc -= e;
		return this;
    }
    vector_state& vector_state::operator*(float e){
    	this->pos *= e;
		this->vel *= e;
		this->acc *= e;
		return this;
    }
    vector_state& vector_state::operator/(float e){
    	this->pos /= e;
		this->vel /= e;
		this->acc /= e;
		return this;
    }

}
