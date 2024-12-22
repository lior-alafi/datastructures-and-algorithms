
# Online Python - IDE, Editor, Compiler, Interpreter

arr = [[0,1,0,0],
       [0,1,0,1],
       [0,1,0,1]]
       
class Solution:
    def __init__(self,arr):
        super().__init__()
        self.arr = arr
       
        self.shape = (len(arr),len(arr[0]))
        
        print(self.shape)
        
        
    def neighbour(self,i:int,j:int,value):
        neighbours = []
        #top line
        if j > 0:
            if i > 0 and self.arr[i-1][j-1] == value :
                      neighbours.append((i-1,j-1))
            if self.arr[i][j-1] == value:
                      neighbours.append((i,j-1))
            if  i < self.shape[0] -1 and self.arr[i+1][j-1] == value:
                      neighbours.append((i+1,j-1))  
        #middle line
        if  i > 0 and self.arr[i-1][j] == value:
                  neighbours.append((i-1,j))
        if  i < self.shape[0] -1 and  self.arr[i+1][j] == value:
                  neighbours.append((i+1,j))  
        
        #bottom line
        if j < self.shape[1] -1:
            if  i > 0 and self.arr[i-1][j+1] == value:
                      neighbours.append((i-1,j+1))
            if self.arr[i][j+1] == value:
                      neighbours.append((i,j+1))
            if i < self.shape[0] -1 and  self.arr[i+1][j+1] == value:
                      neighbours.append((i+1,j+1))  
        return set(neighbours)
                  
    def BFS(self,i,j,value):
        visited = set()
        queue = []
        if self.arr[i][j]==value:
            queue.append((i,j))
        while len(queue) > 0:
            coord = queue.pop(0)
            
            visited.add(coord)
            nei = self.neighbour(coord[0],coord[1],value)
           # print(f'coord {coord} -- {nei}')
            for n in nei.difference(visited):
                queue.append(n)
        return visited
   
    def count_islands(self,value:int):
        counter = 0 
        visited = set()
        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                if (i,j) not in visited and arr[i][j]:
                    curr_visited = self.BFS(i,j,value)
                    visited = visited.union(curr_visited)
                    counter += 1
                    
        return counter
        
sol = Solution(arr)
print(sol.count_islands())
                
