#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;

	virtual double eval() const = 0;

	virtual const char *name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : min_{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < min_) {
			min_ = next;
		}
	}

	double eval() const override {
		return min_;
	}

	const char *name() const override {
		return "min";
	}

private:
	double min_;
};


class Max : public IStatistics {
public:
	Max() : max_{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		if (next > max_) {
			max_ = next;
		}
	}

	double eval() const override {
		return max_;
	}

	const char *name() const override {
		return "max";
	}

private:
	double max_;
};

class Mean : public IStatistics {
public:
	Mean() : mean_{0} {
	}

	void update(double next) override {
		++count_;
		sum_ += next;
		mean_ = sum_ / count_;
	}

	double eval() const override {
		return mean_;
	}

	const char *name() const override {
		return "mean";
	}

private:
	double mean_;
	double sum_ = 0;
	int count_ = 0;
};

class Std : public IStatistics {
public:
	Std() : std_{0} {
	}

	void update(double next) override {
		mean_.update(next);
		elements_.push_back(next);
	}

	double eval() const override {
		for (double element: elements_) {
			std_ = std_ + (element - (mean_.eval())) * (element - (mean_.eval()));
		}
		return sqrt(std_ / (double) elements_.size());
	}

	const char *name() const override {
		return "std";
	}

private:
	mutable double std_;
	Mean mean_;
	std::vector<double> elements_;
};

class Pct : public IStatistics {
public:
	Pct(int p) : pct_percent_{p} {
	}

	void update(double next) override {
		elements_.push_back(next);
	}

	double eval() const override {
		if(!elements_.empty()){
			std::sort(elements_.begin(), elements_.end());
			int index = (int) ceil(pct_percent_ * elements_.size() / 100);
			pct_ = elements_[index];
		}
		return pct_;	
	}

	// тут у меня возникла проблема со сложением pct и pct_percent_, для вывода в функции main. Гугл
	// помог не сильно - в онлайн компиляторе код работает, а в этой программе - нет.
	// Выводит абракадабру
	// const char * foo(int pct_percent_) {
	// 	std::string str = "pct" + (std::to_string(pct_percent_));
	// 	return str.data();
	// }
	// Ну и вообще в корректности этого класса у меня большие сомнения - 
	// я не особо понял, что такое процентиль :)
	const char *name() const override {
		return "pct";
	}

private:
	int pct_percent_ = 0;
	mutable double pct_ = 0;
	mutable std::vector<double> elements_;
};