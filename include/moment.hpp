#ifndef MOMENT_MOMENT_HPP_
#define MOMENT_MOMENT_HPP_

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std::chrono;

namespace moment {

class moment {
    time_point<system_clock> m_unix;
 public:
  std::string toString() const {
    auto current_time = system_clock::to_time_t(m_unix);
    return std::ctime(&current_time);
  }
  moment() {
    m_unix = system_clock::now();
  }
};

std::ostream& operator<<(std::ostream& os, const moment& m) {
  return os << m.toString();
}

}  // namespace moment



#endif  // MOMENT_MOMENT_HPP
