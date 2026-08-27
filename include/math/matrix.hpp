#pragma once
#ifndef _TSTD_MATRIX_HPP__
#define _TSTD_MATRIX_HPP__

#include "..\tstd_definition.h"

; template <typename T> class matrix {

public:

    matrix(void) {

        this->cols = 0;
        this->rows = 0;

    }

    inline t_uint get_cols(void) const  {
        return this->cols;
    };
    inline t_uint get_rows(void) const {
        return this->rows;
    }

private:

    t_uint cols, rows;

};

#endif