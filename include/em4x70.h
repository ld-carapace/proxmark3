//-----------------------------------------------------------------------------
// Copyright (C) Proxmark3 contributors. See AUTHORS.md for details.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// See LICENSE.txt for the text of the license.
//-----------------------------------------------------------------------------
// Low frequency EM4x70 structs -- common to both ARM firmware and client
//-----------------------------------------------------------------------------

#ifndef EM4X70_H__
#define EM4X70_H__

#include <stdint.h>
#include <stdbool.h>

#define EM4X70_NUM_BLOCKS 16

// Common word/block addresses
#define EM4X70_PIN_WORD_LOWER 10
#define EM4X70_PIN_WORD_UPPER 11

typedef struct {
    // ISSUE: `bool` type does not have a standard-defined size.
    //        therefore, compatibility between architectures / 
    //        compilers is not guaranteed.
    // ISSUE: C99 has no _Static_assert() ... was added in C11
    // TODO: add _Static_assert(sizeof(bool)==1);
    // TODO: add _Static_assert(sizeof(em4x70_data_t)==36);
    bool parity;

    // Used for writing address
    uint8_t address;
    uint16_t word;

    // PIN to unlock
    uint32_t pin;

    // Used for authentication
    uint8_t frnd[4];
    uint8_t grnd[3];
    uint8_t rnd[7];

    // Used to write new key
    uint8_t crypt_key[12];

    // used for bruteforce the partial key
    uint16_t start_key;

} em4x70_data_t;

#endif /* EM4X70_H__ */
