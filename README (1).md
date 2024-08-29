
# Trie Auto-Completion

This repository contains an implementation of Trie data structure for auto-completion of words based on a given prefix. The code is written in C++ and uses a Trie data structure to efficiently store and retrieve words. The program allows the user to insert a set of words into the Trie and then provides auto-completion suggestions based on a given prefix



# Functionality

The program provides the following functionality:

**insert**: Inserts a word into the Trie. It traverses the Trie, creating new nodes as necessary, and marks the last node as the end of a word.

**isLastNode**: Checks if a given node is the last node in the Trie. Returns true if all children of the node are NULL, indicating the end of a word.

**suggestionsRec**: Recursive function that prints all auto-completion suggestions for a given node in the Trie. It traverses the Trie from the current node and recursively calls itself for each child node, printing the prefix along the way.

**printAutoSuggestions**: Prints auto-completion suggestions for a given query prefix. It traverses the Trie based on the characters in the prefix, and then calls suggestionsRec to print all suggestions starting from the last matching node.


# Sample Input/Output
```bash
 PS C:\Users\dhars> cd .\Desktop\DSA\
PS C:\Users\dhars\Desktop\DSA> g++ .\main.cpp
PS C:\Users\dhars\Desktop\DSA> .\a.exe
Enter the No of String to insert
5
hello
help
he
hobby
happy


Enter the no of string to get AutoSuggestions
3
h

happy
he
hello
help
hobby
----------------------
help

help
----------------------
he

he
hello
help
----------------------


```

In the above example, we inserted five strings into the Trie: "hello," "help," "he," "hobby," and "happy." Then, we requested auto-suggestions for three query prefixes: "he," "hobby," and "happy." The program provided the corresponding auto-completion suggestions for each query.
