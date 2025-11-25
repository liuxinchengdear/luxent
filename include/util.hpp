#pragma once
#include <random>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <filesystem>
#include <ranges>
#include <utility>

namespace util {

using ll = long long;

inline std::mt19937_64 rnd(20240809);

inline void setSeed(unsigned long long seed = 20240809UL) {
  rnd.seed(seed);
}

template<typename T>
inline T modx(T x) {
  assert(x > 0);
  return rnd() % x; 
}

template<typename T>
inline T mod1(T x) { return modx(x) + 1; }

template<typename T>
inline T rangeRand(T l, T r) { return l + modx(r - l + 1); }

template<typename T>
inline std::pair<T, T> randRange(T L, T R) {
  T l = rangeRand(L, R), r = rangeRand(L, R);
  if (l > r) std::swap(l, r);
  return std::make_pair(l, r);
}

inline char randChar() { return 'a' + modx(26); }

template<typename T>
inline std::vector<T> genArr(int len, T lim, auto &&genFunc) {
  std::vector<T> ret;
  for (auto _ : std::views::iota(0, len)) ret.push_back(genFunc(lim));
  return ret;
}

std::string genStr(int len, auto &&genChar = randChar) {
  std::string ret;
  for (auto _ : std::views::iota(0, len)) ret += genChar();
  return ret;
}

template<typename T>
T choice(const std::vector<T> &a) { return a[modx(a.size())]; }
template<typename T, size_t N>
T choice(const std::array<T, N> &a) { return a[modx(a.size())]; }

template<typename T>
void shuffle_vec(std::vector<T> &a) { std::ranges::shuffle(a, rnd); }

template<typename T>
void printArr(const std::vector<T> &arr, const std::string &split = " ", const std::string &end = "\n") {
  for (auto it = arr.begin(), lst = std::prev(arr.end()); it != arr.end(); ++it) {
    std::cout << *it;
    if (it != lst) std::cout << split;
  }
  std::cout << end;
}

template<typename First, typename... Args>
void println(const First &first, Args&&... args) {
  std::cout << first;
  ((std::cout <<  " " << std::forward<Args>(args)), ...);
  std::cout << '\n';
}

inline void mkdir(const std::string& x) {
  namespace fs = std::filesystem;
  if (!fs::exists(x) || !fs::is_directory(x)) {
    fs::create_directory(x);
    std::cerr << "Created directory: " << x << "\n";
  }
}

struct DataGenerator {
  static void makeData(int T);
  static void makeSample(int T) {} 

  static void run(
    const std::string& dataName = "data",
    int testCnt = 10,
    int sampleCnt = 0,
    const std::string& stdName = "std",
    const std::string& dataFolderName = "data",
    const std::string& sampleFoldName = "down"
  ) {
    const std::string dataPath = "./" + dataFolderName + "/";
    const std::string samplePath = "./" + sampleFoldName + "/";
    mkdir(dataFolderName);
    mkdir(sampleFoldName);
    
    for (int T = 1; T <= testCnt; ++T) {
      const auto taskName = dataName + std::to_string(T);
      generateFile(dataPath + taskName + ".in", [T] { makeData(T); });
      generateAnswer(dataPath + taskName, stdName);
    }
    
    for (int T = 1; T <= sampleCnt; ++T) {
      const auto taskName = std::to_string(T);
      generateFile(samplePath + taskName + ".in", [T] { makeSample(T); });
      generateAnswer(samplePath + taskName, stdName);
    }
  }

 private:
  static void generateFile(const std::string& filename, auto&& genFunc) {
    freopen(filename.c_str(), "wb", stdout);
    genFunc();
    std::cerr << "Generated: " << filename << "\n";
    fflush(stdout);
  }

  static void generateAnswer(const std::string& prefix, const std::string &stdName) {
    const std::string cmd = "./" + stdName +  "< " + prefix + ".in > " + prefix + ".ans";
    system(cmd.c_str());
    std::cerr << "Generated answer: " << prefix << ".ans\n";
  }
};

}