#include "three.h"

extern "C" {
    u32 __stacksize__ = 0x400000;
}

void remove_dir(char *path)
{
    struct dirent *entry = NULL;
    DIR *dir = NULL;
    dir = opendir(path);
    while((entry = readdir(dir)))
    {
        DIR *sub_dir = NULL;
        FILE *file = NULL;
        char abs_path[100] = {0};
        if(*(entry->d_name) != '.')
        {
            if((sub_dir = opendir(abs_path)))
            {
                closedir(sub_dir);
                remove_dir(abs_path);
            }
            else
            {
                if((file = fopen(abs_path, "r")))
                {
                    fclose(file);
                    remove(abs_path);
                }
            }
        }
    }
    rmdir(path);
}

int main()
{
    App *app = App::getInstance();
    //FILE *file = fopen("foobar.txt", "w+");
    remove_dir("test");
    app->startController(new DefaultController());
    app->run(); // This will run the main loop
	return 0;
}
