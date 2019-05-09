
/*
 * nKernel: A Magical kernel for magical needs
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

#pragma once

namespace syscall {

// TODO, move to nFiles?
enum class OpenFlags {
    O_APPEND,
    O_ASYNC,
    O_CLOEXEC,
    O_CREAT,
    O_DIRECT,
    O_DIRECTORY,
    O_DSYNC,
    O_EXCL,
    O_NOATIME,
    O_PATH,
};

int open(const char *pathname, int flags, mode_t mode);

}