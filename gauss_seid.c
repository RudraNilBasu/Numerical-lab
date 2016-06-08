#include<stdio.h>
float ab(float x)
{
	if(x>=0)
		return x;
	return -1*x;
}
int main()
{
	int coeff[3][3],con[3];
	int i,j,k;
	float err;
	float var[3][1000]; // var[0]=x, var[1] = y, var[2] = z
	printf("Coefficient Matrix:\n");
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++)
			scanf("%d",&coeff[i][j]);
	}
	printf("Constant Matrix: \n");
	for(i=0;i<3;i++)
		scanf("%d",&con[i]);
	printf("Error: ");
	scanf("%f",&err);
	i=0;j=0;k=0;
	float x,y,z,x0,y0,z0;
	x=0;
	y=0;
	z=0;
	printf("\nx \t\t y \t\t z \n");
	while(1) {
		/*
		var[0][i+1]=( con[0] - coeff[0][1]*var[1][i] - coeff[0][2]*var[2][i++]  )/coeff[0][0];
		var[1][j+1]=( con[1] - coeff[1][0]*var[0][i] - coeff[1][2]*var[2][j++]  )/coeff[1][1];
		var[2][k++]=( con[2] - coeff[2][0]*var[0][i] - coeff[2][1]*var[1][j]  )/coeff[2][2];
		*/
		x0=x;
		y0=y;
		z0=z;
		x= ( con[0] - coeff[0][1]*y - coeff[0][2]*z  )/coeff[0][0];
		y= ( con[1] - coeff[1][0]*x - coeff[1][2]*z  )/coeff[1][1];
		z= ( con[2] - coeff[2][0]*x - coeff[2][1]*x  )/coeff[2][2];
		// printing
		printf("%f \t %f \t %f\n",x,y,z);
		float diffx = ab(x-x0);
		float diffy = ab(y-y0);
		float diffz = ab(z-z0);
		if( diffx<err && diffy<err && diffz<err )
			break;
		//if(fabs(var[0][i]-var[0][i-1]) < err && fabs(var[1][j]-var[1][j-1] ) < err && fabs(var[2][k]-var[2][k-1]) < err)
		//	break;
	}
	//printf("%f\t%f\t%f\n",var[0][i],var[1][j],var[2][k]);
	printf("\nx=%f\ty=%f\tz=%f\n",x,y,z);
	return 0;
}
