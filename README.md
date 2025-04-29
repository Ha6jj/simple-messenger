# Simple client-server messenger
----
- Asynchronous server
- You can create chats and use simple utils to moderate them
- Easy to change platform, because it was written on boost/asio

## 🛠 Build and Launch
![C++](https://img.shields.io/badge/C++-17-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.12+-green.svg)
----
In CMake file write find_packages or path to your boost lib

Set port that your server will listen __before compilation__ (now 54001)
 ```bash
git clone https://github.com/Ha6jj/Simple-Messenger.git
cd Simple-Messenger

mkdir build
cd build

cmake ..
make run
```

## 💫 Usage
- Connect to your server
```bash
nc <server_adress> <port>
```
- Enjoy using commands:
```bash
cmd [ [ [ join | leave | create | delete ] <chat> ] | auth <nickname> ]
msg <chat> <message ..>
```
| Message type | Command  | Argument    |
|--------------|----------|-------------|
| **cmd**      | join     | `<chat>`    |
|              | leave    | `<chat>`    |
|              | create   | `<chat>`    |
|              | delete   | `<chat>`    |
|              | auth     | `<nickname>`|
| **msg**      | `<chat>` | `<message>` |

- Restrictions: chat names can't contain spaces, firstly you need to pass authorization by entering nickname
