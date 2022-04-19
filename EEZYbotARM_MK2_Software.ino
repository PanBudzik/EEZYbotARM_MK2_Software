
#include <Servo.h>

/*class Arm {

  public:

    
};*/

class Actuator {
  public:
    int pin;
    int position;
    int limiter_min;
    int limiter_max;
    Servo myservo;

    void setup(int pin, int position, int limiter_min, int limiter_max){
      this->pin=pin;
      this->position=position;
      this->limiter_min=limiter_min;
      this->limiter_max=limiter_max;
      this->turnFast(position,0);
    }

    void turnFast(int new_position, int pause_ms) {
      this->myservo.attach(this->pin);
      this->myservo.write(new_position);
      delay(pause_ms);
      this->myservo.detach();
      this->position=new_position;
    }

    void turnDelayed(int new_position, int delay_ms, int pause_ms) {
      if(new_position > this->position){
        for (int pos = this->position; pos <= new_position; pos += 1) { 
          this->myservo.attach(this->pin);
          this->myservo.write(pos);
          delay(delay_ms);
        }
        this->myservo.detach();
        this->position=new_position;
      }
      else{
        for (int pos = this->position ; pos >= new_position; pos -= 1) { 
          this->myservo.attach(this->pin);
          this->myservo.write(pos);
          delay(delay_ms);
        }
        this->myservo.detach();
        this->position=new_position;
      }
      delay(pause_ms);
    }
};


/*void ustawienie_podstawowe(){
  nowa_pos1=90;
  nowa_pos2=90;
  nowa_pos3=120;
  nowa_pos4=0;
  ruch(1000);
  }

void podnies(){
  nowa_pos2=180;
  nowa_pos3=70;
  nowa_pos4=180;
  ruch(1000,15);
  
  nowa_pos4=0;
  ruch(500,15);

  nowa_pos2=90;
  nowa_pos3=120;
  ruch(1000,15);
  }*/

void setup() {
  Serial.begin(9600);
  Servo 
  Actuator base, biceps, forearm, fingers;
  base.setup(2,90,0,180);
  biceps.setup(3,90,90,180);
  forearm.setup(4,120,70,180);
  fingers.setup(5,0,20,180);


  
  //ustawienie_podstawowe();
  //podnies();
}

void loop() {}

//M1 0-180 - postawka
//M2 90-180 - prawe (biceps)
//M3  zawadza podstawka??? 70-180 - lewe(przedramie)
//M4 180-20*/
