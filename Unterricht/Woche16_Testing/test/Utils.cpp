//
// Created by Nicolas Haenni on 2019-01-12.
//

#include <fructose/fructose.h>
#include "../src/Utils.h"


const int life_the_available_tests_and_everything = 42;

struct UtilTest : public fructose::test_base<UtilTest> {
    void general(const std::string& general) {
        fructose_assert(Utils::factorial(5) == 120);
    }

    void zeroIsOne(const std::string& zeroisOne) {
        fructose_assert(Utils::factorial(0) == 1);
    }
};

int main(int argc, char** argv) {

    UtilTest tests;
    tests.add_test("general", &UtilTest::general);
    tests.add_test("zeroIsOne", &UtilTest::zeroIsOne);

    return tests.run(argc, argv);
}