/* Recent coding assignment
    I created a menu driven program to manage the records in the binary file. The
    Goal of the assignment was to create a record structure for a student's ID, name, email, course ID 
    and grade. I also had to make sure I could delete, update, add, print and find student records.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining the student record struct
struct Record {
    int studentID;
    char studentName[50];
    char emailID[50];
    int courseID;
    char grade[3];
};

//functions for managing the student records
void addRecord(FILE* file);
void displayRecords(FILE* file);
void searchRecord(FILE* file, int id);
void updateRecord(FILE* file, int id);
void deleteRecord(FILE* file, int id);
void createFile();

//main function, initializes file, displays menu options
int main() {
    FILE* file;
    errno_t err = fopen_s(&file, "records.dat", "rb+"); //opens file

    //checks if file exists
    if (err != 0 || file == NULL) {
        printf("File could not be opened. Creating a new file.\n");
        createFile(); //Create the file if it doesn't exist
        err = fopen_s(&file, "records.dat", "rb+"); //Re-open the file after creation
        if (err != 0 || file == NULL) {
            printf("File could not be opened after creation. Error code: %d\n", err);
            return 1; //Exit if the file couldn't be opened
        }
    }



    int choice;
    do {

        //prints menu option
        printf("         MAIN MENU\n");
        printf("1. Create the binary file\n");
        printf("2. Add Record to the file\n");
        printf("3. Display the contents of the file\n");
        printf("4. Seek specific record\n");
        printf("5. Update the contents of a record\n");
        printf("6. Delete a record for a specific name\n");
        printf("7. Exit\n");
        printf("  \n");
        printf("      Please enter your choice....");
        printf("  \n");
        scanf_s("%d", &choice);
        printf("  \n");

        //switch statement for user input
        switch (choice) {


        case 1:
            //create file choice
            fclose(file); //Closes current file
            createFile(); //Creates file
            err = fopen_s(&file, "records.dat", "rb+"); //Re-open the file
            if (err != 0 || file == NULL) {
                printf("File could not be opened after re-creation. Error code: %d\n", err);
            }
            else {
                printf("File re-opened successfully.\n");
            }
            printf("  \n");
            break;
        case 2:
            //add record
            addRecord(file);
            printf("  \n");
            break;
        case 3:
            //display record
            displayRecords(file);
            printf("  \n");
            break;
        case 4:
            //seek specific record
            printf("Enter Student ID to search: ");
            int searchID;

            //checks if user input is valid
            while (scanf_s("%d", &searchID) != 1) {
                printf("Invalid input. Please enter a valid integer for Student ID: ");
                while (getchar() != '\n'); //Clear the input buffer
            }
            searchRecord(file, searchID);
            printf("  \n");
            break;
        case 5:
            //update student record choice
            printf("Enter Student ID to update: ");
            int updateID;
            scanf_s("%d", &updateID);
            updateRecord(file, updateID);
            printf("  \n");
            break;
        case 6:
            //delete student record choice
            printf("Enter Student ID to delete: ");
            int deleteID;
            scanf_s("%d", &deleteID);
            deleteRecord(file, deleteID);
            printf("  \n");
            break;
        case 7:
            //exits program
            printf("Exiting program.\n");
            printf("  \n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            printf("  \n");
        }


    } while (choice != 7);

    //closes file if its still open
    if (file != NULL) {
        fclose(file);
    }

    return 0;
}



//creating file function
void createFile() {
    FILE* newFile;
    errno_t err = fopen_s(&newFile, "records.dat", "wb"); //Creating a file
    if (err != 0 || newFile == NULL) { //checks if there was an error opening the file or if file is null
        printf("Error creating file.\n");
        return;
    }
    fclose(newFile);
    printf("File created successfully.\n");
}


//add record function
void addRecord(FILE* file) {
    struct Record record;

    printf("Enter Student ID: ");

    //makes sure user input is valid
    while (scanf_s("%d", &record.studentID) != 1) {
        printf("Invalid input. Please enter a valid integer for Student ID: ");
        while (getchar() != '\n'); //Clear the input buffer
    }

    printf("Enter Student Name: ");
    scanf_s("%49s", record.studentName, (unsigned)sizeof(record.studentName));

    printf("Enter Email ID: ");
    scanf_s("%49s", record.emailID, (unsigned)sizeof(record.emailID));

    printf("Enter Course ID: ");

    //makes sure input is valid
    while (scanf_s("%d", &record.courseID) != 1) {
        printf("Invalid input. Please enter a valid integer for Course ID: ");
        while (getchar() != '\n'); //Clear the input buffer
    }

    printf("Enter Grade (Letter Grade): ");

    //makes sure input is valid
    while (scanf_s("%2s", record.grade, (unsigned)sizeof(record.grade)) != 1) {
        printf("Invalid input. Please enter a valid letter grade: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    printf(" ");
    fseek(file, 0, SEEK_END); //Move the file pointer to the end


    //makes sure that the record was recorded successfully
    if (fwrite(&record, sizeof(struct Record), 1, file) != 1) {
        printf("Error writing record to file.\n");
    }
    else {
        printf("Record added successfully.\n");
    }

    printf(" ");
}


//Update record function
void updateRecord(FILE* file, int id) {
    struct Record record;
    int found = 0;

    //makes sure file is not null
    if (file == NULL) {
        printf("Error: File pointer is NULL.\n");
        return;
    }

    //Checks if the file is empty
    fseek(file, 0, SEEK_END); //moves the file pointer to the end
    long fileSize = ftell(file); //Gets the file size
    if (fileSize == 0) {
        printf("The file is empty.\n");
        return;
    }

    rewind(file); //Movess the file pointer to the beginning

    //Searches for the record
    while (fread(&record, sizeof(struct Record), 1, file) == 1) {
        if (record.studentID == id) {
            found = 1;
            printf("Enter new Student Name: ");
            scanf_s("%49s", record.studentName, (unsigned)sizeof(record.studentName));

            printf("Enter new Email ID: ");
            scanf_s("%49s", record.emailID, (unsigned)sizeof(record.emailID));

            printf("Enter new Course ID: ");
            //makes sure user input is valid
            while (scanf_s("%d", &record.courseID) != 1) {
                printf("Invalid input. Please enter a valid integer for Course ID: ");
                while (getchar() != '\n'); //Clear the input buffer
            }

            printf("Enter new Grade (letter grade): ");
            //makes sure user input is valid
            while (scanf_s("%2s", record.grade, (unsigned)sizeof(record.grade)) != 1) {
                printf("Invalid input. Please enter a valid letter grade: ");
                while (getchar() != '\n'); // Clear the input buffer
            }



            fseek(file, -(long)sizeof(struct Record), SEEK_CUR); //Moves the file pointer back

            //checks if the record was updated to the file correctly
            if (fwrite(&record, sizeof(struct Record), 1, file) != 1) {
                printf("Error updating record in file.\n");
            }
            else {
                printf("Record updated successfully.\n");
            }
            break;
        }



    }

    //If not found
    if (!found) {
        printf("Record with Student ID %d not found.\n", id);
    }
}


//Display records function
void displayRecords(FILE* file) {
    struct Record record;

    //if files null
    if (file == NULL) {
        printf("Error: File pointer is NULL.\n");
        return;
    }

    fseek(file, 0, SEEK_END);//Moves the file pointer to the end
    long fileSize = ftell(file);//Gets the file size

    //checks file size
    if (fileSize == 0) {
        printf("The file is empty.\n");
        return;
    }

    rewind(file);//Moves the file pointer to the beginning


    // Prints all the records found in the file
    printf("%-10s %-20s %-30s %-10s %-5s\n", "Student ID", "Student Name", "Email ID", "Course ID", "Grade");
    int recordFound = 0;

    while (fread(&record, sizeof(struct Record), 1, file) == 1) {
        printf("%-10d %-20s %-30s %-10d %-5s\n",
            record.studentID,
            record.studentName,
            record.emailID,
            record.courseID,
            record.grade); // %s for grade
        recordFound = 1;
    }

    //if no records
    if (!recordFound) {
        printf("No records found.\n");
    }


}


//Search record function
void searchRecord(FILE* file, int id) {

    //checks if file is null
    if (file == NULL) {
        printf("Error: File pointer is NULL.\n");
        return;
    }

    struct Record record;
    int found = 0;

    rewind(file); //Moves the file pointer to the beginning

    //Checks if the file is empty
    if (fseek(file, 0, SEEK_END) == 0 && ftell(file) == 0) {
        printf("The file is empty.\n");
        return;
    }

    //Moves the file pointer to the beginning
    rewind(file);

    //Searches for the record
    while (fread(&record, sizeof(struct Record), 1, file) == 1) {
        if (record.studentID == id) {
            found = 1;
            printf("Record found:\n");
            printf("Student ID: %d\n", record.studentID);
            printf("Student Name: %s\n", record.studentName);
            printf("Email ID: %s\n", record.emailID);
            printf("Course ID: %d\n", record.courseID);
            printf("Grade: %s\n", record.grade);
            break;
        }
    }

    //If not found
    if (!found) {
        printf("Record with Student ID %d not found.\n", id);
    }


}


//delete record function
void deleteRecord(FILE* file, int id) {
    struct Record record;
    FILE* tempFile;
    errno_t err; //error handling

    //Open a temporary file 
    err = fopen_s(&tempFile, "temp.dat", "wb");
    if (err != 0 || tempFile == NULL) {
        printf("Error creating temporary file.\n");
        return;
    }

    rewind(file); //Moves the file pointer to the beginning
    int found = 0;

    //copies records to temp file (except deleted record)
    while (fread(&record, sizeof(struct Record), 1, file) == 1) {
        if (record.studentID == id) {
            found = 1; //Record to be deleted
            continue; //Skip the record to be deleted
        }
        //write current record to temp file
        if (fwrite(&record, sizeof(struct Record), 1, tempFile) != 1) {
            printf("Error writing record to temporary file.\n");
            fclose(tempFile);
            return;
        }
    }

    fclose(file); //Closes the original file
    fclose(tempFile); //Closes the temporary file

    //Removes the original file
    if (remove("records.dat") != 0) {
        printf("Error removing the original file.\n");
        return;
    }

    //Rename the temporary file to the original file name
    if (rename("temp.dat", "records.dat") != 0) {
        printf("Error renaming the temporary file.\n");
        return;
    }

    //Reopens the file
    err = fopen_s(&file, "records.dat", "rb+");
    if (err != 0 || file == NULL) {
        printf("Error reopening the file.\n");
        return;
    }

    //if the deleted record was found
    if (found) {
        printf("Record with Student ID %d deleted successfully.\n", id);
    }
    else {//if not

        remove("temp.dat"); //Remove the temporary file if record not found
        printf("Record with Student ID %d not found.\n", id);
    }


}
