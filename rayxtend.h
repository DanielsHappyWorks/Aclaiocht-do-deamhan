#include "raylib.h"

#ifndef RAYXTEND_H
#define RAYXTEND_H

void DrawTextureFromPoint(Texture2D texture, Vector2 pos, Vector2 pivotPoint, float scale, float rotation, Color color);
void DrawTextureFromCentre(Texture2D texture, Vector2 pos, float scale, float rotation, Color color);

Rectangle TextureRectFromCentre(Texture2D texture, Vector2 pos, float scale);
Rectangle TextureRectFromPoint(Texture2D texture, Vector2 pos, Vector2 pivotPoint, float scale);

#endif /* RAYXTEND_H */