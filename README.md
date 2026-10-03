# Bài tập coding luyện tập — Mô-đun 01–03

**Học phần:** C for Embedded PE  
**Thời lượng gợi ý:** 60–90 phút  
**Ngôn ngữ:** C17

Hai bài tập giả lập thanh ghi và cảm biến trên máy tính; không cần bo mạch hoặc thư viện riêng biệt. Các em kiểm tra file [bai_tap.h](bai_tap.h) là **template chưa hoàn chỉnh**: Các em phải lập trình hai kiểu dữ liệu ở vị trí `TODO` trước khi biên dịch, rồi định nghĩa hai hàm đã khai báo. Nộp `bai_tap.h`, `bai1.c` và `bai2.c`; mỗi file `.c` cần `#include "bai_tap.h"`. Hệ thống chấm gọi trực tiếp các hàm này; không yêu cầu viết `main` hoặc đọc từ bàn phím. Các em có thể tự viết `main` trong file khác để thử nghiệm các test cases tự mình đặt ra.

Kiểm tra cú pháp và cảnh báo của từng file:

```sh
cc -std=c17 -Wall -Wextra -Wpedantic -c bai1.c
cc -std=c17 -Wall -Wextra -Wpedantic -c bai2.c
```

## Bài 1 — Cấu hình thanh ghi điều khiển (5 điểm)

Một thanh ghi điều khiển 8 bit có bố cục sau:

| Bit | Ý nghĩa |
| --- | --- |
| 0 | `ENABLE`: `1` là bật, `0` là tắt |
| 1–2 | `MODE`: chế độ từ `0` đến `3` |
| 3–7 | Các bit khác; phải giữ nguyên |

Viết hàm `update_control` nhận giá trị thanh ghi ban đầu, giá trị `ENABLE` mới và giá trị `MODE` mới. Hàm cập nhật **chỉ** ba bit 0–2 rồi trả về giá trị thanh ghi mới.

**Đầu vào:** `reg` trong khoảng 0–255; `enable` bằng `0` hoặc `1`; `mode` trong khoảng 0–3. Bộ kiểm thử bảo đảm các giá trị thuộc những khoảng này.

**Đầu ra:** Giá trị thanh ghi mới kiểu `uint8_t`. Khi tự in để kiểm tra, dùng dạng `0x` và đúng hai chữ số thập lục phân in hoa, chẳng hạn `printf("0x%02X\n", (unsigned int)result);`.

**Yêu cầu triển khai:** Định nghĩa đúng hàm `uint8_t update_control(uint8_t reg, uint8_t enable, uint8_t mode)` đã khai báo trong `bai_tap.h`. Dùng `uint8_t` cho thanh ghi và các tham số; dùng mặt nạ và toán tử bit để xóa rồi ghi các trường cần cập nhật; không thay đổi các bit 3–7.

**Ví dụ:** `update_control(168, 1, 2)` trả về `173` (`0xAD`). Giá trị ban đầu `168` tương ứng `0xA8`; sau khi đặt `ENABLE = 1` và `MODE = 2`, ba bit thấp là `101₂`, các bit còn lại giữ nguyên.

## Bài 2 — Điều khiển quạt theo ngưỡng nhiệt độ (5 điểm)

Quạt có hai trạng thái `FAN_OFF` và `FAN_ON`; ban đầu là `FAN_OFF`. Với mỗi giá trị nhiệt độ đọc được, áp dụng quy tắc:

- Nếu đang `FAN_OFF` và nhiệt độ **từ 70 trở lên**, chuyển sang `FAN_ON`.
- Nếu đang `FAN_ON` và nhiệt độ **từ 50 trở xuống**, chuyển sang `FAN_OFF`.
- Các trường hợp còn lại giữ nguyên trạng thái. Trong khoảng 51–69, kết quả phụ thuộc trạng thái trước đó.

Viết hàm `evaluate_fan` nhận số lượng giá trị và mảng nhiệt độ. Hàm xử lý các phần tử theo thứ tự, rồi trả về `FanResult` gồm trạng thái cuối, số lần quạt ở trạng thái `FAN_ON` **sau khi xử lý từng giá trị**, và số lần chuyển trạng thái.

**Đầu vào:** `count` từ 1 đến 1000; `temperatures` trỏ tới mảng có đúng `count` phần tử, mỗi phần tử trong khoảng 0–100. Bộ kiểm thử bảo đảm con trỏ hợp lệ và các giá trị thuộc những khoảng này.

**Đầu ra:** Một giá trị `FanResult` có ba trường `final_state`, `on_count` và `transition_count` theo yêu cầu `TODO` trong header. Không in kết quả trong hàm. Khi tự kiểm tra, có thể in `ON` hoặc `OFF`, tiếp theo là hai số đếm.

**Yêu cầu triển khai:** Tự khai báo trong `bai_tap.h` kiểu liệt kê (enum) `FanState` với `FAN_OFF = 0`, `FAN_ON = 1`, và kiểu cấu trúc `FanResult` gồm `FanState final_state`, `size_t on_count`, `size_t transition_count`. Sau đó định nghĩa đúng hàm `FanResult evaluate_fan(size_t count, const uint8_t temperatures[])` đã khai báo trong header. Dùng vòng lặp xử lý từng phần tử; so sánh trạng thái trước và sau mỗi lần đọc để đếm số lần chuyển. Có thể viết thêm hàm phụ để xử lý một giá trị nhiệt độ.

**Ví dụ:** Với `count = 7` và `temperatures = {45, 70, 65, 49, 60, 75, 50}`, hàm trả về `final_state = FAN_OFF`, `on_count = 3`, `transition_count = 4`. Quạt ở trạng thái `FAN_ON` sau các lần đọc thứ 2, 3 và 6.

## Tiêu chí đánh giá

| Nội dung | Điểm |
| --- | ---: |
| Bài 1: 5 ca kiểm thử đều trả về đúng kết quả | 3 |
| Bài 1: tên biến, tên hàm và cách trình bày mã rõ ràng | 2 |
| Bài 2: 5 ca kiểm thử đều trả về đúng kết quả | 3 |
| Bài 2: tên biến, tên hàm và cách trình bày mã rõ ràng | 2 |

File ca kiểm thử dùng để tính điểm không được công bố.
