print("Q) Write a Python program to store marks scored in subject 'Fundamental of Data Structure' by N students in the class. Write functions to compute following:\na) The average score of class\nb) Highest score and lowest score of class\nc) Count of students who were absent for the test\nd) Display mark with highest frequency")
marks  = []

def acc():
    n = int(input("Enter number of students in class:"))
    for i in range(0, n):
        elem = int(input("Enter marks scored by a student in FDS subject:"))
        marks.append(elem)
    print(f"Marks scored in FDS subject: {marks}")


def absent():
    abs = 0
    for i in marks:
        if i == -1:
            abs +=1
    print(f"Number of students who were absent for the test: {abs}")    




def aver():
    sum = 0        
    for i in marks:
        if i != -1:
            sum = sum + i
    print(f"Average marks scored by students: {sum / len(marks)}")                


def maximum():
    max = marks[0]
    for i in range(0, len(marks)):
        if max < marks[i]:
            max = marks[i]
    print(f"Maximum marks scored: {max}")


def minimum():
    min = 0
    for i in marks:
        if i != -1:
            min = i
            break    


    for i in range(0, len(marks)):
        if min > marks[i] and marks[i] != -1:
            min = marks[i]
    print(f"Minimum marks scored: {min}")


def frequency():
    freq = 0
    for i in range(0, len(marks)):
        count = 1
        if marks[i] != -1:
            for j in range(0, len(marks)):
                if marks[i] == marks[j]:
                    count += 1
            if freq < count:
                freq = count
                variable = marks[i]
    print(f"Marks with highest frequency is(marks, frequency): {variable, freq}")


while True:
    print("\n********************MENU********************")
    print("1 : Accept FDS Marks\n2 : Average score of class\n3 : Highest score and lowest score of class\n4 : Count of students who were absent for the test\n5 : Display mark with highest frequency\n6 : Exit\n")
    ch = int(input("Enter your choice:"))
    if ch == 1:
        acc()
    elif ch == 2:
        aver()
    elif ch == 3:
        maximum()
        minimum()
    elif ch == 4:
        absent()
    elif ch == 5:
        frequency()
    elif ch == 6:
        print("End of program")
        quit()
    else:
        print("Wrong choice entered !! Try again")
