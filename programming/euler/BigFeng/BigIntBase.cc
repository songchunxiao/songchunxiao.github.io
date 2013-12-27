#include "../euler.h"
typedef unsigned char BigUnit;

/*
 * 1.Due to the following reasons, I created BigIntBase as the array type for BigInteger:
 *   A.vector has so many problems when used as class member, ex,
 *     when you use push_back(), When you call std::vector::push_back(), a copy 
 *     of the argument is made before adding it to the vector. 
 *   B.The expansion speed for BigInteger's array is very different from the default
 *     expansion speed of STL::vector, I need to control the expansion.
 *   C.The type for BigUnit is still changing, if I use bit instead of "usnsigned char",
 *     the implementation mechanism may very different, which is difficult to employ
 *     the funcionality of STL::vector.
 * 2.Representation of ingeter:
 *   A. If size==0, the value is 0.
 *   B. If size>0, the value is one positive integer.
 */

class BigIntBase{
private:
    const static ui defaultCapacity = 100;
    BigIntBase(bool forCapacity, ui _capacity){
        setCapacity(_capacity);
    }
    void setCapacity(ui length){
        if (length < defaultCapacity)
            data = new BigUnit[capacity=defaultCapacity];
        else 
            data = new BigUnit[capacity=length];
    }
public:
    ui size;
    ui capacity;
    BigUnit* data = NULL;
protected:
public:
    BigIntBase(): size(0){
        setCapacity();
    }
	BigIntBase(ui n){
        setCapacity();
        if (n == 0){
            data[0] = 0;
            size = 1;
        }else{
            size = 0;
            while(n != 0){
                data[size++] = n % 10;
                n /= 10;
            }
        }
    }
    /* 
     * The input char array can only contain "0-9", for example, 
     * (1) "987643"
     * (3) "00987643"
     * otherwise the result is not defined.
     */
    BigIntBase(char* numStr){
        size = strlen(numStr);
        setCapacity(size*2);
        for (ui i = 0; i < size; i++){
            data[i] = numStr[size-1-i] - '0';
        }
    }
    BigIntBase(const BigIntBase& rhs){
        //cout << "Operator copy has been called" << endl;
        assign(*this, rhs);
    }
    void setCapacity(){
        data = new BigUnit[capacity=defaultCapacity];
    }
    void expand(int newCapacity){
        BigUnit* newData = new BigUnit[newCapacity];
        BigUnit* temp = data;
        memcpy(newData, data, sizeof(BigUnit)*capacity);
        data = newData;
        capacity = newCapacity;
        free(temp);
    }
    void assign(BigIntBase& lhs, const BigIntBase& rhs){
        lhs.size = rhs.size;
        lhs.setCapacity(rhs.capacity);
        memcpy(lhs.data, rhs.data, sizeof(BigUnit) * lhs.capacity);
    }
    BigUnit& operator[](const ui idx) const{
        assert(idx < capacity);
        return data[idx];
    }
    void add(const BigIntBase &a, const BigIntBase &b){
        assert(a.size >= b.size);
        BigIntBase& c = *this;
        if (a.size == 0){
            operator = (b);
            return;
        } else if (b.size == 0) {
            operator = (a);
            return;
        }
        ui i;
        bool carry;
        BigUnit t;
        for (i = 0, carry = 0; i < b.size; i++){
            t = a[i] + b[i] + carry;
            if (t >= 10) carry = 1, t = t - 10;
            else carry = 0;
            c[i] = t;
        }
        for (; i < a.size && carry; i++){
            t = a[i] + 1;
            if (t == 10) carry = 1, t = 0;
            else carry = 0;
            c[i] = t;
        }
        for (; i < a.size; i++)
            c[i] = a[i];
        if (carry){
            c[i] = 1;
            size = a.size + 1;
        }else size = a.size;
    }
    BigIntBase& operator=(const BigIntBase& rhs) {
        assign(*this, rhs);
        return *this;
    }
    BigIntBase operator+(const BigIntBase& b) const{
        BigIntBase ret(true, max(b.capacity, this->capacity)+1);
        if (this->size > b.size)
            ret.add(*this, b);
        else 
            ret.add(b, *this);
        return ret;
    }
    string toStringInBase(ui base){
        if (base == 10){
            string s(size, ' ');
            for (ui i = 0; i < size; i++)
                s[i] = (*this)[size-1-i]+'0';
            return s;
        }else{
            cout << "base " << base << " hasn't been implemented";
            return NULL;
        }
    }
};
ostream& operator <<(ostream &os, BigIntBase& n) {
    os << n.toStringInBase(10);
    return os;
}
