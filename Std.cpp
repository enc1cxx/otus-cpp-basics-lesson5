#include "Std.hpp"

namespace statistics{
    
    Std::Std() : std_{0} {
	}

	void Std::update(double next) {
		mean_.update(next);
		elements_.push_back(next);
	}

	double Std::eval() const {
		for (double element: elements_) {
			std_ = std_ + (element - (mean_.eval())) * (element - (mean_.eval()));
		}
		return sqrt(std_ / (double) elements_.size());
	}

	const char * Std::name() const {
		return "std";
	}

} // end statistics