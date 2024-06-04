scores = []

def accept():
    n = int(input("Enter number of students: "))
    for i in range(0, n):
        elem = int(input("Enter scores of students: "))
        scores.append(elem)
    print("The scores of students are: ", scores)

def quicksort(list):
    if len(list) <= 1:
        return list
    else:
        pivot = list[0]
        left = [i for i in list[1:] if i < pivot]
        middle = [i for i in list if i == pivot]    
        right = [i for i in list[1:] if i > pivot]
        return quicksort(left) + middle + quicksort(right)

accept()
sorted = quicksort(scores)
print("Sorted scores: ", sorted)
