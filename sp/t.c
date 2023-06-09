#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main() {
    const char* username = "930727fre";
    struct passwd* user_info;

    user_info = getpwnam(username);
    if (user_info == NULL) {
        fprintf(stderr, "Failed to get user information for %s\n", username);
        exit(1);
    }

    printf("Username: %s\n", user_info->pw_name);
    printf("User ID: %d\n", user_info->pw_uid);
    printf("Group ID: %d\n", user_info->pw_gid);
    printf("Home directory: %s\n", user_info->pw_dir);
    printf("Shell: %s\n", user_info->pw_shell);

    return 0;
}
