#include "../main.gen.h"
#include "command.gen.h"

// void vailidate_cursor_position(context *context)
// {
// TODO
// }


void command_perform(command command, context *context)//PUBLIC;
{
  switch(command.command_key)
  {
    case UP:
      (*context).cursor.position_y -= 1;
      break;
    case DOWN:
      (*context).cursor.position_y += 1;
      break;
    case RIGHT:
      (*context).cursor.position_x -= 1;
      break;
    case LEFT:
      (*context).cursor.position_x += 1;
      break;
    case EXIT:
      exit(EXIT_SUCCESS);
      break;
    case NONE:
      break;
  }
}