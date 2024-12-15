# The Fast Square Root  

This is a fast square root program that was inspired by fast inverse square root from [Quake III arena](https://github.com/id-Software/Quake-III-Arena/blob/master/code/game/q_math.c#L552).
While it calculates inverse of sqare root, I tried to find alternative formula to get square root.  
  

It basically shifts the bit pattern left once, making the exponent roughly half.
To shift bits of floating point(where shift operator is not available), we use bit-level hacking through pointer.
Even though it's technically an Undefined Behavior according to the statndard(see [my question](https://www.reddit.com/r/cpp_questions/comments/z8s3jf/ub_in_access_to_an_object_through_a_pointer_of_a/)),
it seems working on most cases(tested several versions of gcc/clang/msvc in mac/linux/windows).  
Then it adds a special magic number to adjust the exponent and mantissa.
The magic number must consider when exponent field is odd, where the 1 in LSB is moved into the MSB of mantissa.
Also, magic number must consider that this altorithm uses Newton's approximation method.
  
  
I found the optimal magic number via both [mathametical method](https://github.com/awidesky/MyPapers/blob/master/fsqrt/wolframs.txt) and [brute force](https://github.com/awidesky/RangedLoopAsyncTest/blob/fsqrt/fsqrt/main.cpp).
After I did that in high school, I uploaded some test codes in github a few years later,
and tried to make a well document about it but forgot about it till today.
[Here](https://o365inha-my.sharepoint.com/:b:/g/personal/awidesky_office_inha_ac_kr/EXI0-3DdcApPoP6wLM0uWIYBiruQfq8RBREdEVuJY_ddzA?e=1cXQEL) is the note I wrote back when I studied this algorithm.  


# Is it 'still' fast?
Unfortunately, not always.
In some [cases](https://github.com/awidesky/MyPapers/blob/master/fsqrt/test/iterationtest/code/speed_test.cpp) it's still quite fast, but it can't be faster when compared to native `sqrtss` instruction in SSE.


# Usage  
```
float  fast_sqrtf(float);
double fast_sqrtd(double);
```
Each will return the sqare rooted value of the input.  
Just put a positive value in the function and have fun!
(note: a screenshot is provided in oss.inha project readme, and also in project folder)

# Build(requires shell and GNU make)
* `make` will print help message.
* `make build` will build shared and static library into ./build directory.
* `make test` will build the library and generate test programs into ./testbuild directory.  
After that, please do `cd testbuild`(so that `./link_runtime` could find it's shared library) and run `./link_compile` or `./link_runtime`