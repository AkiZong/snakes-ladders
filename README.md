Probably you have played the game “snake and ladder” before. There is an n×n grid (most commonly n = 10), where the n2 squares are numbered from 1 to n2. All players start from square one. Each takes turns to roll a dice, and move one to six steps depending on the outcome of the dice (i.e. if the current square is i, we may move to square i+1,...,i+6). After a move, if there is a ladder with its bottom in the square that we are in, we move up to the top of the ladder; on the other hand, if there is a snake with its head in the square that we are in, we have to move down to the tail of the snake. The goal is to race to the square n2 as quickly as possible.

Your friend is an amateur in designing new maps for this game. You would like to write a computer program to check whether the new maps are good. There are a couple things that we would like to check. First, we would like to check whether it is possible at all to reach square 100 (it may be impossible if there are too many snakes). Then, we would like to compute how many turns it takes in the worst case to reach square 100 (which could be infinity).

Input: The first line will have three integers, n, l and s, where 2 ≤ n ≤ 1000 is the side length of the grid, and 0 ≤ l ≤ 500000 is the number of ladders in the map, and 0 ≤ s ≤ 500000 is the number of snakes in the map. The next l lines are about the locations of the ladders. Each line will have two numbers 2 ≤ b < u ≤ n2, where b is the bottom square of the ladder and u is the top square of the ladder (note that there is no ladder bottom at square 1). The next s lines are about the locations of the snakes. Each line will have two numbers n2 −1 ≥ h > t ≥ 1, where h is the head square of the snake and t is the tail square of the snake (note that there is no snake head at square n2). You can assume that the ladders and the snakes do not share the same square.

Output: There is only one output for each test case. If it is impossible to reach square n2, output “impossible”. Otherwise, if it is possible to reach square n2, output the largest possible number of steps to reach square n2 if this number is finite, or output “infinity”.

Sample Input 1: 10 0 6 99 1 98 2 97 3 96 4 95 5 94 6 
Sample Output 1: impossible 

Sample Input 2: 10 0 1 99 1 
Sample Output 2: infinity 

Sample Input 3: 10 0 0 
Sample Output 3: 99
# snakes-ladders
