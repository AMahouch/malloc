# malloc

Implemented own version of C's dynamic memory allocation library function ```malloc``` and ```free``` by interacting with the operating system and perform efficient heap management on behalf of a user process. This is achieved through 4 libraries, each of which representing a heap management scheme:

* ```First Fit``` starts at the beginning of the heap, denoted by the heapList pointer, and searches
for the first block that is available as free AND can fit the requested block size. This is
the simplest algorithm to implement, and ends if curr reaches NULL (meaning the end of
the list was reached without finding a node)
* ```Next fit``` is similar to first fit, however the search starts where the previous allocated block
was allocated. In this implementation, it uses a global variable last_allocated which points
to the last allocated block and is updated each time the next fit algorithm is called.
Initially, last_allocated is NULL, meaning the algorithm runs as a first fit, returning
NULL. In iterations after that, the current pointer is set to last_allocated, and the next fit
algorithm searches for a block that is free and fits the requested size. The only caveat is
that if curr reaches NULL, it is set it back to heapList (top of the list) to catch the blocks
that were not iterated. Then, curr is checked against last_allocated and if they are equal, a
full loop has occurred and NULL is returned.
* ```Best fit``` searches for the block that when the requested block is placed in it, it leaves the
least amount of leftover space. This algorithm includes the traversal of the linked list with
a min_difference attribute that is initially set to INT_MAX. For each node, the difference
is calculated and if it is less than min_difference, then it is considered the best fit node
and updated as such. Once the algorithm has ran, curr will be set equal to that node.
* ```Worst fit``` is similar to best fit, except it selects the block with the most amount of space
leftover. This implements a max_difference integer which is initially 0 and updated for
each node, When each node is checked, it possibly updates the max_difference and then
saves that node. Then, the worst fit node is returned.

This program also implements ```calloc``` and ```realloc```. Within malloc and free are several subroutines, like block splitting and block coalescing.
Block splitting occurs when a free block can fit an incoming request with excess, so it splits into
two blocks with the remaining excess considered as a free block. Block coalescing occurs when
two consecutive free blocks are joined to create one large free block.

## Demo
![best_fit SS](https://github.com/AMahouch/malloc/assets/97981126/529f0879-be44-4d36-8be9-2dad6ce50377)



![first_fit SS](https://github.com/AMahouch/malloc/assets/97981126/f380f1d1-c49a-4e01-b0d3-7bdff778a763)


## Building and Running
The code compiles into four shared libraries and six test programs. To build the code, change to your top level assignment directory and type:
```
make
```
Once you have the library, you can use it to override the existing malloc by using
LD_PRELOAD. The following example shows running the ffnf test using the First Fit shared library:
```
$ env LD_PRELOAD=lib/libmalloc-ff.so tests/ffnf
```

To run the other heap management schemes replace libmalloc-ff.so with the appropriate library:
```
Best-Fit: libmalloc-bf.so
First-Fit: libmalloc-ff.so
Next-Fit: libmalloc-nf.so
Worst-Fit: libmalloc-wf.so
```
