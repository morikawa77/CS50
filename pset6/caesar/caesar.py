from sys import argv, exit
from cs50 import get_string


def main():
    # if args diff 2
    if len(argv) != 2:
        print("Usage: python caesar.py k")
    
    # key get second arg
    k = int(argv[1])
    # get string to cipher
    plaintext = get_string("plaintext: ")
    print("ciphertext: ", end="")
    
    # calculate ciphertext
    for ch in plaintext:
        if not ch.isalpha():
            print(ch, end="")
            continue

        ascii_offset = 65 if ch.isupper() else 97

        pi = ord(ch) - ascii_offset
        ci = (pi + k) % 26

        print(chr(ci + ascii_offset), end="")
        
    # prints newline
    print()
    
    # exit
    return 0


if __name__ == "__main__":
    main()