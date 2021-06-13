# LeetCode-Solutions

A folder to store my LeetCode solutions

## [79. Word Search (medium)](https://leetcode.com/problems/word-search/)
Given an `m x n` grid of characters `board` and string `word`, return `true` if `word` exists in the grid. 


## [289. Game of Life (medium)](https://leetcode.com/problems/game-of-life/)
Given a grid of size n x m, apply the four rules for each cell:
1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
2. Any live cell with two or three live neighbors live on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction. 

## [394. Decode String (medium)](https://leetcode.com/problems/decode-string/)

Given a compressed string, i.e. "3[a]2[2[ab]f]", output the decompressed string "aaaababfababf"
**Time Complexity**: A bit unsure with this but... O(n \* m) where
n = input.length
m = value of number in the input
This seems to be pseudopolynomial time

**Space Complexity**: O(n \* m) ?

## [654. Maximum Binary Tree (medium)](https://leetcode.com/problems/maximum-binary-tree/)

Given an array of integers, construct a binary tree where the root node is the largest value
of the array and it's left nodes are all values left of that and the right nodes are to the right of
the array

## [792. Number of Matching Subsequences (medium)](https://leetcode.com/problems/number-of-matching-subsequences/)

Given an array of words and a target string. Find the number of matching **subsequences** where a word _w_ is considered a subsequence of word _target_ if you can remove any number of characters from _target_ to get _w_.

n = targetString.size()
m = arr.size()

**Time Complexity**: O(n \* m)
**Space Complexity**: O(n + m)
