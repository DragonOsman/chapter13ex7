export module rational;

import <ostream>;
import <compare>;
import <stdexcept>;

export class Rational
{
public:
	Rational(const int numerator = 0, const int denominator = 1)
		: m_numerator{ numerator }, m_denominator{ denominator } 
	{
		if (denominator <= 0)
		{
			throw std::runtime_error{ "denominator shouldn't be 0 or negative!" };
		}
		reduce();
	}

	void set_numerator(const int value) { m_numerator = value; }
	void set_denominator(const int value) 
	{ 
		if (value <= 0)
		{
			throw std::runtime_error{ "denominator shouldn't be 0 or negative!" };
		}
		m_denominator = value; 
	}

	int get_numerator() const { return m_numerator; }
	int get_denominator() const { return m_denominator; }

	double get_rational_value() const { return m_numerator * 1.0 / m_denominator; }

	bool operator==(const Rational& rational) const = default;
	bool operator==(int other_value) const
	{
		return get_rational_value() == other_value;
	}
	std::partial_ordering operator<=>(const Rational& rational) const
	{
		return get_rational_value() <=> rational.get_rational_value();
	}
	std::partial_ordering operator<=>(int other_value) const
	{
		return get_rational_value() <=> other_value;
	}

	Rational operator+(const Rational& rational) const;
	Rational operator-(const Rational& rational) const;
	Rational operator*(const Rational& rational) const;
	Rational operator/(const Rational& rational) const;
	Rational operator+(int other_value) const;
	Rational operator-(int other_value) const;
	Rational operator*(int other_value) const;
	Rational operator/(int other_value) const;
	Rational operator+=(const Rational& rational);
	Rational operator-=(const Rational& rational);
	Rational operator*=(const Rational& rational);
	Rational operator/=(const Rational& rational);
	Rational operator+=(int other_value);
	Rational operator-=(int other_value);
	Rational operator*=(int other_value);
	Rational operator/=(int other_value);
	Rational operator++();
	Rational operator++(int);
	Rational operator--();
	Rational operator--(int);
	Rational operator-() const;
	operator double() const { return get_rational_value(); }

private:
	int m_numerator;
	int m_denominator;
	void reduce();
};

export std::ostream& operator<<(std::ostream& stream, const Rational& rational);