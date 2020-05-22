#Levenshtein and Damerau-Levenshtein algoritm
import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from time import clock

def printtable(s1, s2, matrix):
    print("end=       ")
    for i in range(len(s1)):
        print(s1[i], "end=  ")
    print()
    print(" ",matrix[0])
    for i in range(len(s2)):
        print(s2[i], matrix[i+1])

def Livenshtein(s1, s2):
    matrix = []
    for i in range(len(s2) + 1):
        matrix.append([0] * (len(s1) +1))
    for i in range(1, len(s2)+1 ):
        matrix[i][0] = i
    for i in range(1, len(s1)+1):
        matrix[0][i] = i
    for i in range (1, len(s1)+1):
        for j in range (1, len(s2)+1):
            cost = 0 if s2[j - 1] == s1[i - 1] else 1
            matrix[j][i] = min(matrix[j-1][i]+1,
                               matrix[j][i-1]+1,
                               matrix[j-1][i-1] + cost)
   # printtable(s1,s2, matrix)

def DamLivenshtein(s1, s2):
    matrix = []
    string = s1
    
    for i in range(len(s2) + 1):
        matrix.append([0] * (len(s1) +1))
    for i in range(1, len(s2)+1 ):
        matrix[i][0] = i
    for i in range(1, len(s1)+1):
        matrix[0][i] = i
    for i in range (1, len(s1)+1):
        for j in range (1, len(s2)+1):
            cost = 0 if s2[j - 1] == s1[i - 1] else 1
            if j>1 and i>1 and s1[i - 1] == s2[j - 2] and s1[i - 2] == s2[j - 1]:
                matrix[j][i] = min(matrix[j - 1][i] +1,
                               matrix[j][i - 1] +1,
                               matrix[j - 1][i - 1] + cost,
                               matrix[j - 2][i - 2] +1)
            else:
                matrix[j][i] = min(matrix[j - 1][i] +1,
                                   matrix[j][i - 1] +1,
                                   matrix[j - 1][i - 1] + cost)
  #  printtable(s1,s2, matrix)

def RecLivenshtein(s1, s2):
    if s1 == "":
        return len(s2)
    if s2 == "":
        return len(s1)
    cost = 0 if s1[-1] == s2[-1] else 1

    result = min(RecLivenshtein(s1[:-1], s2) + 1,
                 RecLivenshtein(s1, s2[:-1]) + 1,
                 RecLivenshtein(s1[:-1], s2[:-1]) + cost)
    
    return result    
'''
string1 = input("Input first string: ")

string2 = input("Input second string: ")

print("Левинштеин:")
start = clock()
Livenshtein(string1, string2)
print(clock() - start)
print("Дамерал-Левинштеин:")
start = clock()
DamLivenshtein(string1, string2)
print(clock() - start)
print("Левинштеин Рекурсивный:")
start = clock()
RecLivenshtein(string1, string2)
print(clock() - start)
'''
x = [7, 8, 9]
plt.ylabel('time')
plt.xlabel('count')
plt.grid(True)
a1 = plt.plot(x,[0.0014, 0.0013, 0.0012], "red" )
a2 = plt.plot(x,[0.0021, 0.0019, 0.0029], "blue" )
a3 = plt.plot(x,[0.033649, 0.014498, 0.00542], "green" )
plt.show()
plt.savefig("Test.png")

