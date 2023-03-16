# Tutorial-8-Embedded-Systems-and-IoT
RTOS (Real-time Operating System)


Objectives
1.  เขียนโปรแกรมเพื่อให้ microcontroller ประมวลผลงานหลายงานไปพร้อมๆกันได้ และทำงานแยกกัน

Hardware	        
1.	LED		              4
2.	Breadboard          1
3.	Computer	          1
4.	microUSB	          1 

Software
1. Arduino IDE v
--------------------
Instruction

1. ต่อวงจรใช้ LED จำนวน 2 ดวงเข้าที่ GPIO 4 และ 15
2. คัดลอกโค้ดจากไฟล์ lab8.ino และรันโปรแกรม
3. จะเห็นว่า LED แต่ละดวงจะทำงานแยกกันตามโค้ด ดวงที่ 1 ติดดับทุกๆ 100ms ดวงที่ 2 ติดดับทุกๆ 1 วินาที (1000ms)
4. เขียนโปรแกรมสั่งการไฟกระพริบโดยใช้หลอดไฟทั้งหมด 4 ดวงแบ่งเป็น 4 task



