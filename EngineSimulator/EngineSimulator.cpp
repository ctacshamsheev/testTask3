#include <iostream>

#include "Config.h"
#include "GasEngine.h"
#include "LogPrint.h"
#include "TestStand.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  cout << "enter ambient temperature:\t";
  double t = 0.0;
  cin >> t;

  try {
    LogPrint log = LogPrint("output0.log");

    Config cfg = Config("settings.conf");  // чтение настроек из файла
    // Config cfg = Config(); // настройки по умолчанию из задания
    log.getOutputStream() << cfg;

    GasEngine engine = GasEngine(cfg, t);
    TestStand testStand = TestStand(&engine, &log);

    t = testStand.test();
    cout << "time elapsed from start to overheat:\t" << t << endl;

  } catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
