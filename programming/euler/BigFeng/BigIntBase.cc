#include "BigIntBase.h"

BigIntBase::BigIntBase(bool forCapacity, ui _capacity){
    setCapacity(_capacity);
}
BigIntBase::BigIntBase(): size(0){
    setCapacity();
}
BigIntBase::BigIntBase(ui n){
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
BigIntBase::BigIntBase(const char* numStr){
    size = strlen(numStr);
    setCapacity(size*2);
    for (ui i = 0; i < size; i++){
        data[i] = numStr[size-1-i] - '0';
    }
}
BigIntBase::BigIntBase(const BigIntBase& rhs){
    //cout << "Operator copy has been called" << endl;
    assign(*this, rhs);
}
void BigIntBase::setCapacity(){
    data = new BigUnit[capacity=defaultCapacity];
}
void BigIntBase::setCapacity(ui _capacity){
    if (_capacity < defaultCapacity)
        data = new BigUnit[capacity=defaultCapacity];
    else 
        data = new BigUnit[capacity=_capacity];
}
void BigIntBase::expand(int newCapacity){
    cout << "expand here" << endl;
    BigUnit* newData = new BigUnit[newCapacity];
    BigUnit* temp = data;
    memcpy(newData, data, sizeof(BigUnit)*capacity);
    data = newData;
    capacity = newCapacity;
    free(temp);
}
void BigIntBase::assign(BigIntBase& lhs, const BigIntBase& rhs){
    lhs.size = rhs.size;
    lhs.setCapacity(rhs.capacity);
    memcpy(lhs.data, rhs.data, sizeof(BigUnit) * lhs.capacity);
}
/*
 * If the requested idx >= capacity, it will expand the capacity twice.
 * The benefit is that the other part of the program does not need to consider expansion  issue.
 * Thus, this little trick can largely reduce the programming complexity. 
 * Also, in this way, the program is easier to read and to maintain.
 */
BigUnit& BigIntBase::operator[](const ui idx) {
    if (idx >= capacity) expand(capacity << 1);
    return data[idx];
}
void BigIntBase::add(BigIntBase &a, BigIntBase &b){
    assert(a.size >= b.size);
    if (a.size == 0){
        operator = (b);
        return;
    } else if (b.size == 0) {
        operator = (a);
        return;
    }
    BigIntBase& c = *this;
    ui i;
    bool carry = 0;
    BigUnit t;
    for (i = 0; i < b.size; i++){
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
int BigIntBase::compare(BigIntBase &b) {
    BigIntBase& a = *this;
    if (a.size != b.size) return a.size - b.size;
    else{
        for (int i = a.size - 1; i >= 0; i--){
            if (a[i] == b[i]) continue;
            else return a[i] - b[i];
        }
        return 0;
    }
}
void BigIntBase::subtract(BigIntBase &a, BigIntBase &b){
    if (b.size == 0){
        operator = (a);
        return;
    }
    BigIntBase& c = *this;
    ui i;
    bool carry = 0;
    BigUnit t;
    for (i = 0; i < b.size; i++){
        t = carry + b[i];
        if (a[i] < t){
            c[i] = 10 + a[i] - t;
            carry = 1;
        }else{
            c[i] = a[i] - t;
            carry = 0;
        }
    }
    for (; i < a.size && carry; i++)
        if (a[i] == 0) c[i] = 9;
        else c[i] = a[i]-1, carry = 0;
    for (; i < a.size; i++)
        c[i] = a[i];

    size = a.size-1;
    while( c[size] == 0 && size >= 0) size--;
    size++;
}
void BigIntBase::multiply(BigIntBase &a, BigIntBase &b){
    if (a.size == 0)
        this->size = 0;
    else if (a.size == 1 && a[0] == 1){
        operator = (b);
        return;
    } else if (b.size == 1 && b[0] == 1) {
        operator = (a);
        return;
    }
    BigIntBase& c = *this;
    ui i;
    bool carry = 0;
    BigUnit t;

}
BigIntBase& BigIntBase::operator=(const BigIntBase& rhs) {
    assign(*this, rhs);
    return *this;
}
BigIntBase BigIntBase::operator+(BigIntBase& b) {
    BigIntBase ret(true, max(b.capacity, this->capacity)+2);
    if (this->size > b.size)
        ret.add(*this, b);
    else 
        ret.add(b, *this);
    return ret;
}
BigIntBase BigIntBase::operator-(BigIntBase& b){
    assert(compare(b) >= 0);
    BigIntBase ret(true, capacity);
    ret.subtract(*this, b);
    return ret;
}
string BigIntBase::toStringInBase(ui base){
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

inline ostream& operator <<(ostream &os, BigIntBase& n) {
    os << n.toStringInBase(10);
    return os;
}
