#pragma once

#include "IStatistics.hpp"
#include "Mean.hpp"

#include <vector>

namespace statistics{

    class Std final : public IStatistics {
    public:
        Std();

        void update(double next) override;

        double eval() const override;

        const char *name() const override;

    private:
        mutable double std_;
        Mean mean_;
        std::vector<double> elements_;
    };
    
} // end statistics