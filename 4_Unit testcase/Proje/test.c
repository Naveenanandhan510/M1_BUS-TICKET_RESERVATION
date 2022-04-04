#include <stdio.h>
#include <unity.h>
#include<sys/stat.h>
void setUp(void){}
void tearDown(void){}
void login(){}
int main(){
    UnityBegin(NULL);
    RUN_TEST(login);
    return (UnityEnd());
}