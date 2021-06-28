import re
def program(int):
    pattern = re.compile('(100{1,}1{1,}|01){1,}')
    result = pattern.fullmatch(int)
    if result == None:
        return -1
    else:
        return 1

num = int(input(""))
search = []
for i in range(num):
    code = input()
    search.append(code)

print("")

for i in range(num):
    cmp = search[i]

    if program(cmp) == 1:
        print("DANGER")
    else:
        print("PASS")