#include <iostream>
#include "matrix.h"
#include "exceptions.h"

using namespace std;

int main()
{
    try
    {
        matrix<int> matr1 = matrix<int>({{1,1},{2,2},{3,3}});
        matrix<int> matr2 = matrix<int>({{1,2,3},{4,5,6}});
        matrix<int> matr4 = matrix<int>({{1,2,3},{4,5,6}, {7, 8, 9}});
        matrix<int> matr3 = matr1 * matr2;
        std::cout << "Matrix #1:\n" << matr1 << endl;
        matr2 += matr2;
        std::cout << "Matrix #4:\n" << matr4 << endl;
        std::cout << "Transposed matrix #4:\n" << !matr4 << endl;
        std::cout << "Matrix #2 after addition:\n" << matr2 << endl;
        std::cout << "Matrix #3:\n" << matr3 << endl;
        std::cout << "Matrix #1 after multiplication:\n" << matr1 << endl;
        std::cout << matr1[0][0] << ' ' << matr1[0][1] << ' ' << matr1[1][0] << endl;
        std::cout << "Matrix #1:\n" << matr1 << '\n' << "Matrix #2:\n" << matr2 << "\n" << "Matrix #3:\n" << matr3 << endl;
        std::cout << "Matrix #4:\n" << matr4 << endl;
        //matr1 += matr1 * 2.0;
        //std::cout << matr1 << endl;

        for (auto iter = matr4.begin(); iter != matr4.end(); ++iter)
        {
            std::cout << bool(iter) << ' ';
        }

    }
    catch (base_exception& except)
    {
        cout << except.what();
    }

    return 0;
}
