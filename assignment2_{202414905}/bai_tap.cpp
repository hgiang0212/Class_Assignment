#include "bai_tap.h"
#include <climits>
#include <cstddef>
#include <unordered_map>
/* =========================================================================
 * BÀI 1: TÌM CẶP PHẦN TỬ CÓ TỔNG BẰNG MỤC TIÊU (TWO SUM)
 * ========================================================================= */
std::vector<int> two_sum(const std::vector<int> &nums, int target)
{
    // TODO: Sinh viên hoàn thiện hàm này
    if (nums.size() < 2)
    {
        return {};
    }

    std::unordered_map<int, int> indexed;
    indexed.reserve(nums.size());
    for (std::size_t i = 0; i <= nums.size() - 1; i++)
    {
        const long long tmp = static_cast<long long>(target) - nums[i];

        if (tmp >= INT_MIN && tmp <= INT_MAX)
        {
            const auto it = indexed.find(static_cast<int>(tmp));
            if (it != indexed.end())
            {
                return {it->second, static_cast<int>(i)};
            }
        }

        indexed[nums[i]] = static_cast<int>(i);
    }

    return {};
}

/* =========================================================================
 * BÀI 2: TÌM TIỀN TỐ CHUNG DÀI NHẤT (LONGEST COMMON PREFIX)
 * ========================================================================= */
std::string longest_common_prefix(const std::vector<std::string> &strs)
{
    // TODO: Sinh viên hoàn thiện hàm này
    if (strs.empty())
    {
        return "";
    }
    const std::string &first = strs[0];
    for (std::size_t position = 0; position < first.size(); ++position)
    {
        const char cur = first[position];
        for (std::size_t k = 1; k <= strs.size() - 1; k++)
        {
            if (position >= strs[k].size() || strs[k][position] != cur)
            {
                return first.substr(0, position);
            }
        }
    }
    return first;
}

/* =========================================================================
 * BÀI 3: CỘNG MỘT ĐƠN VỊ VÀO SỐ NGUYÊN LỚN (PLUS ONE)
 * ========================================================================= */
std::vector<int> plus_one(const std::vector<int> &digits)
{
    // TODO: Sinh viên hoàn thiện hàm này
    if (digits.empty())
    {
        return {};
    }
    std::vector<int> res = digits;
    int tmp = 1;
    for (std::size_t i = res.size(); i-- > 0 && tmp != 0;)
    {
        const int sum = res[i] + tmp;
        res[i] = sum % 10;
        tmp = sum / 10;
    }
    if (tmp != 0)
    {
        res.insert(res.begin(), tmp);
    }

    return res;
}
