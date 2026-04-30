#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
    std::vector<int> container;
    unsigned int max;

public:
    Span()
    {}
    
    Span(unsigned int n) : max(n)
    {
        
    }

    Span(const Span& other)
    {
        container = other.container;
    }

    Span& operator=(const Span& other) 
    {
        if (this != &other)
        {
            container = other.container;
        }
        return *this;
    }
    
    ~Span() {}

    
    void addNumber(int n)
    {
        if (container.size() >= max)
        {
            throw std::runtime_error("Span is full");    
        }
        container.push_back(n);
    }

    template <typename Iterator>
    void addRange(Iterator first, Iterator last)
    {
        for (; first != last; ++first)
        {
            addNumber(*first);
        }
    }
    std::ostream& operator<<(std::ostream& out);

    int shortestSpan() const
    {
        if (container.size() <= 1)
            throw std::runtime_error("Not enough numbers");

        std::vector<int> tmp = container;
        std::sort(tmp.begin(), tmp.end());

        int minSpan = tmp[1] - tmp[0];
        for (size_t i = 0; i < tmp.size() - 1; ++i)
        {
            int diff = tmp[i + 1] - tmp[i];
            if (diff < minSpan)
                minSpan = diff;
        }

        return (minSpan);
    }

    int longestSpan() const
    {
        if (container.size() <= 1)
            throw std::runtime_error("Not enough numbers");

        std::vector<int> tmp = container;
        std::sort(tmp.begin(), tmp.end());
        return (tmp.back()) - tmp.front();    
    }
};

std::ostream& Span::operator<<(std::ostream& out)
{
    return out;
}
