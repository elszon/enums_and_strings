#include <iostream>

#include "EnumOne.h"
#include "EnumTwo.h"

int main() {
    std::cout << two1 << "\n";
    std::cout << *toString(two1) << "\n";
    std::cout << *toEnum<Name1>("two1") << "\n";

    std::cout << "===================\n";

    std::cout << two2 << "\n";
    std::cout << *toString(two2) << "\n";
    std::cout << *toEnum<Name2>("two2") << "\n";

    std::cout << "===================\n";

    std::cout << three2 << "\n";
    std::cout << *toString(three2) << "\n";
    std::cout << *toEnum<Name2>("three2") << "\n";
    std::cout << std::endl;
}
