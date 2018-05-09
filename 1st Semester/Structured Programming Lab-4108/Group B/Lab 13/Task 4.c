SabiSa#include <stdio.h>

int main(){
    int i=0;
    double arr[11]={},a[11]={},b[11]={},c[11]={};
    //Taking input
    for(i=0; i<10; i++)     scanf("%lf",&arr[i]);
    //First type of file writing
    FILE *fp1=fopen("Task 3 File 1.txt", "wb");
    for(i=0; i<10; i++){
        fwrite(&arr[i],sizeof arr[i],1, fp1);
    }
    fclose(fp1);
    //Printing the first file writing type
    fp1=fopen("Task 3 File 1.txt", "rb");
    printf("This is reading the first file \n");
    for(i=0; i<10; i++){
        fread(&a[i],sizeof a[i],1, fp1);
        printf("%lf\n",a[i]);
    }
    //Second type of file saving
    fp1=fopen("Task 3 File 2.txt", "wb");
    fwrite(arr,sizeof arr,1, fp1);
    fclose(fp1);
    //Printing the second type of file saving
    fp1=fopen("Task 3 File 1.txt", "rb");
    printf("This is reading the second file \n");
    fread(b,sizeof b,10, fp1);
    for(i=0; i<10; i++){
        printf("%lf\n",b[i]);
    }
    fclose(fp1);
    //Third type of file saving
    fp1=fopen("Task 3 File 3.txt", "wb");
    fwrite(arr,sizeof arr[0],10, fp1);
    fclose(fp1);
    //Printing the third type of file saving
    fp1=fopen("Task 3 File 3.txt", "rb");
    fread(c,sizeof c,10, fp1);
    printf("This is reading the third file \n");
    for(i=0; i<10; i++)
        printf("%lf\n",c[i]);
    fclose(fp1);
    return 0;
}
