typedef struct
{
    float x, y, z;
    float speed;
    VERTEX vector;
} STAR;

#define MAXSTARS 0xFF

void DrawStarfield();
void UpdateStars();
void GenerateStars();