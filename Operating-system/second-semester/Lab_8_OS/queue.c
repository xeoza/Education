#include <linux/module.h> // module_init, ...
#include <linux/kernel.h> // printk
#include <linux/init.h> //__init, __exit
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/time.h>

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Author");

#define SHARED_IRQ 12
static int irq = SHARED_IRQ;
int my_dev_id = 0;
int irq_counter = 0;
module_param( irq, int, S_IRUGO );

struct workqueue_struct *wq;
void hardwork_function(struct work_struct *work);

DECLARE_WORK( hardwork, hardwork_function );

/* Bottom Half Function */
void hardwork_function(struct work_struct *work) {
    struct timespec time;
    getnstimeofday(&time);
    printk(KERN_INFO "[WorkQueue] time: %ld", time.tv_sec);
    return;
}

static irqreturn_t my_interrupt( int irq, void *dev_id ) {
   irq_counter++;
   printk( KERN_INFO "[INTERRUPT] Counter = %d\n", irq_counter );
   if(irq==define_irq)
   {
       queue_work( wq, &hardwork );
       return IRQ_HANDLED;// прерывание обработан
   }
   else
       return IRQ_NONE;// прерывание не обработано
}

static int __init my_wokqueue_init(void) {
	//irq – номер прерывания
    //*handler –указатель на обработчик прерывания
    //irqflags – флаги
    //devname – ASCII текст, представляющий устройство, связанное с прерыванием
    //dev_id – используется прежде всего для разделения (shared) линии прерывания.
    //IRQF_SHARED разрешает разделение irq несколькими устройствами
    if( request_irq( irq, my_interrupt, IRQF_SHARED, "my_interrupt", &my_dev_id ) ) 
    	return -1;
    printk( KERN_INFO "[INTERRUPT] Successfully loading ISR handler on IRQ %d\n", irq );
    // wq = create_workqueue( "my_queue" );
    //name - имя очереди, но в отличие от старых реализаций потоков с этим именем не создается
    //flags - флаги определяют как очередь работ будет выполняться
    //max_active - ограничивает число задач из данной очереди, которые могут одновременно выполняться на одном CPU.
    // WQ_UNBOUND - предназначен для ситуаций, когда задачи могут выполняться в течение длительного времени, причем так долго, что лучше разрешить планировщику управлять своим местоположением
    wq = alloc_workqueue("my_queue", WQ_UNBOUND, 0);
    if ( wq ) {
        printk(KERN_INFO "[MODULE] Workqueue created.\n");
    }

	printk(KERN_INFO "[MODULE] Module is now loaded.\n");
	return 0;
}

static void __exit my_wokqueue_exit(void) {
    flush_workqueue( wq );
    destroy_workqueue( wq );
	synchronize_irq( irq );
   	free_irq( irq, &my_dev_id );
   	printk( KERN_INFO "[INTERRUPT] Successfully unloading, irq_counter = %d\n", irq_counter );
	printk(KERN_INFO "[MODULE] Module is now unloaded.\n");
  	return;
}

module_init(my_wokqueue_init);
module_exit(my_wokqueue_exit);
