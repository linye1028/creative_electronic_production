#define Color_R 10
#define Color_G 11
#define Color_B 12

void setup() {
  // put your setup code here, to run once:
	for(char i=2;i<=12;i++)
	{
		pinMode(i,OUTPUT);
		digitalWrite(i,HIGH);
	}
}
char LED_n=2;
char LED_dir=1;
char LED_c=Color_R;
long premillis=0;
long interval=500;
void loop() {
  // put your main code here, to run repeatedly:
    long currentmillis=millis();
	setColor(LED_c);
    if(currentmillis-premillis>=interval)    
    {
		premillis=currentmillis; 
		LED_n= LED_dir ? LED_n+1:LED_n-1;
		if(LED_dir==1 && LED_n==9 )
		{
			LED_dir=0;
			LED_c= LED_c==Color_B ? Color_R : LED_c+1;
		}
			
		if(LED_dir==0 && LED_n==2 )
		{
			LED_dir=1;	
			LED_c= LED_c==Color_B ? Color_R : LED_c+1;	
		}
    }
	for(char i=2;i<=9;i++)
	{
		if(i==LED_n)
			digitalWrite(i,LOW);
		else
			digitalWrite(i,HIGH);
	}
  
}
void setColor(char color)
{
	for(char i=10;i<=12;i++)
	{
		if(color==i)
			digitalWrite(i,LOW);
		else
			digitalWrite(i,HIGH);
	}
}
