#include<stdio.h>
#include<stdlib.h>
//function to create a new file
void createFile(const char *filename){
    FILE *fp = fopen(filename,"w"); //open file in write mode(creates new or overwrites)
    if (fp==NULL){
        printf("Error creating file!\n");
        return;
    }
    printf("File created successfully:%\n",filename);
    fclose(fp);  //close the file
}
//function to write data to file (overwrites existing content)
void writeFile(const char *filename){
    FILE *fp = fopen(filename,"w");  //open file in write mode
    if (fp==NULL){
        printf("Error opening file for writing!\n");
        return;
    }
    char data[100];
    printf("Enter data to write to the file:\n");
    fflush(stdin);  //clear the input buffer
    fgets(data, sizeof(data),stdin);  //get input from user
    fputs(data,fp);  //write data to file
    printf("Data written successfully.\n");
    fclose(fp);
}

//function to append data to file 
void appendFile(const char *filename){
    FILE *fp= fopen(filename,"a");  //open file in append mode
    if (fp==NULL){
        printf("Error  opening file for appending!\n");
        return;
    }
    char data[100];
    printf("Enter data to append to the file:\n");
    fflush(stdin);
    fgets(data, sizeof(data),stdin);
    fputs(data,fp);  //append data to file
    printf("Data appended successfully.\n");
    fclose(fp);
}

//function to read and display file content
void readFile(const char *filename){
    FILE *fp = fopen(filename,"r"); //open file in read mode
    if (fp==NULL){
        printf("Error opening file for read!\n");
        return;
    }
    char ch;
    printf("\nContents of the file:\n");
    while ((ch= fgetc(fp)) != EOF){  //read character by character
        putchar(ch);  //display character
    }
    fclose(fp);
}

int main(){
    char filename[50]="codtech_file.txt"; //default filename
    int choice;  //menu driven program
    do{
        printf("1. Create file\n");
        printf("2. Write to file\n");
        printf("3. Append to file\n");
        printf("4. Read file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline from input buffer

        switch (choice){
            case 1:
                createFile(filename);
                break;
            case 2:
                writeFile(filename);
                break;
        
            case 3:
                appendFile(filename);
                break;
            case 4:
                readFile(filename);
                break;
            case 5:
                printf("Exiting program......\n");
                break;
            default:
                printf("Invalid choice.Try again.\n");
        


        }
    }
    while (choice != 5); //Repeat until user chooses to exit
    return 0;
}