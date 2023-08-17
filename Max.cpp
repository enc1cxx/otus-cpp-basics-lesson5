#include "Max.hpp"

#include <limits>


namespace statistics{

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
    
} // end statistics