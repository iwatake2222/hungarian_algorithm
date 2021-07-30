/* Copyright 2021 iwatake2222

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>

#include "hungarian_algorithm.h"


std::vector<std::vector<float>> MakeTestData_1()
{
    int32_t rows = 3;
    int32_t cols = 4;

    std::vector<std::vector<float>> score_table(rows, std::vector<float>(cols));
    score_table[0][0] = 0.1F;
    score_table[0][1] = 0.9F;
    score_table[0][2] = 0.2F;
    score_table[0][3] = 0.1F;
    score_table[1][0] = 0.1F;
    score_table[1][1] = 0.1F;
    score_table[1][2] = 0.8F;
    score_table[1][3] = 0.1F;
    score_table[2][0] = 0.7F;
    score_table[2][1] = 0.4F;
    score_table[2][2] = 0.4F;
    score_table[2][3] = 0.1F;

    return score_table;
}

std::vector<std::vector<float>> MakeTestData_2()
{
    int32_t rows = 4;
    int32_t cols = 3;

    std::vector<std::vector<float>> score_table(rows, std::vector<float>(cols));
    score_table[0][0] = 0.1F;
    score_table[0][1] = 0.9F;
    score_table[0][2] = 0.2F;
    score_table[1][0] = 0.1F;
    score_table[1][1] = 0.1F;
    score_table[1][2] = 0.1F;
    score_table[2][0] = 0.8F;
    score_table[2][1] = 0.1F;
    score_table[2][2] = 0.7F;
    score_table[3][0] = 0.4F;
    score_table[3][1] = 0.4F;
    score_table[3][2] = 0.1F;

    return score_table;
}

int main(int argc, char *argv[])
{
    std::vector<std::vector<float>> score_table = MakeTestData_2();

    std::vector<int32_t> assign_for_row(score_table.size(), -1);
    std::vector<int32_t> assign_for_col(score_table[0].size(), -1);

    HungarianAlgorithm<float> solver(score_table);
    solver.Solve(assign_for_row, assign_for_col);

    printf("\nassign_for_row\n");
    for (int32_t i = 0; i < assign_for_row.size(); i++) {
        printf("%d  %d\n", i, assign_for_row[i]);
    }

    printf("\nassign_for_col\n");
    for (int32_t i = 0; i < assign_for_col.size(); i++) {
        printf("%d  %d\n", i, assign_for_col[i]);
    }

    return 0;
}

