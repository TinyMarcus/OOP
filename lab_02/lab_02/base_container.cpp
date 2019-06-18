#include "base_container.h"

base_container::base_container()
    : element_count(0) {}

base_container::base_container(size_t count)
    : element_count(count) {}

base_container::~base_container()
{
    this->element_count = 0;
}

bool base_container::is_empty() const
{
    return element_count == 0;
}

size_t base_container::size() const
{
    return element_count;
}
