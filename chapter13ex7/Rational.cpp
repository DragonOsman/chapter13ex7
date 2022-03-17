module rational;

import <ostream>;
import <numeric>;

int gcd(int a, int b)
{
	for (;;)
	{
		if (a == 0)
		{
			return b;
		}
		b %= a;
		if (b == 0)
		{
			return a;
		}
		a %= b;
	}
}

int lcm(int a, int b)
{
	int temp{ gcd(a, b) };
	return temp ? (a / temp * b) : 0;
}

void Rational::reduce()
{
	m_numerator /= gcd(m_numerator, m_denominator);
	m_denominator /= gcd(m_numerator, m_denominator);
}

Rational Rational::operator-() const
{
	Rational copy{ *this };
	copy.m_numerator = -copy.m_numerator;
	copy.m_denominator = -copy.m_denominator;
	return copy;
}

Rational Rational::operator+(const Rational& rational) const
{
	Rational copy{ *this };
	copy += rational;
	return copy;
}

Rational Rational::operator-(const Rational& rational) const
{
	Rational copy{ *this };
	copy -= rational;
	return copy;
}

Rational Rational::operator*(const Rational& rational) const
{
	Rational copy{ *this };
	copy *= rational;
	return copy;
}

Rational Rational::operator/(const Rational& rational) const
{
	Rational copy{ *this };
	copy /= rational;
	return copy;
}

Rational Rational::operator+(const int other_value) const
{
	Rational copy{ *this };
	copy += other_value;
	return copy;
}

Rational Rational::operator-(const int other_value) const
{
	Rational copy{ *this };
	copy -= other_value;
	return copy;
}

Rational Rational::operator*(const int other_value) const
{
	Rational copy{ *this };
	copy *= other_value;
	return copy;
}

Rational Rational::operator/(const int other_value) const
{
	Rational copy{ *this };
	copy /= other_value;
	return copy;
}

Rational Rational::operator+=(const Rational& rational)
{
	if (m_denominator == rational.m_denominator)
	{
		m_numerator += rational.m_numerator;
		return *this;
	}

	int lcm_val{ lcm(m_numerator, rational.m_numerator) };
	
	m_numerator *= lcm_val;
	m_denominator *= lcm_val;
	Rational copy{ rational };
	copy.m_numerator *= lcm_val;
	copy.m_denominator *= lcm_val;

	m_numerator += copy.m_numerator;
	reduce();
	return *this;
}

Rational Rational::operator-=(const Rational& rational)
{
	(*this) += (-rational);
	reduce();
	return *this;
}

Rational Rational::operator*=(const Rational& rational)
{
	m_numerator *= rational.m_numerator;
	m_denominator *= rational.m_denominator;
	reduce();
	return *this;
}

Rational Rational::operator/=(const Rational& rational)
{
	Rational copy{ rational };
	copy.m_numerator = copy.m_denominator;
	copy.m_denominator = copy.m_numerator;
	(*this) *= copy;
	reduce();
	return *this;
}

Rational Rational::operator+=(const int other_value)
{
	Rational rational{ other_value, 1 };
	(*this) += rational;
	reduce();
	return *this;
}

Rational Rational::operator-=(const int other_value)
{
	(*this) += (-other_value);
	reduce();
	return *this;
}

Rational Rational::operator*=(const int other_value)
{
	m_numerator *= other_value;
	m_denominator *= other_value;
	reduce();
	return *this;
}

Rational Rational::operator/=(const int other_value)
{
	Rational rational{ other_value, 1 };
	rational.m_numerator = rational.m_denominator;
	rational.m_denominator = rational.m_numerator;
	(*this) *= rational;
	reduce();
	return *this;
}

Rational Rational::operator++()
{
	(*this) += 1;
	reduce();
	return *this;
}

Rational Rational::operator++(int)
{
	Rational copy{ *this };
	++(*this);
	reduce();
	return copy;
}

Rational Rational::operator--()
{
	(*this) -= 1;
	reduce();
	return *this;
}

Rational Rational::operator--(int)
{
	Rational copy{ *this };
	--(*this);
	reduce();
	return copy;
}

std::ostream& operator<<(std::ostream& stream, const Rational& rational)
{
	stream << rational.get_numerator() << '/' << rational.get_denominator();
	return stream;
}