
#include <ranges>


class sentinel {};

class iterator : public std::forward_iterator_tag
{

public:
    using value_type      = int;
    using reference       = int&;
    using difference_type = std::ptrdiff_t;

    using iterator_category = std::forward_iterator_tag;

public:
    constexpr auto operator*() const noexcept -> int&;
    constexpr auto operator*()       noexcept -> int&;

public:
    constexpr auto operator++()    noexcept -> iterator&; 
    constexpr auto operator++(int) noexcept -> iterator ;

public:
    friend constexpr auto operator==(iterator, iterator) noexcept -> bool;
    friend constexpr auto operator==(iterator, sentinel) noexcept -> bool;
    friend constexpr auto operator==(sentinel, iterator) noexcept -> bool;

    friend constexpr auto operator!=(iterator, iterator) noexcept -> bool;
    friend constexpr auto operator!=(iterator, sentinel) noexcept -> bool;
    friend constexpr auto operator!=(sentinel, iterator) noexcept -> bool;
};


static_assert( std::forward_iterator<iterator> );
