// C++ SFML Example 001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "tools.hpp"

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>

int main() {
    std::cout << "Program started." << std::endl;

#ifdef _DEBUG
    std::cout << "Debug build" << std::endl;
#else
    std::cout << "Release build" << std::endl;
#endif

#ifdef NDEBUG
    std::cout << "NDEBUG defined" << std::endl;
#else
    std::cout << "NDEBUG not defined" << std::endl;
#endif

    appendToLogFile("Log.txt", getCurrentDateTime());

    // Load font
    sf::Font font;
    if (!font.loadFromFile("fonts/Inconsolata-Regular.ttf")) {
        // Error handling: Failed to load font
        pauseWithOptionalTimeout();
        return 1;
    }

#ifdef _DEBUG
    // Create a window with dimensions 640x480
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Hello World");
#else
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Fullscreen Window", sf::Style::Fullscreen);
#endif

    // Run the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window.close();
            }
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw a message to the window
        sf::Text text("\tHello, SFML!\nPress ENTER or ESC to continue...", font, 48);
        window.draw(text);

        // Display the window
        window.display();
    }

    // Wait for user input without timeout
    //pauseWithOptionalTimeout();

    std::cout << "Have a nice day!" << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

/*
How do I setup the SFML library in Visual Studio?

Sure! Here are the general steps to set up SFML library in Visual Studio:

Step 1: Download and install SFML library

Go to the official SFML website (https://www.sfml-dev.org/) and download the latest stable version of SFML for your operating system (Windows, macOS, or Linux).
Follow the installation instructions provided by SFML to install the library on your system.
Step 2: Create a new Visual Studio project

Open Visual Studio and create a new C++ project by going to File -> New -> Project.
Choose the appropriate project template, such as "Console App" or "Empty Project", and click Next.
Choose a location and name for your project, and click Create.
Step 3: Add SFML include paths

In your Visual Studio project, right-click on the project name in the Solution Explorer, and go to Properties.
In the Property Pages window, go to Configuration Properties -> C/C++ -> General.
In the Additional Include Directories field, add the path to the SFML include folder. This is typically the "include" folder in the SFML installation directory.
Step 4: Add SFML library paths

In the Property Pages window, go to Configuration Properties -> Linker -> General.
In the Additional Library Directories field, add the path to the SFML library folder. This is typically the "lib" folder in the SFML installation directory.
Step 5: Link SFML libraries

In the Property Pages window, go to Configuration Properties -> Linker -> Input.
In the Additional Dependencies field, add the names of the SFML libraries that you want to link. For example, if you're using SFML's Graphics, Window, and System modules, you would add "sfml-graphics.lib", "sfml-window.lib", and "sfml-system.lib" respectively.
Step 6: Copy SFML DLLs

Copy the SFML DLLs (dynamic link libraries) from the SFML installation directory to your Visual Studio project's output directory (where your compiled executable will be placed). The DLLs are typically located in the "bin" folder in the SFML installation directory, and you need to copy the DLLs corresponding to the SFML modules you're using (e.g., sfml-graphics.dll, sfml-window.dll, sfml-system.dll).
Step 7: Write SFML code

Now you can start writing your SFML code in your Visual Studio project. You can include SFML headers in your code and use the SFML functions and classes as needed.
Step 8: Build and run your SFML project

Build your Visual Studio project to compile your SFML code into an executable.
Run the compiled executable, and you should see your SFML application running with the SFML functionalities you've used in your code.
That's it! You have successfully set up SFML library in Visual Studio and can start using it to develop your C++ games or applications with graphics, audio, and input capabilities.
*/