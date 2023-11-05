# cserver-EmreKolbakir 🌌

A powerful C++ web server with a modern, dynamic, and interactive UI. Showcase your personal social media profiles, projects, or any other content with a unique and engaging touch.

## Features 🌠
- Backend driven by a C++ web server.
- Dynamic starry night background animation.
- Links to social media platforms.
- Dedicated contact section.

## Introduction 📌
This project offers a unique blend of high-performance C++ backend with a visually appealing frontend. It's designed to not only serve web content efficiently but also provide an interactive and immersive experience for the users.

## Description 📜
Built around a core C++ web server, this project delivers a responsive web template with a canvas-based starry background. The background utilizes both static and moving stars to simulate a peaceful nighttime scene. Additionally, users can find dedicated sections for social media links and contact details. The design ensures seamless adaptability across both desktop and mobile devices.

## 📋 User Manual

### Prerequisites
---
#### C++ Compiler
**Ensure you have a modern C++ compiler that supports the C++11 standard (e.g., `g++`).**

#### ASIO Library
**This project uses the standalone version of ASIO, which does not require Boost. Install it via package managers like `apt` on Ubuntu:**

    sudo apt install libasio-dev

## 🛠️ Compilation

**Navigate to the root directory of the project. Compile the server using the following command:**

    g++ -std=c++11 -pthread src/server.cpp -o bin/server -l pthread

**Include the ASIO headers if they are in a non-standard directory:**

    g++ -std=c++11 -pthread -I/path/to/asio/include src/server.cpp -o bin/server -l pthread

## 🏃‍♂️ Running the Server

**Run the compiled server binary:**

    ./bin/server

**The server starts on port 8080 by default. Visit http://[your private IP]:8080 in your browser to access it.**

## 📱💻 Accessing from Other Devices

**On the same local network, access the server by entering http://<Server's Local IP Address>:8080 in a browser. Find the server's IP address using `ifconfig` (Linux/Mac) or `ipconfig` (Windows).**

## 🛑 Stopping the Server

**Stop the server with Ctrl+C in the terminal where it's running.**

## Usage 🚀

### For Visitors 🌐
Just navigate to the provided URL and enjoy the dynamic and interactive space. Feel free to click on the available links to explore more!

### For Developers 💡

1. **Clone the Repository**

   git clone https://github.com/[YourUsername]/cserver-EmreKolbakir.git

2. **Navigate to the Repository Directory**

   cd cserver-EmreKolbakir

3. **Modify the Placeholders**  
Open `index.html` and replace placeholders with your desired content. Update:
- Social media links.
- Contact details.

4. **Set Up the C++ Web Server**  
Follow the user manual above to get the server up and running.

5. **Host Your Website**  
Use platforms like GitHub Pages, Netlify, or Vercel for hosting the frontend. Make sure your C++ server is operational and reachable where your frontend is hosted.

## Customization ✨
Developers can tweak the appearance and behavior of the site to fit their preferences.
- Modify the `styles.css` file to change color schemes, fonts, and more.
- Adjust star behavior and count in the `script.js` file.

## Dependencies 📦
- A modern C++ compiler (e.g., g++ supporting C++11).
- ASIO library for standalone asynchronous networking.
- Modern web browsers (Chrome, Firefox, Safari, or Edge) for the best viewing experience.

## Safety Concerns 🔒
Running a C++ web server involves important safety considerations. Handle user data with care, protect against common vulnerabilities such as buffer overflows and memory leaks, and use SSL/TLS for secure data transmission. Implement rate limiting, validate and sanitize user input, regularly update dependencies, and monitor server activities. For detailed safety measures, refer to the safety section above.




