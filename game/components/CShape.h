#ifndef C_SHAPE_H
#define C_SHAPE_H

enum class ShapeType
{
  RECTANGLE,
  CIRCLE
};

struct CShape
{
  int width;
  int height;
  ShapeType type;
};

#endif // C_SHAPE_H