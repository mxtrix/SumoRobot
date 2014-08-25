/******** start code ********/
/*
 *  created     2013-07-12
 *  by      lisper (leyapin@gmail.com)
 *  function    test gp2d12, read value from A0
 *      
 *      VCC -- VCC  
 *      GND -- GND  
 *      Signal -- Analog 5 
 */
 
#define pin A5
 
void setup () {
    Serial.begin (9600);
    pinMode (pin, INPUT);
}
 
void loop () {
    //uint16_t value = analogRead (pin);
    float value = analogRead (pin);
    float filtvalue = 2121.3*(pow(value,-1.036));
    uint16_t range = get_gp2d12 (value);
    Serial.print(filtvalue,2);
    Serial.print("cm");
    Serial.println("");
    delay (500);
}
 
uint16_t get_gp2d12 (uint16_t value) {
    if (value < 10) value = 10;
    return ((67870.0 / (value - 3.0)) - 40.0);
}
 
/******** end code ********/
