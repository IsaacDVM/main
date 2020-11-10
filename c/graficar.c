#include <stdio.h>
#include <math.h>
int main(){
  FILE *fp=NULL;
  fp=fopen("circle.txt","w");
  double r;
  double x,y,x0,y0;
  printf("Enter the radius of the circle to be plotted: ");
  scanf("%lf",&r);
  printf("Enter the x and y-coordinates of the center: ");
  scanf("%lf%lf",&x0,&y0);
  for(y=y0-r;y<=y0+r;y=y+0.05){
    x = sqrt(r*r-(y-y0)*(y-y0))+x0; 
    fprintf(fp,"%lf\t %lf\n",x,y);
  }
  for(y=y0+r;y>=y0-r;y=y-0.05){
    x = -sqrt(r*r-(y-y0)*(y-y0))+x0; 
    fprintf(fp,"%lf\t %lf\n",x,y);
  }
  return 0;
}
