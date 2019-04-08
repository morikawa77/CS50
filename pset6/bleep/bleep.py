from cs50 import get_string
from sys import argv

# Words in banned words list
bannedwords = set()
instrings = str()


def main():
    # if args diff 2
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)
        
    while True:
        instrings = get_string("What message would you like to censor?\n")
        if len(instrings) > 0:
            break
    
    # load banned words
    loaded = load(argv[1])
    
    # Checks if string in instrings are in banned words
    for uniquestring in instrings.split():
        if uniquestring.lower() not in bannedwords:
            print(uniquestring, end=" ")
        else:
            n = len(uniquestring)
            print("*" * n, end=" ")
    # prints a newline after string before close program
    print()
    # unload list
    unload()
    
    
def load(list):
    # Load list of banned words
    file = open(list, "r")
    for line in file:
        bannedwords.add(line.rstrip("\n"))
    file.close()
    return True
  
    
def unload():
    # Unload list of banned words
    return True


if __name__ == "__main__":
    main()
