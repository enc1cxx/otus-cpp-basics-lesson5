#pragma once

#include "IStatistics.hpp"

namespace statistics{

	class Min final : public IStatistics {
	public:
		Min();

		void update(double next) override;

		double eval() const override;

		const char *name() const override;

	private:
		double min_;
	};

} // end statistics