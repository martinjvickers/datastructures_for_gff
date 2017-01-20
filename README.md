# datastructures_for_gff
Some Datastructures for solving problems when working with very large GFF files. These aren't full programs, just examples that can be used to solve a task.

## Override Hash

The purpose of this small program is to override the hash function of a unordered map so that two gff features (defined only by the feature reference, start and end position) will be deemed the same when added to an unordered map. This is useful, amoung other things, for counting the number of the same feature.

### Compiling and running

```
martin@x250:~/$ g++ -std=c++0x override_hash.cpp 
martin@x250:~/$ ./a.out 
chr2 322 363 1
chr1 322 363 3
chr1 322 362 1
```
