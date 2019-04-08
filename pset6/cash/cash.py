from cs50 import get_float
from math import floor


def main():
    # get value greater than 0
    while True:
        cash = get_float("Change owed: ")
        # trasnform value in cents
        cents = floor(cash * 100)

        if cents > 0:
            break

    # calculate how many 25c coins
    quarters = cents // 25
    # calculate how many 10c coins
    dimes = (cents % 25) // 10
    # calculate how many 5c coins
    nickels = ((cents % 25) % 10) // 5
    # calculate how many 1c coins
    pennies = ((cents % 25) % 10) % 5

    print(f"{quarters + dimes + nickels + pennies}")


if __name__ == "__main__":
    main()