#include "EAssert.h"
#include <iostream>

void CustomAssert(const std::string& expression, const std::string filename, int line)
{
	std::cerr << "Assertion failed: (" << expression << "), file " << filename << ", line " << line << std::endl;
	std::abort();
}
