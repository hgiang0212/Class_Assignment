#ifndef C_FOR_EMBED_PE_BAI_TAP_H
#define C_FOR_EMBED_PE_BAI_TAP_H

#include <stddef.h>
#include <stdint.h>

/* Bài 1: Cập nhật bit ENABLE (bit 0) và MODE (bit 1–2).
 * Các bit 3–7 của reg phải được giữ nguyên.
 * Điều kiện đầu vào: enable <= 1, mode <= 3.
 */
uint8_t update_control(uint8_t reg, uint8_t enable, uint8_t mode);

/* TODO (các em): Khai báo typedef enum FanState với hai giá trị
 * FAN_OFF = 0 và FAN_ON = 1.
 */

/* TODO (các em): Khai báo typedef struct FanResult với ba trường:
 * FanState final_state;
 * size_t on_count;
 * size_t transition_count;
 */

/* Bài 2: Xử lý count nhiệt độ theo thứ tự trong temperatures.
 * Trạng thái ban đầu là FAN_OFF. Đếm on_count sau mỗi lần xử lý.
 * Điều kiện đầu vào: 1 <= count <= 1000, temperatures trỏ tới count
 * phần tử hợp lệ (mỗi giá trị từ 0 đến 100).
 */
FanResult evaluate_fan(size_t count, const uint8_t temperatures[]);

#endif
