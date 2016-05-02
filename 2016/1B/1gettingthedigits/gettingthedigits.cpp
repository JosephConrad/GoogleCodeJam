/*
 * Header file available here:
 * https://github.com/JosephConrad/GoogleCodeJam/tree/master/2016
 */
#include "../../template.h"


void processNumber(char let, std::string alpha, int result[10], int num,
                   std::map<char, int> &lettersCounter) {
    if (lettersCounter[let] > 0) {
        int number = lettersCounter[let];
        result[num] = number;
        for (auto &c : alpha) {
            lettersCounter[c] = lettersCounter[c] - number;
        }
    }
}


std::string solve(std::vector<char> letters) {

    std::vector<std::string> stringNumbers = {"ZERO", "TWO", "FOUR", "SIX", "EIGHT",
                                              "ONE", "THREE", "FIVE", "SEVEN"};
    std::vector<char> chars = {'Z', 'W', 'U', 'X', 'G', 'O', 'H', 'F', 'S'};
    std::vector<int> number = {0, 2, 4, 6, 8, 1, 3, 5, 7};
    std::map<char, int> lettersCounter;

    int result[10];
    REP(i, 10) result[i] = 0;

    for (auto &letter: letters) {
        lettersCounter[letter] = lettersCounter[letter] + 1;
    }

    for (int i = 0; i < stringNumbers.size(); i++) {
        processNumber(chars[i], stringNumbers[i], result, number[i], lettersCounter);
    }
    result[9] = lettersCounter['N'] / 2;

    std::string print = "";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < result[i]; ++j)
            print += std::to_string(i);
    }
    return print;
}


int main() {

#ifndef GOOGLE_CODE_JAM
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t start = clock();

    std::string name;
    std::getline(std::cin, name);
    int T = std::stoi(name);
    REP(cc, T) {
        std::getline(std::cin, name);
        std::vector<char> letters = splitString<char, std::vector>(name);
        printf("Case #%d: %s\n", cc + 1, solve(letters).c_str());
    }
    fprintf(stderr, "*** Total time: %.3lf seconds ***\n",
            ((clock() - start) / (double) CLOCKS_PER_SEC));
    return 0;
}
