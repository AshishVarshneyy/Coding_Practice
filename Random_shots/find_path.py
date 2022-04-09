'''
Question: Path find with start and end point
Input: 
A->B
B->C
C->D
D->E

Output: 
A->B->C->D->E
'''

class Solution:
    def __init__(self) -> None:
        pass

    def find_path(self, route):
        #reverse route from --> to To to --> from
        rev_route = {value: key for key, value in route.items()}
        
        #find the starting point by looking from values into to values, there in one from value which is not present in to values
        for key in route:
            if key not in rev_route:
                starting_point = key
                break
        #print starting point
        print(starting_point, end="")

        #iterate through the route till end point
        while starting_point in route:
            print("->",route[starting_point], end="")
            starting_point = route[starting_point]

if __name__ == "__main__":
    route = {"A" :"B", "B" :"C", "C" :"D", "D": "E"}
    obj = Solution()
    obj.find_path(route)