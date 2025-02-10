  /*
    ESP32 จะมี library ของ RTOS มาให้แล้วในขณะที่ ESP8266 จะต้องติดตั้ง library ต่างหาก
    ส่งผลให้สามารถใช้งาน RTOS ได้โดยที่ไม่ต้องติดตั้ง library ใดๆ
    RTOS จะแบ่งงานเป็นแต่ละงานซึ่งจะทำงานแยกออกจากกันเรียกว่า Task
    โค้ดการทำงานของแต่ละงานจะไม่อยู่ใน loop() และจะมีฟังก์ชันเป็นของตัวเอง โดยแต่ละ Task จะทำงานแบบวนลูปอยู่แล้ว
  */

#define ledPIN1 4
#define ledPIN2 15

void setup() {
  
  /*
    สร้าง task ด้วยคำสั่ง xTaskCreate() มี parameter ดังนี้
    xTaskCreate( pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask)
  */
  xTaskCreate(&first_task, "first_task", 1024, NULL, 5, NULL);  // สร้าง task ที่ 1
  xTaskCreate(&second_task,"second_task",1024, NULL, 5, NULL);  // สร้าง task ที่ 2
  
}
// ฟังก์ชัน loop ไม่ได้ใช้งาน เนื่องจากฟังก์ชันแต่ละงานจะทำงานแบบวนลูปอยู่แล้ว
void loop() {
}

/*
  สร้างฟังก์ชันการทำงานสำหรับ task ที่ 1
*/
void first_task(void *pvParameter){       // ไม่ส่งค่า parameterใดๆเข้าฟังก์ชัน

  pinMode(ledPIN1,OUTPUT);

  while(true) {
    digitalWrite(ledPIN1, HIGH);
    vTaskDelay(100 / portTICK_RATE_MS);   // คำสั่ง vTaskDelay สำหรับกำหนดดีเลย์ให้กับการทำงานแบบ multitasking
    digitalWrite(ledPIN1, LOW);
    vTaskDelay(100 / portTICK_RATE_MS);
  }
}

/*
  สร้างฟังก์ชันการทำงานสำหรับ task ที่ 2
*/
void second_task(void *pvParameter){

  pinMode(ledPIN2,OUTPUT);

  while(true) {
    digitalWrite(ledPIN2, HIGH);
    vTaskDelay(500 / portTICK_RATE_MS);
    digitalWrite(ledPIN2, LOW);
    vTaskDelay(500 / portTICK_RATE_MS);
  }
}
