#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>

#include "Config.h"
#include "GasEngine.h"
#include "TestStand.h"



int main() {

    try {

        Config cfg1 = Config("settings.conf");
        std::cout << cfg1;
        GasEngine engine = GasEngine(cfg1, 50);
        TestStand testStand = TestStand(&engine);
        std::cout << testStand.test();
    }
    catch (std::invalid_argument e) {
        std::cout << e.what() << std::endl;
    }

   // Config config("hell");
  /*  loadConfig(config);
    cout << config.num << '\n';
    cout << config.str << '\n';
    cout << config.flt << '\n';*/
    return 0;
}