// Jose De Jesus Alarcon
// Simple Simon
// 10/3/2022

const int MAX_LEVEL = 10;// Here is the max level of levels to 10
int sequence[MAX_LEVEL];// Above the max level 10 is being placed into these brackets [].
int your_sequence[MAX_LEVEL];
int level = 1;// converting the value into a data type. 

int velocity = 1000;

void setup() {
pinMode(A0, INPUT);//Here is where inputs A0-A3 is inputed into the 10k resistor.
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);

pinMode(2, OUTPUT);//Here pins 2-5 is connected into the 220 ohms for brightness then into the anode.
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);

digitalWrite(2, LOW);// Here writing the digitalWrite keeping the correspondings to LOW.
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
}

void loop()
{
if (level == 1)
generate_sequence();//generate a sequence;

if (digitalRead(A4) == LOW || level != 1) //If start button is pressed it is meant to start the game.
{
show_sequence();//show the sequence
get_sequence();//wait for your sequence
}
}

void show_sequence()// In this line it shows the sequence to do a random type of colors.
{
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);

for (int i = 0; i < level; i++)
{
digitalWrite(sequence[i], HIGH);
delay(velocity);
digitalWrite(sequence[i], LOW);
delay(200); // pauses the amount of time which is milliseconds, which would then be as a parameter.
}
}

void get_sequence()// Here is for the user to right the sequence after the show sequence.
{
int flag = 0; //this flag indicates if the sequence is correct

for (int i = 0; i < level; i++)// Using the "for" loop to incorporate the repetive operation.
{
flag = 0;
while(flag == 0)// Using the while for a continous loop. 
{
if (digitalRead(A0) == LOW)
{
digitalWrite(5, HIGH);
your_sequence[i] = 5;
flag = 1;
delay(200);// again pauses the amount of time which is milliseconds, which would then be as a parameter.
if (your_sequence[i] != sequence[i])
{
wrong_sequence();
return;
}
digitalWrite(5, LOW);
}

if (digitalRead(A1) == LOW)
{
digitalWrite(4, HIGH);
your_sequence[i] = 4;
flag = 1;
delay(200);// Another pause that the amount of time which is milliseconds, which would then be as a parameter.
if (your_sequence[i] != sequence[i])// Using the "!=" say if it is false then restart.
{
wrong_sequence();
return;
}
digitalWrite(4, LOW);
}

if (digitalRead(A2) == LOW)// Using the "if" statements to see if it is true.  
{
digitalWrite(3, HIGH);
your_sequence[i] = 3;
flag = 1;
delay(200);
if (your_sequence[i] != sequence[i])
{
wrong_sequence();
return;
}
digitalWrite(3, LOW);
}

if (digitalRead(A3) == LOW)
{
digitalWrite(2, HIGH);
your_sequence[i] = 2;
flag = 1;
delay(200);
if (your_sequence[i] != sequence[i])
{
wrong_sequence();
return;// using the "return" if wrong then it moves on if ye
}
digitalWrite(2, LOW);
}

}
}
right_sequence();
}

void generate_sequence()
{
randomSeed(millis()); //initalizes the number generator, which causes it to point in a random sequence.

for (int i = 0; i < MAX_LEVEL; i++)
{
sequence[i] = random(2,6);
}
}
void wrong_sequence()// Using the "void" to declare the wrong_sequence.
{
for (int i = 0; i < 3; i++)// implementing the "for" loop to incorporate the repetive operation.
{
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
delay(250);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
delay(250);//putting the pauses for the amount of time which is milliseconds, which would then be as a parameter.
}
level = 1;
velocity = 1000;
}

void right_sequence()
{
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
delay(250);//putting the pauses for the amount of time which is milliseconds, which would then be as a parameter.

digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
delay(500);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
delay(500);

if (level < MAX_LEVEL);
level++;

velocity -= 100; //increase difficulty of the game.
}
