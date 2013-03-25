#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#define NUM 10

void get_random_bytes(void *buf, int nbytes);


static int get_random_num(void)
{
    unsigned long randnum[NUM];
    int i = 0;
    
    printk(KERN_ALERT "To some real random num .\n");

    for(i=0 ; i < NUM; i++)
    {
        get_random_bytes(&randnum[i],sizeof(unsigned long));
        printk(KERN_ALERT "The Random number : %ld\n",randnum[i]);   
    }
    return 0;
}

static void random_exit(void)
{
    printk(KERN_ALERT "quit random generator");
}

module_init(get_random_num);
module_exit(random_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("huaixiaoz@gmail.com");
