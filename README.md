# Concordance-of-a-Text-File

This is a program to that processes a text file and produces a concordance: an 
alphabetical listing of the words in the file and the number of times each word appears. The 
program will ignore any non-alphabetical character and punctuations. The software will store 
the concordance in a text file and print the output to the user

# Relevant information

A concordance of a text file can be described as an alphabetical list of the unique words in the text file. 

The program will start with a file that contains the words. The file might contain numbers, non alphabetical characters, white space, newline, and punctuation. All the characters that were mentioned will be ignored by the program and won’t read them and will be used as delimiters. These delimiters will be used to determine how to split a string into different words. Then the software will start comparing each word with the whole file until it gets the minimum value (a word that starts with letter “a”, mostly, or any letter after “a” if it does not exist). So, to sum it up, we can say we are creating a concordance of a text file

