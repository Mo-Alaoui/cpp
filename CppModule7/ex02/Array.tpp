template <typename T>
Array<T>::Array() : _arr(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    if (_size == 0)
    {
        throw std::invalid_argument("Size must be greater than 0");
    }
    try
    {
        _arr = new T[n]();
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
    _arr = new T[other._size];
    for (int i = 0; i < _size; i++)
        _arr[i] = other._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _arr;
        _size = other._size;
        _arr = new T[_size]();
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = other._arr[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](const unsigned int i)
{
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return (_arr[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _arr;
}