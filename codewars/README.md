# Codewars
[Codewars](https://www.codewars.com/dashboard)

Currently my favourite site, that has problems that are a bit more technical / real-worldly than others.

## Solutions
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
