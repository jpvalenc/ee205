template <typename T>
void BubbleSortVector<T>::sort() {
    // Lookup the bubble sort algorithm online.
    //
    // The algorithm is so-named "bubble sort" because
    // lesser valued elements "bubble up" to the "top" (front)
    // of the array/container/sequence.
    //
    // You'll have to perform a lot of swaps for the algorithm.
    //
    // You are free to write your own swap helper function
    // if you so desire.

    bool sorted = false;

    while (!sorted) {
        int i;
        for (i = 0; i < (*this).size(); i++) {
            bool swapped;

            if ((*this)[i] > (*this)[i + 1]) {
                swap(&(*this)[i], &(*this)[i + 1]);
                swapped = true;
            }

            if (i == (*this).size() - 1 && swapped == false) {
                sorted = true;
            } else {
                swapped = false;
            }
        }
    }


    // arr[j] (*this)[j]
    // n (*this).size()
    // swap(&arr[i],&arr[i+1]) swap(&(*this)[i],&(*this)[i+1])
}
