#include <bits/stdc++.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
// #include <iostream>
// #include <limits>

void Menu() {
  system("clear");
  std::cout << "Aplikasi Sorting Insertion" << "\n";
  std::cout << "1. Memasukkan Data" << "\n";
  std::cout << "2. Menampilkan Data" << "\n";
  std::cout << "3. Sorting" << "\n";
  std::cout << "4. Kata-Kata" << "\n";
  std::cout << "5. Exit" << "\n";
  std::cout << "Masukan angka: ";
}

// Callback function untuk menulis response
size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                     std::string *output) {
  size_t total_size = size * nmemb;
  output->append((char *)contents, total_size);
  return total_size;
}

using json = nlohmann::json;
void AI() {

  CURL *curl;
  CURLcode res;
  std::string response;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();

  if (curl) {
    std::string input;
    std::cout << "Masukkan pertanyaan: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);

    char *encodedInput = curl_easy_escape(curl, input.c_str(), input.length());
    std::string url = "https://api.ryzumi.vip/api/ai/chatgpt?text=" +
                      std::string(encodedInput);
    curl_free(encodedInput);

    // Set header untuk bypass Cloudflare
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "accept: application/json");
    headers = curl_slist_append(headers, "accept-language: en-US,en;q=0.9");
    headers = curl_slist_append(headers,
                                "user-agent: Mozilla/5.0 (Windows NT 10.0; "
                                "Win64; x64) AppleWebKit/537.36 (KHTML, like "
                                "Gecko) Chrome/101.0.4951.54 Safari/537.36");
    headers = curl_slist_append(headers, "referer: https://api.ryzumi.vip/");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // Set opsi tambahan
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Ikuti redirect
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);

    if (res == CURLE_OK) {
      try {
        json jsonResponse = json::parse(response);
        if (jsonResponse["success"]) {
          std::cout << "AI: " << jsonResponse["result"] << std::endl;
        } else {
          std::cerr << "API Error: " << jsonResponse.dump() << std::endl;
        }
      } catch (...) {
        std::cerr << "Response (non-JSON):\n" << response << std::endl;
      }
    } else {
      std::cerr << "CURL Error: " << curl_easy_strerror(res) << std::endl;
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();
  std::cout << "Proses Selesai" << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

template <typename T> void InsertData(T &data) {
  system("clear");
  if (!data.empty()) {
    data.clear();
  }
  size_t n;

  std::cout << "Masukkan banyak data yang mau dimasukkan: ";
  std::cin >> n;

  for (size_t i = 0; i < n; i++) {
    std::cout << "Masukkan Data[" << i << "]: ";
    int buff;
    std::cin >> buff;
    data.push_back(buff);
  }
}

template <typename T> void PrintData(T &data) {
  system("clear");
  std::cout << "Array: ";
  for (const auto &i : data) {

    std::cout << i << " ";
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

template <typename T> void SortingData(T &data) {
  system("clear");

  size_t n = data.size();
  for (size_t i = 1; i < n; i++) {
    int tmp = data[i];
    size_t j = i;

    while (j > 0 and data[j - 1] > tmp) {
      data[j] = data[j - 1];

      j--;
    }
    data[j] = tmp;
  }

  std::cout << "Sorting data berhasil!" << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

using myArray = std::vector<int>;

int main() {
  myArray arr;
  char pl;
  do {
    Menu();
    std::cin >> pl;
    switch (pl) {
    case '1':
      /* code */
      InsertData<myArray>(arr);
      break;
    case '2':
      /* code */
      PrintData<myArray>(arr);
      break;
    case '3':
      /* code */
      SortingData<myArray>(arr);
      break;
    case '4':
      /* code */
      AI();
      break;
    case '5':
      /* code */
      break;

    default:
      system("clear");
      std::cout << "Pilihan Tidak Tersedia";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin.get();
      break;
    }

  } while (pl != '5');

  return 0;
}
