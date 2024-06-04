print("Q) Write a python program to store first year percentage of students in array. Write functions for sorting array of floating point numbers in ascending order using\na) Selection sort\nb) Bubble sort and display top five scores.")
per = []
def percent():
    n = int(input("Enter number of students in first year:"))
    for i in range(0, n):
        elem = int(input("Enter percentage of a student:"))
        per.append(elem)
    print(f"Percentage of students in first year:{per}")


def bubble():
    for i in range(0, len(per) - 1):
        for j in range(0, len(per) - 1):
            if per[j] > per[j+1]:
                temp  = per[j]
                per[j] = per[j+1]
                per[j+1] = temp
    print(f"Bubble sort: {per}")
    return per


def top():
    print("Top five percentages:")
    for i in range(len(per) -1, len(per) - 6, -1):
        print(per[i])
        
        
def selec():
    for i in range(0, len(per)):
        min = i
        for j in range(i+1, len(per)):
            if per[j] < per[min]:
                min = j
        temp = per[i]
        per[i] = per[min]
        per[min] = temp
    print(f"Selection sort: {per}")    
        
                
while True:
    print("\n1 : Accept percentages\n2 : Selection sort\n3 : Bubble sort and display top five scores\n4 : Exit\n")
    ch = int(input("Enter your choice:"))
    if ch == 1:
        percent()
    elif ch == 2:
        selec()
    elif ch == 3:
        bubble()
        top()
    elif ch == 4:    
        print("End of program")
        quit()
    else:
        print("Wrong choice entered !! Try again")
