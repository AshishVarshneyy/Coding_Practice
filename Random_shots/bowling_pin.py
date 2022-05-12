'''
Question: Evaluate score board result
Input                               Output
11 11 11 11 11 11 11 11 11 11           20

5/ 4/ 3/ 2/ 1/ 0/ X 9/ 4/ 7/2          143

X X X X X X X X X XXX                  300
'''


class ScoreBoard:
    def __init__(self) -> None:
        pass

    def eval_strike(self, each_ball, ball):
        itr_res = 10
        if (each_ball[ball] == 'X') and (int(ball) == int(len(each_ball)-2)):
            return 0
        if (each_ball[ball] == 'X') and (int(ball) == int(len(each_ball)-1)):
            return 0
        else:
            if each_ball[ball+1] == 'X':
                itr_res += 10
            else:
                itr_res += int(each_ball[ball+1])
            if each_ball[ball+2] == 'X':
                itr_res += 10
            elif each_ball[ball+2] == '/':
                itr_res += (10 - int(each_ball[ball+1]))
            else:
                itr_res += int(each_ball[ball+2])
        return itr_res
            
        
    def eval_spare(self, each_ball, ball):
        itr_res = (10 - int(each_ball[ball-1]))
        if each_ball[ball+1] == 'X':
            itr_res += 10
        else:
            itr_res += int(each_ball[ball+1])  
        return itr_res

    def eval_score(self, frames):
        each_ball = [res for val in frames.split() for res in val]
        
        if 'X' not in each_ball and '/' not in each_ball:
            return sum([int(val) for val in each_ball])
        else:
            if len(frames.split()[-1]) == 3:
                itr = len(each_ball) - 3
            else:
                itr = len(each_ball) - 2 

            res = 0
            for ball in range(0,itr):
                if each_ball[ball] == 'X':
                    res += int(self.eval_strike(each_ball, ball))
                elif each_ball[ball] == '/':
                    res += int(self.eval_spare(each_ball, ball))
                else:
                    res += int(each_ball[ball])

            ball += 1
            for i in each_ball[itr:-1]:
                if i == 'X':
                    res += int(self.eval_strike(each_ball, ball))
                elif i == '/':
                    res += int(self.eval_spare(each_ball, ball))
                else:
                    res += int(i)
                ball += 1
            return res


obj = ScoreBoard()
frame1 = "5/ 4/ 3/ 2/ 1/ 0/ X 9/ 4/ 7/2"
frame2 = "11 11 11 11 11 11 11 11 11 11"
frame3 = "X X X X X X X X X XXX"
result = obj.eval_score(frame1)
print(result)