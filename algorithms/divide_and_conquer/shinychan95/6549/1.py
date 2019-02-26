""" 세그먼트 트리, 스택, 분할 정복, numpy """
import numpy as np
import time

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
        z = np.full(self.width, self.height)
        arr = arr - z
        x = self.__slice_based_on(arr, 0)

        if x:
            for elem in x:
                tree = Tree()
                tree.set_arg(elem, self.length+self.height, self)
                self.child.append(tree)
        else:
            pass

    def __slice_based_on(self, arr, num):
        idx = np.where(arr == num)[0]
        return [a[a != num] for a in np.split(arr, idx) if len(a[a != num])]

    def print_tree(self):
        #print('parent: ', self.parent)
        #print('width: ', self.width)
        #print('height: ', self.height)
        #print('length: ', self.length)
        #print('child: ', self.child)
        print(self.height, self.width, '/', self.length)
        print('*'*10)
        for elem in self.child:
            elem.print_tree()

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


def main():
    x = [7, 2, 1, 4, 5, 1, 3, 3]
    arr = np.array(x[1:])

    tree = Tree()
    tree.set_arg(arr, 0, None)

    return tree.get_largest_rectangle()

    #print(np.where(x == 1))
    #print(np.where(x == 1, 1, 3))




if __name__ == '__main__':
    # Input Data Type: List = [Length, elem1, elem2, ..., elemN]
    start_time = time.time()
    print('Lagest Area: ', main())
    print('Start Time: ', start_time)
    print('--- %s seconds ---' % (time.time() - start_time))




