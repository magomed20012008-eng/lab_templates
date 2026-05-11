// #pragma once

// #include <cstddef>

// template <typename T>
// class Array {
// public:
//     // ======================== Constructors ========================

//     Array() = default;                                // empty array, size 0
//     explicit Array(size_t size) : size_(size) {
//         data_ = new T[size_];

//     };            // default-constructed elements
//     Array(size_t size, const T& value) : size_(size) {
//         data_ = new T[size_]
//         for(size_t i = 0; i < size_; ++i) {
//             data_[i] = value
//         }
//     }    // all elements = value

//     // =================== Copy and Move ===========================

//     Array(const Array& other) {
//         size_ = other.size_;
//         data_ = new T[size_];
//         for(size_t i = 0, i < size_, ++i) {
//             data_[i] = other.data_[i]
//         }
//      };
//     Array(Array&& other) {
//         size_ = other.size_;
//         data_ = other.data_
//      };
//     };
//     Array& operator=(const Array& other) {
//         size_ = other.size_;
//         data_ = new T[size_]
//         for(size_t i = 0; i < size_; ++i) {
//             data_[i] = other.data_[i];
//         }
//         return *this;

//     };
//     Array& operator=(Array&& other) {
//         size_ = other.size;
//         data_ = other.data_;
//         return *this;

//     };

//     // =================== Destructor ==============================

//     ~Array() {
//         delete[] data;
//     };

//     // =================== Element access ==========================

//     T&       operator[](size_t index) {
//         return data_[index];
//     };
//     const T& operator[](size_t index) const {
//                 return data_[index];

//     };

//     T&       front() {
//         return data_[0];
//     };
//     const T& front()  const {
//                 return data_[0];

//     };

//     T&       back() {
//         return data_[size_ - 1];
//     };
//     const T& back() const {
//     return data_[size_ - 1];
//     };

//     T*       data() {
//             return data_;
//     };
//     const T* data() const{
//         return data_ 
//     };

//     // =================== Capacity ================================

//     size_t size() const;
//     bool   empty() const;

//     // =================== Operations ==============================

//     void fill(const T& value) {
//         for(size_t i = 0, i < size_, ++i) {
//             data_[i] = value;
//         }
//     };
//     void swap(Array& other) {
        
//         T* tempData = other.data_ // !!!
//         T* tempSize = other.size_
//         other.size_ = size_
//         size_ = tempSize

//         other.data_ = data_
//         data_ = tempData
 
//     };

//     // =================== Comparison ==============================

//     bool operator==(const Array& rhs) const {
//         for(size_t i = 0, i < size_, ++i) {
//             if ( data_[i] == other.data_[i]) {
//                 continue
//             }
//             else {
//                 return false;
//             }
//                         return true;

            
//         }

//     };
//     bool operator!=(const Array& rhs) const {
//          for(size_t i = 0, i < size_, ++i) {
//             if ( data_[i] != other.data_[i]) {
//                 continue
//             }
//             else {
//                 return false;
//             }
//             return true;
            
//         }
//     };

// private:
//     T*     data_ = nullptr;
//     size_t size_ = 0;
// };
#pragma once

#include <cstddef>
#include <utility>

// fixed-size heap array
template <typename T>
class Array {
public:
    Array() = default;

    explicit Array(size_t size)
        : data_(new T[size]), size_(size) {}

    Array(size_t size, const T& value)
        : data_(new T[size]), size_(size) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = value;
        }
    }

    Array(const Array& other)
        : data_(new T[other.size_]), size_(other.size_) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    Array(Array&& other)
        : data_(other.data_), size_(other.size_) {
        other.data_ = nullptr;
        other.size_ = 0;
    }

Array& operator=(const Array& other) {
    if (this == &other) return *this;

    T* newData = new T[other.size_];      
    for (size_t i = 0; i < other.size_; ++i) {
        newData[i] = other.data_[i];        
    }

    delete[] data_;                        
    data_ = newData;
    size_ = other.size_;
    return *this;
}
    Array& operator=(Array&& other) {
        if (this == &other) {
            return *this; 
        }

        delete[] data_;

        data_ = other.data_;
        size_ = other.size_;

        other.data_ = nullptr;
        other.size_ = 0;

        return *this;
    }

    ~Array() {
        delete[] data_;
    }

    T& operator[](size_t index) {
        return data_[index];
    }

    const T& operator[](size_t index) const {
        return data_[index];
    }

    T& front() {
        return data_[0];
    }

    const T& front() const {
        return data_[0];
    }

    T& back() {
        return data_[size_ - 1];
    }

    const T& back() const {
        return data_[size_ - 1];
    }

    T* data() {
        return data_;
    }

    const T* data() const {
        return data_;
    }

    size_t size() const {
        return size_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void fill(const T& value) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = value;
        }
    }

    void swap(Array& other) {
        
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    }

    bool operator==(const Array& rhs) const {
        if (size_ != rhs.size_) {
            return false;
        }

        for (size_t i = 0; i < size_; ++i) {
            if (!(data_[i] == rhs.data_[i])) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const Array& rhs) const {
        return !(*this == rhs);
    }

private:
    T* data_ = nullptr;
    size_t size_ = 0;
};