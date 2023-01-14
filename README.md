# School_C_Project
### (A) Intro to project features:

The Project consist of 6 options as bellow:

(1) to Add New Student.

(2) to Edit Student Data.

(3) to Delete Student.

(4) To print All Students.

(5) to print Specific Student.

(6) to call specific student.

Each one has its own functions and some shared same source files.
First Add feature: in this mode you add all student data (name-gender-age-telephone), and family data as well father, mother and brothers/sisters, after that came the core of any school the subjects, also add (name-max_degree-student_degree) with limits on input, the overall gpa would be calculated by the program and could be displaied form print student or print all students.

Edit Mode: here you can add any this, any data you enrolled except brothers/sisters data (maybe i will add this feature some time else).
Delete mode: from the name lets kick some students :P.

Lets jump to call mode as it would display student number and the call would start (not really), and after few seconds message with no responce would appear.

*************************************************************************************************************************************************************
### (B)Idea:

*The main core which is array of structures, this array would hold the all students in it which i would refer as (std_Object), the student is person with subjects to study so the structure of the std_object would contain structure to person and pointer to structure of subject type as nmuber of subjects isn't fixed,
Id of student is the same as array index for making things easily, and there is an global variable contain amount of current students in the school.

*************************************************************************************************************************************************************
### (C)Project Files:

There are 6 c source files and so headers files, each file hold some functions to make one of the previous mentioned features work.

(1)Insertion_Editing: this file hold most of the work, it consist all functions would connect main file with data base, if user wanted to add student in the main just call Insertion_Add_Student(), and it would start connect with database.c file using functions to add student data.
(2)Printing: contain all the function that print any information about the std_Object also contain the implementaion of call student function.
(3)Data_Base: this fill contain the array of structure i mentioned before, also most modules has access to it except main file.
(4)Validation: any function check or find for id or name of student in the project would be found there also the delete student function.
(5)String: most of the string funcion i used are implemented in this file. i recommend see the content of it as well.

thats all for this project, in future insha allah, i would modify the data base file to contain functions which deals with files stored in the system to save the students data in them.
