//
// Created by Sigve Langva on 3/31/2022.
//

#ifndef PG4400_V22_KNR1033_DIRECTION_H
#define PG4400_V22_KNR1033_DIRECTION_H


class Direction {
public:
    Direction(int x, int y, int maxY);

    [[nodiscard]] int getX() const;

    void setX();

    [[nodiscard]] int getY() const;

    int getMaxY() const;
    void giveXval(int xV);
    void giveYval(int yV);
private:
    int x;
    int y;
    int maxY;

};


#endif //PG4400_V22_KNR1033_DIRECTION_H
