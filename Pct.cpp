#include "Pct.hpp"

#include <algorithm>
#include <iostream>

namespace statistics{

    Pct::Pct(int p)
     : pct_percent_{p},
     pct_name_{"pct" + std::to_string(pct_percent_)} {

	}

	void Pct::update(double next) {
		elements_.push_back(next);
	}

	double Pct::eval() const {
        int index = (int)ceil(pct_percent_ * elements_.size() / 100);
		std::nth_element(elements_.begin(), 
		elements_.begin() + index, 
		elements_.end());
		return elements_[index];
	}

	const char * Pct::name() const {
		return pct_name_.c_str();
	}
    
} // end statistics