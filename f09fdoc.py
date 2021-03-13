import sys

newfile = ""

if len(sys.argv) >= 2:
    file = open(sys.argv[1])
    lines = file.readlines()

    for num, line in enumerate(lines):
        if line[0] == "~":
            comment = line.split()[1]
            newfile += "#### " + comment + "\n"

            new_syntax = "```c++\n"
            num += 1
            while (next_line := lines[num]).rstrip() != "":
                new_syntax += next_line
                num += 1

            newfile += new_syntax + "\n"
            newfile += "```\n"


if len(sys.argv) >= 3:
    file = open(sys.argv[2], "w")
    file.write(newfile)
else:
    print(newfile)
