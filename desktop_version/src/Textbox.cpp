#include "Textbox.h"

textboxclass::textboxclass()
{
    firstcreate();
}

void textboxclass::firstcreate()
{
    //Like clear, only it creates the actual arrays, etc
    for (int iter = 0; iter < 10; iter++)
    {
        std::string t;
        t = "";
        line.push_back(t);
    }
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    numlines = 0;
    lw = 0;
    tl = 0;
    tm = 0;
    active = false;
    timer = 0;
}

void textboxclass::clear()
{
    //Set all values to a default, required for creating a new entity
    for (size_t iter = 0; iter < line.size(); iter++)
    {
        line[iter]="";
    }
    xp = 0;
    yp = 0;
    w = 0;
    h = 0;
    numlines = 1;
    lw = 0;
    tl = 0;
    tm = 0;
    active = true;
    timer = 0;
}

void textboxclass::centerx()
{
    resize();
    xp = 160 - (w / 2);
    resize();
}
void textboxclass::centery()
{
    resize();
    yp = 120 - (h / 2);
    resize();
}

void textboxclass::adjust()
{
    resize();
    if (xp < 10) xp = 10;
    if (yp < 10) yp = 10;
    if (xp + w > 310) xp = 310 - w;
    if (yp + h > 230) yp = 230 - h;
    resize();
}

void textboxclass::initcol(int rr, int gg, int bb)
{
    tr = rr;
    tg = gg;
    tb = bb;
    r = 0;
    g = 0;
    b = 0;
    tl = 0.5;
}

void textboxclass::setcol(int rr, int gg, int bb)
{
    r = rr;
    g = gg;
    b = bb;
}

void textboxclass::fixedupdate() {
	// fade in
	if (tm == 0) {
		tl += .1f;
		if (tl >= 1) {
			tl = 1;
			tm = 1;
		}
		setcol(int(tr * tl), int(tg * tl), int(tb * tl));
	}
	// fade out
	else if (tm == 2) {
		tl -= .1f;
		if (tl <= 0.5) {
			tl = 0.5;
			active = false;
		}
		setcol(int(tr * tl), int(tg * tl), int(tb * tl));
	}
	// if timer reaches 0 then fade out
	if (timer > 0) {
		timer--;
		if (timer == 0) tm = 2;
	}
}

void textboxclass::remove()
{
    tm = 2;
    tl = 1.0f; //Remove mode
}

void textboxclass::removefast()
{
    tm = 2;
    tl = 0.4f; //Remove mode
}

void textboxclass::resize()
{
    //Set the width and height to the correct sizes
    max = 0;
    for (int iter = 0; iter < numlines; iter++)
    {
        if (line[iter].length() > (unsigned int)max) max = line[iter].length();
    }

    lw = max;
    w = (max +2) * 8;
    h = (numlines + 2) * 8;
    textrect.x = xp;
    textrect.y = yp;
    textrect.w = w;
    textrect.h = h;
}

void textboxclass::addline(std::string t)
{
    line[numlines] = t;
    numlines++;
    resize();
    if (numlines >= 12) numlines = 0;
}
