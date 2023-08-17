#pragma once

#include "IStatistics.hpp"

namespace statistics{

    class Max final : public IStatistics {
    public:
        Max();

        void update(double next) override;

        double eval() const override;

        const char *name() const override;

    private:
        double max_;
    };
    
} // end statistics