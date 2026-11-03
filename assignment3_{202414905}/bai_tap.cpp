#include <iostream>
#include "bai_tap.h"

/* =========================================================================
 * BÀI 1: BỘ ĐỆM VÒNG DÙNG MẢNG VÀ 2 CHỈ SỐ (ARRAY & 2 INDICES)
 * ========================================================================= */

void cb_index_init(IndexCircularBuffer& cb) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
}

bool cb_index_is_empty(const IndexCircularBuffer& cb) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
    return true;
}

bool cb_index_is_full(const IndexCircularBuffer& cb) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
    return false;
}

int cb_index_size(const IndexCircularBuffer& cb) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
    return 0;
}

bool cb_index_write(IndexCircularBuffer& cb, int value) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
    (void)value;
    return false;
}

bool cb_index_read(IndexCircularBuffer& cb, int& out_value) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
    (void)out_value;
    return false;
}

/* =========================================================================
 * BÀI 2: BỘ ĐỆM VÒNG DÙNG MẢNG VÀ 2 CON TRỎ (ARRAY & 2 POINTERS)
 * ========================================================================= */

void cb_ptr_init(PointerCircularBuffer& cb) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
}

bool cb_ptr_is_empty(const PointerCircularBuffer& cb) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
    return true;
}

bool cb_ptr_is_full(const PointerCircularBuffer& cb) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
    return false;
}

int cb_ptr_size(const PointerCircularBuffer& cb) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
    return 0;
}

bool cb_ptr_write(PointerCircularBuffer& cb, int value) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
    (void)value;
    return false;
}

bool cb_ptr_read(PointerCircularBuffer& cb, int& out_value) {
    // TODO: Sinh viên hoàn thiện hàm này
    (void)cb;
    (void)out_value;
    return false;
}

/* =========================================================================
 * KHUNG MÔ PHỎNG KỊCH BẢN GHI - ĐỌC (WRITER - READER SCENARIO)
 *
 * Sinh viên biên dịch và chạy trực tiếp tệp bai_tap.cpp này để kiểm thử:
 *   c++ -std=c++20 -Wall -Wextra -Wpedantic bai_tap.cpp -o bai_tap
 *   ./bai_tap
 *
 * Khi nộp bài: Giữ nguyên hàm main() bên dưới; nén riêng bai_tap.cpp ở thư mục
 * gốc của assignment3_{student_id}.zip, thay {student_id} bằng mã số sinh viên.
 * Ví dụ: assignment3_20241234.zip (không ghi dấu ngoặc nhọn trong tên tệp).
 * ========================================================================= */

static void print_index_buffer_state(const IndexCircularBuffer& cb, const char* step_title) {
    std::cout << "  [" << step_title << "] "
              << "head=" << cb.head
              << ", tail=" << cb.tail
              << ", size=" << cb_index_size(cb)
              << ", empty=" << (cb_index_is_empty(cb) ? "true" : "false")
              << ", full=" << (cb_index_is_full(cb) ? "true" : "false")
              << "\n";
}

static void print_ptr_buffer_state(const PointerCircularBuffer& cb, const char* step_title) {
    long head_offset = (cb.head != nullptr) ? (cb.head - cb.data) : -1;
    long tail_offset = (cb.tail != nullptr) ? (cb.tail - cb.data) : -1;
    std::cout << "  [" << step_title << "] "
              << "head=&data[" << head_offset << "]"
              << ", tail=&data[" << tail_offset << "]"
              << ", size=" << cb_ptr_size(cb)
              << ", empty=" << (cb_ptr_is_empty(cb) ? "true" : "false")
              << ", full=" << (cb_ptr_is_full(cb) ? "true" : "false")
              << "\n";
}

static void run_writer_reader_scenario_index() {
    std::cout << "=================================================================\n";
    std::cout << "MO PHONG WRITER - READER: BAI 1 (ARRAY & 2 INDICES)\n";
    std::cout << "=================================================================\n";

    IndexCircularBuffer cb;
    cb_index_init(cb);
    print_index_buffer_state(cb, "Khoi tao");

    // Pha 1: Writer đẩy đợt 1 gồm 5 mẫu dữ liệu cảm biến {10, 20, 30, 40, 50}
    std::cout << "\n-> Pha 1 (Writer): Ghi 5 mau {10, 20, 30, 40, 50}\n";
    int batch1[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i) {
        bool ok = cb_index_write(cb, batch1[i]);
        std::cout << "   Writer ghi " << batch1[i] << " -> " << (ok ? "THANH CONG" : "THAT BAI (DAY)") << "\n";
    }
    print_index_buffer_state(cb, "Sau Pha 1");

    // Pha 2: Reader xử lý 3 mẫu đầu tiên (kỳ vọng: 10, 20, 30)
    std::cout << "\n-> Pha 2 (Reader): Doc ra 3 mau\n";
    for (int i = 0; i < 3; ++i) {
        int val = -1;
        bool ok = cb_index_read(cb, val);
        if (ok) {
            std::cout << "   Reader doc duoc: " << val << "\n";
        } else {
            std::cout << "   Reader doc THAT BAI (RONG)\n";
        }
    }
    print_index_buffer_state(cb, "Sau Pha 2");

    // Pha 3: Writer đẩy đợt 2 gồm 6 mẫu {60, 70, 80, 90, 100, 110}
    // Lúc này bộ đệm đang có 2 mẫu (40, 50), chỉ còn 5 chỗ trống (sức chứa tối đa là 7).
    // Chỉ số head sẽ đi qua cuối mảng và xoay vòng (wrap-around) về đầu mảng.
    // Mẫu cuối cùng (110) sẽ bị từ chối vì bộ đệm đầy!
    std::cout << "\n-> Pha 3 (Writer): Ghi tiep 6 mau {60, 70, 80, 90, 100, 110} (kiem tra xoay vong & tran)\n";
    int batch2[6] = {60, 70, 80, 90, 100, 110};
    for (int i = 0; i < 6; ++i) {
        bool ok = cb_index_write(cb, batch2[i]);
        std::cout << "   Writer ghi " << batch2[i] << " -> " << (ok ? "THANH CONG" : "TU CHOI (BO DEM DAY)") << "\n";
    }
    print_index_buffer_state(cb, "Sau Pha 3");

    // Pha 4: Reader đọc cạn toàn bộ dữ liệu trong bộ đệm (8 lần gọi read, lần thứ 8 phải báo rỗng)
    std::cout << "\n-> Pha 4 (Reader): Doc can toan bo du lieu (8 lan goi read)\n";
    for (int i = 0; i < 8; ++i) {
        int val = -1;
        bool ok = cb_index_read(cb, val);
        if (ok) {
            std::cout << "   Reader doc duoc: " << val << "\n";
        } else {
            std::cout << "   Reader doc lan " << (i + 1) << " -> TU CHOI (BO DEM RONG)\n";
        }
    }
    print_index_buffer_state(cb, "Sau Pha 4");
}

static void run_writer_reader_scenario_pointer() {
    std::cout << "\n=================================================================\n";
    std::cout << "MO PHONG WRITER - READER: BAI 2 (ARRAY & 2 POINTERS)\n";
    std::cout << "=================================================================\n";

    PointerCircularBuffer cb;
    cb_ptr_init(cb);
    print_ptr_buffer_state(cb, "Khoi tao");

    // Pha 1: Writer đẩy 5 mẫu {10, 20, 30, 40, 50}
    std::cout << "\n-> Pha 1 (Writer): Ghi 5 mau {10, 20, 30, 40, 50}\n";
    int batch1[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i) {
        bool ok = cb_ptr_write(cb, batch1[i]);
        std::cout << "   Writer ghi " << batch1[i] << " -> " << (ok ? "THANH CONG" : "THAT BAI (DAY)") << "\n";
    }
    print_ptr_buffer_state(cb, "Sau Pha 1");

    // Pha 2: Reader đọc 3 mẫu
    std::cout << "\n-> Pha 2 (Reader): Doc ra 3 mau\n";
    for (int i = 0; i < 3; ++i) {
        int val = -1;
        bool ok = cb_ptr_read(cb, val);
        if (ok) {
            std::cout << "   Reader doc duoc: " << val << "\n";
        } else {
            std::cout << "   Reader doc THAT BAI (RONG)\n";
        }
    }
    print_ptr_buffer_state(cb, "Sau Pha 2");

    // Pha 3: Writer ghi tiếp 6 mẫu (con trỏ head xoay vòng qua cuối mảng)
    std::cout << "\n-> Pha 3 (Writer): Ghi tiep 6 mau {60, 70, 80, 90, 100, 110}\n";
    int batch2[6] = {60, 70, 80, 90, 100, 110};
    for (int i = 0; i < 6; ++i) {
        bool ok = cb_ptr_write(cb, batch2[i]);
        std::cout << "   Writer ghi " << batch2[i] << " -> " << (ok ? "THANH CONG" : "TU CHOI (BO DEM DAY)") << "\n";
    }
    print_ptr_buffer_state(cb, "Sau Pha 3");

    // Pha 4: Reader đọc cạn
    std::cout << "\n-> Pha 4 (Reader): Doc can toan bo du lieu (8 lan goi read)\n";
    for (int i = 0; i < 8; ++i) {
        int val = -1;
        bool ok = cb_ptr_read(cb, val);
        if (ok) {
            std::cout << "   Reader doc duoc: " << val << "\n";
        } else {
            std::cout << "   Reader doc lan " << (i + 1) << " -> TU CHOI (BO DEM RONG)\n";
        }
    }
    print_ptr_buffer_state(cb, "Sau Pha 4");
}

static void student_custom_tests() {
    // TODO (Tùy chọn cho sinh viên): Viết thêm các ca kiểm thử biên tại đây
    // Ví dụ:
    // - Đọc ngay khi vừa khởi tạo (bộ đệm rỗng)
    // - Ghi 1 phần tử rồi đọc ngay lặp lại 20 lần liên tiếp để kiểm tra xoay vòng nhiều chu kỳ
    // - Kiểm tra giá trị âm, giá trị 0
}

int main() {
    run_writer_reader_scenario_index();
    run_writer_reader_scenario_pointer();
    student_custom_tests();
    return 0;
}
