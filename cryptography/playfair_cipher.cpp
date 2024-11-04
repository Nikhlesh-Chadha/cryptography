
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
// remove spaces and add padding to the plaintext
void plaintext(string p){
p.erase(remove(p.begin(), p.end(), ' '), p.end());
for (int i=1; i<p.size(); i++){
if(p[i]==p[i-1]){
char x = 'x';
p+=x;
for(int k=p.size(); k>i; k--){
p[k] = p[k-1];
}
p[i]= 'x';
}
}
if((p.size()%2) !=0){
char a = 'x';
p+=a;
}
cout<<”Plaintext ”<<p<<endl;
}
// encryption algorithm
string encrypt(char a[5][5], string p){
char s[2];
string encr="";
for(int i=0; i<p.size(); ){
s[0]=p[i];
s[1]= p[i+1];
int i1, i2, j1, j2;
for(int i=0; i<5; i++){
for(int j=0; j<5; j++){
if(a[i][j]==s[0]){
i1 = i;
j1 = j;
}
if(a[i][j]==s[1]){
i2 = i;
j2 = j;
}
}
}
if(i1 == i2){
int c1 = (j1+1)%5;
int c2 = (j2+1)%5;
encr+=a[i1][c1];
encr+=a[i2][c2];
}
else if(j1 ==j2){
int c1 = (i1+1)%5;
int c2 = (i2+1)%5;
encr+= a[c1][j1];
encr+= a[c2][j2];
}
else{
encr+= a[i1][j2];
encr+= a[i2][j1];
}
i+=2;
}
return encr;
}
// decryption algorithm
string decrypt(char a[5][5], string p){
char s[2];
string decr="";
for(int i=0; i<p.size(); ){
s[0]=p[i];
s[1]= p[i+1];
int i1, i2, j1, j2;
for(int i=0; i<5; i++){
for(int j=0; j<5; j++){
if(a[i][j]==s[0]){
i1 = i;
j1 = j;
}
if(a[i][j]==s[1]){
i2 = i;
j2 = j;
}
}
}
if(i1 == i2){
if(j1==0){
decr+=a[i1][4];
decr+=a[i2][j2-1];
}
else if(j2==0){
decr+=a[i1][j1-1];
decr+=a[i2][4];
}else{
decr+=a[i1][j1-1];
decr+=a[i2][j2-1];
}
}
else if(j1 ==j2){
if(i1==0){
decr+=a[4][j1];
decr+=a[i2-1][j2];
}
else if(i2==0){
decr+=a[i1-1][j1];
decr+= a[4][j2];
}
else{
decr+= a[i1-1][j1];
decr+= a[i2-1][j2];
}
}
else{
decr+= a[i1][j2];
decr+= a[i2][j1];
}
i+=2;
}
return decr;
}
int main(){
string a, p;
cout<<"Enter the key ";
getline(cin, a);
cout<<"Enter the plaintext ";
getline(cin, p);
plaintext(p);
int k=0;
int c=0;
char b[5][5];
int i=0;
int j;
// adding the non repeating key letters to the 5 x 5 matrix
for (; i<5 && k<a.size(); i++){
for(j=0; j<5 && k<a.size(); ){
if (k==0){
b[0][0] = a[0];
k++;
j++;
c++;
}
else if(k>0){
int n;
bool flag = 0;
for(n=0; n<k; n++ ){
if(a[k]==a[n]){
flag=1;
}
}
if(flag==0){
b[i][j] = a[k];
k++;
j++;
c++;
}
else
k++;
}
}
}
i=c/5;
j=c-5;
if(j<0){
j=j*(-1);
}
char d = 'a';
// adding the remaining english language alphabets to the matrix
for(; i<5; i++){
for(; j<5; ){
bool flag = 0;
for(int k=0; k<a.size(); k++){
if(d==a[k]){
flag = 1;
}
}
if (flag==0 && d=='j'){
d+=1;
}
else if(flag==0 && d!='j'){
b[i][j]= d;
d+=1;
j++;
}
else if(flag==1){
d+=1;
}
}
j=0;
}
for(i=0; i<5; i++){
for(j=0; j<5; j++){
cout<<b[i][j]<< " ";
}
cout<<"\n";
}
cout<<"\n";
string encr = encrypt(b, p);
cout<< “Encrypted text “<<encr<<endl;
string decr = decrypt(b,encr);
cout<<”Decrypted Text “<<decr<<endl;
return 0;
}
