#include <iostream>

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX 100

class BigInt
{
public:
	BigInt();
	BigInt(int a);
	BigInt operator+() const;
	BigInt operator-() const;
	BigInt operator+(const BigInt& a) const;
	BigInt operator-(const BigInt& a) const;
	BigInt& operator+=(const BigInt& a);
	BigInt& operator-=(const BigInt& a);
	bool operator<(const BigInt a) const;
	bool operator<=(const BigInt a) const;
	bool operator>(const BigInt a) const;
	bool operator>=(const BigInt a) const;
	bool operator==(const BigInt a) const;
private:
	int count;
	unsigned data[MAX];
};

BigInt::BigInt() :count(0) {}

BigInt::BigInt(int a)
{
	count = a >= 0 ? 1 : -1;
	data[0] = a;
}

BigInt BigInt::operator+() const
{
	return *this;
}

BigInt BigInt::operator-() const
{
	BigInt temp = *this;
	temp.count *= -1;
	return temp;
}

BigInt BigInt::operator+(const BigInt& a) const
{
	if (a.count < 0) return operator-(-a);
	if (count < 0) return a.operator-(-*this);
	unsigned maxcount = (ABS(a.count) > ABS(count) ? ABS(a.count) : ABS(count)), carrying = 0;
	BigInt res;
	res.count = maxcount;
	for (int i = 0; i < maxcount; i++)
	{
		res.data[i] = a.data[i] + data[i] + carrying;
		if (res.data[i] <= data[i] && res.data[i] <= a.data[i]) carrying = 1;
		else carrying = 0;
	}
	if (carrying && maxcount < MAX)
	{
		res.count++;
		res.data[maxcount] = 1;
	}
	return res;
}

BigInt BigInt::operator-(const BigInt& a) const
{
	if (a.count < 0) return operator+(-a);
	if (count < 0) return -a.operator+(-*this);
	if (*this < a) return -a.operator-(*this);
	int carrying = 0;
	BigInt res;
	for (int i = 0; i < count; i++)
	{
		res.data[i] = data[i] - a.data[i] - carrying;
		if (res.data[i] >= data[i] && res.data[i] >= a.data[i]) carrying = 1;
		else carrying = 0;
	}
	for (int j = count; j > 0; j--)
	{
		if (res.data[j - 1] != 0)
		{
			res.count = j;
			break;
		}
	}
	return res;
}

BigInt& BigInt::operator+=(const BigInt& a)
{
	*this = *this + a;
	return *this;
}

BigInt& BigInt::operator-=(const BigInt& a)
{
	*this = *this - a;
	return *this;
}

bool BigInt::operator<(const BigInt a) const
{
	if (count < a.count) return true;
	if (count > 0)
	{
		for (int i = count - 1; i >= 0; i--)
		{
			if (data[i] > a.data[i]) return false;
			if (data[i] < a.data[i]) return true;
		}
		return false;
	}
	if (count < 0)
	{
		for (int i = -count - 1; i >= 0; i--)
		{
			if (data[i] > a.data[i]) return true;
			if (data[i] < a.data[i]) return false;
		}
		return false;
	}
	return false;
}

bool BigInt::operator<=(const BigInt a) const
{
	if (count < a.count) return true;
	if (count > 0)
	{
		for (int i = count - 1; i >= 0; i--)
		{
			if (data[i] > a.data[i]) return false;
			if (data[i] < a.data[i]) return true;
		}
		return true;
	}
	if (count < 0)
	{
		for (int i = -count - 1; i >= 0; i--)
		{
			if (data[i] > a.data[i]) return true;
			if (data[i] < a.data[i]) return false;
		}
		return true;
	}
	return true;
}

bool BigInt::operator>(const BigInt a) const
{
	if (count > a.count) return true;
	if (count > 0)
	{
		for (int i = count - 1; i >= 0; i--)
		{
			if (data[i] > a.data[i]) return true;
			if (data[i] < a.data[i]) return false;
		}
		return false;
	}
	if (count < 0)
	{
		for (int i = -count - 1; i >= 0; i--)
		{
			if (data[i] > a.data[i]) return false;
			if (data[i] < a.data[i]) return true;
		}
		return false;
	}
	return false;
}

bool BigInt::operator>=(const BigInt a) const
{
	if (count > a.count) return true;
	if (count > 0)
	{
		for (int i = count - 1; i >= 0; i--)
		{
			if (data[i] > a.data[i]) return true;
			if (data[i] < a.data[i]) return false;
		}
		return true;
	}
	if (count < 0)
	{
		for (int i = -count - 1; i >= 0; i--)
		{
			if (data[i] > a.data[i]) return false;
			if (data[i] < a.data[i]) return true;
		}
		return true;
	}
	return true;
}

bool BigInt::operator==(const BigInt a) const
{
	if (count != a.count) return false;
	for (int i = ABS(count) - 1; i >= 0; i--)
		if (data[i] != a.data[i]) return false;
	return true;
}

std::ostream& operator<<(std::ostream& out, const BigInt a)
{

}

int main()
{
	BigInt a;
	return 0;
}
