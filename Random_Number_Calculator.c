#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sign(void);

int main(int argc, char *argv[]){
	srand(time(NULL));
	FILE *fp=fopen("result.txt", "w"); 	//Open (or create if missing) file result.txt, with writing privileges
	if(fp==NULL){	//Check file pointer
		fprintf(stderr, "ERROR: Failed to open/create file.\n");
		exit(EXIT_FAILURE);
		}
	fprintf(fp, "1756132\n\n");
	if(argc!=2){	//Check number of command line inputs
		fprintf(stderr, "ERROR: wrong number of inputs.\n");
                exit(EXIT_FAILURE);
		}

	int arity=atoi(argv[1]);	//Read command line input

	if(arity<3 || arity>5){		//Check correctness of input
		fprintf(stderr, "ERROR: arity of the operation must be between 3 and 5.\n");
		exit(EXIT_FAILURE);
		}

	float operands[arity];	//Create array of operands with required arity

	for(int i=0; i<arity; i++){     //Choose operands from integers in range [0,100]
                                operands[i]=rand()%101;
                                }

	int num_ops=0; 		//Make user choose how many operations to perform
	puts("How many operations do wou want to perform?");
	scanf("%d", &num_ops);
	switch(arity){
		case(3):
		for(int j=0; j<num_ops; j++){
		for(int i=0; i<arity; i++){     //Choose operands from integers in range [0,100]
                                operands[i]=rand()%101;
                                }
					//Choose random signs usign function "int sign(void)"

			int sgn1=sign(), sgn2=sign();
			int Dsgn=sgn1-sgn2;

					//Build operations by combining signs and operands

			switch(sgn1){	//Sgn1 represents the first sign
				case(1):
					if(Dsgn==0){
						fprintf(fp,"%.0f + %.0f + %.0f = %.4f\n", operands[0], operands[1], operands[2], float(operands[0]+operands[1]+operands[2]));
						goto exit;
						}
					if(Dsgn==-4){
						fprintf(fp,"(%.0f + %.0f) * %.0f = %.4f\n", operands[0], operands[1], operands[2], float((operands[0]+operands[1])*operands[2]));
                                                goto exit;
						}
					if(Dsgn==-10){
						fprintf(fp,"%.0f + %.0f - %.0f = %.4f\n", operands[0], operands[1], operands[2], float(operands[0]+operands[1]-operands[2]));
                                                goto exit;
						}
					if(Dsgn==-12){
						fprintf(fp,"(%.0f + %.0f) / %.0f = %.4f\n", operands[0], operands[1], operands[2], float((operands[0]+operands[1])/operands[2]));
                                                goto exit;
						}
				exit:
				break;
				case(5):
					if(Dsgn==0){
                                                fprintf(fp,"%.0f * %.0f * %.0f = %.4f\n", operands[0], operands[1], operands[2], float(operands[0]*operands[1]*operands[2]));
                                                goto exit1;
                                                }
                                        if(Dsgn==4){
                                                fprintf(fp,"(%.0f * %.0f) + %.0f = %.4f\n", operands[0], operands[1], operands[2], float((operands[0]*operands[1]) +operands[2]));
                                                goto exit1;
                                                }
                                        if(Dsgn==-6){
                                                fprintf(fp,"(%.0f * %.0f) - %.0f = %.4f\n", operands[0], operands[1], operands[2], float((operands[0]*operands[1]) -operands[2]));
                                                goto exit1;
                                                }
                                        if(Dsgn==-8){
                                                fprintf(fp,"(%.0f * %.0f) / %.0f = %.4f\n", operands[0], operands[1], operands[2], float((operands[0]*operands[1]) /operands[2]));
                                                goto exit1;
                                                }
                                exit1:
                                break;
				case(11):
					if(Dsgn==0){
                                                fprintf(fp,"%.0f - %.0f - %.0f = %.4f\n", operands[0], operands[1], operands[2], float(operands[0]-operands[1]-operands[2]));
                                                goto exit2;
                                                }
                                        if(Dsgn==10){
                                                fprintf(fp,"%.0f - %.0f + %.0f = %.4f\n", operands[0], operands[1], operands[2], float(operands[0]-operands[1]+operands[2]));
                                                goto exit2;
                                                }
                                        if(Dsgn==6){
                                                fprintf(fp,"(%.0f - %.0f) * %.0f = %.4f\n", operands[0], operands[1], operands[2], float((operands[0]-operands[1])*operands[2]));
                                                goto exit2;
                                                }
                                        if(Dsgn==-2){
                                                fprintf(fp,"(%.0f - %.0f) / %.0f = %.4f\n", operands[0], operands[1], operands[2], float((operands[0]-operands[1])/operands[2]));
                                                goto exit2;
                                                }
                                exit2:
                                break;
				case(13):
					if(Dsgn==0){
                                                fprintf(fp,"(%.0f / %.0f) / %.0f = %.4f\n", operands[0], operands[1], operands[2], float((operands[0]/operands[1])/operands[2]));
                                                goto exit3;
                                                }
                                        if(Dsgn==12){
                                                fprintf(fp,"(%.0f / %.0f) + %.0f = %.4f\n", operands[0], operands[1], operands[2], float((operands[0]/operands[1])+operands[2]));
                                                goto exit3;
                                                }
                                        if(Dsgn==8){
                                                fprintf(fp,"(%.0f / %.0f) * %.0f = %.4f\n", operands[0], operands[1], operands[2], float((operands[0]/operands[1])*operands[2]));
                                                goto exit3;
                                                }
                                        if(Dsgn==2){
                                                fprintf(fp,"(%.0f / %.0f) - %.0f = %.4f\n", operands[0], operands[1], operands[2], float((operands[0]/operands[1])-operands[2]));
                                                goto exit3;
                                                }
                                exit3:
				break;
				default:
				break;
				}	//End of switch sgn1
			}//End of for(j)
		break;
		case(4):
		for(int j=0; j<num_ops; j++){
			for(int i=0; i<arity; i++){     //Choose operands from integers in range [0,100]
                                operands[i]=rand()%101;
                                }
			int list=rand()%10;		//Create random variable to choose from a list of operations
			switch(list){
				case(0):
					fprintf(fp, "[(%.0f / %.0f) - %.0f] * %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], float(((operands[0]/operands[1])-operands[2])*operands[3]));
				break;
				case(1):
					fprintf(fp, "[(%.0f / %.0f) + %.0f] / %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], float(((operands[0]/operands[1])+operands[2])/operands[3]));
                                break;
				case(2):
					fprintf(fp, "(%.0f - %.0f + %.0f) * %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], float((operands[0]-operands[1]+operands[2])*operands[3]));
                                break;
				case(3):
					fprintf(fp, "[(%.0f - %.0f) / %.0f] / %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], float(((operands[0]-operands[1])/operands[2])/operands[3]));
                                break;
				case(4):
					fprintf(fp, "%.0f - %.0f + %.0f - %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], float(operands[0]-operands[1]+operands[2]-operands[3]));
                                break;
				case(5):
					fprintf(fp, "(%.0f + %.0f + %.0f) / %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], float((operands[0]+operands[1]+operands[2])/operands[3]));
                                break;
				case(6):
					fprintf(fp, "[(%.0f + %.0f) / %.0f] * %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], float(((operands[0]+operands[1])/operands[2])*operands[3]));
                                break;
				case(7):
					fprintf(fp, "[(%.0f / %.0f) / %.0f] / %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], float(((operands[0]/operands[1])/operands[2])/operands[3]));
                                break;
				case(8):
					fprintf(fp, "(%.0f + %.0f) * %.0f - %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], float(((operands[0]+operands[1])*operands[2])-operands[3]));
                                break;
				case(9):
					fprintf(fp, "%.0f * %.0f * %.0f - %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], float((operands[0]*operands[1]*operands[2])-operands[3]));
                                break;
				}//End of switch list
			}//End of for(j)
		break;
		case(5):
		for(int j=0; j<num_ops; j++){
                        for(int i=0; i<arity; i++){     //Choose operands from integers in range [0,100]
                                operands[i]=rand()%101;
                                }
                        int list=rand()%10;
                        switch(list){
                                case(0):
					fprintf(fp, "{[(%.0f / %.0f) - %.0f] * %.0f} / %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], operands[4], float((((operands[0]/operands[1])-operands[2])*operands[3])/operands[4]));
                                break;
                                case(1):
					fprintf(fp, "[(%.0f * %.0f) / %.0f] - %.0f + %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], operands[4], float((((operands[0]*operands[1])/operands[2])-operands[3])+operands[4]));
                                break;
                                case(2):
					fprintf(fp, "(%.0f * %.0f * %.0f) - (%.0f / %.0f) = %.4f\n", operands[0], operands[1], operands[2], operands[3], operands[4], float((operands[0]*operands[1]*operands[2])-(operands[3]/operands[4])));
                                break;
                                case(3):
					fprintf(fp, "%.0f - [(%.0f / %.0f) / %.0f] - %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], operands[4], float((operands[0]-((operands[1]/operands[2])/operands[3]))-operands[4]));
                                break;
                                case(4):
					fprintf(fp, "%.0f + %.0f - %.0f + %.0f + %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], operands[4], float(operands[0]+operands[1]-operands[2]+operands[3]+operands[4]));
                                break;
                                case(5):
					fprintf(fp, "(%.0f / %.0f) + [(%.0f / %.0f) * %.0f] = %.4f\n", operands[0], operands[1], operands[2], operands[3], operands[4], float((operands[0]/operands[1])+((operands[2]/operands[3])*operands[4])));
                                break;
                                case(6):
					fprintf(fp, "%.0f - %.0f - %.0f - (%.0f / %.0f) = %.4f\n", operands[0], operands[1], operands[2], operands[3], operands[4], float(operands[0]-operands[1]-operands[2]-(operands[3]/operands[4])));
                                break;
                                case(7):
					fprintf(fp, "{[(%.0f / %.0f) / %.0f] * %.0f} - %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], operands[4], float((((operands[0]/operands[1])/operands[2])*operands[3])-operands[4]));
                                break;
                                case(8):
					fprintf(fp, "{%.0f - %.0f - (%.0f * %.0f)] / %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], operands[4], float((operands[0]-operands[1]-(operands[2]*operands[3]))/operands[4]));
                                break;
                                case(9):
					fprintf(fp, "(%.0f * %.0f) + (%.0f / %.0f) - %.0f = %.4f\n", operands[0], operands[1], operands[2], operands[3], operands[4], float((operands[0]*operands[1])+(operands[2]/operands[3])-operands[4]));
                                break;
                                }//End of switch list
                        }//End of for(j)
		break;
		default:
		break;
		}	//End of switch
	fprintf(fp, "\n\nWARNING: This file will be overwritten at each run of the program.\n");
	fclose(fp); 	//Close file
	puts("Check result.txt for results.");
return 0;
}

int sign(void){
	int result=0, num1=rand()%10, num2=rand()%10;
	if(num1%2==0 && num2%2==0){
		result=1;			//This will be addition (+) result==1
		return result;
		}
	else if(num1%2==0 && num2%2!=0){	//Multiplication (*) result==5
		result=5;
		return result;
		}
	else if(num1%2!=0 && num2%2!=0){	//Difference (-) result==11
		result=11;
		return result;
		}
	else{					//Division (/) result==13
		result=13;
		return result;
		}
}

