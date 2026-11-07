#Bismillah hirahman nirahim

#Testing remote Git Repo Access From Pc to start plan
#May Allah swt aid us

cmake_minimum_required(VERSION 3.28)#gets atleast version 3.28 of cmake (needed for sfml 3)
project(Project LANGUAGES CXX)#This is Project name, it makes the .sln name This Project name we gave "Project"
#CXX means C++; we simply told it; that project uses languages C++ (only)

set(CMAKE_CXX_STANDARD 17)#Means C++17 to be used; (because Sfml 3 needs that)
#Note this is just a suggestion (not enforeced strictly by CMake)

set(BUILD_SHARED_LIBS OFF)#Build shared libs mean .dll files, OFF makes it so that we dont .dll files; so it builds them into the .exe (hence one file does the job, no need for shared files (.dll)s)
#SO we dont see the alot of dependacy .dlls needed by sfml and simply see a single .exe file

include(FetchContent)#This enables the fetching (downloading if external source, or simply using if already in computer (source can be differnt))

FetchContent_Declare(SFML# we declare that we are fetching SFML
GIT_REPOSITORY https://github.com/SFML/SFML.git #We download using git (which also allows to download from universty server not just github (considering that it uses git too and some other things consdiered)), we could also use a url to github:specific page like we do in fdm to download from there;
GIT_TAG 3.1.0 #Tells we want to get the sfml version 3.1.0
#If this version doesnt exsist configuration will fail
GIT_SHALLOW On)# This makes it so that we dont get theri old git hsitory

FetchContent_MakeAvailable(SFML) #This line actually fetches based on our fetch declraation when run (as command of cmake is run)\

add_executable(Program main.cpp)#Program is the name of the exe file to build; 
#self as no src folder so deleted /src from main's path
#Each Program is an exe file, a project can have multiple exe files
#Program provides a target to include source files in
#It also serves as a target to link libraries to
target_link_libraries(Program PRIVATE SFML::Graphics)
#sfml graphics is a sub library in sfml that handles windows and display
#This links this library to our target "Program" (which serves as an exe because linker literally copy pastes all library code inside (so work as code together to be exe)



#Issue came, cmake didnt have access to the git; added a 