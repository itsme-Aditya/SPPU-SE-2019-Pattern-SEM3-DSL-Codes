print("Q) In second year computer engineering class, group A student's play cricket, group B students play badminton and group C students play football.\nWrite a Python program using functions to compute following:\na) List of students who play both cricket and badminton\nb) List of students who play either cricket or badminton but not both\nc) Number of students who play neither cricket nor badminton\nd) Number of students who play cricket and football but not badminton.")
secomp = []
cric = []
bad = []
foot = []

def set_secomp():
    n = int(input("Enter number of students in SE Comp:"))
    for i in range(0, n):
        elem = str(input("Enter names of students in SE Comp:"))
        secomp.append(elem)


def set_cric():
    n = int(input("Enter number of students playing cricket:"))
    for i in range(0, n):
        elem = str(input("Enter names of students who play cricket:"))
        cric.append(elem)


def set_bad():
    n = int(input("Enter number of students playing badminton:"))
    for i in range(0, n):
        elem = str(input("Enter names of students who play badminton:"))
        bad.append(elem)


def set_foot():
    n = int(input("Enter number of students playing football:"))
    for i in range(0, n):
        elem = str(input("Enter names of students who play football:"))
        foot.append(elem)


def intersection(list1, list2):
    list3 = []
    for i in list1:
        if i in list2:
            list3.append(i)
    return list3    


def one_of_two(list1, list2):
    list3 = []
    for i in list1:
        if i not in list2:
            list3.append(i)
    for j in list2:
        if j not in list1:
            list3.append(j)        
    return list3


def union(list1, list2):
    list3 = []
    for i in list2:
        list3.append(i)
    for j in list1:
        if j not in list2:
            list3.append(j)
    return list3


def diff(lst1,lst2):
    lst3=[]
    for i in lst1:
        if i not in lst2:
            lst3.append(i)
    return lst3


def c_itn_b():
    cric_and_bad = intersection(cric, bad)
    print("a) Students who play both cricket and badminton:", cric_and_bad)


def c_or_b():
    cric_or_bad = one_of_two(cric, bad)
    print("b) Students who play either cricket or badminton but not both:", cric_or_bad)


def c_union_b():
    c_and_f = union(cric, bad)
    only_foot = diff(foot, c_and_f)
    print("c) Students who neither play cricket nor badminton:", only_foot)
    print(len(only_foot))
    

def c_itn_f():
    cric_and_foot = intersection(cric, foot)
    cric_and_foot_no_bad = diff(cric_and_foot, bad)
    print("d) Students who play cricket and football but not badminton: ", cric_and_foot_no_bad)
    print(len(cric_and_foot_no_bad))      


while True:
    print("\n********************MENU********************")
    print("1) Accept students\n2) List of students who play both cricket and badminton\n3) List of students who play either cricket or badminton but not both\n4) Number of students who play neither cricket nor badminton\n5) Number of students who play cricket and football but not badminton.\n6) Exit")
    ch = int(input("Enter your choice: "))
    if ch == 1:
        set_secomp()
        print("Students in SE Comp:", secomp)
        set_cric()
        print("Students who play cricket:", cric)
        set_bad()
        print("Students who play badminton:", bad)
        set_foot()
        print("Students who play football:", foot)
    elif ch == 2:
        c_itn_b()
    elif ch == 3:
        c_or_b()
    elif ch == 4:
        c_union_b()
    elif ch == 5:
        c_itn_f()
    elif ch == 6:
        print("**********THANK YOU**********")
        quit()
    else: 
        print("Wrong input, try again")    
