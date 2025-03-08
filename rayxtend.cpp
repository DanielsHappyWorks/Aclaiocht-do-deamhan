#include "rayxtend.h"

void DrawTextureFromCentre(Texture2D texture, Vector2 pos, float scale, float rotation, Color color) {
    Vector2 centre_point = {(float)texture.width * scale / 2, (float)texture.height * scale / 2};
    DrawTextureFromPoint(texture, pos, centre_point, scale, rotation, color);
}

void DrawTextureFromPoint(Texture2D texture, Vector2 pos, Vector2 pivotPoint, float scale, float rotation, Color color) {
    Rectangle texture_rect = {0, 0, (float)texture.width, (float)texture.height};
    Rectangle dest_rect = {pos.x, pos.y, (float)texture.width * scale, (float)texture.height * scale};
    DrawTexturePro(texture, texture_rect, dest_rect, pivotPoint, rotation, color);
}

Rectangle TextureRectFromCentre(Texture2D texture, Vector2 pos, float scale) {
    Vector2 centre_point = {(float)texture.width * scale / 2, (float)texture.height * scale / 2};
    return TextureRectFromPoint(texture, pos, centre_point, scale);
}

Rectangle TextureRectFromPoint(Texture2D texture, Vector2 pos, Vector2 pivotPoint, float scale) {
    Rectangle dest_rect = {pos.x, pos.y, (float)texture.width * scale, (float)texture.height * scale};
    float x = dest_rect.x - pivotPoint.x;
    float y = dest_rect.y - pivotPoint.y;
    return {x, y, dest_rect.width, dest_rect.height};
}