SRC_DIR := Ray
SRC_FILES := Engine.cpp main.cpp Material.cpp Plane.cpp PlanePrim.cpp \
    Primitive.cpp Ray.cpp Scene.cpp Sphere.cpp Surface.cpp Vector3.cpp

CFLAGS += -O2 -Wall -Wextra -std=c++11 -I$(SRC_DIR) -DLINUX
LIBS += -lm -lsfml-window -lsfml-graphics -lsfml-system

SRCS := $(addprefix $(SRC_DIR)/,$(SRC_FILES))
all:
	g++ $(CFLAGS) $(SRCS) -o /tmp/ray $(LIBS)
