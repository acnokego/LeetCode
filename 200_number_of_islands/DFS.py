class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        """
        Complexity: O(row*col), search all element once
        Space: O(row*col)
        Find connected component.
        """
        def DFS(r, c, visited, row, col):
            rownbr = [-1,0,1,0]
            colnbr = [0,-1,0,1]
            visited[r][c] = True
            for k in range(4): # try not to use loop if the number is small
                new_r = r + rownbr[k]
                new_c = c + colnbr[k]
                if new_r >= 0 and new_c >= 0 and new_r < row and new_c < col and not visited[new_r][new_c] and grid[new_r][new_c] == '1':
                    DFS(new_r, new_c, visited, row, col)
            
        row = len(grid)
        if row == 0:
            return 0
        col = len(grid[0])
        if col == 0:
            return 0
        
        visited = [[False for i in range(col)] for j in range(row)]
        count = 0
        for i in range(row):
            for j in range(col):
                if not visited[i][j] and grid[i][j] == '1':
                    DFS(i, j, visited, row, col)
                    count += 1
        return count
