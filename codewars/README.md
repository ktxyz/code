# Codewars
[Codewars](https://www.codewars.com/dashboard)

Currently my favourite site, that has problems that are a bit more technical / real-worldly than others.

# Solutions
## Kata 4
### Mystery Function
[Kata Link](https://www.codewars.com/kata/56b2abae51646a143400001d)

#### Difficulty
Kata 4 - In my opinion should be Kata 5.

#### Languages
* C++

#### Solution
We can simulate the behaviour in $O(\log{}N)$.

#### Resources
[Gray code on wikipedia](https://en.wikipedia.org/wiki/Gray_code)

### Getting along with integer partitions
[Kata Link](https://www.codewars.com/kata/55cf3b567fc0e02b0b00000b/cpp)

#### Difficulty
Kata 4  - I was kinda dissapointed this is a simple coding problem

#### Languages
* C++

#### Solution
We can simply generate the prod list, just have to do so in a bit more optimized way than pure bruteforce.

My approach to this was to build it from previous results. We can observe that number $\text{prod}(n)$ will obviously contain $\text{prod}(n - 1)$. When we move from $n$ to $n + 1$ we add additional 1 to every partition. 

If we layout the partitions as simply number followed by ones like: 

$6 = [[1, 1, 1, 1, 1, 1], [2, 1, 1, 1, 1], [3, 1, 1, 1], [4, 1, 1], [5, 1], [6]]$

we can see that

$\text{prod}(6) = \text{mulp}(\text{prod}(1), 5) + \text{mulp}(\text{prod}(2), 4) + \text{mulp}(\text{prod}(3), 3) + \text{mulp}(\text{prod}(4), 2) + \text{mulp}(\text{prod}(5), 1) + [6]$

where $\text{mulp}$ is a result of multiplying each element of first argument by second argument.

I was kinda hoping this would have some cool math solution, since Range is possible to get with simple formula(look math.stackexchange post):

$
    \max(\text{prod}(n)) = \left\{\begin{array}{lr}
        3^k, & \text{for } n = 3k \\
        4 * 3^{k - 1}, & \text{for } n = 3k + 1\\
        2 * 3^k, & \text{for } n = 3k + 2\\
        \end{array}\right.
$

But It seems its not possible (or at least neither I nor anyone from solutions came up with it).

#### Resources
[Partitions on wikipedia](https://en.wikipedia.org/wiki/Integer_partition)

[Math stackexchange post about largest product](https://math.stackexchange.com/questions/1760268/partitions-of-a-number-with-greatest-product)

### Square into trees. Protect trees!
[Kata Link](https://www.codewars.com/kata/54eb33e5bc1a25440d000891/cpp)

#### Difficulty
Kata 4 - In my opinion should be Kata 5.

#### Languages
* C++

#### Solution
Just bruteforce solution.

#### Resources
None

### Sum of Perfect Squares
[Kata Link](https://www.codewars.com/kata/5a3af5b1ee1aaeabfe000084/cpp)

#### Difficulty
Kata 4 

#### Languages
* C++

#### Solution
Nice, simple (with access to internet at least) problem. There are only 4 possible solutions since all numbers can be expressed as sum of 4 squares.

##### Case 1
We just have to check if number is a perfect square.

##### Case 2
To be representable as sum of 2 squares, number can't have any prime factor that is congruent to $3 \mod 4$ with an odd factor.

##### Case 3
Almost every number can be represented with 3 squares. Only numbers in form $4^a(8b + 7)$ can't.

##### Case 4
Else.

#### Resources
[2 squares case](https://en.wikipedia.org/wiki/Sum_of_two_squares_theorem)
[3 squares case](https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem)
[4 squares case](https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem)

### Range Extraction
[Kata Link](https://www.codewars.com/kata/51ba717bb08c1cd60f00002f/cpp)

#### Difficulty
Kata 4 - should be Kata 5 100%

#### Languages
* C++

#### Solution
It's very basic implementation

#### Resources
Nothing.

### Roman Numerals Helper
[Kata Link](https://www.codewars.com/kata/51b66044bce5799a7f000003/cpp)

#### Difficulty
Kata 4 - should be Kata 5 100%

#### Languages
* C++

#### Solution
It's very basic implementation. And also boring.

#### Resources
Nothing.

### Twice Linear
[Kata Link](https://www.codewars.com/kata/5672682212c8ecf83e000050/cpp)

#### Difficulty
Kata 4 

#### Languages
* C++

#### Solution
This is pretty nice task. My solution is memoization + doing some buffering to make sure that we have the smallest n values at least. I think using single priority_queue/set would be better so we don't have to do over-computing. 

#### Resources
Nothing.

### Factorial Trail
[Kata Link](https://www.codewars.com/kata/55c4eb777e07c13528000021)

#### Difficulty
Kata 4 

#### Languages
* C++

#### Solution
This is also a pretty nice task. 

So, the solution for the base 10 is pretty well know. For a 0 at the end, the number has to be divisible by 10. And for that to be true, it has to be divisible by 2 and 5. In any factorial we can clearly see that number of 5 divisors is going to be less than of 2. And as such we just have the count of 5 factors. We can do that by dividing the number by consecutive powers of 5.

Now with different base, we generalize that requirement so for every 0 at the end, the factorial has to be divisible by base. I'm not sure if it's possible to figure out generally which power is least likely without checking each out - but that doesn't matter since base is small and we can just do that. One thing to keep track of is that powers in base decomposition can have higher powers than 1. For them we have to divide the number calculate by standard method by that power - for base 49 we need number of $7^2$ not just 7.

#### Resources
Nothing.

### Next bigger number with the same digits
[Kata Link](https://www.codewars.com/kata/55983863da40caa2c900004e/cpp)

#### Difficulty
Kata 4 

#### Languages
* C++

#### Solution
Pretty standard task. We have to observe that we want to swap first digit we can with previous larger one. Once we find that, we can sort digits tailing the swapped one.

#### Resources
Nothing.

### Snail
[Kata Link](https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1/cpp)

#### Difficulty
Kata 4 - should be 5

#### Languages
* C++

#### Solution
Simple implementation

#### Resources
Nothing.

### Sum of Intervals
[Kata Link](https://www.codewars.com/kata/52b7ed099cdc285c300001cd/cpp)

#### Difficulty
Kata 4 - should be 5 probably

#### Languages
* C++

#### Solution
Simple implementation

#### Resources
Nothing.

### Rectangle Rotation
[Kata Link](https://www.codewars.com/kata/5886e082a836a691340000c3)

#### Difficulty
Kata 4

#### Languages
* C++

#### Solution
Very nice problem.

Solution for this is quite simple, but implementation is pretty satisfying.

I'm sure there is some nicer solution, with better maths. But I'm not that good with it, especially geometry so I went the brute way.

My idea is pretty simple. Since the total height of the rectangle wont be larger than $2*10^4$ we can find number of points for every y inside the rectangle.

How do we do that? At first I thought about doing a binary search for the left side and binary search for the right side to find outmost points by using cross product to tell if it's left/right of an edge. Then I cursed myself for being stupid. We don't need to do that at all since the edges are linear, we can do linear interpolation of y to find the x.

To get total answer we simply iterate over all y (I did it in 3 parts, since edges where we check change, but my code is pretty bad) and sum all the ranges.

##### Sidenote
While looking around for some math, I found out you can solve this for any polygon with lattice points. It looks cool.

#### Resources
[How to solve this for polygons with lattice points](https://iq.opengenus.org/number-of-integral-points-inside-rectangle/)
