#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
int sethp (int HP){
    if(HP>666) HP = 666;
    if(HP<0) HP = 0;
    return HP;
}
int setexp(int exp){
    if(exp>600) exp = 600;
    if(exp<0) exp = 0;
    return exp;
}
int setm(int m){
    if(m>3000) m=3000;
    if(m<0) m = 0;
    return m;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    exp1 = setexp(exp1);
    exp2 = setexp(exp2);
    if (e1 < 0 || e1 > 99) return -99;
    if(e1 >= 0 && e1 <= 3) { 
      if(e1 == 0) exp2+=29;
      if(e1 == 1) exp2+=45;
      if(e1 == 2 ) exp2+=75;
      if(e1 == 3 ) exp2+=(29 + 45 + 75);
      int d;
          d = e1*3 + exp1*7;
      if((d%2) == 0 ) {exp1 = exp1 + ceil(d/200.0);}
        else {exp1 = ceil(exp1 - d/100.0);}
    }
    if(e1 >= 4 && e1 <= 99) {
      if(e1 >= 4 && e1 <= 19) exp2 += ceil(e1/4.0 + 19);
      if(e1 >= 20 && e1 <= 49) exp2 += ceil(e1/9.0 + 21);
      if(e1 >= 50 && e1 <= 65) exp2 += ceil(e1/16.0 + 17);
      if(e1 >= 66 && e1 <= 79) {
        exp2 += ceil(e1/4.0 + 19);
        if(exp2 > 200) exp2 += ceil(e1/9.0 + 21);
      }
      if(e1 >= 80 && e1 <= 99) {
        exp2 += ceil(e1/4.0 + 19); exp2 +=ceil(21 +  e1/9.0);
        if(exp2 > 400) {
            exp2 += ceil(e1/16.0 + 17);
            exp2 += ceil(exp2*15.0/100);
           }
      }
      exp1 -= e1;
    } 
    exp1 = setexp(exp1);
    exp2 = setexp(exp2);
    return exp1 + exp2;
}

// Task 2
int findscp(int num) {
    int r = round(sqrt(num));
    if((num - (r*r)) < (((r+1)*(r+1)) - num))
    return r*r; else return (r+1)*(r+1);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
   //way1
   HP1 = sethp(HP1);
   EXP1 = setexp(EXP1);
   M1 = setm(M1);
   if(E2<0 || E2>99) return -99;
    int s;
    float p1,p2,p3,p4;
    s = findscp(EXP1);
    if(s <= EXP1) p1 = 100;
       else p1 = (EXP1*1.0/s + 80)*100/123.0;
    //way2
    float n1=0;
    //n1 = ceil(M1*0.5);
    if((E2%2) != 0){
    while(n1 <= M1*0.5 && M1 > 0){
        //mua do
        if(HP1 < 200){
            HP1 += ceilf(HP1*30.0/100); HP1 = sethp(HP1);
            n1 += 150;
            if(n1>ceilf(M1*50.0/100)) break;
        } else {
            HP1 += ceilf(HP1*10.0/100); HP1 = sethp(HP1);
            n1 += 70;
            if(n1>ceilf(M1*50.0/100)) break;
        }
        //thue xe
        if(EXP1 < 400) {
            n1 += 200;
            EXP1 += ceilf(EXP1*13.0/100); EXP1 = setexp(EXP1);
            if(n1>ceilf(M1*50.0/100)) break;
        } else {
            n1 += 120;
            EXP1 += ceilf(EXP1*13.0/100); EXP1 = setexp(EXP1);
            if(n1>ceilf(M1*50.0/100)) break;
        }
        //EXP1 += ceil(EXP1*13.0/100);
        //homeless
        if(EXP1 < 300){
            n1 += 100;
            EXP1 -= floorf(EXP1*10.0/100); EXP1 = setexp(EXP1);
            if(n1>ceilf(M1*50.0/100)) break;
        } else {
            n1 += 120;
            EXP1 -= floorf(EXP1*10.0/100); EXP1 = setexp(EXP1);
            if(n1>ceilf(M1*50.0/100)) break;
        }
        //EXP1 -= ceil(10.0/100*EXP1);
    }
    M1 -= n1;
    HP1 -= floorf(HP1*17.0/100);  HP1 = sethp(HP1);
    EXP1 += ceil(EXP1*17.0/100); EXP1 = setexp(EXP1);
    } else if((E2%2) == 0){
        //mua do
         if(M1 > 0) {
            if(HP1 < 200){
            HP1 += ceilf(HP1*30.0/100); HP1 = sethp(HP1);
            M1 -= 150;
        } else {
            HP1 += ceilf(HP1*10.0/100); HP1 = sethp(HP1);
            M1 -= 70;
        }
        }
        //thue xe
        if(M1 > 0){
        if(EXP1 < 400) {
            M1 -= 200;
            EXP1 += ceilf(EXP1*13.0/100); EXP1 = setexp(EXP1);
        } else {
            M1 -= 120;
            EXP1 += ceilf(EXP1*13.0/100); EXP1 = setexp(EXP1);
        }
        //EXP1 += ceilf(EXP1*13.0/100); EXP1 = setexp(EXP1);
        }
        //homeless
        if(M1 > 0){
        if(EXP1 < 300){
            M1 -= 100;
            EXP1 -= floorf(EXP1*10.0/100); EXP1 = setexp(EXP1);
        } else {
            M1 -= 120;
            EXP1 -= floorf(EXP1*10.0/100); EXP1 = setexp(EXP1);
        }  
        }        
        HP1 -= floorf(HP1*17.0/100); HP1 = sethp(HP1);
        EXP1 += ceilf(EXP1*17.0/100); EXP1 = setexp(EXP1);
    }
    s = findscp(EXP1);
    if(s <= EXP1) p2 = 100;
       else p2 = (EXP1/s + 80)*100.0/123;
    //way3
    int p[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2 < 10) p3 = p[E2]; else {
         int sum = (int)(E2 / 10) + (E2 % 10);
         int i = sum % 10;
         p3 = p[i];
    }
    p4 = (p1+p2+p3)/3.0;
    if(p4 == 100) {EXP1 -= floorf(EXP1*25.0/100); EXP1 = setexp(EXP1);}
    else if(p4 < 50) {
        HP1 -= floorf(HP1*15.0/100); HP1 = sethp(HP1);
        EXP1 +=ceilf(EXP1*15.0/100); EXP1 = setexp(EXP1);
    } else if(p4 >= 50) {
        HP1 -= floorf(HP1*10.0/100); HP1 = sethp(HP1);
        EXP1 +=ceilf(EXP1*20.0/100); EXP1 = setexp(EXP1);
    }
    HP1 = sethp(HP1);
    EXP1 = setexp(EXP1);
    M1 = setm(M1);
    return HP1 + EXP1 + M1;
}
//tim so cho task3
 int findnum(int num){
        if(num < 10) return num;
        else {
        int sum = (num / 10) + (num % 10);
        if(sum < 10) return sum; else {
        int i = sum % 10 + (sum / 10);
        return i;
        }
    }
    }
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3<0 || E3>99) return -99;
    HP1 = sethp(HP1);
    EXP1 = setexp(EXP1);
    HP2 = sethp(HP2);
    EXP2 = setexp(EXP2);
    int mattaxi[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mattaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int sumb = 0; int summ = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(mattaxi[i][j] > E3*2) sumb += 1;
            if(mattaxi[i][j] < (-E3)) summ += 1;
        }
    }
    //tim diem (i,j)
    int a = findnum(sumb);
    int b = findnum(summ);
    int r;
    int temp = mattaxi[a][b];
    // I
    int i1 = a;
    int j1 = b;
    while(i1 >= 0 && j1 >= 0){   
            if(temp < mattaxi[i1][j1]) temp = mattaxi[i1][j1];
            --i1;
            --j1;
        }
    // II
    int i2 = a;
    int j2 = b;
    while(i2 <= 9 && j2 >= 0){   
            if(temp < mattaxi[i2][j2]) temp = mattaxi[i2][j2];
            ++i2;
            --j2;
        }
    // III
    int i3 = a;
    int j3 = b;
    while(i3 <= 9 && j3 <= 9){   
            if(temp < mattaxi[i3][j3]) temp = mattaxi[i3][j3];
            ++i3;
            ++j3;
        }
    // IV
    int i4 = a;
    int j4 = b;
    while(i4 >= 0 && j4 <= 9){   
            if(temp < mattaxi[i4][j4]) temp = mattaxi[i4][j4];
            --i4;
            ++j4;
        }
    if(temp < 0) temp = abs(temp);
    if(abs(mattaxi[a][b]) > temp ) {
        EXP1 -= floorf(EXP1*12.0/100); EXP1 = setexp(EXP1);
        EXP2 -= floorf(EXP2*12.0/100); EXP2 = setexp(EXP2);
        HP1 -= floorf(HP1*10.0/100); HP1 = sethp(HP1);
        HP2 -= floorf(HP2*10.0/100); HP2 = sethp(HP2);
        r = mattaxi[a][b];
    } else {
        EXP1 += ceilf(EXP1*12.0/100); EXP1 = setexp(EXP1);
        EXP2 += ceilf(EXP2*12.0/100); EXP2 = setexp(EXP2);
        HP1 += ceilf(HP1*10.0/100); HP1 = sethp(HP1);
        HP2 += ceilf(HP2*10.0/100); HP2 = sethp(HP2);
        r = temp;
    }   
    return r;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    int len = strlen(s);
    string special_chars = "@#%$!";
    //string s1 = strcpy(s);
    if (len < 8) return -1;
    if (len > 20) return -2;
    string se = string(email).substr(0, string(email).find('@'));
    if (string(s).find(se) != string::npos) return -(300 + string(s).find(se));
    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i+1] && s[i+1] == s[i+2]) return -(400 + i);
    }
    //if (string(s).find_first_of(special_chars) == len) return -5;
    bool coktdb = false;
    for (int i = 0; i < len; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            coktdb = true;
    }
     if (!coktdb)
        return -5;
    int fse = string(s).find(se);
    if (fse != string::npos) return -(300 + fse);
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (!isdigit(c) && !isalpha(c) && special_chars.find(c) == string::npos) return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int max_count = 0;
    int max_length = 0;
    const char * corpass = nullptr;
    // duyet xau pass
    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        // check so lan xuat hien
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }
        int length = strlen(arr_pwds[i]);
        if (count > max_count || (count == max_count && length > max_length)) {
            max_count = count;
            max_length = length;
            corpass = arr_pwds[i];
        }
    }
    // firstpoint pass
    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], corpass) == 0) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////