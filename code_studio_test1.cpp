//You are given a string ‘S’ of length ‘N’. The string can be encoded using the following rules:
1) If the ‘i-th’ character is a vowel, change it to the next character in the alphabetical sequence. For example, the next character of ‘o’ is ‘p’.
2) If the ‘i-th’ character is a consonant, change it to the previous character in the alphabetical sequence. For example, the previous character of ‘h’ is ‘g’.

string encodeString(string &s, int n) 
{
    for(int i=0;i<n;i++)
    {
      if(s[i] == 97 || s[i] == 101 || s[i] == 105 || s[i] == 111 || s[i] == 117) s[i]++;
        else s[i]--;
    } 
    return s;
}

https://www.codingninjas.com/codestudio/contests/love-babbar-contest-4/problems/15544

Problem Statement
Ninja is studying binary numbers and he likes binary numbers with maximum length.
He is having an array ‘A’ containing ‘N’ positive integers. He multiplies all the array elements and finds the maximum length binary number which is not greater than this product.
Can you tell the maximum length Ninja calculated.
Example :
N = 3
A = [ 1, 3, 4 ]

Explanation : 

The product of all array elements is 12.
The maximum length binary representation is 4 and one of such representations is 1010 as 10 <= 12.
  
  
  Problem Statement
Ninja is given the task to create a perfect gift for the king. He has ‘N’ wraps to choose from which he can choose to wrap the gifts. He also has ‘M’ gifts from which he can choose the gifts for the king. To choose the gifts, he sets some rules:
1) He must select exactly one wrapper to wrap all the chosen gifts.
2) He can select one or more gifts or no gifts at all.
3) He has 2 copies of the same gift. So, he can take 0 or 1 or 2 copies of each gift.
He also has a number ‘X’. He decided to spend in such a way that the total cost is as close as ‘X’. If there are multiple answers, print the minimum one.
For example:
Let’s say you have two wrappers with cost [1, 2] and three gifts with cost [3, 4, 5] and ‘X’ = 7. In the first case, you select wrapper number ‘2’ and gift number ‘1’ and ‘3’, so your total cost will be 2 + 3 + 5 = 10. While in the second case, you select wrapper number ‘1’ and gift number ‘2’, so your total cost will be 1 + 4 = 5. So out of both the cases, second case is closer to ‘X’ as abs(7 - 5) = 2 and abs(7 - 10) = 3.
  
  Problem Statement
Given a matrix 'MAT' consisting of 'N' rows and 'M' columns. All elements in the matrix 'MAT' are non-negative integers. In one operation, you can select any row of the matrix and make all the elements in this row as 0.
Let the sum of elements in the i-th column is denoted as 'S[i]'. Your task is to find the minimum number of operations needed such that 'S[M]' <= 'S[j]' for at least one 'j' ( where 1 <= 'j' <= 'M'-1).
Note:
Please note that operations are performed on rows, and the sum is calculated on columns.
Example :
N = 3
M = 3
MAT = [ [3, 1, 2], [2, 3, 5], [3, 1, 2] ]

Initially, sum of elements in columns, S = [8, 5, 9].
If we operate on the second row, the updated array of sums S = [6, 2, 4], where S[3] <= S[1]. Hence we need at least one operation.

Return 1 as our final answer.
