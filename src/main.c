#include "main.gen.h"

/*EXPORT
#define BUFFER_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>


#include "type/unsigned_type.gen.h"
#include "type/multibyte_char_type.gen.h"
#include "type/mutable_string_type.gen.h"
#include "type/lines_type.gen.h"
#include "type/cursor_type.gen.h"
#include "type/context_type.gen.h"
*/

#include "render/render.gen.h"
#include "keyboard/keyboard.gen.h"
#include "command/command.gen.h"

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("[error]illegal args\n");
    return (EXIT_FAILURE);
  } else {
    context context;
    context_read_file(&context, argv[1]);
    context.cursor.position_x = 1;
    context.cursor.position_y = 1;
    context.render_start_height = 0;
    multibyte_char key = multibyte_char_malloc();
    command cmd_none;
    cmd_none.command_key = NONE;
    command_perform(cmd_none, &context);
    while (1) {
      render_setting(&context);
      render(context);
      keyboard_scan(&key);
      command cmd = command_parse(key);
      command_perform(cmd, &context);
    }
    multibyte_char_free(key);
    return EXIT_SUCCESS;
  }
}
