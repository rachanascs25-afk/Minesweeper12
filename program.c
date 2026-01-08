#include <stdio.h>
// Color macros
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"
int main() {
 int n, m;
 int mine[10][10];
 int result[10][10];
 printf(BLUE "Enter number of rows and columns: " RESET);
 scanf("%d %d", &n, &m);
 printf(BLUE "Enter matrix (-1 for mine, 0 for empty):\n" RESET);
 for(int i = 0; i < n; i++) {
 for(int j = 0; j < m; j++) {
 scanf("%d", &mine[i][j]);
 }
 }
 int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
for(int i = 0; i < n; i++) {
 for(int j = 0; j < m; j++) {
 if(mine[i][j] == -1) {
 result[i][j] = -1;
 } else {
 int count = 0;
 for(int k = 0; k < 8; k++) {
 int ni = i + dx[k];
 int nj = j + dy[k];
 if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
 if(mine[ni][nj] == -1)
 count++;
 }
 }
 result[i][j] = count;
 }
}
 }
printf("\n" BLUE "===== MINESWEEPER OUTPUT =====\n" RESET);
 for(int i = 0; i < n; i++) {
 for(int j = 0; j < m; j++) {
 if(result[i][j] ==-1)
   printf(RED "* " RESET);
 else
 printf(GREEN "%d " RESET, result[i][j]);
 }
 printf("\n");
 }
 return 0;
}
