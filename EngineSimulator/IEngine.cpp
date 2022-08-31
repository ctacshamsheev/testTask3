#include "IEngine.h"

std::ostream& operator<<(std::ostream& out, const IEngine& data) {
  out << data.toString();
  return out;
}
