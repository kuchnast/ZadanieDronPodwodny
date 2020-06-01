CXX      := g++
CXXFLAGS := -Wall -pedantic -std=c++14
LDFLAGS  := -L/usr/lib -lstdc++ -lm -lpthread
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := dron
INCLUDE  := -Iinc/ -Iinc/Gnuplot/ -Iinc/Interfejsy -Iinc/Obiekty3D -Iinc/Przeszkody -Iinc/Powierzchnie -Iinc/SkladoweObiektow -Iinc/Zbiornik
SRC      := $(wildcard src/Gnuplot/*.cpp)				\
			$(wildcard src/SkladoweObiektow/*.cpp) 		\
			$(wildcard src/Obiekty3D/*.cpp) 			\
			$(wildcard src/Przeszkody/*.cpp) 			\
			$(wildcard src/Zbiornik/*.cpp) 				\
			$(wildcard src/Powierzchnie/*.cpp) 			\
			$(wildcard src/Interfejsy/*.cpp) 			\
			$(wildcard src/*.cpp) 		  				\

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)
	@ln -svf $(APP_DIR)/$(TARGET) $(TARGET)

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*
	-@rm -vf $(TARGET)