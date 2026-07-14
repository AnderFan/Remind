# Remind

`remind` is a lightweight CLI utility for Linux that schedules desktop notifications using `systemd-run` and `notify-send`.

## Requirements

* **systemd** (default on Arch Linux)
* **libnotify** (provides `notify-send`)
* **g++** (only if building from source)

---

## Installation

### Option A: Use Pre-compiled Binary

1. Download the `remind` binary from the [Releases](https://github.com/AnderFan/Remind/releases) page.
2. Make it executable and move it to your `$PATH`:
   ```bash
   chmod +x remind
   sudo cp remind /usr/local/bin/
   ```

### Option B: Use Pre-compiled Binary
1. Clone the repository:
   ```bash
   git clone [https://github.com/AnderFan/Remind.git](https://github.com/AnderFan/Remind.git)
   cd Remind
   ```
2. Compile and install:
   ```bash
   g++ main.cpp -o remind -O3
   sudo cp remind /usr/local/bin/
   ```

## Usage
```bash
remind <date> <time> <title> [message]
```

### Examples
* ISO Format (YYYY-MM-DD):
    ``` bash
    remind 2026-07-14 12:00:00 "Lunch"
    ```

* RU Format (DD.MM.YYYY):
    ```bash
    remind 14.07.2026 13:23:00 "Ping" "pong"
    ```

* Short ISO Format:
    ```bash
    remind 07-14 09:42 "Daily sync"
    ```

* Short RU Format (DD.MM. - current year assumed):
    ```bash
    remind 14.07 12:00 "Ping" "Simple alert"
    ```
