#pragma once

#include "IStatistics.hpp"

namespace statistics{

    class Mean final : public IStatistics {
    public:
        Mean();

        void update(double next) override;

        double eval() const override;

        const char *name() const override;

    private:    
        double sum_ = 0;
        int count_ = 0;
    };
    
} // end statistics