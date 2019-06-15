#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>


void main_loop(ALLEGRO_DISPLAY* disp, ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_FONT* font);

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
  ALLEGRO_DISPLAY* disp = al_create_display(640, 480);
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
  al_register_event_source(queue, al_get_keyboard_event_source());        //register keyboard event source, used for kb input
  al_register_event_source(queue, al_get_display_event_source(disp));     //register display event source, used for buttons and stuff I guess
  al_register_event_source(queue, al_get_timer_event_source(timer));      //register timer event source, used for timing (duh)
  //main loop in separate function
  main_loop(disp, timer, queue, font);
  //get rid of everything
  al_destroy_font(font);
  al_destroy_display(disp);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);
  return 0;
}

void main_loop(ALLEGRO_DISPLAY* disp, ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_FONT* font){
  bool redraw = true;
  ALLEGRO_EVENT event;

  al_start_timer(timer);
  while (1) {
    al_wait_for_event(queue, &event);
    if (event.type == ALLEGRO_EVENT_TIMER) redraw = true;
    else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
  }
}
