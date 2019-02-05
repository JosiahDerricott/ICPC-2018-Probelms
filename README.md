
# Paper Cuts

Tito has a paper strip with some letters written on it. He would like to rearrange the letters to
form some other word. He does this by making some number of vertical cuts and then rearranging
the remaining strips of paper. For example, a strip with letters

*abbaaddccee*

can be cut into four pieces,

*abb | aa | ddcc | ee*

and be put together in a different order:

*aaabbeeddcc*

Given Tito’s paper strip and the word he wants to form, determine the minimum number of cuts
that Tito needs to make in order to construct the desired word.

## Input

The first line of input contains a single string of lowercase letters, representing Tito’s paper strip.

The second line of input contains a single string of lowercase letters, representing the word Tito
wants to form by rearranging the letters.

It is guaranteed that the two lines consist of the same number of letters between 1 and 18 (inclusive),
and that the letters consisting the two lines are exactly the same, i.e., it is always possible to reach
Tito’s desired word by rearranging the letters in the paper strip.

## Output

Print, on a single line, the minimum number of cuts that Tito has to make.

```
Input 1: abbaaddccee  |   Output: 3
Input 2: aaabbeeddcc  |
```
```
Input 1: abba         |   Output: 3
Input 2: abba         |
```
