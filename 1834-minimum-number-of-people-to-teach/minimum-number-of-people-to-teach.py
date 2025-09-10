class Solution(object):
    def minimumTeachings(self, n, languages, friendships):
        """
        :type n: int
        :type languages: List[List[int]]
        :type friendships: List[List[int]]
        :rtype: int
        """
        u = []
        for i in friendships:
            a = set(languages[i[0] - 1])
            b = set(languages[i[1] - 1])
            c = a.intersection(b)
            if len(c) == 0:
                u.append(i)

        users_in_need = set()
        for i in u:
            users_in_need.add(i[0] - 1)
            users_in_need.add(i[1] - 1)

        mi= float('inf')
        for l in range(1, n + 1):
            r=0
            for u in users_in_need:
                if l not in languages[u]:
                    r += 1
            mi= min(mi, r)
        return mi