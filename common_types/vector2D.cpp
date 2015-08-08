#include "headers/typedef.h"

namespace rover{

	// polar_vec_t implementation ###############

	polar_vec_t& polar_vec_t::operator+(polar_vec_t &v){
		this->r += v.r;
		this->a += v.a;
		return *this;
	}
    polar_vec_t& polar_vec_t::operator+(float e){
		this->r += e;
		this->a += e;
		return *this;
	}
    polar_vec_t& polar_vec_t::operator-(polar_vec_t &v){
		this->r -= v.r;
		this->a -= v.a;
		return *this;
	}
    polar_vec_t& polar_vec_t::operator-(float e){
		this->r -= e;
		this->a -= e;
		return *this;
	}
    polar_vec_t& polar_vec_t::operator*(float e){
    	this->r *= e;
		this->a *= e;
		return *this;
    }
    polar_vec_t& polar_vec_t::operator/(float e){
    	this->r /= e;
		this->a /= e;
		return *this;
	}
	polar_vec_t& polar_vec_t::operator+=(polar_vec_t &v){
		this->r += v.r;
		this->a += v.a;
		return *this;
	}
    polar_vec_t& polar_vec_t::operator+=(float e){
		this->r += e;
		this->a += e;
		return *this;
	}
    polar_vec_t& polar_vec_t::operator-=(polar_vec_t &v){
		this->r -= v.r;
		this->a -= v.a;
		return *this;
	}
    polar_vec_t& polar_vec_t::operator-=(float e){
		this->r -= e;
		this->a -= e;
		return *this;
	}
	polar_vec_t& polar_vec_t::operator*=(float e){
		this->r *= e;
		this->a *= e;
		return *this;
	}
	polar_vec_t& polar_vec_t::operator/=(float e){
		this->r /= e;
		this->a /= e;
		return *this;
	}

	// vector_state implementation ##############

	vector_state::vector_state():
		pos({0.0,0.0}),
		spd({0.0,0.0}),
		acc({0.0,0.0}){}

	vector_state& vector_state::operator+(vector_state &vs){
		this->pos += vs.pos;
		this->spd += vs.spd;
		this->acc += vs.acc;
		return *this;
	}
	vector_state& vector_state::operator+(polar_vec_t &v){
		this->pos += v;
		this->spd += v;
		this->acc += v;
		return *this;
	}
    vector_state& vector_state::operator+(float e){
    	this->pos += e;
		this->spd += e;
		this->acc += e;
		return *this;
    }
    vector_state& vector_state::operator-(vector_state &vs){
    	this->pos -= vs.pos;
		this->spd -= vs.spd;
		this->acc -= vs.acc;
		return *this;
    }
    vector_state& vector_state::operator-(polar_vec_t &v){
    	this->pos -= v;
		this->spd -= v;
		this->acc -= v;
		return *this;
    }
    vector_state& vector_state::operator-(float e){
    	this->pos -= e;
		this->spd -= e;
		this->acc -= e;
		return *this;
    }
    vector_state& vector_state::operator*(float e){
    	this->pos *= e;
		this->spd *= e;
		this->acc *= e;
		return *this;
    }
    vector_state& vector_state::operator/(float e){
    	this->pos /= e;
		this->spd /= e;
		this->acc /= e;
		return *this;
    }

    vector_state& vector_state::operator+=(vector_state &vs){
		this->pos += vs.pos;
		this->spd += vs.spd;
		this->acc += vs.acc;
		return *this;
	}
	vector_state& vector_state::operator+=(polar_vec_t &v){
		this->pos += v;
		this->spd += v;
		this->acc += v;
		return *this;
	}
    vector_state& vector_state::operator+=(float e){
    	this->pos += e;
		this->spd += e;
		this->acc += e;
		return *this;
    }
    vector_state& vector_state::operator-=(vector_state &vs){
    	this->pos -= vs.pos;
		this->spd -= vs.spd;
		this->acc -= vs.acc;
		return *this;
    }
    vector_state& vector_state::operator-=(polar_vec_t &v){
    	this->pos -= v;
		this->spd -= v;
		this->acc -= v;
		return *this;
    }
    vector_state& vector_state::operator-=(float e){
    	this->pos -= e;
		this->spd -= e;
		this->acc -= e;
		return *this;
    }
    vector_state& vector_state::operator*=(float e){
    	this->pos *= e;
		this->spd *= e;
		this->acc *= e;
		return *this;
    }
    vector_state& vector_state::operator/=(float e){
    	this->pos /= e;
		this->spd /= e;
		this->acc /= e;
		return *this;
    }

}
