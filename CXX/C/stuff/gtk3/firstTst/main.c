#include <gtk/gtk.h>

static void print_hello(GtkApplication *app, gpointer user_data);
static void activate(GtkApplication *app, gpointer user_data);

int main(int argc, char **argv){
  GtkApplication *app;
  int status;

  app = gtk_application_new("com.mentalabs.firstTst", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}

static void print_hello(GtkApplication *app, gpointer user_data){
  GtkWidget *window;
  GtkWidget *label;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "The Truth");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 30);

  label = gtk_label_new("ur mom asphalt");
  gtk_container_add(GTK_CONTAINER(window), label);
  
  gtk_widget_show_all(window);
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "162Test");
  gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);

  button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add(GTK_CONTAINER(window), button_box);

  button = gtk_button_new_with_label("The truth");
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

  gtk_container_add(GTK_CONTAINER(button_box), button);
  
  gtk_widget_show_all(window);
}
