#include "mbed.h"
#include "LSM6DSLSensor.h"
// A program used to ajust the brightness of an led using Pwm depending on the angle of the accelerometer using parts of Lab 3. 
#define PI 3.141592654
PwmOut led1(LED1);
PwmOut led2(LED2);
PwmOut led3(LED3);
static DevI2C devI2c(PB_11,PB_10);
static LSM6DSLSensor acc_gyro(&devI2c,0xD4,D4,D5); 
int main() {
    acc_gyro.init();
    while (1) {
        float x, y, z;
        acc_gyro.readXYZGravity(&x, &y, &z);
        float brightness1 = fabs(x) * 0.2; 
        float brightness2 = fabs(y) * 0.6; 
        float brightness3 = fabs(z) * 0.8; 
        led1 = brightness1;
        led2 = brightness2;
        led3 = brightness3;
        wait_us(10); 
    }
}
