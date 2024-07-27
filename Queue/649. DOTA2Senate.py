class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        rq = []
        dq = []
        n = len(senate)
        for i in range(n):
            if senate[i] == "R":
                rq.append(i)
            else:
                dq.append(i)

        while len(rq) > 0 and len(dq) > 0:
            if rq[0] < dq[0]:
                rq.append(rq[0] + n)
                rq.pop(0)
                dq.pop(0)
            else:
                dq.append(dq[0] + n)
                rq.pop(0)
                dq.pop(0)
        
        if len(dq) > 0:
            return "Dire"
        else:
            return "Radiant"
