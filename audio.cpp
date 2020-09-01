/*
 * This program uses the Allegro game library to display a blank window.
 *
 * It initializes the display and starts up the main game loop. The
 * game loop only checks for two events: timer (determined by the FPS)
 * and display close (when the user tries to close the window).
 *
 * http://www.damienradtke.org/building-a-mario-clone-with-allegro
 */

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

const float FPS = 60.0f;

int main(int argc, char** argv) {
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_TIMER *timer = NULL;

  bool running = true;
  bool redraw = true;

  // Initialize allegro
  if (!al_init()) {
    fprintf(stderr, "Failed to initialize allegro.\n");
    return 1;
  }

  // Initialize the timer
  timer = al_create_timer(1.0f / FPS);
  if (!timer) {
    fprintf(stderr, "Failed to create timer.\n");
    return 1;
  }

  // Create the display
  /*
  display = al_create_display(640, 480);
  if (!display) {
    fprintf(stderr, "Failed to create display.\n");
    return 1;
  }
*/

  // Create the event queue
  event_queue = al_create_event_queue();
  if (!event_queue) {
    fprintf(stderr, "Failed to create event queue.");
    return 1;
  }

  // Register event sources
//al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));


//Loading sound file from datafile
ALLEGRO_SAMPLE *laserShot=NULL;
laserShot = al_load_sample( "arriving.wav" );

//Error checking
if (laserShot == NULL) {
    printf("Error loading arriving.wav\n");
}
else {
    //Playing sound for shot
    al_play_sample( laserShot);
}


  // Clean up
  al_destroy_event_queue(event_queue);

  return 0;
}
