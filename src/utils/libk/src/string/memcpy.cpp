
/*
 * nKernel: Magical kernel for magical needs
 * Copyright (C) 2019 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <string.h>

void* memcpy(void* _dest, const void* _src, size_t num) {
    uint8_t* dest = reinterpret_cast<uint8_t*>(_dest);
    const uint8_t* src = reinterpret_cast<const uint8_t*>(_src);
    for (size_t i = 0; i < num; i++)
        dest[i] = src[i];
    return dest;
}
