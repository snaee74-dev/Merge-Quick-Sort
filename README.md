# Merge-Quick-Sort
How different sorting method (merge,quick)perform under varying input conditions
# Merge Sort vs Quick Sort (Comparison Count)

A C program that sorts N records using Merge Sort and Quick Sort, counts the element comparisons of each, and merges a new sorted batch of M records into the sorted array without re-sorting.

## Input (input.txt)
```
N M
N integers (any order)
M integers (already sorted)
```

## How to Run
```
gcc main.c -o main
./main
```

## Output
- Merge Sort result
- Quick Sort result
- Merge Comparisons
- Quick Comparisons
- Updated Array (after merging the new batch)

## Counting Rule
- **Merge Sort:** one comparison for each `array[i] <= array[j]` check inside `merge()`.
- **Quick Sort:** one comparison for each element-vs-pivot check inside `partition()` (last element as pivot).

## Time & Space Complexity

| Part | Time | Extra Space |
|---|---|---|
| Merge Sort | O(N log N) in best, average and worst case | O(N) for the `temp` array |
| Quick Sort | Best/Average: O(N log N), Worst: O(N²) | Average: O(log N), Worst: O(N) for recursion stack |
| Batch Merge | O(N + M) | O(N + M) for the result array |

**Notes:**
- Merge Sort always splits the array in half, so its time stays O(N log N) for every input.
- Quick Sort with the last element as pivot hits its worst case on already sorted (or reverse sorted) input, because each partition removes only one element. That gives (N−1) + (N−2) + ... + 1 = O(N²) comparisons.
- The new sorted batch is merged using two pointers in a single pass, so the whole array is not sorted again.
