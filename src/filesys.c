#include "filesys.h"

#include <string.h>

seta_file_t *seta_file_new(const char *name, const char *deploy_folder)
{
    seta_file_t *sf = malloc(sizeof(seta_file_t));
    sf->name = name;
    sf->deploy_folder = deploy_folder;
    return sf;
}

int seta_file_clone(seta_file_t *sf)
{
    char file_path[1024];

    if (sf->deploy_folder[strlen(sf->deploy_folder) - 1] != '/') {
        snprintf(
            file_path,
            sizeof(file_path),
            "%s/%s",
            sf->deploy_folder,
            sf->name
        );
    } else {
        snprintf(
            file_path,
            sizeof(file_path),
            "%s%s",
            sf->deploy_folder,
            sf->name
        );
    }

    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        perror("Failed to create SETA file");
        return -1;
    }

    fclose(file);
    return 0;
}

void seta_file_done(seta_file_t *sf)
{
    free(sf);
}
