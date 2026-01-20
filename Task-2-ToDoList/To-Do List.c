#include <stdio.h>
#include <string.h>

#define MAX 100
#define SIZE 200

struct Task {
    char description[SIZE];
    int completed;
};

void addTask(struct Task tasks[], int *count) {
    getchar();
    printf("Enter task description: ");
    fgets(tasks[*count].description, SIZE, stdin);
    tasks[*count].description[strcspn(tasks[*count].description, "\n")] = 0;
    tasks[*count].completed = 0;
    (*count)++;
    printf("Task added successfully!\n");
}

void viewTasks(struct Task tasks[], int count) {
    if (count == 0) {
        printf("No tasks available!\n");
        return;
    }
    printf("\n--- To-Do List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. [%s] %s\n", i + 1, tasks[i].completed ? "Done" : "Pending", tasks[i].description);
    }
}

void completeTask(struct Task tasks[], int count) {
    int num;
    printf("Enter task number to mark as complete: ");
    scanf("%d", &num);

    if (num < 1 || num > count) {
        printf("Invalid task number!\n");
        return;
    }
    tasks[num - 1].completed = 1;
    printf("Task marked as completed!\n");
}

void deleteTask(struct Task tasks[], int *count) {
    int num;
    printf("Enter task number to delete: ");
    scanf("%d", &num);

    if (num < 1 || num > *count) {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = num - 1; i < (*count) - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    (*count)--;
    printf("Task deleted successfully!\n");
}

int main() {
    struct Task tasks[MAX];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- TO-DO LIST MENU ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(tasks, &count); break;
            case 2: viewTasks(tasks, count); break;
            case 3: completeTask(tasks, count); break;
            case 4: deleteTask(tasks, &count); break;
            case 5: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
