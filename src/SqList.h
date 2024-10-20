#pragma once
#include <memory>
#include <exception>
#include <cstring>


//***********************************************
// name      : 顺序表
// brief     : 使用一组地址连续的存储单元依次存贮线性表的数据元素
// attention : None
//***********************************************

template <typename T>
class SqList
{
public:
    explicit SqList(size_t capacity)
    : _data(std::make_unique<T[]>(capacity)), _len(0), _capacity(capacity)
    {}

    SqList(const SqList& list)
    {
        _len = list._len;
        _capacity = list._capacity;
        _data = std::make_unique<T[]>();
        std::memcpy(_data.get(),list._data.get(),sizeof(T) * list._len);
    }

    SqList(SqList&& list) noexcept = default;

    ~SqList()= default;

    T& operator[](unsigned int pos)
    {
        if(pos >= _len)
        {
            throw std::out_of_range("out of range");
        }
        return _data[pos];
    }

    void Clear() noexcept
    {
        _len = 0;
    }

    size_t Length() const
    {
        return _len;
    }

    void PushBack(const T& val)
    {
        CheckCapacity();

        _data[_len] = val;
        ++_len;
    }

    void insert(unsigned int pos,const T& val)
    {
        if(pos == _len)
        {
            PushBack(val);
        }
        else if(pos > _len)
        {
            throw std::out_of_range("out of range");
        }
        else
        {
            CheckCapacity();
            std::memmove(_data.get() + pos + 1,_data.get() + pos,sizeof(T) * (_len - pos));
            ++_len;
            _data[pos] = val;
        }
    }

    void remove(unsigned int pos)
    {
        if(pos >= _len)
        {
            throw std::out_of_range("out of range");
        }
        std::memmove(_data.get() + pos,_data.get()+ pos+1 ,sizeof(T)*(_len - pos -1) );
        --_len;
    }

    void forEach(void (*print)(const T&))
    {
        if(!print)
        {
            throw std::invalid_argument("invalid argument");
        }
        for(int i =0;i<_len;++i)
        {
            print(_data[i]);
        }
    }

    size_t capacity() const
    {
        return _capacity;
    }

private:
    void CheckCapacity()
    {
        if(_len >= _capacity)
        {
            /// 每次扩展为原容量的一倍
            ExtendCapacity(2*_capacity);
        }
    }

    void ExtendCapacity(size_t newCapacity)
    {
        T* newSpace = new T[newCapacity];
        std::memcpy(newSpace,_data.get(),_len);
        _capacity = newCapacity;
        _data.reset(newSpace);
    }

    std::unique_ptr<T[]> _data;
    size_t _len{};
    size_t _capacity{};
};