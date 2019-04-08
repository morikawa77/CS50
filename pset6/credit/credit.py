from cs50 import get_int
from math import floor


def main():
    # declaring vars
    digit1 = 0
    digit2 = 0
    count = 0
    sumofdoubleodds = 0
    sumofevens = 0
    
    # get credit card number from user
    ccnumber = get_int("Number: ")
    
    # if ccnumber > 0 verify with Luhn’s algorithm
    while ccnumber > 0:
        digit2 = digit1
        digit1 = ccnumber % 10

        if count % 2 == 0:
            sumofevens += digit1
        else:
            multiple = 2 * digit1
            sumofdoubleodds += (multiple // 10) + (multiple % 10)

        ccnumber //= 10
        count += 1

    # if is valid
    isvalid = (sumofevens + sumofdoubleodds) % 10 == 0
    firsttwodigits = (digit1 * 10) + digit2

    # print card flag if valid
    if digit1 == 4 and 13 <= count <= 16 and isvalid:
        print("VISA\n")
    elif 51 <= firsttwodigits <= 55 and count == 16 and isvalid:
        print("MASTERCARD\n")
    elif firsttwodigits == 34 or 37 and count == 15 and isvalid:
        print("AMEX\n")
    else:
        print("INVALID\n")


if __name__ == "__main__":
    main()