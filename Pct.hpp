#pragma once

#include "IStatistics.hpp"

#include <string>
#include <vector>

namespace statistics{

    class Pct final : public IStatistics {
    public:
        Pct(int p);

        void update(double next) override;

        double eval() const override;

        const char *name() const override;

    private:
        int pct_percent_ = 0;
        mutable std::vector<double> elements_;
        mutable std::string pct_name_ = "";
    };

} // end statistics