#include "Camera.hh"
#include "Engine.hh"
#include <string>
#include <chrono>

#define WIDTH 200
#define HEIGHT 200

int main(){
    //start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    Camera camera(Point3(-2,-2,0.1), Point3(0,0,0.1), Vector3(0,0,1)
                  ,70,70);
    Scene scene(camera);
    Engine engine(scene, WIDTH, HEIGHT, 1);
    float power  = 1;
    float step = 0.05;
    sf::Image* sfml_image = new sf::Image;
    sfml_image->create(WIDTH, HEIGHT);

    // create an SFML texture and set its image
    sf::Texture texture;

    // create an SFML sprite and set its texture
    sf::Sprite sprite;

    // create an SFML render window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Display window");

    // main display loop: display the image and handle events
    while (window.isOpen()) {
        // display the image on screen
        window.clear();
        engine.generateImage(sfml_image, power);
        texture.loadFromImage(*sfml_image);
        sprite.setTexture(texture);
        window.draw(sprite);
        window.display();

        // process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        power+=step;
    }


    //get elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed time: " << duration.count() << " ms\n";

    return 0;
}
