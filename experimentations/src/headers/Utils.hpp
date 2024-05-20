#ifndef UTILS_HPP
#define UTILS_HPP

using namespace std;

/**
 * @brief
 */
class Utils {
public:
    Utils() = default;

    /**
     * @brief
     */
    int comb(int n, int k) {
        int result = 1;
        for (int i = 1; i <= k; ++i) {
            result *= (n - k + i);
            result /= i;
        }
        return result;
    }
};


#endif