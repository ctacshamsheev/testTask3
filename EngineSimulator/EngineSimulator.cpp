#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>

#include "Config.h"



int main() {

    Config cfg = Config();
    std::cout << cfg;
    try {

        Config cfg1 = Config("settings.conf");
        std::cout << cfg1;
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