def test_reversestring():
    
    def reverse_str(s) -> None:
        if len(s) == 1:
            return s

        m = reverse_str(s[:-1])

        m.insert(0, s.pop())

        return m


    l = ['h', 'e', 'l', 'l', 'o']

    result = reverse_str(l)

    print(result)
