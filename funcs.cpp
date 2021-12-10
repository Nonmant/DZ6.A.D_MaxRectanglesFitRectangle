//https://contest.yandex.ru/contest/27844/problems/D/

#include "funcs.h"
#include <bits/stdc++.h>

//! @brief Index of last true. If everything is false return 0
template<typename F1, typename F2>
unsigned long long binSearchLowerBound(F1 valueGenerate,
                           F2 valueCheck,
                                       unsigned long long left, unsigned long long right){
    while (left<right){
        unsigned long long cur = (left + right + 1)/2;
        auto value = valueGenerate(cur);
        if(valueCheck(value)){
            left = cur;
        } else {
            right = cur-1;
        }
    }
    return right;
}

unsigned long long rectanglesFit(unsigned long long subRecW,
                                 unsigned long long subRecH,
                                 unsigned long long recW,
                                 unsigned long long recH){
    unsigned long long columns = recW/subRecW;
    unsigned long long rows = recH/subRecH;
    return columns*rows;
}

bool fit(
        unsigned long long d,
        unsigned long long w,
        unsigned long long h,
        unsigned long long a,
        unsigned long long b,
        unsigned long long n){
    return n <= rectanglesFit(a+2*d, b+2*d, w, h) ||
           n <= rectanglesFit(a+2*d, b+2*d, h, w);
}

void parseFile(std::istream & input, std::ostream & output){

    unsigned long long n, a, b, w, h;
    input >> n >> a >> b >> w >> h;
    unsigned long long left = 0, right = std::max(w,h) - std::min(a,b);
    auto d = binSearchLowerBound(
            [](unsigned long long d){return d;},
                [&n, &a, &b, &w, &h](unsigned long long d){
                    return fit(d,w,h,a,b,n);
                },
                    left, right);

    output << d;
}
