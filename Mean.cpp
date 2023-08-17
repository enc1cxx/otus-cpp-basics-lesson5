#include "Mean.hpp"

namespace statistics{

    Mean::Mean(){
    }

    void Mean::update(double next) {
		++count_;
		sum_ += next;
	}

	double Mean::eval() const {
		return sum_ / count_;
	}

	const char * Mean::name() const {
		return "mean";
	}
	
} // end statistics