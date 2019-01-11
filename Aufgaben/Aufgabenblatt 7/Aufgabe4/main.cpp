//
// Created by Nicolas Haenni on 2019-01-11.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class ProblemUtil {
public:
    static int getMaxSubArrayProduct(const vector<int>& values);
};

int ProblemUtil::getMaxSubArrayProduct(const vector<int>& values) {
    // only possible way to get a negative product is a single negative number
    if (values.size() == 1) return values.at(0);

    // init helper variables
    int result = 1;      // store overall largest positive product
    // (initialize with 1 because empty product is 1)
    int minNegProd = 1;  // store current smallest negative product
    int maxPosProd = 1;  // store current largest positive product
    bool isZero = true;  // false as soon as a pos or 2 consecutive neg found

    for (const auto& c : values) {
        // ZERO
        if (c == 0) {
            minNegProd = 1;
            maxPosProd = 1;
        }

            // NEGATIVE
        else if (c < 0) {
            // product must be positive on 2 consecutive negatives
            isZero = isZero && minNegProd == 1;

            int tmp = minNegProd;
            minNegProd = maxPosProd * c;
            maxPosProd = max(tmp * c, 1);
        }

            // POSITIVE
        else {
            isZero = false;

            minNegProd = min(minNegProd * c, 1);
            maxPosProd = maxPosProd * c;
        }

        // update overall max positive product
        if (maxPosProd > result) result = maxPosProd;
    }

    if (isZero && values.size() > 0) return 0;
    return result;
}

int main(int argc, char const* argv[]) {
    vector<int> values{-2, -3, 0, -2, 100, -40, 10, 0, -1, -2};
    // vector<int> values{5};
    // vector<int> values{0};
    // vector<int> values{-5};
    // vector<int> values{0, 0, 0, 0, 0};
    // vector<int> values{0, -1, 0, -2, 0, -3};
    // vector<int> values{0, -5, -4, 0, -10, 0};
    // vector<int> values{};

    for (const auto& c : values) cout << c << "  ";
    cout << endl
         << "Max product is: " << ProblemUtil::getMaxSubArrayProduct(values)
         << endl;

    cout << endl;
    return 0;
}