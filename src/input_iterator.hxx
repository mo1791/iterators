
#include <ranges>

class iterator : public std::input_iterator_tag
{

public:
    using value_type = int;
    using reference  = int&;
    using difference_type = std::ptrdiff_t;

    using iterator_category = std::input_iterator_tag;

public:
    constexpr auto operator*() const noexcept -> int&;
    constexpr auto operator*()       noexcept -> int&;

public:
    constexpr auto operator++()    noexcept -> iterator&; 
    constexpr auto operator++(int) noexcept -> iterator;
};


static_assert( std::input_iterator<iterator> );
