#include "heap.h"
#include <stdlib.h>

using namespace std;

int main()
{
    heap<int> h;

    int SOME_NUMBER = 10;

    for(int i=0; i<SOME_NUMBER; i++)
        h.insert(rand()%100);

    while(h.size() > 0) {
        cout << h.max() << endl;
        h.remove_max();
}
}
