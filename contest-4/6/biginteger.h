// ID: 66254310
// https://contest.yandex.ru/contest/35212/problems/6/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BigInteger {
public:
    BigInteger();
    BigInteger(int a);
    BigInteger(string s);

    friend const BigInteger operator*(const BigInteger& b, const BigInteger& a);
    friend const BigInteger operator/(const BigInteger& a, const BigInteger& b);
    friend const BigInteger operator%(const BigInteger& a, const BigInteger& b);
    friend const BigInteger operator+(const BigInteger& a, const BigInteger& c);
    friend const BigInteger operator-(const BigInteger& a, const BigInteger& c);
    BigInteger& operator*=(const BigInteger& b);
    BigInteger& operator+=(const BigInteger& c);
    BigInteger& operator%=(const BigInteger& b);
    BigInteger& operator/=(const BigInteger& c);
    BigInteger& operator++();
    const BigInteger operator++(int);
    BigInteger& operator--();
    const BigInteger operator--(int);
    BigInteger abs() const;
    const BigInteger operator-();
    BigInteger& operator-=(const BigInteger& c);
    bool operator<(BigInteger const& b) const;
    bool operator>(BigInteger const& b) const;
    bool operator<=(BigInteger const& b) const;
    bool operator>=(BigInteger const& b) const;
    bool operator==(BigInteger const& b) const;
    bool operator!=(BigInteger const& b) const;
    const string toString() const;
    explicit operator bool();
    friend istream& operator>>(istream&, BigInteger&);
    friend ostream& operator<<(ostream&, const BigInteger&);
private:
    vector<int> digit;
    bool positive = true;
    void up_lvl();
    void kill0();
    void dif(BigInteger& a, const BigInteger& b);
    void sum(BigInteger& a, const BigInteger& b);
    int cmp(const BigInteger& a, int k = 1) const;
};

BigInteger::BigInteger() {
    positive = true;
}

BigInteger::BigInteger(int a) {
    if (a < 0) {
        positive = false;
        a *= -1;
    }
    else if (a == 0) {
        digit.push_back(0);
        positive = true;
    }
    while (a != 0) {
        digit.push_back(a % 10);
        a /= 10;
    }
}


BigInteger::BigInteger(string s) {
    positive = true;
    for (size_t i = s.length() - 1; i > 0; i--) {
        digit.push_back(s[i] - '0');
    }
    if (s[0] == '-') {
        positive = false;
    }
    else {
        digit.push_back(s[0] - '0');
    }
}

const BigInteger operator-(const BigInteger& a, const BigInteger& c) {
    BigInteger dif = a;
    return dif -= c;
}

const BigInteger operator+(const BigInteger& a, const BigInteger& c) {
    BigInteger sum = a;
    return sum += c;
}

const BigInteger operator*(const BigInteger& b, const BigInteger& a) {
    size_t length = a.digit.size() + b.digit.size() + 1;
    BigInteger c;
    c.digit.resize(length, 0);
    for (size_t i = 0; i < a.digit.size(); i++) {
        for (size_t j = 0; j < b.digit.size(); j++) {
            c.digit[i + j] += a.digit[i] * b.digit[j];
        }
    }
    for (size_t i = 0; i < length; i++) {
        if (i < length - 1) {
            c.digit[i + 1] += c.digit[i] / 10;
        }
        c.digit[i] %= 10;
    }
    c.positive = a.positive == b.positive;
    c.kill0();
    return c;
}

const BigInteger operator/(const BigInteger& a, const BigInteger& b) {
    BigInteger res;
    res.digit.resize(a.digit.size());
    BigInteger curValue;
    for (int i = int(a.digit.size()) - 1; i >= 0; i--) {
        curValue.up_lvl();
        curValue.kill0();
        curValue.digit[0] = a.digit[i];
        int x = 0;
        int l = 0, r = 9;
        while (l <= r) {
            int m = (l + r) / 2;
            BigInteger cur(0);
            cur = b.abs() * m;
            if (cur.cmp(curValue, 0) <= 0) {
                x = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        res.digit[i] = x;
        curValue -= b.abs() * x;
    }
    res.positive = a.positive == b.positive;
    res.kill0();
    return res;
}

const BigInteger operator%(const BigInteger& a, const BigInteger& b) {
    BigInteger res;
    res.digit.resize(a.digit.size());
    BigInteger curValue;
    for (int i = int(a.digit.size()) - 1; i >= 0; i--) {
        curValue.up_lvl();
        curValue.kill0();
        curValue.digit[0] = a.digit[i];
        int x = 0;
        int l = 0, r = 9;
        while (l <= r) {
            int m = (l + r) >> 1;
            BigInteger cur;
            cur = b.abs() * m;
            if (cur.cmp(curValue, 0) <= 0) {
                x = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        res.digit[i] = x;
        curValue = curValue - b.abs() * x;
    }
    curValue.kill0();
    curValue.positive = a.positive;
    if (curValue.digit.empty()) {
        curValue.digit.push_back(0);
    }
    return curValue;
}

istream& operator>>(istream& str, BigInteger& a) {
    string s;
    str >> s;
    BigInteger b(s);
    a = b;
    return str;
}

ostream& operator<<(ostream& str, const BigInteger& a) {
    string s;
    s = a.toString();
    str << s;
    return str;
}

bool BigInteger::operator<(BigInteger const& b) const {
    return cmp(b) == -1;
}

bool BigInteger::operator>(BigInteger const& b) const {
    return cmp(b) == 1;
}

bool BigInteger::operator<=(BigInteger const& b) const {
    int comp = cmp(b);
    return comp == -1 || comp == 0;
}

bool BigInteger::operator>=(BigInteger const& b) const {
    int comp = cmp(b);
    return comp == 1 || comp == 0;
}

bool BigInteger::operator==(BigInteger const& b) const {
    return cmp(b) == 0;
}

bool BigInteger::operator!=(BigInteger const& b) const {
    return cmp(b) != 0;
}

BigInteger& BigInteger::operator*=(const BigInteger& b) {
    BigInteger rez = *this;
    return *this = rez * b;
}

BigInteger& BigInteger::operator+=(const BigInteger& c) {
    if ((positive && c.positive) || (!positive && !c.positive)) {
        sum(*this, c);
        return *this;
    }
    if ((positive && !c.positive) || (!positive && c.positive)) {
        if (this->cmp(c, 0) >= 0) {
            dif(*this, c);
            return *this;
        }
        else {
            BigInteger tmpa = *this;
            BigInteger tmpb = c;
            dif(tmpb, tmpa);
            return *this = tmpb;
        }
    }
    return *this;
}

void BigInteger::up_lvl() {
    digit.insert(digit.begin(), 0);
}

BigInteger& BigInteger::operator%=(const BigInteger& b) {
    return *this = *this % b;
}

BigInteger& BigInteger::operator/=(const BigInteger& c) {
    BigInteger rez = *this;
    return *this = rez / c;
}

BigInteger& BigInteger::operator++() {
    *this += 1;
    return *this;
}

const BigInteger BigInteger::operator++(int) {
    BigInteger tmp = *this;
    ++(*this);
    return tmp;
}

BigInteger& BigInteger::operator--() {
    *this -= 1;
    return *this;
}

const BigInteger BigInteger::operator--(int) {
    BigInteger tmp = *this;
    --(*this);
    return tmp;
}

BigInteger BigInteger::abs() const {
    BigInteger b = (*this);
    b.positive = true;
    return b;
}

const BigInteger BigInteger::operator-() {
    BigInteger b = *this;
    b.positive = !this->positive;
    if (digit.size() == 1 && digit[0] == 0) {
        b.positive = true;
        b.digit[0] = 0;
        return b;
    }
    else {
        return b;
    }
}

BigInteger& BigInteger::operator-=(const BigInteger& c) {
    if ((positive && c.positive) || (!positive && !c.positive)) {
        if (this->cmp(c, 0) >= 0) {
            dif(*this, c);
            return *this;
        }
        else {
            BigInteger tmpA = *this;
            BigInteger tmpB = c;
            dif(tmpB, tmpA);
            tmpB.positive = !tmpB.positive;
            return *this = tmpB;
        }
    }
    else {
        sum(*this, c);
        return *this;
    }
}

const string BigInteger::toString() const {
    string s = positive ? "" : "-";
    if (digit[0] == 0 && digit.size() == 1) {
        s = '0';
        return s;
    }
    bool forwNuls = true;
    for (int i = int(digit.size()) - 1; i >= 0; i--) {
        if (digit[i] == 0 && forwNuls) {
            continue;
        }
        else {
            forwNuls = false;
            s += digit[i] + '0';
        }
    }
    if (s.empty() || (s[0] == '-' && s.length() == 1)) {
        s = '0';
    }
    return s;
}

BigInteger::operator bool() {
    return *this != 0;
}

void BigInteger::kill0() {
    while (!digit.empty() && *digit.rbegin() == 0) {
        digit.pop_back();
    }
    if (digit.empty()) {
        positive = true;
        digit.push_back(0);
    }
}

void BigInteger::dif(BigInteger& a, const BigInteger& b) {
    int carry = 0;
    for (size_t i = 0; i < b.digit.size() || carry; ++i) {
        a.digit[i] -= carry + (i < b.digit.size() ? b.digit[i] : 0);
        carry = a.digit[i] < 0;
        if (carry) a.digit[i] += 10;
    }
    a.kill0();
}

void BigInteger::sum(BigInteger& a, const BigInteger& b) {
    int carry = 0;
    for (size_t i = 0; i < max(a.digit.size(), b.digit.size()) || carry; ++i) {
        if (i == a.digit.size()) {
            a.digit.push_back(0);
        }
        a.digit[i] += carry + (i < b.digit.size() ? b.digit[i] : 0);
        carry = a.digit[i] / 10;
        a.digit[i] %= 10;
    }
    a.kill0();
}

int BigInteger::cmp(const BigInteger& a, int k) const {
    int check = 1;
    if (k == 1) {
        if (positive && !a.positive) {
            return 1;
        }
        if (!positive && a.positive) {
            return -1;
        }
        if (!positive && !a.positive) {
            check = -1;
        }
    }
    if (digit.size() < a.digit.size()) {
        return -1 * check;
    }
    if (digit.size() > a.digit.size()) {
        return check;
    }
    for (size_t i(digit.size()); i > 0; i--) {
        if (digit[i - 1] < a.digit[i - 1]) return -1 * check;
        if (digit[i - 1] > a.digit[i - 1]) return check;
    }
    return 0;
}
