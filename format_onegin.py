f = open("formatted_onegin.txt", "w")
with open("onegin.txt") as file:
    for line in file:

        if "Notes to Chapter" in line:
            while "-----" not in line:
                line = file.readline()

        line = line.strip()
        line += "\n"
        line = line.replace("`", "'").replace("", "").replace("", "")

        if not line.startswith("{") and line.strip() and not line.startswith("--------") and not line.startswith("... ..."):
            f.write(line)
f.close()
