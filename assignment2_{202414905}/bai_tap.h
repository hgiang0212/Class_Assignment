#ifndef C_FOR_EMBED_PE_ASSIGNMENT2_BAI_TAP_H
#define C_FOR_EMBED_PE_ASSIGNMENT2_BAI_TAP_H

#include <vector>
#include <string>

/*
 * ASSIGNMENT 2
 * Quy cách nộp bài:
 * - Sinh viên định nghĩa cả 3 hàm bên dưới vào duy nhất 1 tệp: bai_tap.cpp
 * - Chỉ nộp duy nhất tệp bai_tap.cpp (không viết hàm main trong bai_tap.cpp).
 */

/* =========================================================================
 * BÀI 1: CẶP PHẦN TỬ CÓ TỔNG BẰNG MỤC TIÊU (TWO SUM) (3.0 điểm)
 * =========================================================================
 * Cho vector số nguyên nums và một giá trị mục tiêu target.
 * Tìm hai vị trí (chỉ số i, j) khác nhau trong vector sao cho:
 *     nums[i] + nums[j] == target
 *
 * Đầu vào:
 * - nums: tham chiếu hằng tới vector số nguyên (const std::vector<int>&)
 * - target: giá trị mục tiêu kiểu số nguyên có dấu int
 * - Giả định: Mỗi bộ dữ liệu kiểm thử hợp lệ có đúng một nghiệm duy nhất;
 *   không sử dụng cùng một phần tử hai lần.
 *
 * Đầu ra:
 * - std::vector<int> gồm đúng 2 phần tử {i, j} chứa hai chỉ số tìm được
 *   (thứ tự {i, j} hay {j, i} đều được chấp nhận).
 * - Trả về vector rỗng {} nếu nums có ít hơn 2 phần tử hoặc không tìm thấy nghiệm.
 *
 * Yêu cầu triển khai:
 * - Trả về trực tiếp đối tượng std::vector<int> chứa hai chỉ số.
 * - Sinh viên được tự do lựa chọn và sáng tạo giải pháp thuật toán phù hợp
 *   bên trong bai_tap.cpp. Các giải thuật khác nhau sẽ có điểm số khác nhau.
 *   Theo đó, giải thuật càng tối ưu thì điểm càng cao.
 *
 * Ví dụ minh họa:
 * - nums = {2, 7, 11, 15}, target = 9  --> trả về {0, 1} (vì nums[0] + nums[1] = 2 + 7 = 9)
 * - nums = {3, 2, 4},      target = 6  --> trả về {1, 2} (vì nums[1] + nums[2] = 2 + 4 = 6)
 * - nums = {3, 3},         target = 6  --> trả về {0, 1} (hai phần tử ở 2 vị trí khác nhau)
 * - nums = {-1, -2, -3, -4, -5}, target = -8 --> trả về {2, 4} (vì (-3) + (-5) = -8)
 * - nums = {100, 20, 30, 40, -100}, target = 0 --> trả về {0, 4} (vì 100 + (-100) = 0)
 * - nums = {1, 2, 3},      target = 100 --> trả về {}    (không tìm thấy nghiệm)
 */
std::vector<int> two_sum(const std::vector<int>& nums, int target);

/* =========================================================================
 * BÀI 2: TIỀN TỐ CHUNG DÀI NHẤT (LONGEST COMMON PREFIX) (3.5 điểm)
 * =========================================================================
 * Cho vector strs chứa danh sách các xâu ký tự std::string.
 * Tìm tiền tố chung dài nhất xuất hiện ở đầu tất cả các xâu trong vector.
 *
 * Đầu vào:
 * - strs: tham chiếu hằng tới vector các xâu ký tự (const std::vector<std::string>&)
 *
 * Đầu ra:
 * - Đối tượng std::string biểu diễn tiền tố chung dài nhất.
 * - Trả về xâu rỗng "" nếu vector strs rỗng hoặc giữa các xâu không có ký tự chung nào ở đầu.
 *
 * Yêu cầu triển khai:
 * - Xử lý đầy đủ các trường hợp: vector rỗng, vector chỉ có 1 xâu, hoặc chứa xâu rỗng "".
 * - Tận dụng các phương thức chuẩn của std::string (như .substr(), .size(), []).
 *
 * Ví dụ minh họa:
 * - strs = {"flower", "flow", "flight"}               --> trả về "fl"
 * - strs = {"dog", "racecar", "car"}                  --> trả về "" (không có ký tự chung ở đầu)
 * - strs = {"thiet_bi", "thiet_bi_do", "thiet_bi_dieu_khien"} --> trả về "thiet_bi"
 * - strs = {"sensor"}                                 --> trả về "sensor" (chỉ có 1 xâu)
 * - strs = {"", "abc", "abd"}                         --> trả về "" (chứa xâu rỗng)
 * - strs = {}                                         --> trả về "" (vector rỗng)
 */
std::string longest_common_prefix(const std::vector<std::string>& strs);

/* =========================================================================
 * BÀI 3: CỘNG MỘT ĐƠN VỊ VÀO SỐ NGUYÊN LỚN (PLUS ONE) (3.5 điểm)
 * =========================================================================
 * Cho vector digits biểu diễn một số nguyên không âm.
 * Chữ số có trọng số cao nhất (hàng cao nhất) nằm ở digits[0], và chữ số
 * hàng đơn vị nằm ở cuối vector (digits.back()).
 * Thực hiện phép toán cộng thêm 1 đơn vị vào số nguyên này và trả về vector
 * các chữ số kết quả.
 *
 * Đầu vào:
 * - digits: tham chiếu hằng tới vector các chữ số (const std::vector<int>&),
 *   mỗi phần tử trong khoảng từ 0 đến 9.
 * - Dãy chữ số không chứa số 0 ở đầu, ngoại trừ trường hợp chính số 0 ({0}).
 *
 * Đầu ra:
 * - std::vector<int> chứa các chữ số của kết quả sau khi cộng 1.
 * - Trả về vector rỗng {} nếu digits rỗng.
 *
 * Yêu cầu triển khai:
 * - Duyệt và tính toán phép cộng từ phải sang trái (từ hàng đơn vị sang hàng
 *   cao nhất), quản lý biến nhớ (carry).
 * - Xử lý trường hợp đặc biệt khi toàn bộ các chữ số ban đầu đều là 9
 *   (ví dụ: 999 + 1 = 1000): kích thước vector kết quả tăng thêm 1 phần tử
 *   so với ban đầu. Không sử dụng lệnh goto.
 *
 * Ví dụ minh họa:
 * - digits = {1, 2, 3}    --> trả về {1, 2, 4}    (123 + 1 = 124)
 * - digits = {1, 2, 9}    --> trả về {1, 3, 0}    (129 + 1 = 130, nhớ sang hàng chục)
 * - digits = {1, 9, 9}    --> trả về {2, 0, 0}    (199 + 1 = 200, nhớ lan truyền)
 * - digits = {9, 9, 9}    --> trả về {1, 0, 0, 0} (999 + 1 = 1000, tăng số lượng chữ số)
 * - digits = {9}          --> trả về {1, 0}       (9 + 1 = 10)
 * - digits = {0}          --> trả về {1}          (0 + 1 = 1)
 * - digits = {}           --> trả về {}           (vector rỗng)
 */
std::vector<int> plus_one(const std::vector<int>& digits);

#endif /* C_FOR_EMBED_PE_ASSIGNMENT2_BAI_TAP_H */
