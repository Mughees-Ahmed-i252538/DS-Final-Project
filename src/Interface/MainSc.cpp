// Bismillah hirahman nirahim

// This file will contain the logic of the main screen

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int MainSc(sf::RenderWindow &window) // returns outputs for debugging or forwarding (tentative exact puroose but kept this way for flexibilluty may not be used in current version)
{
    sf::Texture MainSc_Bg_Texture;

    if (!MainSc_Bg_Texture.loadFromFile("../src/Assets/images/MainSc_Bg.jpg")) // starts from build folder
    {
        cout << "Failed to Load MainSc_Bg_Texture" << endl;
    } // issue: file suggestion offerned by intellesnece are relative to this file, but actual checks are relative to build folder.. it was mossing the src in file path
    // Unlikd this the #include is reolved at compile time so it uses location of including file as starter

    sf::Sprite MainSc_Bg_Sprite(MainSc_Bg_Texture); // No default cosntructor exsist hence must give texture at start

    while (window.isOpen()) // had done if instead of while, windows only opened for a brief moment
    {
        while (std::optional event = window.pollEvent()) // This is the sfml 3 syntax, the 2 syntax was make an sf::Event event and do while(window.pollevent(event)), which is no longer usable as eents can no longer be empty (they did it to upgrade from c to c++ usage , it puts safety checks...)
        {                                                // And yes we can and are initializing a variable inside the paranthesis of while, i think if no event is present it returns std::nullopt the std::optional converts to false, (it converts to true if it holds a value), when it becomes false we get out of poll loop...
            if (event->is<sf::Event::Closed>())
            {
                return 0;
            } // Exit is working ALhamdulilah
        }
        window.draw(MainSc_Bg_Sprite);
        window.display();
    }

    return 0; // Just a placeholder to remove the warning that comes, curretn logic doenst reach it and pretriggers
}

// Note the std::option contains the sf::Event datatype
// It is like a box, either expty or full
// It takes in the evenet datatype because the window.poll returns event
// If the widnows.poll returns std::nullopt
// The box knows that it has to be empty, although its type is std::optiona<sf::Event>
// the nullopt can be returned even though return type is sf::Event because it fucnitons like a nullptr, which can be returned for int*, float* etc  ptr
// When the std;:optional sees this nullopt,
// Atlthough its type remains std::optional<sf::Event>
// a bool inside optional is made = false that tells it is empty and the event object inside isnt initialized
// We can adccess the is object isnide it using the -> (because it has been overloaded)
// The ->
// As the event itself is the std::optional
// the . operator access its own fucnitons etc
// They overaloaded he -> operator to let us access the fucnitosn of the sf::event isnide it
// Then the is() is a fucnito with a template inside it
// It lets us send the datatypes themseles and uses a clever indexinf mechanism in the events to check if the the event type id is same as the id assigned to the class / type of event we have sent
