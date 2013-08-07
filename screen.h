#ifndef SCREEN_H
#define SCREEN_H

class Screen {
public:
    Screen() = default;
    virtual int run() = 0;
    virtual ~Screen() = default;
};

#endif
