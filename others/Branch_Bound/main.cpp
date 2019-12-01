/*
Analysis And Design Of Algorithms Laboratory
Open Ended

Submitted By: Akshat Agarwal  1SI16CS010
              Akarsh Singh    1SI16CS007
Problem 7

Let there be N workers and N jobs. Any worker can be assigned to perform any job,
incurring some cost that may vary depending on the work-job assignment.
It is required to perform all jobs by assigning exactly one worker to each job
and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

*/

#include <bits/stdc++.h>
using namespace std;
#define N 4

struct Node
{
    Node* parent;
    int pathCost;
    int cost;
    int workerID;
    int jobID;
    bool assigned[N]; // info about available jobs
};


// Function to allocate a new search tree node
// Here Person x is assigned to job y
Node* newNode(int x, int y, bool assigned[],Node* parent)
{
    Node* node = new Node;
    for (int j = 0; j < N; j++)
        node->assigned[j] = assigned[j];
    node->assigned[y] = true;
    node->parent = parent;
    node->workerID = x;
    node->jobID = y;
    return node;
}


// Function to calculate the least promising cost
// of node after worker x is assigned to job y.
int calculateCost(int costMatrix[N][N], int x,int y, bool assigned[])
{
    int cost = 0;
    bool available[N] = {true};  // to store unavailable jobs
    // start from next worker
    for (int i = x + 1; i < N; i++)
    {
        int min = INT_MAX, minIndex = -1;
        // do for each job
        for (int j = 0; j < N; j++)
        {
            // if job is unassigned
            if (!assigned[j] && available[j] && costMatrix[i][j] < min)
            {
                // store job number
                minIndex = j;
                // store cost
                min = costMatrix[i][j];
            }
        }
        // add cost of next worker
        cost += min;
        // job becomes unavailable
        available[minIndex] = false;
    }
    return cost;
}


// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node* lhs,const Node* rhs) const
    {
        return lhs->cost > rhs->cost;
    }
};


// print Assignments
void printAssignments(Node *min)
{
    if(min->parent==NULL)
        return;
    printAssignments(min->parent);
    cout << "Assign Worker " << char(min->workerID + 'A') << " to Job " << min->jobID + 1 << endl;
}


// Finds minimum cost using Branch and Bound.
int findMinCost(int costMatrix[N][N])
{
    // Create a priority queue to store live nodes of search tree;
    priority_queue<Node*, std::vector<Node*>, comp> pq;
    // initailize heap to dummy node with cost 0
    bool assigned[N] = {false};
    Node* root = newNode(-1, -1, assigned, NULL);
    root->pathCost = root->cost = 0;
    root->workerID = -1;
    // Add dummy node to list of live nodes;
    pq.push(root);
    // Finds a live node with least cost,
    // add its childrens to list of live nodes and
    // finally deletes it from the list.
    while (!pq.empty())
    {
      // Find a live node with least estimated cost
      Node* min = pq.top();
      // The found node is deleted from the list of live nodes
      pq.pop();
      // i stores next worker
      int i = min->workerID + 1;
      // if all workers are assigned a job
      if (i == N)
      {
          printAssignments(min);
          return min->cost;
      }
      // do for each job
      for (int j = 0; j < N; j++)
      {
        // If unassigned
        if (!min->assigned[j])
        {
          // create a new tree node
          Node* child = newNode(i, j, min->assigned, min);
          // cost for ancestors nodes including current node
          child->pathCost = min->pathCost + costMatrix[i][j];
          // calculate its lower bound
          child->cost = child->pathCost +
            calculateCost(costMatrix, i, j, child->assigned);
          // Add child to list of live nodes;
          pq.push(child);
        }
      }
    }
}


// Driver code
int main()
{
    int costMatrix[N][N];
    char c='A';

    cout << "Enter cost matrix\n\n";
    cout << "\tJob1\tJob2\tJob3\tJob4\n";

    for(int i=0;i<4;i++)
    {
        cout << c++ << "\t";
        for(int j=0;j<4;j++)
        {
            cin >> costMatrix[i][j];
        }
    }
    cout<<endl;
    cout << "\nOptimal Cost is " << findMinCost(costMatrix) << endl;
    return 0;
}
