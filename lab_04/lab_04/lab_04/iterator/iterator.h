#ifndef ITERATOR_H
#define ITERATOR_H

#include "object/object.h"

#include <iostream>
#include <memory>
#include <vector>

typedef std::vector<std::shared_ptr<Object>>::iterator ObjectIter;

#endif // ITERATOR_H
