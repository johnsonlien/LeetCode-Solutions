# LeetCode-Solutions

A folder to store my LeetCode solutions

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
