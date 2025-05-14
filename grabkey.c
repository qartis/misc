#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>

/* Andrew Fuller <abf@google.com>

   Globally capture an X11 key:
   $ cc grabkey.c -lX11 -o grabkey
   $ ./grabkey 15 KP_Page_Down
   $ echo $?
*/

#define TIMEOUT 5
#define KEY "Escape"

int main(int argc, char **argv)
{
    Display *dpy = XOpenDisplay(0);
    Window root = DefaultRootWindow(dpy);
    int keysym = XStringToKeysym(KEY);
    int keycode;
    int timeout = TIMEOUT;
    XEvent ev;

    if (argc > 1)
      timeout = atoi(argv[1]);

    if (argc > 2)
      keysym = XStringToKeysym(argv[2]);

    keycode = XKeysymToKeycode(dpy, keysym);

    alarm(timeout);
    XGrabKey(dpy, keycode, AnyModifier, root, False, GrabModeAsync,
             GrabModeAsync);
    XSelectInput(dpy, root, KeyPressMask);

    for (;;) {
      XNextEvent(dpy, &ev);
      if (ev.type == KeyPress)
        break;
    }

    XCloseDisplay(dpy);
    return 0;
}
