from cs50 import get_int


def main():
    while True:
        h = get_int("Height: ")
        w = h
        if h > 0 and h < 9:
            break

    for i in range(1, h + 1):
        nh = i
        ns = w - nh
        # print spaces without break line
        print(" " * ns, end="")
        # print left hashes
        print("#" * nh, end="")
        # print 2 spaces
        print(" " * 2, end="")
        # print right hashes
        print("#" * nh)


if __name__ == "__main__":
    main()