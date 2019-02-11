// addding 2 sensor more  total 5 sensor 
//xl and xr   extra sensor 
//  sensor cny70

#include <Servo.h>
Servo leftServo;
Servo rightServo;


#define sensorPincent A4
#define sensorPinright A5
#define sensorPinleft A3

#define sensorPinxleft A2
#define sensorPinxright A1




int rv = 0;  
int lv = 0;  
int cv = 0; 

int xl =0;
int xr =0;
int c=0;
int r=0;
int l=0;
int li=0;
int ri=0;

//left =2  ,straight=1 ,right=3, intersection points  with delay 
int a = 1;
int b = 2;
int d = 3;
int e = 3;
int f = 1;
int g = 3;
int h = 2;

int z=609;

void setup() {
  leftServo.attach(13);
  rightServo.attach(12);
  Serial.begin(9600);
}

void loop() {

  cv = analogRead(sensorPincent);//b\w 0-170/170-600
  lv = analogRead(sensorPinright);//b\w 0-150/150-400
  rv = analogRead(sensorPinleft);//b\w 0-500/500-1023
  xl = analogRead(sensorPinxleft);//b\w 0-500/500-1023
  xr = analogRead(sensorPinxright);//b\w 0-500/500-1023


   if(cv>200){c=0;}
  else{c=1;}

   if(lv>130){l=0;}
  else{l=1;}

   if(rv>500){r=0;}
  else{r=1;}

   if(xl>500){li=0;}
  else{li=1;}

   if(xr>500){ri=0;}
  else{ri=1;}


  if((xl== 1 && xr == 1 &&l==c==r==0)){stp();
    }

  if (( l == 0 && c ==1 && r==0)) {
    fwd();
  }

 if (( l == 1 && c ==1 && r==0)) {
    sright();
  }
 if (( l == 0 && c ==1 && r==1)) {
    sleft();
   
  }
 if (( l == 1 && c ==0 && r==0)) {
    sright();
  
  }
  if (( l == 0 && c ==0 && r==1)) {
    sleft();
     //delay(3);
  }
 if (( l == 0 && c ==0 && r==0)) {
    fwd();
  }
 if (( l == 1 && c ==1 && r==1)) {
    halt();
 }
  if((xl== 1 && xr == 1 &&  l == 1 && c ==1 && r==1)){halt();
    }
     if((xl== 0 && xr == 1 &&  l == 1 && c ==1 && r==1)){halt();
    }
     if((xl== 1&& xr == 0 &&  l == 1 && c ==1 && r==1)){halt();
    }
    


  
printoutput();


   
}




void rotatel()
{ leftServo.writeMicroseconds(1400); // rotate l
  rightServo.writeMicroseconds(1400);

}
void rotater()
{ leftServo.writeMicroseconds(1600); // rotate r
  rightServo.writeMicroseconds(1600);

}


void left()
{ leftServo.writeMicroseconds(1500); // left
  rightServo.writeMicroseconds(1300);
  
}
void sleft()
{ leftServo.writeMicroseconds(1300); // right
  rightServo.writeMicroseconds(1300);
}

void sright()
{ leftServo.writeMicroseconds(1700); // right
  rightServo.writeMicroseconds(1700);
}
void right()
{ leftServo.writeMicroseconds(1700); // right
  rightServo.writeMicroseconds(1500);
}

void fwd()
{ leftServo.writeMicroseconds(1700); // front
  rightServo.writeMicroseconds(1300);
  
}
void slowleft()
{ leftServo.writeMicroseconds(1500); //  slowleft
  rightServo.writeMicroseconds(1475);
 
}
void slowright()
{ leftServo.writeMicroseconds(1525); // slowright
  rightServo.writeMicroseconds(1500);
}
void rew()
{ leftServo.writeMicroseconds(1300); // front
  rightServo.writeMicroseconds(1700);
  }

void slowfwd()
{ leftServo.writeMicroseconds(1515); // front
  rightServo.writeMicroseconds(1485);
  }

  void rotat()
{ leftServo.writeMicroseconds(1300); // front
  rightServo.writeMicroseconds(1300);
  }

 void halt()
{ leftServo.writeMicroseconds(1500); // front
  rightServo.writeMicroseconds(1500);
  delay(1000);
  fwd();
  delay(350);
  leftServo.writeMicroseconds(1500); // front
  rightServo.writeMicroseconds(1500);
  delay(500);
  dec();
  
  }


void stp()
{ leftServo.writeMicroseconds(1500); // front
  rightServo.writeMicroseconds(1500);
  delay(500);}

  
void printoutput(){

  Serial.print(  xl);
   Serial.print( ",");
   Serial.print(li);
    Serial.print("\t ");
    
    Serial.print(lv);
    Serial.print( ",");
   Serial.print(l);
    
    Serial.print("\t ");
   Serial.print(cv);
   Serial.print( ",");
   Serial.print(c);
    
    Serial.print("\t ");
  
    Serial.print(   rv);
    Serial.print( ",");
    Serial.print(r);
    
    Serial.print("\t ");
   

    Serial.print(   xr);
   Serial.print(ri);

    Serial.print("\t ");
    Serial.print(   a);
   Serial.print(b);
    Serial.print( d);
   Serial.print(e);
   Serial.print(   f);
   Serial.print(g);
    
    

     Serial.print("\n ");
     
    delay(2);}

    void dec()
{
  if (a > 0)
  {
    if (a == 1)
    {
      fwd();
      delay(z);
      //a=0;
    }
    else if (a == 2)
    { 
      rotatel();
      delay(z);
    }
    else if (a == 3)
    { rotater();
    delay(z);
    }
    
  a=0;
  goto exit;
  }

   else if (b > 0)
  {
    if (b == 1)
    {
      slowfwd();
      delay(z);
    }
    if (b == 2)
    { rotatel();
    delay(z);

    }
    if (b == 3)
    { rotater();
    delay(z);
    }
b=0;
goto exit;
  }

 if (d > 0)
  {
    if (d == 1)
    {
      slowfwd();
      delay(z);
    }
    if (d == 2)
    { rotatel();
    delay(z);

    }
    if (d == 3)
    { rotater();
    delay(z);
    }
d=0;
goto exit;
  }

   if (e > 0)
  {
    if (e == 1)
    {
      slowfwd();
      delay(z);
    }
    if (e == 2)
    { rotatel();
 delay(z);
    }
    if (e == 3)
    { rotater();
    delay(z);
    }
e=0;
goto exit;
  }


    if (f > 0)
  {
    if (f == 1)
    {
      slowfwd();
      delay(z);
    }
    if (f == 2)
    { rotatel();
    delay(z);

    }
    if (f == 3)
    { rotater();
    delay(z);
    }
f=0;
goto exit;
  }

    if (g > 0)
  {
    if (g == 1)
    {
      slowfwd();
      delay(z);
    }
    if (g == 2)
    { rotatel();delay(z);

    }
    if (g == 3)
    { rotater();
    delay(z);}
g=0;
goto exit;
  }

    if (h > 0)
  {
    if (h == 1)
    {
      slowfwd();
      delay(z);
    }
    if (h == 2)
    { rotatel();delay(z);

    }
    if (h == 3)
    { rotater();
    delay(z);}

    if(h == 4)
    {leftServo.detach(); // front
  rightServo.detach();}
h=0;
goto exit;
  }
  
exit:
stp();


}
