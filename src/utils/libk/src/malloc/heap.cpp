
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

#include <mutex>

namespace heap {

// TODO, what to actually store here
class Header {
public:

};
// make a set to store freespace, ensure to insertion sort it when freespace is taken away and added.
// switch insert search direction depending on add or loose to shorten the search length by using our last points size
// instead of header, have it a map or a set or something?
// new idea, header stores cache info for the freespaces
class Chunk {
public:
    enum class Flags { kFreed, kCount };
    std::bitset<Flags::kCount> special;
};

static void* raw_heap = nullptr;

void malloc() {

}

void free(void* raw_ptr) {
    if (raw_ptr == nullptr)
        return;

}

void Init() {
    static std::once_flag init_guard;
    std::call_once(init_guard, [](){

    });
}

}
