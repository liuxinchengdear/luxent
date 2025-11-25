#include <iostream> 
#include <random>

int main() {
    // 创建一个随机数引擎，使用随机设备作为种子
    std::random_device rd;
    std::mt19937 gen(rd());

    // 创建一个均匀分布，范围是0到99
    std::uniform_int_distribution<> dis(0, 99);

    // 生成一个随机数
    int random_number = dis(gen);

    std::cout << "Random number: " << random_number << std::endl;

    return 0;
}