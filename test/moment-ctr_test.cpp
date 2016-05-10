#include <sstream>
#include <gtest/gtest.h>
#include "../include/moment.hpp"

namespace {
TEST(CtrTest, TestCout) {
    std::stringstream oss;
    oss << ::moment::moment();
    ASSERT_GT(oss.str().size(), 0);
}
}  // namespace
