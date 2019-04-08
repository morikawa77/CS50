from nltk.tokenize import sent_tokenize


def lines(a, b):
    # returns lines in common from string 1 and 2
    return set(dict.fromkeys(a.splitlines())) & set(dict.fromkeys(b.splitlines()))


def sentences(a, b):
    # returns sentecenes in common from string 1 and 2
    return set(dict.fromkeys(sent_tokenize(a))) & set(dict.fromkeys(sent_tokenize(b)))
    
    
def substrings(a, b, n):
    # list of substrings in a
    list_a = get_substrings(a, n)
    # list of substrings in b
    list_b = get_substrings(b, n)
    # returns substrings in common from string 1 and 2
    return list_compare(list_a, list_b)
    
    
def get_substrings(a, n):
    output = []
    temp = len(a) - n + 1

    for i in range(temp):
        output.append(a[i:n + i])
    # returns a list of substrings
    return output


def list_compare(a, b):
    output = []

    for i in a:
        for j in b:
            if i == j and j not in output:
                output.append(j)
    # returns a list of substrings matched
    return output