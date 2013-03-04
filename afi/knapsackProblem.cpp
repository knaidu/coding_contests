// Given a knapsack with weight W, and a list of items v[], 
// find the max number of items that can fit in the knapsack

int knapsack(vector<int> v, // items
             vector<int> w, // weight of items
             int W) {
  int V[MAX][MAX];
  
  for(int i=0; i<v.size(); i++) V[i][0] = 0;
  
  for(int i=0; i<v.size(); i++) {
    for(int j = 0; j<W; j++) {
      if(j < W) {
        V[i][j] = max(V[i-1][j], V[i-1][j-w[i-1]] + w[i]);
      }
      else {
        V[i][j] = V[i-1][j];
      }
    }
  }
  
  return v[n][W];
}