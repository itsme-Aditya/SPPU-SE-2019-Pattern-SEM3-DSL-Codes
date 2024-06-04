words = []
word = ""
string = input("Enter your string: ")
for i in string:
    if i != " ":
        word = word + i
    else:
        words.append(word)
        word = ""

if word != "":
    words.append(word)

def longest_word():  
    longest = ""
    for i in words:
        if len(i) > len(longest):
            longest = i

    print(f"Longest word is {longest}")


def palindrome():
    string = input("Enter a word to check palindrome: ")
    w = ""
    for j in range(len(string), 0, -1):
        w += string[j-1]
          
    if string == w:
        print(f"{string} is palindrome")
    else:
        print(f"{string} is not palindrome")
        

def frequency():
    char = input("Enter character to check frequency of occurance: ")
    freq = 0
    for i in string:
        if i == char:
            freq += 1
    print(f"The occurance of character '{char}' is {freq} times.")

def first():
    sub = str(input("Enter substring to find index of: "))
    index = string.find(sub)
    if index == -1:
        print(f"The substring '{sub}' does not exist in the main string.")
    else:    
        print("The index of first appearance of the substring is ", index)


def occurance():
    word_count = {}
    for i in words:
        if i in word_count:
            word_count[i] += 1
        else:
            word_count[i] = 1
    
    for j, k in word_count.items():
        print(f"Occurance of {j}:{k} times.")


while True:
    print("1) Display the word with longest length.")
    print("2) Determine the occurance of a particular character in the string.")
    print("3) Check whether the entered string is palindrome or not.")
    print("4) Dispaly the index of first occurance of a substring.")
    print("5) Count the occurances of each word in given string.")
    print("6) Exit\n\n")
    ch = int(input("Enter your choice: "))
    print("\n")
    if ch == 1:
        longest_word()
    elif ch == 2:
        frequency()
    elif ch == 3:
        palindrome()
    elif ch == 4:
        first()
    elif ch == 5:
        occurance()
    elif ch == 6:
        quit()    
    else:
        print("Wrong choice entered. TRY AGAIN!")
