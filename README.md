## Counting suffixes
### Statement   

Please implement a data structure D to efficiently support four operations:

I s: Inserts the string s into D. No changes are made if s is already in D.
E s: Erases the string s from D. No changes are made if s is not in D.
C s: Counts the number of strings in D that end with the suffix s.
R: Resets D, that is, removes all strings from D.

### Input

Input consists of several operations over an initially empty D. Assume that each s is made up of between 1 and 100 lowercase letters. At no moment the sum of the sizes of the strings stored in D will be larger than 106.

### Output

Print the result of each C s operation, and three dashes for each R operation.
