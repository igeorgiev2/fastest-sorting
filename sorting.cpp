/******************************************************************************
Features:
 - Sorts unordered whole numbers in the range 0 to 200000000.
 - It has a linear complexity O(n).
*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

void pause() {
    cout << "Press Enter key to continue.";
    cin.ignore().get();
}

int main () {
    srand(time(NULL));
    if (sizeof(int) >= 4) {
        int random_array_length, sorted_array_length, n, zeros = 0, i = 0;
        cout << "Enter random numbers array length up to 100000000" << endl;
        cin >> random_array_length;
        if (random_array_length < 2 or random_array_length > 100000000) {
            cout << "Number is out of range!";
            return 1;
        }
        int *array = new int[random_array_length];
        int *random_array = new int[random_array_length];
        for (n = 0; n < random_array_length; ++n) {
            random_array[n] = rand() % random_array_length;
            array[random_array[n]] = random_array[n];
        }
        cout << endl;
        int smallest = *min_element(random_array, random_array + random_array_length);
        int largest = *max_element(random_array, random_array + random_array_length);
        cout << "The smallest number is " << smallest << endl;
        cout << "The largest number is "  << largest << endl;
        pause();
        clock_t tStart = clock();
        for (n = smallest; n < largest + 1; ++n) {
            zeros = (array[n] == 0) ? zeros += 1 : zeros;
        }
        zeros = (smallest == 0) ? zeros -= 1 : zeros;
        sorted_array_length = (largest + 1) - smallest - zeros;
        int *sorted_array = new int[sorted_array_length - 1];
        sorted_array[0] = smallest;
        if (smallest == 0) i = 1;
        for (n = smallest; n < largest + 1; ++n) {
            if (array[n] != 0) {
                sorted_array[i] = array[n];
                i = i + 1;
            }
        }
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
        delete[] array;
        array = nullptr;
        delete[] random_array;
        random_array = nullptr;
        pause();
        /* for (n = 0; n < sorted_array_length; ++n) {  // Enable only for small numbers!
            cout << n << " - " << sorted_array[n] << endl;
        } */
        delete[] sorted_array;
        sorted_array = nullptr;
    }
    return 0;
}
