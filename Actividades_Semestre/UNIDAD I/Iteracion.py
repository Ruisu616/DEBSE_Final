lst = ["a", "s"]

output = []

for i in range(0, len(lst)):
    for j in range(0, len(lst)):

        if (i != j):
            output.append((lst[i], lst[j]))

print(output)