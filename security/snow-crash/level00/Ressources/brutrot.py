import sys

def rot_alpha(n):
    from string import ascii_lowercase as lc, ascii_uppercase as uc
    lookup = str.maketrans(lc + uc, lc[n:] + lc[:n] + uc[n:] + uc[:n])
    return lambda s: s.translate(lookup)


print("===== BrutRot.py ===== ")
start = input("Start range: ")

try:
    int(start)
    start = int(start)
except:
    print("Enter a valid number !")
    exit(1)


end = input("End range: ")

try:
    int(end)
    end = int(end) + 1
except:
    print("Enter a valid number !")
    exit(1)

string = input("String: ")

print("")

for i in range(start, end):
    print("rot(" + str(i) +'): '+ rot_alpha(int(i))(string))
