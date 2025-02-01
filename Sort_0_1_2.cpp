#include <algorithm>

void sort012(int *arr, int n)
{
    int i = 0;
    int nextZero = 0;
    int nextTwo = n - 1;

    while (i <= nextTwo)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[nextZero]);
            i++;
            nextZero++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[nextTwo]);
            nextTwo--;
        }
        else
        {
            i++;
        }
    }
}
/*
We’ll use a three-pointer approach to solve this problem

The three-pointers will be: current, zeroPos and twoPos.:
current - This will hold the position of the current element that we’re on during the iteration of the array. This will be initialised to 0.
zeroPos - This will hold the index where we will push any 0s that we may encounter. This will be initialised to 0.
twoPos - This will hold the index where we will push any 2s that we may encounter. This will be initialised to n - 1, where n is the size of the array.
We’ll iterate through the array using the current pointer. Every element is either 0, 1 or 2 so let’s see what we’ll be doing in each of these cases:
If arr[current] = 0 - In this case, we need to push the element towards the front of the array. To do that we can swap arr[current] and arr[zeroPos], then we will increase both current and zeroPos by 1.
If arr[current] = 1 - In this case, we will just increase the current by 1, since we are only concerned with push 0s to the front and 2s to the end of the array.
If arr[current] = 2 - In this case, we need to push the element towards the end of the array. Again, to do this, we’ll just swap arr[current] and arr[twoPos]. We will decrease twoPos by 1. However, in this case, we will not increase the current by 1.
What will be the condition that must be satisfied so that our loop can end? You might think that it’s when current reaches the end of the array but that’s not the case here. Let’s see why. Can you see what exactly the two pointers, zeroPos and twoPos are doing? As we go through the array, every element before zeroPos is a 0 and every element after twoPos is a 2. Also, every element after zeroPos but before the current is a 1. Therefore, all these elements are ‘sorted’. The element that remains to be sorted is the ones that lie between the indices current and twoPos. Therefore our loop will terminate when the current reaches the value of twoPos.
Now, let’s understand why we can’t increase the value of current when arr[current] = 2. 
When we swap arr[current] with arr[twoPos], we don’t know what value was initially at index twoPos (before the swap happened)
, it could be any of the values 0, 1, or 2. So, we can’t increase the value of current without checking what value was swapped with twoPos.
We didn’t have to worry about this in the case where we were swapping arr[current] with arr[zeroPos] because then we would always be swapping 0 and 1.
This is primarily because the number coming from the right (or two Posistion is unvisted yet in your iteration)

Time Complexity
O(N), where ‘N’ is the size of the array.

We are only doing a Single Pass of the array.  So Overall Time Complexity is O(N).

Space Complexity
O(1), As we are using constant space.
*/
