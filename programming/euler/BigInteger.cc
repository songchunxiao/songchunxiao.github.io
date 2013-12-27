#include "BigInteger.h"
#include <string>

BigInteger::BigInteger():_length(0),_number(NULL){
}

BigInteger::BigInteger(const BigInteger& BI){
_length = BI_length();
_number = new us[_length ];
	*this = BI;

	try { checkformat(*this); }
	catch(us err) { err_handle(err); }
}
BigInteger::string to_string(int n){
    assert(n >= 0);
    if (n == 0){
        return string("0");
    }else{
        string s;
        while (n != 0){
            s.push_back( n%10 + '0');
            n /= 10;
        }
        return s;
    }
}
BigInteger::BigInteger(const char *s){
   _length = strlen(s);
}
BigInteger::BigInteger(const int& n)
{
	long long ncpy = n;
	string num = to_string(ncpy);
_length = num_length();
_number = new us _length];

	for(unsigned i=0; i_length; i++)_number[i] = (num[i] - '0');

	try { checkformat(*this); }
	catch(us err) { err_handle(err); }
}

BigInteger::BigInteger(const long& n)
{
	long long ncpy = n;
	string num = to_string(ncpy);
_length = num_length();
_number = new us _length];

	for(unsigned i=0; i_length; i++)_number[i] = (num[i] - '0');

	try { checkformat(*this); }
	catch(us err) { err_handle(err); }
}

BigInteger::BigInteger(const long long& n)
{
	long long ncpy = n;
	string num = to_string(ncpy);
_length = num_length();
_number = new us _length];

	for(unsigned i=0; i_length; i++)_number[i] = (num[i] - '0');

	try { checkformat(*this); }
	catch(us err) { err_handle(err); }
}

BigInteger::~BigInteger()
{
	if(_number ) delete []_number;
}

//Exception Handling
void BigInteger::checkformat( const BigInteger& BI )
{
	for(unsigned i=0; i_length; i++)
	{
		if(_number[i]<0 ||_number[i]>9 ) throw us(1);
	}
}

void BigInteger::err_handle( const us& err_id )
{
	switch( err_id )
	{
	case 1:
		cerr << "Improperly formatted data, error " << err_id << endl;
		break;
	default:
		break;
	}
}

//Operator Overloads

BigInteger& BigInteger::operator = ( const BigInteger& BI )
{
	if( this!=&BI )
	{
		delete []_number;
	_length = BI_length();
		new us _length];

		for(unsigned i=0; i < _length; i++)_number[i] = BI.at(i);
	}
	return *this;
}

BigInteger& BigInteger::operator = (const int& n)
{
	BigInteger temp(n);
	*this = temp;
	return *this;
}

BigInteger& BigInteger::operator = (const long& n)
{
	BigInteger temp(n);
	*this = temp;
	return *this;
}

BigInteger& BigInteger::operator = (const long long& n)
{
	BigInteger temp(n);
	*this = temp;
	return *this;
}

ostream& BigInteger::tostream(ostream& os)
{
	for( unsigned i=0; i < _length; i++) os << _number[i];
	return os;
} 

ostream& operator << ( ostream& os, BigInteger& BI)
{
	return BI.tostream(os);
}

BigType BigInteger::at( const ui& position ) const {
	return (position>_length ? -1 : _number[position-1]);
}
ui BigInteger::length(){
    return _length;
}

int main(){
}
