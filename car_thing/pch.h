#ifndef PCH_H
#define PCH_H

constexpr int windowWIDTH = 800;
constexpr int windowHEIGHT = 600;


#if 1
#define LOG(x) std::cout << x << "\n"
#else
#define LOG(x)
#endif // 1


#endif //PCH_H
