""" Problem 6549 """
class Tree:
    def __init__(self):
        self.height = 0
        self.width = 0
        self.length = 0
        self.child = []
        self.parent = 0

    def set_arg(self, arr, length, parent):
        self.parent = parent
        self.length = length
        self.width = len(arr)
        self.height = min(arr)
        self.set_child(arr)

    def set_child(self, arr):
        arr = [elem-self.height for elem in arr]
        x = self.__slice_based_on(arr, 0)
        if x:
            for elem in x:
                tree = Tree()
                tree.set_arg(elem, self.length+self.height, self)
                self.child.append(tree)

    def __slice_based_on(self, arr, num):
        s = []
        indices = [i for i, x in enumerate(arr) if x == num]
        indices.append(len(arr))
        n = 0
        for i in indices:
            if i - n:
                s.append(arr[n:i])
            n = i + 1
        return s

    def get_area(self):
        return (self.height*self.width) + (self.length*self.width)

    def get_all_area_list(self):
        l = []
        l.append(self.get_area())
        for elem in self.child:
            l += elem.get_all_area_list()
        return l

    def get_largest_rectangle(self):
        return max(self.get_all_area_list())


def main(arr):
    tree = Tree()
    tree.set_arg(arr, 0, None)
    print(tree.get_largest_rectangle())


if __name__ == '__main__':
    # Input Data Type: List = [Length, elem1, elem2, ..., elemN]
    while True:
        try:
            line = input()
            if line == '0':
                break
            arr = [int(elem) for elem in line if elem != ' ']
            main(arr)
        except EOFError:
            break
