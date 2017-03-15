/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

#ifndef HEADER_GUARD_ARRAY_H
#define HEADER_GUARD_ARRAY_H

#include <cstddef>
#include <type_traits>
#include <stdexcept>
#include <utility>
#include <algorithm>

namespace czipperz {
namespace containers {
template <class T, std::size_t Num>
class array {
    T* _end;
    char _buffer[sizeof(T[Num])];

    static T* elem(char* point) noexcept {
        return reinterpret_cast<T*>(point);
    }
    static char* cast(T* elem) noexcept {
        return const_cast<char*>(
            reinterpret_cast<const volatile char*>(elem));
    }

public:
    using element_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = T&;
    using pointer = T*;
    using const_pointer = const T*;
    using iterator = T*;
    using const_iterator = const T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator =
        std::reverse_iterator<const_iterator>;

    array() noexcept : _end(elem(_buffer)) {}

    void clear() noexcept(std::is_nothrow_destructible<T>::value) {
        while (!empty()) {
            pop_back();
        }
    }

    void insert(const_iterator it, T&& elem) {
        emplace(it, std::move(elem));
    }
    void insert(const_iterator it, const T& elem) {
        emplace(it, elem);
    }

    template <class... Args>
    void emplace(const_iterator it, Args&&... args) {
        if (it == _end) {
            emplace_back(std::forward<Args>(args)...);
        } else {
            emplace_back(std::move(*it));
            it->~T();
            try {
                new (it) T(std::forward<Args>(args)...);
            } catch(...) {
                for (auto i = it + 1; i != _end; ++i) {
                    i->~T();
                }
                _end = it;
                throw;
            }
            std::rotate(it, it + 1, _end);
        }
    }

    void push_back(const T& e) {
        emplace_back(e);
    }
    void push_back(T&& e) {
        emplace_back(std::move(e));
    }
    template <class... Args>
    void emplace_back(Args&&... args) {
        if (_end == elem(_buffer) + Num) {
            throw std::logic_error("czipperz::containers::array::"
                                   "push_back(): Not enough space "
                                   "for another element.");
        }
        new (_end) T(std::forward<T>(args)...);
        ++_end;
    }

    void pop_back() noexcept(std::is_nothrow_destructible<T>::value) {
        _end->~T();
        --_end;
    }

    bool empty() const noexcept { return begin() == end(); }

    std::size_t size() const noexcept { return end() - begin(); }

    iterator begin() noexcept { return elem(_buffer); }
    const_iterator begin() const noexcept { return elem(_buffer); }
    const_iterator cbegin() const noexcept { return begin(); }
    iterator end() noexcept { return _end; }
    const_iterator end() const noexcept { return _end; }
    const_iterator cend() const noexcept { return end(); }

    reverse_iterator rbegin() noexcept { return end(); }
    reverse_iterator rbegin() const noexcept { return end(); }
    reverse_iterator crbegin() const noexcept { return end(); }
    reverse_iterator rend() noexcept { return begin(); }
    reverse_iterator rend() const noexcept { return begin(); }
    reverse_iterator crend() const noexcept { return begin(); }

    reference operator[](std::size_t index) noexcept {
        return data()[index];
    }
    const_reference operator[](std::size_t index) const noexcept {
        return data()[index];
    }

    pointer data() noexcept { return elem(_buffer); }
    const_pointer data() const noexcept { return elem(_buffer); }

    reference front() noexcept { return *elem(_buffer); }
    const_reference front() const noexcept { return *elem(_buffer); }

    reference back() noexcept { return elem(_end)[-1]; }
    const_reference back() const noexcept { return elem(_end)[-1]; }

    void swap(array& other) {
        using std::swap;
        for (std::size_t i = 0; i != Num; ++i) {
            swap((*this)[i], other[i]);
        }
    }
};
}
}

#endif
