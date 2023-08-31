#include <Wire.h>
#include"SI7021.h"

SI7021 sensor;

void setup() {
    Serial.begin(115200);
    sensor.begin();
}

void loop() {

    // temperature is an integer in hundredths
    int temperature = sensor.getCelsiusHundredths();
    temperature = temperature / 400;
    Serial.print("Temperature :");  
    Serial.print(temperature);
    Serial.println("°Celcius");
    
    delay(500);
    
    // humidity is an integer representing percent
    float humidity = sensor.getHumidityPercent()/1.7;
    Serial.print("Humidity :");  
    Serial.print(humidity);
    Serial.println("%");
    
    
    delay(500);
    
    
    // enable internal heater for testing
    sensor.setHeater(true);
      Serial.println("Activate heater");  
    
    delay(20000);
    sensor.setHeater(false);
    Serial.println("Desactivate heater");
    
    // see if heater changed temperature
    temperature = sensor.getCelsiusHundredths();
    temperature = temperature / 400;
    Serial.print("Temperature :");  
    Serial.print(temperature);
    Serial.println("°Celcius");
    
    
    //cool down
    delay(20000);

    // get humidity and temperature in one shot, saves power because sensor takes temperature when doing humidity anyway
    si7021_env data = sensor.getHumidityAndTemperature();
    Serial.print("Temperature :");  
    Serial.print(data.celsiusHundredths/400);
    Serial.println("°Celcius");
    
    delay(500);
}
