class Node:
    def __init__(self, ch):
        self.c = ch
        self.left = None
        self.mid = None
        self.right = None
        self.is_end_of_string = False


class TernarySearchTree:
    def __init__(self):
        self.root = None
        self.string_set = set()

    def insert(self, s):
        if s not in self.string_set:
            self.root = self._insert(self.root, s, 0)
            self.string_set.add(s)

    def _insert(self, t, s, i):
        if t is None:
            t = Node(s[i])

        if s[i] < t.c:
            t.left = self._insert(t.left, s, i)
        elif s[i] > t.c:
            t.right = self._insert(t.right, s, i)
        else:
            if i + 1 < len(s):
                t.mid = self._insert(t.mid, s, i + 1)
            else:
                t.is_end_of_string = True
        return t

    def erase(self, s):
        if s in self.string_set:
            self.root = self._erase(self.root, s, 0)
            self.string_set.remove(s)

    def _erase(self, t, s, i):
        if t is None:
            return None

        if s[i] < t.c:
            t.left = self._erase(t.left, s, i)
        elif s[i] > t.c:
            t.right = self._erase(t.right, s, i)
        else:
            if i + 1 < len(s):
                t.mid = self._erase(t.mid, s, i + 1)
            else:
                t.is_end_of_string = False
        return t

    def reset(self):
        self.root = None
        self.string_set.clear()

    def clear(self, t):
        if t is None:
            return
        self.clear(t.left)
        self.clear(t.mid)
        self.clear(t.right)
        del t

    def __del__(self):
        self.clear(self.root)
        self.string_set.clear()

    def count_words_ending_with(self, suffix):
        count = 0
        for word in self.string_set:
            if word.endswith(suffix):
                count += 1
        return count


if __name__ == "__main__":
    ds = TernarySearchTree()
    import sys
    input = sys.stdin.read
    data = input().split()
    i = 0
    while i < len(data):
        operation = data[i]
        if operation == "I":
            s = data[i + 1]
            ds.insert(s)
            i += 2
        elif operation == "E":
            s = data[i + 1]
            ds.erase(s)
            i += 2
        elif operation == "C":
            s = data[i + 1]
            print(ds.count_words_ending_with(s))
            i += 2
        elif operation == "R":
            ds.reset()
            print("---")
            i += 1
