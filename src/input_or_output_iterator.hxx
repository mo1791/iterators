
#include <ranges>

class iterator 
{

public:
    using difference_type = std::ptrdiff_t;

public:
    constexpr auto operator*() const noexcept -> int&;
    constexpr auto operator*()       noexcept -> int&;

public:
    constexpr auto operator++()    noexcept -> iterator&; 
    constexpr auto operator++(int) noexcept -> iterator;
};


static_assert( std::input_or_output_iterator<iterator> );
