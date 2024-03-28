
#include <ranges>


class sentinel {};

class iterator : public std::contiguous_iterator_tag
{


public:
    using value_type      = int;
    using reference       = int&;
    using difference_type = std::ptrdiff_t;

    using iterator_category = std::contiguous_iterator_tag;

public:
    constexpr auto operator*() const noexcept -> int&;
    constexpr auto operator*()       noexcept -> int&;

    constexpr auto operator[](int) const noexcept -> int&;
    constexpr auto operator[](int)       noexcept -> int&;

public:
    constexpr auto operator->() const noexcept -> int*;
    constexpr auto operator->()       noexcept -> int*;

public:
    constexpr auto operator++()    noexcept -> iterator&; 
    constexpr auto operator++(int) noexcept -> iterator ;
    constexpr auto operator--()    noexcept -> iterator&; 
    constexpr auto operator--(int) noexcept -> iterator ;

public:
    constexpr auto operator+=(int) noexcept -> iterator&;
    constexpr auto operator-=(int) noexcept -> iterator&;
    
    friend constexpr auto operator+(iterator, int) noexcept -> iterator ;
    friend constexpr auto operator+(int, iterator) noexcept -> iterator ;
    friend constexpr auto operator-(iterator, int) noexcept -> iterator ;
    friend constexpr auto operator-(int, iterator) noexcept -> iterator ;

public:
    friend constexpr auto operator==(iterator, iterator) noexcept -> bool;
    friend constexpr auto operator==(iterator, sentinel) noexcept -> bool;
    friend constexpr auto operator==(sentinel, iterator) noexcept -> bool;

    friend constexpr auto operator!=(iterator, iterator) noexcept -> bool;
    friend constexpr auto operator!=(iterator, sentinel) noexcept -> bool;
    friend constexpr auto operator!=(sentinel, iterator) noexcept -> bool;


    friend constexpr auto operator>(iterator, iterator) noexcept -> bool;
    friend constexpr auto operator>(sentinel, iterator) noexcept -> bool;
    friend constexpr auto operator>(iterator, sentinel) noexcept -> bool;

    friend constexpr auto operator<(iterator, iterator) noexcept -> bool;
    friend constexpr auto operator<(iterator, sentinel) noexcept -> bool;
    friend constexpr auto operator<(sentinel, iterator) noexcept -> bool;

    friend constexpr auto operator>=(iterator, iterator) noexcept -> bool;
    friend constexpr auto operator>=(iterator, sentinel) noexcept -> bool;
    friend constexpr auto operator>=(sentinel, iterator) noexcept -> bool;

    friend constexpr auto operator<=(iterator, iterator) noexcept -> bool;
    friend constexpr auto operator<=(iterator, sentinel) noexcept -> bool;
    friend constexpr auto operator<=(sentinel, iterator) noexcept -> bool;

public:
    friend constexpr auto operator-(iterator, iterator) noexcept -> difference_type;
    friend constexpr auto operator-(iterator, sentinel) noexcept -> difference_type;
    friend constexpr auto operator-(sentinel, iterator) noexcept -> difference_type;
    
};


static_assert( std::contiguous_iterator<iterator> );
