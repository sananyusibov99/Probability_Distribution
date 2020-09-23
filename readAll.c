#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *OpenFile(char *filename){
	FILE *fp=fopen(filename, "r");
	if(!fp){
		printf("Couldn't open the file");
		exit(1);
	}
	return fp;
}

void extractData(FILE *pf, int n, int m){
	char str[1000], *token; int i=0, j=0; //j-line i-col
	float val;
	do{
		i=0;
		fscanf(pf, "%s", str);j++;
		token = strtok(str,";");
		while(token!=NULL){
			token = strtok(NULL, ";"); i++;
			if(i==n && j==m){ 
					printf("%s\n", token);
			}
		}
	}while(fgetc(pf)!=EOF);
}

int main(int argc, int **argv){
	if(argc<2){
		printf("Usage: %s nameOfFile.csv \n", argv[0]);
		return 0;
	}else{
		float testBinomial = strcmp(argv[1],"Binomial.csv");
		if(testBinomial == 0.00){
			FILE *ptrf=OpenFile(argv[1]);
			int c, line, col;
			float z;
			int p;
			printf("This program will give you the result of between 0 and 1\n");
			printf("Give us a number of N (5,10,15,20,25): ");
			scanf("%d", &p);
			printf("Give us a float number from 0 to N with 1 digit after comma, for example 1.2: ");
			scanf("%f", &z);
			int new=z*10;
			col = new%10;
			line=new/10;
			if(p==10){ line += 6; }
			if(p==15){ line = line + 17; }
			if(p==20){ line = line + 33; }
			if(p==25){ line = line + 54; }
			printf("It is line %d, col %d, and the result will be ", line+3, col);
			extractData(ptrf, col, line+3);
		}
		float testChi = strcmp(argv[1],"Chi.csv");
		if(testChi == 0.00){
			FILE *ptrf=OpenFile(argv[1]);
			int c, line, col;
			int v;
			float P;

			printf("Give us a float number (0.995, 0.99, 0.975, 0.95, 0.9, 0.1, 0.05, 0.025, 0.01, 0.005) for P: ");
			float arr[12] = { 0.995, 0.99, 0.975, 0.95, 0.9, 0.1, 0.05, 0.025, 0.01, 0.005 };
			scanf("%f", &P);

			//Finding the column index
			int i,C,P_index, v_index = 0;
			int n=sizeof(arr)/sizeof(arr[0]);
			for(i=0;i<n;i++){
				if(arr[i]==P){
				    P_index=i;
				    C=1;
				    break;
				}
				else{
				    C=0;
				}
			}

			printf("Give us another integer number from 1 to 30 for v: ");
			scanf("%d", &v_index);

			printf("The result will be ");
			extractData(ptrf, P_index+1, v_index+1);
		}
		float testFisher = strcmp(argv[1],"Fisher.csv");
		if(testFisher == 0.00){
			FILE *ptrf=OpenFile(argv[1]);
			int c, line, col;
			int n1, n2;
			float prob;
			printf("Give us value of p (0.95 or 0.99): ");
			scanf("%f", &prob);

			printf("Give us an integer number from 1 to 10, 15, 20, 30, 50 or 100 for n1: ");
			int arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 30, 50, 100 };
			scanf("%d", &n1);

			//Finding the column index
			int i,C,n1_index = 0;
			int n=sizeof(arr)/sizeof(arr[0]);
			for(i=0;i<n;i++){
				if(arr[i]==n1){
				    n1_index=i;
				    C=1;
				    break;
				}
				else{
				    C=0;
				}
			}

			printf("Give us another integer number from 1 to 20, 25, 30, 35, 40, 45, 50, 60, 70, 80, 90, 100, 150 or 200 for n2: ");
			int arr2[33] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25, 30, 35, 40, 45, 50, 60, 70, 80, 90, 100, 150, 200 };
			scanf("%d", &n2);
			
			//Finding the row index
			i,C = 0;
			int n2_index = 0;
			n=sizeof(arr2)/sizeof(arr2[0]);
			for(i=0;i<n;i++){
				if(arr2[i]==n2){
				    n2_index=i;
				    C=1;
				    break;
				}
				else{
				    C=0;
				}
			}

			if(prob=0.99){
				n2_index = n2_index + 35;
			}

			printf("The result will be ");
			extractData(ptrf, n1_index+1, n2_index+2);
		}
		float testNormal = strcmp(argv[1],"Normal.csv");
		if(testNormal == 0.00){
			FILE *ptrf=OpenFile(argv[1]);
			int c, line, col;
			float z;
			printf("This program will give you the result of N(0,1)\n");
			printf("Give us a float number with 2 digits after comma, for example 1.22: ");
			scanf("%f", &z);
			int new=z*100;
			col = new%10;
			line=new/10;
			printf("It is line %d, col %d, and the result will be ", line+1, col+1);
			extractData(ptrf, col+1, line+2);
		}
		float testStudent = strcmp(argv[1],"Student.csv");
		if(testStudent == 0.00){
			FILE *ptrf=OpenFile(argv[1]);
			int c, line, col;
			int v;
			float P;

			printf("Give us a float number (0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.05, 0.02, 0.01 for P: ");
			float arr[12] = { 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.05, 0.02, 0.01 };
			scanf("%f", &P);

			//Finding the column index
			int i,C,P_index, v_index = 0;
			int n=sizeof(arr)/sizeof(arr[0]);
			for(i=0;i<n;i++){
				if(arr[i]==P){
				    P_index=i;
				    C=1;
				    break;
				}
				else{
				    C=0;
				}
			}

			printf("Give us another integer number from 1 to 30 for v: ");
			scanf("%d", &v_index);

			printf("The result will be ");
			extractData(ptrf, P_index+1, v_index+1);
		}
	}
	return 0;
}
