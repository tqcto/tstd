#pragma once
#ifndef _TSTD_COMPLEX_HPP_
#define _TSTD_COMPLEX_HPP_

#include <cmath>
#include <stdexcept> // for std::runtime_error

template <typename T>
class complex {

public:

    T real;
    T imag;

    complex() noexcept{

        this->real = static_cast<T>(0);
        this->imag = static_cast<T>(0);

    }
    complex(T _real, T _imag) noexcept {

        this->real = _real;
        this->imag = _imag;

    }

    ~complex() {


        
    }

    inline complex<T> conjugate() const {
    
        return complex<T>(this->real, -this->imag);

    }

    complex<T> reciprocal() const {
    
        T denominator = this->real * this->real + this->imag * this->imag;

        if (denominator == static_cast<T>(0)) {
            throw std::runtime_error("Division by zero in complex reciprocal.");
        }

        return complex<T>(this->real / denominator, -this->imag / denominator);
    
    }

    inline T norm() const {
    
        return std::sqrt(this->real * this->real + this->imag * this->imag);
    
    }

    inline complex<T> operator+(const complex<T>& other) const {
    
        return complex<T>(this->real + other.real, this->imag + other.imag);
    
    }

    inline complex<T> operator-(const complex<T>& other) const {
    
        return complex<T>(this->real - other.real, this->imag - other.imag);
    
    }

    inline complex<T> operator*(const complex<T>& other) const {
    
        T realPart = this->real * other.real - this->imag * other.imag;
        T imagPart = this->real * other.imag + this->imag * other.real;
        return complex<T>(realPart, imagPart);
    
    }

    complex<T> operator/(const complex<T>& other) const {
    
        T denominator = other.real * other.real + other.imag * other.imag;

        if (denominator == static_cast<T>(0)) {
            throw std::runtime_error("Division by zero in complex division.");
        }

        T realPart = (this->real * other.real + this->imag * other.imag) / denominator;
        T imagPart = (this->imag * other.real - this->real * other.imag) / denominator;
        return complex<T>(realPart, imagPart);
    
    }

    inline complex<T> operator*(const T& scalar) const {
    
        return complex<T>(this->real * scalar, this->imag * scalar);
    
    }

    friend complex<T> operator*(const T& scalar, const complex<T>& c) noexcept {

        return complex<T>(c.real * scalar, c.imag * scalar);

    }

    complex<T> operator/(const T& scalar) const {
    
        if (scalar == static_cast<T>(0)) {
            throw std::runtime_error("Division by zero in complex scalar division.");
        }

        return complex<T>(this->real / scalar, this->imag / scalar);
    
    }

    inline complex<T> operator-() const {
    
        return complex<T>(-this->real, -this->imag);

    }

};

#endif