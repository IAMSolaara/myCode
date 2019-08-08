#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>

void main_loop(ALLEGRO_DISPLAY* disp, ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_FONT* font, ALLEGRO_SAMPLE* sample);

int main(){
  //allegro init
  if (!al_init()) {
    printf("can't initialize allegro.\n");
    return 1;
  }
  //keyboard init
  if (!al_install_keyboard()) {
    printf("cannot initialize keyboard.\n");
    return 1;
  }
  //mouse init
  if (!al_install_mouse()) {
    printf("cannot initialize mouse.\n");
    return 1;
  }
  //display init
  ALLEGRO_DISPLAY* disp = al_create_display(1280, 1024);
  if (!disp) {
    printf("cannot initialize display.\n");
    return 1;
  }
  //timer init
  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
  if (!timer) {
    printf("cannot initialize timer.\n");
    return 1;
  }
  //queue init
  ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
  if (!queue) {
    printf("cannot initialize queue.\n");
    return 1;
  }
  //font init
  ALLEGRO_FONT* font = al_create_builtin_font();
  if (!font) {
    printf("cannot initialize font.\n");
    return 1;
  }
  //image init
  if (!al_init_image_addon()) {
    printf("cannot initialize image addon.\n");
    return 1;
  }
  //audio and codec init
  if (!al_install_audio()) {
    printf("cannot initialize audio.\n");
    return 1;
  }
  if (!al_init_acodec_addon()){
    printf("cannot initialize codec addon.\n");
    return 1;
  }
  //sample reservation
  if (!al_reserve_samples(1)) {
    printf("cannot reserve sample memory.\n");
  }
  ALLEGRO_SAMPLE* sample = al_load_sample("moo.wav");
  if (!sample) {
    printf("cannot load sample.\n");
    return 1;
  }
  al_register_event_source(queue, al_get_keyboard_event_source());        //register keyboard event source, used for kb input
  al_register_event_source(queue, al_get_mouse_event_source());           //register mouse event source, used for kb input
  al_register_event_source(queue, al_get_display_event_source(disp));     //register display event source, used for buttons and stuff I guess
  al_register_event_source(queue, al_get_timer_event_source(timer));      //register timer event source, used for timing (duh)
  //main loop in separate function
  main_loop(disp, timer, queue, font, sample);
  //get rid of everything
  al_destroy_font(font);
  al_destroy_display(disp);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);
  return 0;
}

void main_loop(ALLEGRO_DISPLAY* disp, ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_FONT* font, ALLEGRO_SAMPLE* sample){
  bool redraw = true;
  bool done = false;
  ALLEGRO_EVENT event;
  ALLEGRO_BITMAP* image = al_load_bitmap("swoosh.png");

  char str[10000];
  int i = 0;
  
  al_start_timer(timer);
  while (1) {
    al_wait_for_event(queue, &event);
    switch(event.type) {
      case ALLEGRO_EVENT_TIMER:
        i++;
        redraw = true;
	break;
      case ALLEGRO_EVENT_DISPLAY_CLOSE:
	done = true;
	break;
    }

    if (redraw && al_is_event_queue_empty(queue)) {
      sprintf(str, "%d", i);
      al_clear_to_color(al_map_rgb(0,0,0));
      al_draw_bitmap(image,100,100,0);
      al_flip_display();

      redraw = false;
    }
    if (done) break;
  }
}
