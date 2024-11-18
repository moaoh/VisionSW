# VisionSW

VisionSW 프로젝트는 OpenCV의 cv::Blur 필터를 직접 구현하여 이미지의 Blur 처리를 수행하고, 그 성능을 비교하는 프로젝트입니다. 이 프로젝트는 성능 테스트와 이미지 처리 비교를 목표로 하고 있습니다.


## Table Of Contents
1. [Preview](#preview)
2. [Build and Run](#build-and-run)
3. [Log Output](#log-output)
4. [Performance Results](#performance-results)


## Preview

<table>
  <tr>
    <td>
      <img width="300" style="margin-bottom: 5px;" alt="image" src="https://github.com/user-attachments/assets/f560a7d4-324c-475f-9861-e997f527fd9b">
    </td>
  </tr>
  <tr>
    <td>
      <span>output Images</span>
    </td>
  </tr>
</table>

<table>
  <th colspan="2">
    ksize: 51 x 51
  </th>
  <tr>
    <td>
      <img width="450" alt="before" src="https://github.com/user-attachments/assets/70e0442e-3eb6-4bb6-b575-9f69ddf4535a">
    </td>
    <td>
      <img width="450" alt="after" src="https://github.com/user-attachments/assets/2c1993a1-5478-4267-a065-b6d742e18ed9">
    </td>
  </tr>

  <tr >
    <td align="center">
      <span>before</span>
    </td>
   <td align="center">
      <span>after</span>
    </td>
  </tr>
</table>


## Build and Run

OpenCV 설치 및 프로젝트 빌드를 위한 단계입니다.

1. OpenCV 설치 스크립트 실행:

    ```bash
    ./setup_opencv.sh
    ```

    이 스크립트는 OpenCV를 클론하고, 빌드하여 사용할 수 있도록 설정합니다.


2. 빌드 디렉토리 생성 및 프로젝트 빌드:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3. 실행:

    ```bash
    cd ../bin
    ./test_code <config.txt>
    ```

    `config.txt` 파일에는 처리할 이미지나 설정이 포함되어 있어야 합니다.


#### (example) config.txt
```txt
image_paths=<image_file_path>
image_paths=<image_file_path>
kernel_size=<kernel_size (홀수)> 
output_path=<output_path>
```
#### config.txt
```txt
image_paths="../images/image1.jpg"
image_paths="../images/image2.jpg"
image_paths="../images/image3.jpg"
image_paths="../images/image4.jpg"
kernel_size=21
output_path="../output/"
```


## Log Output

이미지 처리 중 발생하는 로그 출력 예시입니다. 이 로그에는 처리된 이미지와 성능, 메모리 사용량 등의 정보가 포함됩니다.

```plaintext
[Mon Nov 18 18:05:30 2024] [INFO] [opencv] Image saved to ../output/opencvimage1.jpg
[Mon Nov 18 18:05:30 2024] [INFO] [opencv] Memory Usage :298MB
[Mon Nov 18 18:05:30 2024] [INFO] [opencv] duration time :1.221481
[Mon Nov 18 18:07:44 2024] [INFO] [custom] Image saved to ../output/customimage1.jpg
[Mon Nov 18 18:07:44 2024] [INFO] [custom] Memory Usage :18446744073709551467MB
[Mon Nov 18 18:07:44 2024] [INFO] [custom] duration time :133.418781
[Mon Nov 18 18:07:45 2024] [INFO] ../images/image1.jpg are identical
[Mon Nov 18 18:07:47 2024] [INFO] [opencv] Image saved to ../output/opencvimage2.jpg
[Mon Nov 18 18:07:47 2024] [INFO] [opencv] Memory Usage :178MB
[Mon Nov 18 18:07:47 2024] [INFO] [opencv] duration time :1.571371
[Mon Nov 18 18:10:36 2024] [INFO] [custom] Image saved to ../output/customimage2.jpg
[Mon Nov 18 18:10:36 2024] [INFO] [custom] Memory Usage :18446744073709551306MB
[Mon Nov 18 18:10:36 2024] [INFO] [custom] duration time :168.127283
[Mon Nov 18 18:10:37 2024] [INFO] ../images/image2.jpg are identical
[Mon Nov 18 18:10:38 2024] [INFO] [opencv] Image saved to ../output/opencvimage3.jpg
[Mon Nov 18 18:10:38 2024] [INFO] [opencv] Memory Usage :79MB
[Mon Nov 18 18:10:38 2024] [INFO] [opencv] duration time :1.112949
[Mon Nov 18 18:12:55 2024] [INFO] [custom] Image saved to ../output/customimage3.jpg
[Mon Nov 18 18:12:55 2024] [INFO] [custom] Memory Usage :18446744073709551287MB
[Mon Nov 18 18:12:55 2024] [INFO] [custom] duration time :136.285041
[Mon Nov 18 18:12:56 2024] [INFO] ../images/image3.jpg are identical
[Mon Nov 18 18:12:57 2024] [WARNING] It's not a black-and-white image ../images/image4.jpg
[Mon Nov 18 18:12:58 2024] [WARNING] It's not a black-and-white image ../images/image4.jpg
```
### 로그 항목 설명:
- `INFO`: 정상적인 처리 결과입니다. 이미지 저장 경로, 메모리 사용량, 처리 시간 등의 유용한 정보를 기록합니다.
- `WARNING`: 처리 중 경고 메시지가 나타납니다. 예를 들어, 처리하려는 이미지가 흑백 이미지가 아닐 경우 경고가 발생할 수 있습니다.
- `ERROR`: 처리 중 문제가 발생한 경우입니다. 예를 들어, 이미지 블러 처리에 실패했거나 이미지를 저장할 수 없는 경우가 있습니다. 이때는 해당 실패에 대한 원인을 구체적으로 기록하는 것이 중요합니다.
   - **이미지 블러 처리 실패**: 이미지 블러 처리 함수가 실패하면 `"Failed to apply blur on image"`와 같은 메시지를 기록할 수 있습니다.
   - **이미지 저장 실패**: 이미지를 지정된 경로에 저장할 수 없는 경우 `"Failed to save image to <경로>"`와 같이 오류를 기록합니다.

## Performance Results

### OpenCV vs Custom Implementation

| Metric          | OpenCV (Time) | OpenCV (Memory) | Custom (Time)  | Custom (Memory) |
|-----------------|---------------|-----------------|----------------|-----------------|
| Image 1         | 1.22s         | 298MB           | 133.42s        | 18446744073709551467MB |
| Image 2         | 1.57s         | 178MB           | 168.13s        | 18446744073709551306MB |
| Image 3         | 1.11s         | 79MB            | 136.29s        | 18446744073709551287MB |

### Analysis
- **OpenCV**: 이미지를 처리하는 속도가 매우 빠르고, 메모리 사용량도 안정적입니다.
- **Custom Implementation**: 속도가 매우 느리고, 메모리 사용량이 비정상적으로 크며, 이는 64비트 음수 값처럼 보이는 이상한 값으로 기록되고 있습니다. 
  이 문제는 메모리 할당 및 관리 부분에서 최적화가 필요할 수 있음을 나타냅니다.

### Notes
### 이미지 비교
- `이미지 1`, `이미지 2`, `이미지 3`은 OpenCV와 사용자 정의 구현을 통해 처리된 결과가 동일하다는 로그로 확인되었습니다.

### WARNING
- `image4.jpg`는 흑백 이미지가 아니었으므 WARNING을 발생시켰습니다.
