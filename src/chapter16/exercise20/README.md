#16.20 T9
On old cell phones, users typed on a numeric keypad and phone would provided a list of words that matches these numbers. Each digit mapped to a set of 0-4 letters. Implement an algorithm to return a list of matching words given a sequence of digits. You are provided a list of valid words (provided in whetever data structure you'd like). The mapping is shown in the diagram below.

    [     1] [abc 2] [def  3]
    [ghi  4] [jkl 5] [mno  6]
    [pqrs 7] [tuv 8] [wxyz 9]


## Brute force

We generate the list of possible words matching the sequence. We then check if a word is in the 'dictionary' and then add to the list of words

## Smart: we use Tries
To restrict the search to all real words: We use a prefix tree built on top of the dictionary, which uses as alphabet the T9 keypad.
- for each word in dictionary:
    - create a t9 representation
    - fill the trie


## Smart ^ 2: Hashtable
We can reuse the trie setup to prepare a multi-hashmap <string t9, list<string>> which map to a t9 strings all the words with the same representation.
