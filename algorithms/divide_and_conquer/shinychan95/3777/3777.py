""" Problem 3777 """
def main(x):
    one = 0
    zero = 0
    repeat = x // 2
    for i in range(repeat):
        n_one = one+zero+zero+one+1
        n_zero = zero+one+one+zero
        one = n_one
        zero = n_zero
    print(zero+one) if x%2 == 1 else print(one)

if __name__ == '__main__':
    while True:
        try:
            line = int(input())
        except EOFError:
            break
        main(line)