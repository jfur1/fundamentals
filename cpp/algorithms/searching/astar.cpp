#include <iostream>
#include "math.h" // Used for sqrt()
#include <cfloat> // Used for FLT_MAX
#include <stack> // Used for backtracking current paths
#include <set> // Used to created our explored set
using namespace std;

/*
    A* Search Algorithm: 
        One of the best and most popular path-finding algorithms and graph traversals
*/

#define ROW 9
#define COL 10

// Create type for (int, int) pair
typedef pair<int, int> Pair;

// Create type of pair<double, pair<int, int> >
typedef pair<double, pair<int, int> > pPair;

// Structure for our cells
struct cell{
    // Row and Col idx of its parent
    // Note: 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    double f, g, h;
};

// Utility function to check whether a given cell (row, col) is valid
bool isValid(int row, int col){
    // Return true if row and col indices are within valid range
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Utility function to check whether a cell is blocked or not
bool isUnblocked(int grid[][COL], int row, int col){
    return true ? (grid[row][col] == 1) : false;
}

// Utility function to check whether destination cell has been reached
bool isDestination(int row, int col, Pair dest){
    return true ? (row == dest.first && col == dest.second) : false;
}

// Utility funciton to calculate euclidian distance (heuristic eval)
double calculateH(int row, int col, Pair dest){
    return ((double)sqrt(
        (row - dest.first) * (row - dest.first) 
        + (col - dest.second)  * (col - dest.second)
        ));
}

// Utility function to trace the path from source node to destination
void tracePath(cell cellDetails[][COL], Pair dest){
    cout << "\nThe Path is: ";
    int row = dest.first;
    int col = dest.second;

    stack<Pair> Path;

    while(!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)){
        Path.push(make_pair(row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    Path.push(make_pair(row, col));
    while(!Path.empty()){
        pair<int, int> p = Path.top();
        Path.pop();
        cout << "-> (" << p.first << ", " << p.second << ") ";
    }
    cout << "\n\n";
    return;
}


// Function to find the shortest path between a given start node and given target node via A* Search Algorithm
void aStarSearch(int grid[][COL], Pair src, Pair dest){
    // If the source is out of range:
    if(!isValid(src.first, src.second)){
        cout << "Source is invalid!\n";
        return;
    }

    // If the destination is out of range:
    if(!isValid(dest.first, dest.second)){
        cout << "Destination is out of range!\n";
        return;
    }

    // If either the source or destination nodes are blocked:
    if(!isUnblocked(grid, src.first, src.second) || !isUnblocked(grid, dest.first, dest.second)){
        cout << "Source or destination node is blocked!\n";
        return;
    }

    // If target node is the same as the source node:
    if(isDestination(src.first, src.second, dest)){
        cout << "We are already at the destination!\n";
        return;
    }

    // Initialize the explored using a boolean 2D Array, with value of false which means no cells have been added yet
    bool explored[ROW][COL];
    memset(explored, false, sizeof(explored));

    // Declare a 2D array of structs to hold details for the cells/nodes
    cell cellDetails[ROW][COL];

    int i, j;

    for(i = 0; i < ROW; i++){
        for(j = 0; j< COL; j++){
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }

    // Initialize parameters for our start node:
    i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    // Create an explored set with elements <f, <i, j> >
    // Where f = g + h
    // and i, j are the row, col index of that cell
    // Implemented using a set of pairs of pairs
    set<pPair> frontier;

    // Insert the start node in the explored set, with f = 0
    frontier.insert(make_pair(0.0, make_pair(i, j)));

    // Target flag
    bool foundDest = false;

    while(!frontier.empty()){
        pPair p = *frontier.begin();

        // Remove node from the frontier
        frontier.erase(frontier.begin());

        // Add node to the explored set
        i = p.second.first;
        j = p.second.second;
        explored[i][j] = true;
        
        /*
         Generating all the 8 successor of this cell
 
             N.W   N   N.E
               \   |   /
                \  |  /
             W----Cell----E
                  / | \
                /   |  \
             S.W    S   S.E
 
         Cell-->Popped Cell (i, j)
         N -->  North       (i-1, j)
         S -->  South       (i+1, j)
         E -->  East        (i, j+1)
         W -->  West        (i, j-1)
         N.E--> North-East  (i-1, j+1)
         N.W--> North-West  (i-1, j-1)
         S.E--> South-East  (i+1, j+1)
         S.W--> South-West  (i+1, j-1)*/
 
        // To store the 'g', 'h' and 'f' of the 8 successors
        double gNew, hNew, fNew;
        
        //----------- 1st Successor (North) ------------
 
        // Only process this cell if this is a valid one
        if (isValid(i - 1, j) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i - 1, j, dest) == true) {
                // Set the Parent of the destination cell 
                cellDetails[i - 1][j].parent_i = i;
                cellDetails[i - 1][j].parent_j = j;
                cout << "The destination cell is found\n";
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (explored[i - 1][j] == false
                     && isUnblocked(grid, i - 1, j)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateH(i - 1, j, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i - 1][j].f == FLT_MAX
                    || cellDetails[i - 1][j].f > fNew) {
                    frontier.insert(make_pair(
                        fNew, make_pair(i - 1, j)));
                    // Update the details of this cell
                    cellDetails[i - 1][j].f = fNew;
                    cellDetails[i - 1][j].g = gNew;
                    cellDetails[i - 1][j].h = hNew;
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                }
            }
        }

        //----------- 2nd Successor (South) ------------
 
        // Only process this cell if this is a valid one
        if (isValid(i + 1, j) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i + 1, j, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
                cout << "The destination cell is found\n";
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (explored[i + 1][j] == false
                     && isUnblocked(grid, i + 1, j)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateH(i + 1, j, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i + 1][j].f == FLT_MAX
                    || cellDetails[i + 1][j].f > fNew) {
                    frontier.insert(make_pair(
                        fNew, make_pair(i + 1, j)));
                    // Update the details of this cell
                    cellDetails[i + 1][j].f = fNew;
                    cellDetails[i + 1][j].g = gNew;
                    cellDetails[i + 1][j].h = hNew;
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                }
            }
        }
 
        //----------- 3rd Successor (East) ------------
 
        // Only process this cell if this is a valid one
        if (isValid(i, j + 1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i, j + 1, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i][j + 1].parent_i = i;
                cellDetails[i][j + 1].parent_j = j;
                cout << "The destination cell is found \n";
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (explored[i][j + 1] == false
                     && isUnblocked(grid, i, j + 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateH(i, j + 1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i][j + 1].f == FLT_MAX
                    || cellDetails[i][j + 1].f > fNew) {
                    frontier.insert(make_pair(
                        fNew, make_pair(i, j + 1)));
                    // Update the details of this cell
                    cellDetails[i][j + 1].f = fNew;
                    cellDetails[i][j + 1].g = gNew;
                    cellDetails[i][j + 1].h = hNew;
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                }
            }
        }
 
        //----------- 4th Successor (West) ------------
 
        // Only process this cell if this is a valid one
        if (isValid(i, j - 1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i, j - 1, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i][j - 1].parent_i = i;
                cellDetails[i][j - 1].parent_j = j;
                cout << "The destination cell is found\n";
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (explored[i][j - 1] == false
                     && isUnblocked(grid, i, j - 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateH(i, j - 1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i][j - 1].f == FLT_MAX
                    || cellDetails[i][j - 1].f > fNew) {
                    frontier.insert(make_pair(
                        fNew, make_pair(i, j - 1)));
                    // Update the details of this cell
                    cellDetails[i][j - 1].f = fNew;
                    cellDetails[i][j - 1].g = gNew;
                    cellDetails[i][j - 1].h = hNew;
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                }
            }
        }
 
        //----------- 5th Successor (North-East)
        //------------
 
        // Only process this cell if this is a valid one
        if (isValid(i - 1, j + 1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i - 1, j + 1, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i - 1][j + 1].parent_i = i;
                cellDetails[i - 1][j + 1].parent_j = j;
                cout << "The destination cell is found\n";
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (explored[i - 1][j + 1] == false
                     && isUnblocked(grid, i - 1, j + 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateH(i - 1, j + 1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i - 1][j + 1].f == FLT_MAX
                    || cellDetails[i - 1][j + 1].f > fNew) {
                    frontier.insert(make_pair(
                        fNew, make_pair(i - 1, j + 1)));
                    // Update the details of this cell
                    cellDetails[i - 1][j + 1].f = fNew;
                    cellDetails[i - 1][j + 1].g = gNew;
                    cellDetails[i - 1][j + 1].h = hNew;
                    cellDetails[i - 1][j + 1].parent_i = i;
                    cellDetails[i - 1][j + 1].parent_j = j;
                }
            }
        }
 
        //----------- 6th Successor (North-West)
        //------------
 
        // Only process this cell if this is a valid one
        if (isValid(i - 1, j - 1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i - 1, j - 1, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i - 1][j - 1].parent_i = i;
                cellDetails[i - 1][j - 1].parent_j = j;
                cout << "The destination cell is found\n";
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (explored[i - 1][j - 1] == false
                     && isUnblocked(grid, i - 1, j - 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateH(i - 1, j - 1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i - 1][j - 1].f == FLT_MAX
                    || cellDetails[i - 1][j - 1].f > fNew) {
                    frontier.insert(make_pair(
                        fNew, make_pair(i - 1, j - 1)));
                    // Update the details of this cell
                    cellDetails[i - 1][j - 1].f = fNew;
                    cellDetails[i - 1][j - 1].g = gNew;
                    cellDetails[i - 1][j - 1].h = hNew;
                    cellDetails[i - 1][j - 1].parent_i = i;
                    cellDetails[i - 1][j - 1].parent_j = j;
                }
            }
        }
 
        //----------- 7th Successor (South-East)
        //------------
 
        // Only process this cell if this is a valid one
        if (isValid(i + 1, j + 1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i + 1, j + 1, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i + 1][j + 1].parent_i = i;
                cellDetails[i + 1][j + 1].parent_j = j;
                cout << "The destination cell is found\n";
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (explored[i + 1][j + 1] == false
                     && isUnblocked(grid, i + 1, j + 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateH(i + 1, j + 1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i + 1][j + 1].f == FLT_MAX
                    || cellDetails[i + 1][j + 1].f > fNew) {
                    frontier.insert(make_pair(
                        fNew, make_pair(i + 1, j + 1)));
                    // Update the details of this cell
                    cellDetails[i + 1][j + 1].f = fNew;
                    cellDetails[i + 1][j + 1].g = gNew;
                    cellDetails[i + 1][j + 1].h = hNew;
                    cellDetails[i + 1][j + 1].parent_i = i;
                    cellDetails[i + 1][j + 1].parent_j = j;
                }
            }
        }
 
        //----------- 8th Successor (South-West)
        //------------
 
        // Only process this cell if this is a valid one
        if (isValid(i + 1, j - 1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i + 1, j - 1, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i + 1][j - 1].parent_i = i;
                cellDetails[i + 1][j - 1].parent_j = j;
                cout << "The destination cell is found\n";
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (explored[i + 1][j - 1] == false
                     && isUnblocked(grid, i + 1, j - 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateH(i + 1, j - 1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i + 1][j - 1].f == FLT_MAX
                    || cellDetails[i + 1][j - 1].f > fNew) {
                    frontier.insert(make_pair(
                        fNew, make_pair(i + 1, j - 1)));
                    // Update the details of this cell
                    cellDetails[i + 1][j - 1].f = fNew;
                    cellDetails[i + 1][j - 1].g = gNew;
                    cellDetails[i + 1][j - 1].h = hNew;
                    cellDetails[i + 1][j - 1].parent_i = i;
                    cellDetails[i + 1][j - 1].parent_j = j;
                }
            }
        }
    }
 
    // When the destination cell is not found and the open
    // list is empty, then we conclude that we failed to
    // reach the destination cell. This may happen when the
    // there is no way to destination cell (due to
    // blockages)
    if (foundDest == false)
        printf("Failed to find the Destination Cell\n");
 
    return;
}



// Driver program to test above function
int main(){
    /* Description of the Grid-
     1--> The cell is not blocked
     0--> The cell is blocked    */
    int grid[ROW][COL]
        = { { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
            { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
            { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } };
 
    // Source is the left-most bottom-most corner
    Pair src = make_pair(8, 0);
 
    // Destination is the left-most top-most corner
    Pair dest = make_pair(0, 0);
 
    aStarSearch(grid, src, dest);
 
    return (0);

}