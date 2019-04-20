
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

// Data chunk for allocated data
class ChunkData {
public:
    ChunkData(size_t _size, bool mmapped = false) : size(_size) {
        flags[Flags::kMapped] = mmapped;
    }
    enum class Flags { kFreed, kMapped, kCount };
    std::bitset<Flags::kCount> flags;
    std::size_t size;
    std::byte data[];
};
ChunkData* raw_to_chunk(std::byte* raw) {
    return reinterpret_cast<ChunkData*>(raw) - offsetof(ChunkData, data);
}
std::byte* chunk_to_raw(ChunkData* chunk) {
    return reinterpret_cast<std::byte*>(&chunk->data) ;
}

class Heap {
    Heap(std::size_t _size) : size(_size) {
        assert(this->size > sizeof(Heap) + (sizeof(ChunkData) + sizeof(FreeInfo::Part)) + sizeof(ChunkData)); // just in case ;)

        // Initialize a chunk for our free info.
        this->freespace.set = reinterpret_cast<FreeInfo::Part*>(*raw_to_chunk(&this->data) = ChunkData(sizeof(FreeInfo::Part)));
        this->Freespace.set->first = &this->data + sizeof(ChunkData);
        this->Freespace.set->second = this->size - sizeof(ChunkData);
    }
    // Header information
    std::mutex heap_lock;
    Heap* next_heap = nullptr;
    std::size_t size;
    struct FreeInfo {
        using Part = std::pair<std::byte*, size_t>;
        std::byte* Claim(size_t wanted) {
            // Find the smallest freespace avaiable
            auto end = this->set + this->size + 1;
            auto find = std::find_if(this->set, end, [&](Part* i){
                return i->second >= wanted;
            });
            if (find == end)
                return nullptr;
             // Move the free partition down to make space for our chunk

             } else
                RemovePart(find);
        }
    private:
        void RemoveSpace(Part* p, std::size_t size) {
            assert(p->second >= size;);
            // Try to move this partition down some.
            std::size_t end_size = find->second - wanted;
            if (end_size != 0) {
                p->first + wanted;
                p->second = end_size;
                return;
            }
            // Takes the whole partition, we need to remove it from the set
            assert(p >= this->set && p <= this->set + this->size); // Bounds check for part being within set, security issue?

            // Shift down
            // TODO, check code cuz im high while writing it
            for (int i = this->size - 1; this->set[i] >= p; i--)
                this->set[i] = this->set[i - 1];
            // Resize
            EnsureSize(this->size - 1);
        }
        void AddSpace(std::byte* loc, std::size_t size) {
            // Find part that touches the end of our location.
            auto end = this->set + this->size + 1;
            auto find = std::find_if(this->set, end, [&](Part* i){
                return loc == i->first + i->second;
            });
            if (find != end) {
                // we can just add some to that partition
                find->size += size;
                return;
            }
            // Nothings ever that simple, we need to push another part into our set
            this->EnsureSize(this->size + 1);
            Part new = {loc, size};

        }
        // Function to handle our internal allocation
        void EnsureSize(std::size_t size){

        }
        void AddSize(std::size_t size) {

        }
        Part* set;
        std::size_t size = 1;
    } freespace;
    // The trailing data
    std::byte data[];
};

static Heap* heap_start = nullptr;

void* malloc(size_t wanted_size) {
    // Saftey checks
    assert(heap_start != nullptr);
    if (wanted_size <= 0)
        return nullptr;

    // MMAP instead of trying to add it and partition with the rest of the chunks
    void* mmap(0, wanted_size + sizeof(DataChunk), int prot, int flags,
                  int fd, off_t offset);
    // Find next smallest block
    for(Heap* i = heap_start; i != nullptr; i = i->next_heap) {
        std::lock_guard<std::mutex>(i->heap_lock);
        auto find = std::find()
    }

    heap_start
}

void free(void* raw_ptr) {
    assert(heap_start != nullptr);
    if (raw_ptr == nullptr)
        return;

}

void Init() {
    static std::once_flag init_guard;
    std::call_once(init_guard, [](){

    });
}

}
