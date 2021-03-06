#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#define FALSE 0
#define TRUE 1
#define N 6

typedef struct{
    char* first_name;
    char* last_name;
    int age;
}person;

typedef struct point{
    double x, y;
}point;

typedef struct square{
    point pointArr[4];
}square;

typedef struct{
    int day, car_number, gas_type, total_gas, total_fill;
    double gas_sum;
} car_gas;

typedef struct{
    int row, col;
}point8;

typedef struct{
    point8 p;
    int damage;
}hit;
typedef hit* pHit;

typedef struct{
    char* word;
    int index;
    int direction;
}crossword;

int get_int_arr(int**);
/*----------------------- question 1: -----------------------*/
void question1();
int print_digits(int);
/*----------------------- question 2: -----------------------*/
void question2();
int num_sums(int[], int, int);
/*----------------------- question 3: -----------------------*/
void question3();
int* bisearch(int[], int, int);
/*----------------------- question 4: -----------------------*/
void question4();
int highest_digit(int);
/*----------------------- question 5: -----------------------*/
void question5();
int what5(int*, int, int*);
/*----------------------- question 6: -----------------------*/
void question6();
int what6_1(int*, int*);
int what6_2(int*, int*, int);
/*----------------------- question 7: -----------------------*/
void question7();
void my_itoa(int, char*);
int get_size_of_num(int);
char* person_to_string(person*);
char* join_person(person*, int);
/*----------------------- question 8: -----------------------*/
void question8();
pHit** makeMat(pHit*, int, int*, int*);
pHit** updateMatSize(pHit**, int, int, int, int);
/*----------------------- question 9: -----------------------*/
void question9();
float completeSquares(square*, int size);
int isCompleteSquare(square);
int getQuarter(point);
float getDistance(point, point);
/*----------------------- question 10: -----------------------*/
void question10();
char* str_insert(char*, char*, char*);
/*----------------------- question 11: -----------------------*/
void question11();
int strremove(char*, const char*);
int strremoveAll(char*, const char*);
/*----------------------- question 12: -----------------------*/
void question12();
char* moveWords(char*, int*);
char** getWordsArray(char*);
int getWordSize(char*);
int cntWords(char*);
/*----------------------- question 13: -----------------------*/
void question13();
void subSentence(char*, int);
void setNoSpacesSent(char*, char*);
/*----------------------- question 14: -----------------------*/
void question14();
int gasoline(FILE**, int, char*);
int get_min_car_index(car_gas*, int);
void update_working_car(car_gas*, car_gas*);
int read_next_car(FILE*, car_gas*);
/*----------------------- question 15: -----------------------*/
void question15();
int publicSale(FILE*, FILE*, char*, char*);
/*----------------------- question 16: -----------------------*/
void question16();
void path(int, int[N][N]);
void recsolve (int, int[N][N], int[N][N], int, int, int*, int);
/*----------------------- question 17: -----------------------*/
void question17();
int printStrings(int, int, char*, int, int);
/*----------------------- question 17: -----------------------*/
void question18();
void mergeStrings(char*, char*, char*);


void main() {
    int action;
    do{
        printf("Select Exercise:");
        scanf("%d%*c", &action);
        switch(action){
            case 1:
                question1();
                break;
            case 2:
                question2();
                break;
            case 3:
                question3();
                break;
            case 4:
                question4();
                break;
            case 5:
                question5();
                break;
            case 6:
                question6();
                break;
            case 7:
                question7();
                break;
            case 8:
                question8();
                break;
            case 9:
                question9();
                break;
            case 10:
                question10();
                break;
            case 11:
                question11();
                break;
            case 12:
                question12();
                break;
            case 13:
                question13();
                break;
            case 14:
                question14();
                break;
            case 15:
                question15();
                break;
            case 16:
                question16();
                break;
            case 17:
                question17();
                break;
            case 18:
                question18();
                break;
            default:
                printf("Wrong choice.\n");
        }
    }while(action != 0);
}

void question1(){
    int num;
    printf("Enter num:");
    scanf("%d%*c", &num);
    num = highest_digit(num);
    printf("Highest digit: %d\n", num);
}

int highest_digit(int num){
    int sheerit, rest_max;
    if(num == 0)
        return 0;
    sheerit = num%10;
    rest_max = highest_digit(num/10);
    if(sheerit > rest_max)
        return sheerit;
    return rest_max;
}

int get_int_arr(int** arr){
    char arr_str[100];
    int i, arr_size = 0;
    int* tmp;
    printf("Enter array (with spaces end with '.' -e.g: 3 5 1 2 .):");
    while(scanf("%s%*c", arr_str) != EOF){
        if(strcmp(arr_str, ".")==0)
            break;
        tmp = (int*)malloc(sizeof(int) * arr_size+1);
        for(i=0; i<arr_size;i++)
            tmp[i] = (*arr)[i];
        tmp[i] = atoi(arr_str);
        free(*arr);
        *arr = tmp;
        arr_size++;
    }

    return arr_size;
}

void question2(){
    int num;
    printf("Enter num:");
    scanf("%d%*c", &num);
    num = print_digits(num);
    printf("\n Sum:%d\n", num);
}

int print_digits(int num) {
    int sheerit, rest_sum;
    sheerit = num % 10;
    if (num / 10 == 0) {
        printf(" %d", sheerit);
        return sheerit;
    }
    rest_sum =  print_digits(num/10);
    printf(" %d", sheerit);
    return sheerit + rest_sum;
}

void question3(){
    int *arr, arr_size, num;
    arr_size = get_int_arr(&arr);
    printf("Enter Sum:");
    scanf("%d", &num);
    num = num_sums(arr, arr_size, num);
    printf("Total Sums:%d\n", num);
    free(arr);
}

int num_sums(int *a, int size, int n) {
    if (size<=0) {
        return 0;
    }
    if (*a > n) {
        return num_sums(a+1, size-1, n);
    }
    return *a == n ? 1 : num_sums(a+1, size-1, n-*a) + num_sums(a+1, size-1, n);
}

void question4(){
    int arr_size, num, *arr=NULL, *p=NULL;
    arr_size = get_int_arr(&arr);
    printf("Enter num to search:");
    scanf("%d", &num);
    p = bisearch(arr, arr_size, num);
    if(p)
        printf("%d Found In Address %d -> index %d in array\n", num, (int)p, ((int)p-(int)arr)/4);
    else
        printf("%d Not Found.\n", num);
    free(arr);
}

int* bisearch(int* arr, int size, int num) {
    int cur_num;
    if (size <= 0)
        return NULL;
    cur_num = arr[size / 2];
    if (cur_num == num)
        return arr + (size / 2);
    if(cur_num > num)
        return bisearch(arr, size/2, num);
    return bisearch(arr+(size/2)+1, size%2 == 0? (size/2)-1:(size/2), num);
}

void question5(){
    int result, num;
    int a1[] = {3, 4, 3, 8};
    int a2[] = {3, 8, 9, 3, 2, 5, 2, 7, 2, 9};
    int a3[] = {4, 2, 3, 1, 1, 2, 1, 3, 4, 1};
    result = what5(a1, 4, &num);
    printf("%d %d\n", num, result);
    result = what5(a2, 10, &num);
    printf("%d %d\n", num, result);
    result = what5(a3, 10, &num);
    printf("%d %d\n", num, result);
}

int what5(int *arr, int size, int *p){
    int number;
    if(size==1){
        *p = *arr;
        return 1;
    }
    number = what5(arr,size-1, p);
    if(arr[size-1] == *p)
        return number + 1;
    if(arr[size-1] < *p){
        *p = arr[size-1];
        return 1;
    }
    return number;
}

void question6() {
    int arr1[] = {1, 2, 3, 4, -1};
    int arr2[] = {5, 6, 7, 8, -1};
    printf("%d\n", what6_1(arr1,arr2));
    printf("%d\n", what6_2(arr1,arr2, 0));
    printf("%d\n", what6_2(arr1,arr2, 1));
}

int what6_1(int* arr1, int*arr2){
    if(*arr1 == -1)
        return 0;
    return *arr1 - what6_1(arr2+1, arr1+1);
}

int what6_2(int* arr1, int*arr2, int i){
    if(*arr1 == -1)
        return 0;
    if(i)
        return *arr1 - what6_2(arr1+1, arr2+1, 1-i);
    else
        return *arr2 - what6_2(arr1+1, arr2+1, 1-i);
}

void question7(){
    person persons[3];
    persons[0].first_name = (char*)malloc(sizeof(char)*20);
    persons[0].last_name = (char*)malloc(sizeof(char)*20);
    strcpy(persons[0].first_name, "Gidi");
    strcpy(persons[0].last_name, "Gov");
    persons[0].age = 69;
    persons[1].first_name = (char*)malloc(sizeof(char)*20);
    persons[1].last_name = (char*)malloc(sizeof(char)*20);
    strcpy(persons[1].first_name, "Dani");
    strcpy(persons[1].last_name, "Sanderson");
    persons[1].age = 69;
    persons[2].first_name = (char*)malloc(sizeof(char)*20);
    persons[2].last_name = (char*)malloc(sizeof(char)*20);
    strcpy(persons[2].first_name, "Yoni");
    strcpy(persons[2].last_name, "Rechter");
    persons[2].age = 68;
    printf("%s\n", join_person(persons, 3));
}

void my_itoa(int n, char* str){
    int size_n = get_size_of_num(n);
    int i;
    for(i=size_n-1; i>=0; i--, n/=10)
        str[i] = (char)(n%10 + '0');
    str[size_n] = '\0';
}

int get_size_of_num(int n){
    int cnt = 0;
    for(; n!=0; n/=10, cnt++);
    return cnt;
}

char* person_to_string(person* per1){
    char* per_string = NULL;
    char age[4];
    int i=0;
    my_itoa(per1->age, age);
    unsigned int person_size = strlen(per1->last_name) + strlen(per1->first_name) + strlen(age) + 3;
    per_string = (char*)malloc(sizeof(char)*person_size);
    if(!per_string)
        return NULL;
    strcpy(per_string, per1->first_name);
    strcat(per_string, " ");
    strcat(per_string, per1->last_name);
    strcat(per_string, " ");
    strcat(per_string, age);
}

char* join_person(person* per_arr, int size){
    int i;
    char* cur_per_str = NULL, *new_per_str = NULL, *tmp = NULL;
    for(i=0; i<size; i++){
        cur_per_str = person_to_string(per_arr+i);
        if(!new_per_str){
            new_per_str = cur_per_str;
            continue;
        }
        tmp = (char*)malloc(sizeof(char)*(strlen(cur_per_str) + strlen(new_per_str) + (i!=size-1? 2:1)));
        if(!tmp)
            return NULL;
        strcpy(tmp, new_per_str);
        free(new_per_str);
        new_per_str = tmp;
        if(i!=size)
            strcat(new_per_str, "; ");
        strcat(new_per_str, cur_per_str);
    }
    new_per_str[strlen(new_per_str)] = '\0';
    return new_per_str;
}

void question8(){
    int plines, pcolumns, arr_size = 5;
    int i, j;
    pHit arr[arr_size];
    for(i=0; i<arr_size; i++)
        arr[i] = (pHit)malloc(sizeof(hit));
    arr[0]->p.row = 1; arr[0]->p.col = 1; arr[0]->damage = 12;
    arr[1]->p.row = 2; arr[1]->p.col = 3; arr[1]->damage = 9;
    arr[2]->p.row = 5; arr[2]->p.col = 2; arr[2]->damage = 14;
    arr[3]->p.row = 4; arr[3]->p.col = 0; arr[3]->damage = 2;
    arr[4]->p.row = 6; arr[4]->p.col = 1; arr[4]->damage = 77;
    pHit** mat = makeMat(arr, arr_size, &plines, &pcolumns);
    for(i=0; i<plines; i++){
        for(j=0; j<pcolumns; j++) {
            if (mat[i][j])
                printf("(%02d,%02d,%02d) ", mat[i][j]->p.row, mat[i][j]->p.col, mat[i][j]->damage);
            else
                printf("    NULL   ");
        }
        printf("\n");
    }
}

pHit** makeMat(pHit* arr, int size, int* plines, int* pcolumns){
    pHit** mat = NULL;
    pHit cur_hit;
    int i, max_row, max_col;
    *plines = *pcolumns = 0;
    for(i=0; i<size; i++){
        cur_hit = arr[i];
        if(cur_hit->damage < 10)
            continue;
        if(cur_hit->p.row > *plines-1 || cur_hit->p.col > *pcolumns-1){
            max_row = *plines > cur_hit->p.row? *plines : cur_hit->p.row+1;
            max_col = *pcolumns > cur_hit->p.col? *pcolumns : cur_hit->p.col+1;
            mat = updateMatSize(mat, *plines, *pcolumns, max_row, max_col);
            *plines = max_row;
            *pcolumns = max_col;
        }
        mat[cur_hit->p.row][cur_hit->p.col] = cur_hit;
    }
    return mat;
}

pHit** updateMatSize(pHit** oldMat, int old_row, int old_col, int new_row, int new_col){
    int i,j;
    pHit** newMat = (pHit**)malloc(sizeof(pHit*) * new_row);
    for(i=0; i<new_row; i++)
        newMat[i] = (pHit*)malloc(sizeof(pHit)*new_col);
    for(i=0; i<new_row; i++)
        for(j=0; j<new_col; j++){
            if(i>=old_row || j >=old_col)
                newMat[i][j] = NULL;
            else
                newMat[i][j] = oldMat[i][j];
        }
    if(oldMat){
        for(i=0; i<old_row ;i++)
            free(oldMat[i]);
        free(oldMat);
    }
    return newMat;
}

void question9(){
    square squares[3];
    //square[0] is a complete square!
    squares[0].pointArr[0].x = 50;  squares[0].pointArr[0].y = 50;
    squares[0].pointArr[1].x = 50;  squares[0].pointArr[1].y = -50;
    squares[0].pointArr[2].x = -50; squares[0].pointArr[2].y = -50;
    squares[0].pointArr[3].x = -50; squares[0].pointArr[3].y = 50;
    //square[1] is not a complete square (distance<10)!
    squares[1].pointArr[0].x = 4;  squares[1].pointArr[0].y = 4;
    squares[1].pointArr[1].x = 4; squares[1].pointArr[1].y = -4;
    squares[1].pointArr[2].x = -4;  squares[1].pointArr[2].y = -4;
    squares[1].pointArr[3].x = -4; squares[1].pointArr[3].y = 4;
    //square[2] is not a complete square (quarters not follow)!
    squares[2].pointArr[0].x = 50;  squares[2].pointArr[0].y = 50;
    squares[2].pointArr[1].x = -50; squares[2].pointArr[1].y = 50;
    squares[2].pointArr[2].x = -50;  squares[2].pointArr[2].y = -50;
    squares[2].pointArr[3].x = 50; squares[2].pointArr[3].y = -50;
    printf("%f\n", completeSquares(squares, 3));
}

int isCompleteSquare(square sq){
    int i, cur_qrtr, next_qrtr;
    for(i=0; i<4; i++){
        if(getDistance(sq.pointArr[i], sq.pointArr[(i+1)%4]) < 10)
            return FALSE;
        cur_qrtr = getQuarter(sq.pointArr[i]);
        next_qrtr = getQuarter(sq.pointArr[(i+1)%4]);
        if(cur_qrtr%4 + 1 != next_qrtr)
            return FALSE;
    }
    return TRUE;
}

float getDistance(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

float completeSquares(square *arr, int size){
    int cntCompleteSquares = 0,i;
    for(i=0;i<size;i++)
        if(isCompleteSquare(arr[i]))
            cntCompleteSquares++;
    return (float)cntCompleteSquares/(float)size;
}

int getQuarter(point p){
    double x = p.x;
    double y = p.y;
    if(x>0 && y>0)
        return 1;
    if(x>0 && y<0)
        return 2;
    if(x<0 && y<0)
        return 3;
    if(x<0 && y>0)
        return 4;
    return -1;
}

void question10(){
    char* str = "I like ice cream";
    char* new_str = str_insert(str, "do not ", str+2);
    printf("%s\n", new_str);
    free(new_str);
}

char* str_insert(char* str1, char* str2, char* at){
    int i, newlen;
    char* new_str, *tmp;
    if(at>str1+strlen(str1))
        return NULL;
    newlen = strlen(str1)+strlen(str2);
    if(!(new_str = (char*)malloc(sizeof(char)*(newlen+1)))) return NULL;
    tmp = new_str;
    for(i=0;i<newlen;i++)
        new_str[i]='.';
    new_str[i] = '\0';
    while(*tmp){
        if(str1<at)
            *tmp = *(str1++);
        else if(*str2)
            *tmp = *(str2++);
        else
            *tmp = *(str1++);
        tmp++;
    }
    return new_str;
}

void question11(){
    char str[] = "The bigger the error the lower the grade.";
    int cnt_found = strremoveAll(str, "er");
    puts(str);
    printf("%d\n",cnt_found);
}

int strremove(char* str, const char* rem){
    if(!*str || !*rem)
        return -1;
    int i;
    int found = FALSE;
    char *start = str;
    while(*start){
        if(*start == *rem){
            found = TRUE;
            for(i=0; i<(int)strlen(rem); i++)
                if(*(start+i)!=*(rem+i)) {
                    found = FALSE;
                    break;
                }
        }
        if(found)
            break;
        start++;
    }
    if(found){
        i = start-str;
        while(*(start+strlen(rem))){
            *start = *(start+strlen(rem));
            start++;
        }
        *start = '\0';
        return i;
    }
    return -1;
}
int strremoveAll(char* str, const char* rem){
    int cnt = 0, found_ind=0;
    do{
        found_ind = strremove(str+found_ind, rem);
        if(found_ind!=-1)
            cnt++;
    }while(found_ind != -1);
    return cnt;
}

void question12(){
    char *new_str = NULL;
    char str[] = "You have         to dream before your dreams can come true";
    int arr[] = {1, 8, 13, 4, 15, 5, 6, 4, 9, 18, 10, 17, -1};
    new_str = moveWords(str, arr);
    puts(new_str);
}

char* moveWords(char* sentence, int* arr){
    char** str_array = NULL;
    int i, j, cnt_letter=0;
    char* new_str = NULL, *cur_word = NULL;
    str_array = getWordsArray(sentence);
    int cnt_words = cntWords(sentence);
    new_str = (char*)malloc(sizeof(char)*(strlen(sentence)+1));
    if(!cnt_words)
        return NULL;
    for(i=0; arr[i] != -1; i++){
        if(arr[i] > cnt_words)
            continue;
        cur_word = str_array[arr[i]-1];
        for(j=0; j < (int)strlen(cur_word); j++)
            new_str[cnt_letter++] = cur_word[j];
        new_str[cnt_letter++] = ' ';
    }
    new_str[cnt_letter] = '\0';
    //TODO freeStringArray(str_array);
    return new_str;
}

char** getWordsArray(char* sentence){
    char** str_array = (char**)malloc(sizeof(char*)*cntWords(sentence));
    if(!str_array)
        return NULL;
    int cnt_words = 0, i, j;
    for(i=0; i<(int)strlen(sentence); i++){
        if(sentence[i] == ' ')
            continue;
        str_array[cnt_words] = (char*)malloc(sizeof(char) * (getWordSize(sentence+i)+1));
        if(!str_array[cnt_words]){
            //TODO freeStringArray(str_array);
            return NULL;
        }
        for(j=0; sentence[i]!=' ' && i<strlen(sentence); j++,i++)
            str_array[cnt_words][j] = sentence[i];
        str_array[cnt_words][j] = '\0';
        cnt_words++;
    }
    return str_array;
}

int cntWords(char* sentence){
    int cnt_words = 0, isInWord = FALSE, i;
    for(i=0; i < (int)strlen(sentence); i++){
        if(sentence[i] == ' '){
            isInWord = FALSE;
            continue;
        }
        if(!isInWord){
            cnt_words++;
            isInWord = TRUE;
        }
    }
    return cnt_words;
}

int getWordSize(char* sentence){
    int cnt_chars = 0;
    while(sentence[cnt_chars] != ' ' && sentence[cnt_chars] != '\0' && ++cnt_chars);
    return cnt_chars;
}

void question13(){
    char sent[] = "This is a sentence";
    subSentence(sent,2);
}

void subSentence(char* sent, int length){
    char *p1 = NULL;
    char *cur_word = (char*)malloc(sizeof(char)*(length+1));
    char *sentNoSpaces = (char*)malloc(sizeof(char)*strlen(sent));
    int i;
    setNoSpacesSent(sent, sentNoSpaces);
    for(i=0; i<(int)strlen(sentNoSpaces)-length+1; i++){
        strncpy(cur_word, sentNoSpaces+i, length);
        cur_word[length] = '\0';
        p1 = strstr(sentNoSpaces, cur_word);
        if(p1 == sentNoSpaces+i)
            puts(cur_word);
    }
    free(cur_word);
    free(sentNoSpaces);
}

void setNoSpacesSent(char* sent, char* sentNoSpaces){
    int i, cnt_relevant = 0;
    for(i=0; i<(int)strlen(sent); i++)
        if(sent[i] != ' ')
            sentNoSpaces[cnt_relevant++] = sent[i];
    sentNoSpaces[cnt_relevant] = '\0';
}

void question14(){
    int size = 3;
    FILE* arr[size];
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    if(!(arr[0] = fopen("question14\\gasoline_in1.txt", "r"))) exit(1);
    if(!(arr[1] = fopen("question14\\gasoline_in2.txt", "r"))) exit(1);
    if(!(arr[2] = fopen("question14\\gasoline_in3.txt", "r"))) exit(1);
    if(gasoline(arr, size, "question14\\gasoline_out.txt"))
        printf("Done! check %s\n", cwd);
    else
        printf("Something went wrong :(\n");
}

int gasoline(FILE** arr, int size, char* filename) {
    FILE *fp_out = fopen(filename, "w");
    if (!fp_out) return 0;
    car_gas *unified_arr = (car_gas *) malloc(sizeof(car_gas) * size);
    if (!unified_arr) {
        fclose(fp_out);
        return 0;
    }
    car_gas working_car;
    int i, num_eof = 0, min_ind, first=TRUE;
    for (i = 0; i < size; i++)
        if (!read_next_car(arr[i], &unified_arr[i]))
            num_eof++;
    while(num_eof != size){
        min_ind = get_min_car_index(unified_arr, size);
        if(!first)
            if(working_car.day < unified_arr[min_ind].day || working_car.car_number != unified_arr[min_ind].car_number)
                fprintf(fp_out, "%02d%07d%d%03d%06.2f%1d\n", working_car.day, working_car.car_number, working_car.gas_type, working_car.total_gas, working_car.gas_sum, working_car.total_fill);
        first = FALSE;
        update_working_car(&working_car, unified_arr+min_ind);
        if(!read_next_car(arr[min_ind], &unified_arr[min_ind]))
            num_eof++;
    }
    fprintf(fp_out, "%02d%07d%d%03d%06.2f%1d\n", working_car.day, working_car.car_number, working_car.gas_type, working_car.total_gas, working_car.gas_sum, working_car.total_fill);
    for(i=0;i<size;i++)
        fclose(arr[i]);
    fclose(fp_out);
    return TRUE;
}

int get_min_car_index(car_gas* unified_arr, int size) {
    int min_day = 100, min_number=10000000, min_ind=-1, i;
    for (i = 0; i < size; i++){
        if (unified_arr[i].day < min_day){
            min_day = unified_arr[i].day;
            min_number = unified_arr[i].car_number;
            min_ind = i;
            continue;
        }
        if(unified_arr[i].day == min_day){
            if(unified_arr[i].car_number < min_number){
                min_number = unified_arr[i].car_number;
                min_ind = i;
            }
        }
    }
    return min_ind;
}

void update_working_car(car_gas* working_car, car_gas* cur_car){
    if(working_car->day == cur_car->day && working_car->car_number == cur_car->car_number){
        working_car->total_fill++;
        working_car->gas_sum += cur_car->gas_sum;
        working_car->total_gas += cur_car->total_gas;
    }
    else{
        working_car->day = cur_car->day;
        working_car->car_number = cur_car->car_number;
        working_car->gas_type = cur_car->gas_type;
        working_car->total_gas = cur_car->total_gas;
        working_car->gas_sum = cur_car->gas_sum;
        working_car->total_fill = 1;
    }
}

int read_next_car(FILE* file, car_gas* next_car){
    int eof_stat = fscanf(file, "%2d%*5c%7d%1d%3d%lf%*c", &next_car->day, &next_car->car_number, &next_car->gas_type, &next_car->total_gas, &next_car->gas_sum);
    if(eof_stat == EOF){
        next_car->day = 100;
        return FALSE;
    }
    return TRUE;
}

void question15(){
    FILE *forSale = fopen("question15\\items.txt", "r");
    FILE *offers = fopen("question15\\offers.txt", "r");
    publicSale(forSale, offers,"question15\\notSold.txt", "question15\\sold.txt");
    fclose(forSale);
    fclose(offers);
}

int publicSale(FILE *forSale, FILE *offers, char * notSold, char* sold) {
    FILE *fSold, *fNotSold;
    int codForS, codOffer, start, propPrice, finalPrice, flagO, total= 0;
    char item[36], details[30], finalDetails[30];
    if (!(fNotSold = fopen(notSold, "w")) || !(fSold = fopen(sold, "w")))
        return -1;
    if ((flagO = fscanf(offers, "%29[^\n]%*20c%3d%6d%*c",
                        details, &codOffer, &propPrice)) != 3)
        return -1;
    while(fscanf(forSale,"%3d%35[^\n]%6d%*c", &codForS,item,&start)==3){
        if (flagO == EOF || codForS != codOffer) {
            fprintf(fNotSold, "%03d%s%06d\n", codForS, item, start);
            continue;
        }
        finalPrice = propPrice;
        total += finalPrice;
        do {
            if (finalPrice == propPrice)
                strcpy(finalDetails, details);
            flagO = fscanf(offers, "%29[^\n]%*20c%3d%6d%*c",
                           details, &codForS, &finalPrice);
        } while (flagO != EOF && codForS == codOffer);
        fprintf(fSold,"%03d%s%06d\n", codForS,finalDetails,finalPrice);
    }
    if (fclose(fNotSold) == EOF || fclose(fSold) == EOF)
        return -1;
    return total;
}

void question16(){
    int board[N][N] ={{1,1,1,1,1,1},
                      {2,3,4,5,1,1},
                      {2,2,1,1,1,1},
                      {3,7,1,7,6,1},
                      {4,6,1,1,1,1},
                      {5,8,7,8,4,1}
    };
    path(N, board);
}

void recsolve (int size, int board[N][N], int visit[N][N], int r, int c, int* shortestLength, int lengthTillNow){
    visit[r][c]=1;
    if ( (r == size-1) && (c == size-1) ) {
        if ( *shortestLength > lengthTillNow )
            *shortestLength = lengthTillNow ;
    }
    if ( r>0 && board[r-1][c]==board[0][0] && !visit[r-1][c] && *shortestLength >lengthTillNow)
        recsolve(size, board, visit, r-1, c, shortestLength, lengthTillNow+1);
    if ( r < size-1 && board[r+1][c]==board[0][0] &&visit[r+1][c] == 0 && *shortestLength > lengthTillNow)
        recsolve(size, board, visit, r+1, c, shortestLength, lengthTillNow+1);
    if ( c>0 && board[r][c-1] == board[0][0] && visit[r][c-1] ==0 &&*shortestLength > lengthTillNow)
        recsolve(size, board, visit, r, c-1, shortestLength, lengthTillNow+1);
    if (c < size-1 && board[r][c+1]==board[0][0] && visit[r][c+1]==0&& *shortestLength > lengthTillNow)
        recsolve(size, board, visit, r, c+1, shortestLength, lengthTillNow+1);
    visit[r][c] = 0;
}

void path (int size, int board[N][N]){
    int visit[N][N] = {0};
    int shortestLength = size*size;
    if (board[0][0]!=board[size-1][size-1])
        printf("0\n");
    else{
        recsolve(size, board,visit,0,0, &shortestLength, 1 );
        if (shortestLength!=size*size)
            printf("%d\n",shortestLength);
        else
            printf("0\n");
    }
    return;
}

void question17(){
    char str[4];
    str[4] = '\0';
    printf("printStrings: %d\n", printStrings(0, 3, str, 0, 0));
}

int printStrings(int i, int n, char* str, int a, int c){
    int count = 0;
    if(i==n){
        printf("%s, ", str);
        return 1;
    }
    if(a==1)
        a = 0;
    else{
        str[i] = 'a';
        count+=printStrings(i+1, n, str, a+1, c);
    }
    str[i] = 'b';
    count += printStrings(i+1, n, str, a, c);
    if(c==2)
        c = 1;
    else{
        str[i] = 'c';
        count += printStrings(i+1, n, str, a, c+1);
    }
    return count;
}

void question18(){
    char s1[] = "abcf";
    char s2[] = "ade";
    char s3[strlen(s1)+strlen(s2)];
    s3[strlen(s1)+strlen(s2)] = '\0';
    mergeStrings(s1, s2, s3);
    printf("First String: %s\nSecond String: %s\nMerged String: %s\n", s1, s2, s3);
}

void mergeStrings(char* str1, char* str2, char* str3){
    if(!*str1 && !*str2)
        return;
    if(!*str1 || *str2<*str1){
        *str3 = *str2;
        return mergeStrings(str1, str2+1, str3+1);
    }
    *str3 = *str1;
    return mergeStrings(str1+1, str2, str3+1);
}