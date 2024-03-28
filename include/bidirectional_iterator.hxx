#ifndef __BIDIRECTIONAL_ITERATOR_HXX__
#define __BIDIRECTIONAL_ITERATOR_HXX__

#include <ranges>

// Custom sentinel class derived from std::default_sentinel_t
class sentinel : public std::default_sentinel_t
{
public:
    // Comparison operators
    friend auto operator==(sentinel const&, sentinel const&) noexcept -> bool;
    friend auto operator!=(sentinel const&, sentinel const&) noexcept -> bool;
    friend auto operator> (sentinel const&, sentinel const&) noexcept -> bool;
    friend auto operator< (sentinel const&, sentinel const&) noexcept -> bool;
    friend auto operator>=(sentinel const&, sentinel const&) noexcept -> bool;
    friend auto operator<=(sentinel const&, sentinel const&) noexcept -> bool;
};


// Custom iterator class derived from std::bidirectional_iterator_tag
class iterator : public std::bidirectional_iterator_tag
{

private:
    int*        m_current;  // Pointer to the current element
    std::size_t m_count;    // Number of remaining elements

public:
    // Iterator traits
    using value_type      = int;
    using reference       = int&;
    using difference_type = std::ptrdiff_t;

    using iterator_category = std::bidirectional_iterator_tag;


public:
    // Default constructor
    iterator() noexcept;

    // Constructor with current pointer and count of remaining elements
    iterator(int*, std::size_t) noexcept;

public:
    // Dereference operator for reading and writing
    auto operator*() const noexcept -> int&;
    auto operator*()       noexcept -> int&;

public:
    // Pre ( Increment & Decrement ) operators
    auto operator++()    noexcept -> iterator&; 
    auto operator--()    noexcept -> iterator&; 
    
    // Post ( Increment & Decrement ) operators
    auto operator++(this iterator&, int) noexcept -> iterator ;
    auto operator--(this iterator&, int) noexcept -> iterator ;


public:
    // Comparison operators
    friend auto operator==(iterator const&, iterator const&) noexcept -> bool;
    friend auto operator==(iterator const&, sentinel const&) noexcept -> bool;
    friend auto operator==(sentinel const&, iterator const&) noexcept -> bool;

    friend auto operator!=(iterator const&, iterator const&) noexcept -> bool;
    friend auto operator!=(iterator const&, sentinel const&) noexcept -> bool;
    friend auto operator!=(sentinel const&, iterator const&) noexcept -> bool;

};


#endif
