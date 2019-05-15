
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
    O_APPEND,    // Before each write(2), the file offset is positioned at the end of the file
    O_ASYNC      // Async operations thru Sigio
    O_CLOEXEC,   // Close on execve calls
    O_CREAT,     // If the file does not exist it will be created.
    O_DIRECT,    // Automatic O_SYNC
    O_DIRECTORY, // Fail on not directory
    O_LARGEFILE  // Large file support, automatic?
    O_EXCL,      // Ensure the file is created!
    O_NOATIME,   // Dont update atime on read()
    O_NOCTTY,    // Nothing
    O_NOFOLLOW,  // Fail on symlink
    O_NONBLOCK,  // Dont hold the process to do io
    O_SYNC,      // Call will wait until io completes
    O_TRUNC      // Truncate to 0?
};

enum mode_t {
    S_IXOTH = 00001; // Other = x;
    S_IWOTH = 00002; // Other = W
    S_IROTH = 00004; // Other = R;
    S_IRWXO = 00007; // Other = RWX
    S_IXGRP = 00010; // Group = E
    S_IWGRP = 00020; // Group = W
    S_IRGRP = 00040; // Group = R
    S_IRWXG = 00070; // Group = RWX
    S_IXUSR = 00100; // User = X
    S_IWUSR = 00200; // User = W
    S_IRUSR = 00400; // User = R
    S_IRWXU = 00700; // User = RWX
}

int open(std::string_view pathname, int flags, mode_t mode);

}
