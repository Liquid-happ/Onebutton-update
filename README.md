Dự án: Điều khiển 2 LED bằng 1 nút nhấn (ESP32 + OneButton)

Giới thiệu
Dự án sử dụng ESP32 và thư viện OneButton để điều khiển 2 LED chỉ bằng 1 nút nhấn.

Yêu cầu phần cứng
- ESP32 DevKit  
- 1 LED + điện trở hạn dòng (220Ω) 
- 1 nút nhấn  
- Breadboard + dây nối  

Chức năng phần mềm :
- Mở Serial Monitor có trên VS Code
- Ấn số 1 → Bật/Tắt LED đang được chọn.  
- Ấn số 2 → Chuyển chế độ điều khiển giữa LED1 và LED2.  
- Ấn số 3 → LED đang chọn sẽ nhấp nháy với chu kỳ 200ms.  

Sơ đồ kết nối
- LED1 → GPIO 2 (LED tích hợp sẵn).  
- LED2 → GPIO 4.  
- Nút nhấn → GPIO 0 (kéo xuống GND).  

 

