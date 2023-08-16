#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#include "statistics.hpp"

namespace statistics{

	// -------------------- IStatistics --------------------
	IStatistics::~IStatistics() {};


	// -------------------- Min --------------------
	Min::Min() : min_{std::numeric_limits<double>::max()} {
	}

	void Min::update(double next) {
		if (next < min_) {
			min_ = next;
		}
	}

	double Min::eval() const {
		return min_;
	}

	const char * Min::name() const {
		return "min";
	}


	// -------------------- Max --------------------
	Max::Max() : max_{std::numeric_limits<double>::lowest()} {
	}

	void Max::update(double next) {
		if (next > max_) {
			max_ = next;
		}
	}

	double Max::eval() const {
		return max_;
	}

	const char * Max::name() const {
		return "max";
	}


    // -------------------- Mean --------------------
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


	// -------------------- Std --------------------
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


	// -------------------- Pct --------------------
	Pct::Pct(int p) : pct_percent_{p} {
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
		pct_name_ = "pct" + (std::to_string(pct_percent_));
		return pct_name_.data();
	}

} // end statistics