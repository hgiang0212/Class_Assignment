#ifndef C_FOR_EMBED_PE_ASSIGNMENT3_BAI_TAP_H
#define C_FOR_EMBED_PE_ASSIGNMENT3_BAI_TAP_H

#include <cstddef>

/*
 * ASSIGNMENT 3 — BỘ ĐỆM VÒNG (CIRCULAR BUFFER / RING BUFFER)
 *
 * Thang điểm: độ chính xác 8.0 (mỗi bài 4.0), coding style 1.0, độ tối ưu 1.0.
 * Tiêu chí đánh giá chung: Mục 5 trong DE_BAI.md.
 *
 * Quy cách làm bài và nộp bài:
 * - Sinh viên định nghĩa toàn bộ các hàm của Bài 1 và Bài 2 ngay trong tệp bai_tap.cpp.
 * - Cuối tệp bai_tap.cpp đã tích hợp sẵn khung mô phỏng kịch bản Ghi - Đọc
 *   (Writer-Reader scenario) và hàm main() để sinh viên biên dịch và chạy thử trực tiếp:
 *       c++ -std=c++20 -Wall -Wextra -Wpedantic bai_tap.cpp -o bai_tap && ./bai_tap
 * - Nộp assignment3_{student_id}.zip, thay {student_id} bằng mã số sinh viên.
 *   Ví dụ: assignment3_20241234.zip; không ghi dấu ngoặc nhọn trong tên tệp.
 * - ZIP chỉ chứa bai_tap.cpp ở thư mục gốc (giữ nguyên hàm main() khi nộp).
 */

/* Kích thước mảng vật lý cố định của bộ đệm vòng (8 ô nhớ).
 * Lưu ý: Vì chỉ sử dụng mảng và 2 chỉ số (Bài 1) hoặc 2 con trỏ (Bài 2)
 * mà KHÔNG dùng thêm biến đếm số lượng phần tử (count), bộ đệm dành ra 1 ô trống
 * để phân biệt trạng thái Đầy (Full) và Rỗng (Empty).
 * Do đó, dung lượng lưu trữ tối đa tại một thời điểm là (CB_CAPACITY - 1) = 7 phần tử.
 */
constexpr int CB_CAPACITY = 8;

/* =========================================================================
 * BÀI 1: BỘ ĐỆM VÒNG DÙNG MẢNG VÀ 2 CHỈ SỐ (ARRAY & 2 INDICES) (4.0 điểm độ chính xác)
 * =========================================================================
 * Cấu trúc IndexCircularBuffer chỉ sử dụng:
 * - Mảng cố định data[CB_CAPACITY]
 * - Chỉ số ghi (head): vị trí ô nhớ sẽ ghi phần tử tiếp theo (0 .. CB_CAPACITY - 1)
 * - Chỉ số đọc (tail): vị trí ô nhớ sẽ đọc phần tử tiếp theo (0 .. CB_CAPACITY - 1)
 *
 * Quy ước trạng thái:
 * - Khởi tạo (init): head = 0, tail = 0
 * - Rỗng (empty):    head == tail
 * - Đầy (full):      (head + 1) % CB_CAPACITY == tail
 *
 * Ví dụ minh họa với CB_CAPACITY = 8:
 * - Ban đầu: head = 0, tail = 0 --> Rỗng (size = 0)
 * - Ghi 3 số {10, 20, 30}:
 *     data[0]=10, data[1]=20, data[2]=30; head = 3, tail = 0 (size = 3)
 * - Đọc 2 số:
 *     Lấy ra 10 (tại tail=0) và 20 (tại tail=1); head = 3, tail = 2 (size = 1)
 * - Ghi tiếp 6 số {40, 50, 60, 70, 80, 90}:
 *     head lần lượt đi qua 3, 4, 5, 6, 7(->0), 0(->1).
 *     Lúc này head = 1, tail = 2. Vì (head + 1) % 8 == 2 == tail nên bộ đệm ĐẦY (size = 7).
 * - Nếu ghi thêm khi đang đầy: trả về false, không ghi đè dữ liệu.
 */
struct IndexCircularBuffer {
    int data[CB_CAPACITY];
    int head; /* Chỉ số ghi (Writer index) */
    int tail; /* Chỉ số đọc (Reader index) */
};

/* Khởi tạo bộ đệm vòng dùng chỉ số về trạng thái rỗng ban đầu (head = 0, tail = 0) */
void cb_index_init(IndexCircularBuffer& cb);

/* Kiểm tra bộ đệm có đang rỗng hay không */
bool cb_index_is_empty(const IndexCircularBuffer& cb);

/* Kiểm tra bộ đệm đã đầy hay chưa (chứa đủ CB_CAPACITY - 1 phần tử) */
bool cb_index_is_full(const IndexCircularBuffer& cb);

/* Trả về số lượng phần tử hiện đang lưu trong bộ đệm (từ 0 đến CB_CAPACITY - 1) */
int cb_index_size(const IndexCircularBuffer& cb);

/* Ghi (push) một phần tử value vào bộ đệm tại vị trí head:
 * - Nếu bộ đệm đã đầy: không ghi, giữ nguyên trạng thái và trả về false.
 * - Nếu còn chỗ: lưu value vào data[head], cập nhật head xoay vòng và trả về true.
 */
bool cb_index_write(IndexCircularBuffer& cb, int value);

/* Đọc (pop) một phần tử từ bộ đệm tại vị trí tail:
 * - Nếu bộ đệm đang rỗng: không đọc, giữ nguyên out_value và trả về false.
 * - Nếu có dữ liệu: gán phần tử tại data[tail] cho out_value, cập nhật tail
 *   xoay vòng và trả về true.
 */
bool cb_index_read(IndexCircularBuffer& cb, int& out_value);


/* =========================================================================
 * BÀI 2: BỘ ĐỆM VÒNG DÙNG MẢNG VÀ 2 CON TRỎ (ARRAY & 2 POINTERS) (4.0 điểm độ chính xác)
 * =========================================================================
 * Cấu trúc PointerCircularBuffer chỉ sử dụng:
 * - Mảng cố định data[CB_CAPACITY]
 * - Con trỏ ghi (head): trỏ trực tiếp tới ô nhớ trong mảng data sẽ ghi tiếp theo
 * - Con trỏ đọc (tail): trỏ trực tiếp tới ô nhớ trong mảng data sẽ đọc tiếp theo
 *
 * Quy ước trạng thái:
 * - Khởi tạo (init): head = &cb.data[0], tail = &cb.data[0] (tức cb.data)
 * - Khi tăng con trỏ p lên 1 ô (++p): nếu p chạm mốc cuối mảng (cb.data + CB_CAPACITY)
 *   thì p phải quay vòng về lại đầu mảng (cb.data).
 * - Rỗng (empty):    head == tail
 * - Đầy (full):      vị trí kế tiếp (sau khi tính xoay vòng) của head trùng với tail.
 *
 * Lưu ý: Sinh viên thao tác trực tiếp bằng số học con trỏ và giải tham chiếu (*head, *tail),
 * không dùng biến chỉ số phụ bên trong struct.
 */
struct PointerCircularBuffer {
    int data[CB_CAPACITY];
    int* head; /* Con trỏ ghi (Writer pointer) */
    int* tail; /* Con trỏ đọc (Reader pointer) */
};

/* Khởi tạo bộ đệm vòng dùng con trỏ: cho head và tail cùng trỏ vào đầu mảng cb.data */
void cb_ptr_init(PointerCircularBuffer& cb);

/* Kiểm tra bộ đệm dùng con trỏ có đang rỗng hay không */
bool cb_ptr_is_empty(const PointerCircularBuffer& cb);

/* Kiểm tra bộ đệm dùng con trỏ đã đầy hay chưa */
bool cb_ptr_is_full(const PointerCircularBuffer& cb);

/* Trả về số lượng phần tử hiện đang lưu trong bộ đệm (tính qua độ lệch giữa 2 con trỏ) */
int cb_ptr_size(const PointerCircularBuffer& cb);

/* Ghi (push) một phần tử value vào ô nhớ do con trỏ head trỏ tới:
 * - Nếu bộ đệm đã đầy: trả về false.
 * - Nếu còn chỗ: ghi *head = value, dịch chuyển con trỏ head sang ô kế tiếp
 *   (xoay vòng về cb.data nếu chạm cb.data + CB_CAPACITY) và trả về true.
 */
bool cb_ptr_write(PointerCircularBuffer& cb, int value);

/* Đọc (pop) một phần tử từ ô nhớ do con trỏ tail trỏ tới:
 * - Nếu bộ đệm đang rỗng: giữ nguyên out_value và trả về false.
 * - Nếu có dữ liệu: gán out_value = *tail, dịch chuyển con trỏ tail sang ô kế tiếp
 *   (xoay vòng về cb.data nếu chạm cb.data + CB_CAPACITY) và trả về true.
 */
bool cb_ptr_read(PointerCircularBuffer& cb, int& out_value);

#endif /* C_FOR_EMBED_PE_ASSIGNMENT3_BAI_TAP_H */

