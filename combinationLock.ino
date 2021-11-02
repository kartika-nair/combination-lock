const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int button5 = 6;
const int button6 = 7;

const int BLUES[] = {14,15,16,17,18,19};

const int WRONG = 8;
const int CORRECT = 9;

int PASSWORD[] = {1,2,3,4,5,6};
int ATTEMPTED[7];


void check6(int button)
{
  digitalWrite(BLUES[button-1],HIGH);
  if (ATTEMPTED[5] == 0)
  {
    ATTEMPTED[5] = button;
    delay(100);
    check();
  }
}

void check5(int button)
{
  digitalWrite(BLUES[button-1],HIGH);
  if (ATTEMPTED[4] != 0)
    check6(button);
  
  else if (ATTEMPTED[4] == 0)
    ATTEMPTED[4] = button;
}

void check4(int button)
{
  digitalWrite(BLUES[button-1],HIGH);
  if (ATTEMPTED[3] != 0)
    check5(button);
  
  else if (ATTEMPTED[3] == 0)
    ATTEMPTED[3] = button;
}

void check3(int button)
{
  digitalWrite(BLUES[button-1],HIGH);
  if (ATTEMPTED[2] != 0)
    check4(button);
  
  else if (ATTEMPTED[2] == 0)
    ATTEMPTED[2] = button;  
}

void check2(int button)
{
  digitalWrite(BLUES[button-1],HIGH);
  if (ATTEMPTED[1] != 0)
    check3(button);
  
  else if(ATTEMPTED[1] == 0)
    ATTEMPTED[1] = button;
}

void check1(int button)
{
  digitalWrite(BLUES[button-1],HIGH);
  if (ATTEMPTED[0] != 0)
    check2(button);
  
  else if(ATTEMPTED[0] == 0)
    ATTEMPTED[0] = button;
  
}


void setup()
{
  Serial.begin(9600);

  pinMode(button1, INPUT_PULLUP); 
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP); 
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP); 
  pinMode(button6, INPUT_PULLUP); 

  pinMode(WRONG, OUTPUT);
  pinMode(CORRECT, OUTPUT);
  
  digitalWrite(WRONG, LOW);
  for (int i = 0; i < 6;i++)
  {
    Serial.println(PASSWORD[i]);
    Serial.println(ATTEMPTED[i]);
    pinMode(BLUES[i],OUTPUT);
  }
}


void loop()
{
  if (digitalRead(button1) == LOW)
  {
    check1(1);    
    delay(250);    
  }

  else if (digitalRead(button2) == LOW)
  {
    check1(2);
    delay(250);
  }

  else if (digitalRead(button3) == LOW)
  {
    check1(3);
    delay(250);
  }

  else if (digitalRead(button4) == LOW)
  {
    check1(4);
    delay(250);
  }

  else if (digitalRead(button5) == LOW)
  {
    check1(5);
    delay(250);
  }

  else if (digitalRead(button6) == LOW)
  {
    check1(6);
    delay(250);
  }
}


void check()
{
  if ((ATTEMPTED[0]==PASSWORD[0]) && (ATTEMPTED[1]==PASSWORD[1]) && (ATTEMPTED[2]==PASSWORD[2]) && (ATTEMPTED[3]==PASSWORD[3]) && (ATTEMPTED[4]==PASSWORD[4])&& (ATTEMPTED[5]==PASSWORD[5]))
  {
    digitalWrite(WRONG, LOW);
    digitalWrite(CORRECT, HIGH);
    delay(1000);
    digitalWrite(CORRECT, LOW);
  }
  
  else 
  {
    digitalWrite(WRONG, HIGH);
    delay(1000);
    digitalWrite(WRONG, LOW);    
  }

  bluesLow();
}


void bluesLow()
{
  digitalWrite(BLUES[0],LOW);
  digitalWrite(BLUES[1],LOW);
  digitalWrite(BLUES[2],LOW);
  digitalWrite(BLUES[3],LOW);
  digitalWrite(BLUES[4],LOW);
  digitalWrite(BLUES[5],LOW);
}
