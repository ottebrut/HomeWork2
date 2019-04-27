#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <string>
#include <vector>

#define uint64 unsigned long long
#define uint32 unsigned int

class big_integer {
public:
	big_integer();
	big_integer(big_integer const& obj);
	big_integer(int n);
	explicit big_integer(std::string const& s);
	~big_integer();

	big_integer& operator=(big_integer const& other);

	big_integer& operator+=(big_integer const& rhs);
	big_integer& operator-=(big_integer const& rhs);
	big_integer& operator*=(big_integer const& rhs);
	big_integer& operator/=(big_integer const& rhs);
	big_integer& operator%=(big_integer const& rhs);

	big_integer& operator&=(big_integer const& rhs);
	big_integer& operator|=(big_integer const& rhs);
	big_integer& operator^=(big_integer const& rhs);

	big_integer& operator<<=(int rhs);
	big_integer& operator>>=(int rhs);

	big_integer operator+() const;
	big_integer operator-() const;
	big_integer operator~() const;

	big_integer& operator++();
	big_integer operator++(int);

	big_integer& operator--();
	big_integer operator--(int);

	friend bool operator==(big_integer const& a, big_integer const& b);
	friend bool operator!=(big_integer const& a, big_integer const& b);
	friend bool operator<(big_integer const& a, big_integer const& b);
	friend bool operator>(big_integer const& a, big_integer const& b);
	friend bool operator<=(big_integer const& a, big_integer const& b);
	friend bool operator>=(big_integer const& a, big_integer const& b);

	friend std::string to_string(big_integer const& a);	
private:
	std::vector<uint32> number;
	bool sign;
	big_integer(std::vector <uint32> const& obj, bool sign);
	void check_sign();
		
	void swap(big_integer &a);
	friend int compare(const std::vector<uint32> &a, const std::vector<uint32> &b);
	friend int compare(big_integer const& a, big_integer const& b, bool abs);
	friend bool compare_equal_vector(const std::vector<uint32> &a, const std::vector<uint32> &b);
	void subtract_equal_vector(std::vector<unsigned int> &a, const std::vector<unsigned int> &b);

	void add(std::vector<uint32> &res, std::vector<uint32> const &a, std::vector<uint32> const &b);
	void subtract(std::vector<uint32> &res, std::vector<uint32> const &a, std::vector<uint32> const &b);
	void multiply(std::vector<uint32> &res, std::vector<uint32> const &a, std::vector<uint32> const &b);
	void divide(std::vector<uint32> &res, std::vector<uint32> const &a, std::vector<uint32> const &b);   

	void long_mul_short(std::vector<uint32> &res, std::vector<uint32> const &a, const unsigned int b);

	void long_and(std::vector<uint32> &res, std::vector<uint32> const &a, std::vector<uint32> const &b);
	void long_or(std::vector<uint32> &res, std::vector<uint32> const &a, std::vector<uint32> const &b);
	void long_xor(std::vector<uint32> &res, std::vector<uint32> const &a, std::vector<uint32> const &b);
	void long_not(std::vector<uint32> &res, std::vector<uint32> const &a);
	void right_shift(std::vector<uint32> &res, std::vector<uint32> const &a, const int b);
	void left_shift(std::vector<uint32> &res, std::vector<uint32> const &a, const int b);

	std::vector<unsigned int> big_integer_to_byte_vector(big_integer const &a);
	big_integer byte_vector_to_big_integer(std::vector<uint32> const &a);
};

big_integer operator+(big_integer a, big_integer const& b);
big_integer operator-(big_integer a, big_integer const& b);
big_integer operator*(big_integer a, big_integer const& b);
big_integer operator/(big_integer a, big_integer const& b);
big_integer operator%(big_integer a, big_integer const& b);

big_integer operator&(big_integer a, big_integer const& b);
big_integer operator|(big_integer a, big_integer const& b);
big_integer operator^(big_integer a, big_integer const& b);

big_integer operator<<(big_integer a, int b);
big_integer operator>>(big_integer a, int b);

bool operator==(big_integer const& a, big_integer const& b);
bool operator!=(big_integer const& a, big_integer const& b);
bool operator<(big_integer const& a, big_integer const& b);
bool operator>(big_integer const& a, big_integer const& b);
bool operator<=(big_integer const& a, big_integer const& b);
bool operator>=(big_integer const& a, big_integer const& b);

template<typename T>
void clear_end(std::vector<T> &a);
template<typename T>
uint64 mod_division(std::vector<T> &a, uint64 module_base, uint64 input_base);

#endif
