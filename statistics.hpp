#pragma once

#include <limits>
#include <vector>

namespace statistics{

class IStatistics {
public:
	virtual ~IStatistics();

	virtual void update(double next) = 0;

	virtual double eval() const = 0;

	virtual const char *name() const = 0;
};

class Min final : public IStatistics {
public:
	Min();

	void update(double next) override;

	double eval() const override;

	const char *name() const override;

private:
	double min_;
};


class Max final : public IStatistics {
public:
	Max();

	void update(double next) override;

	double eval() const override;

	const char *name() const override;

private:
	double max_;
};

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