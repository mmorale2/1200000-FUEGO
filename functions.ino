void stop1()                    
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}   
void advance(int a,int b)          
{
  analogWrite (E1,a);     
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);

}  
void backoff (char a,char b)          
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}
void turnL (char a,char b)             
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turnR (char a,char b)             
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}
void wall(){
   if(228 < r1 && r1 < 259 ){
      advance(115, 115);
  }
  else if (r2>300){
      turnR(115,115);
      delay(450);
                     }
    else if(r1 < 220) {
      turnL(115,115);
                       }
    else if(r1 > 250){
      turnR(115,115);
                      }

    else if(r1<270 && r2<200 && r3<200){
      advance(105, 85);
      delay(1000);
                                       }
 
    else { 
      advance(105,105);
           }
             }

void set(){
   pinMode(M1, OUTPUT);   
  pinMode(E1, OUTPUT);    
  pinMode(E2, OUTPUT);   
  pinMode(M2, OUTPUT);
  pinMode(bump, INPUT);
  pinMode(s1, INPUT);
 pinMode(s2, INPUT);
 pinMode(s3, INPUT);
 pinMode(flame, INPUT);
 pinMode(flame2, INPUT);
 pinMode(fan, OUTPUT);
 Serial.begin(9600);
}
void fuckreading(){
r1 = analogRead(s1);
r2 = analogRead(s2);
r3 = analogRead(s3);
f1 = analogRead(flame);
f2 = analogRead(flame2);
}
void sad(){
  advance(100,100);
  delay(500);
}
void fuckflame(){
  if(f1<1000 && f2 <1000){
    if(f1>f2){
      turnL(115,155);
      delay(100);
    }
    if(f2<f1){
      turnR(115,115);
      delay(100);
    }
   sad();
  stop1();
  digitalWrite(13, HIGH);
  digitalWrite(fan, HIGH);
  delay(7500);
  }
else if (f1>1000 && f2>1000) {
  digitalWrite(fan, LOW);
}
}
