#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#define MAIN_SLEEP 2
#define THREAD_SLEEP 1
#define AUDIO_FILE  "/Users/tim/Dev/gpredict-2.2.1/allegro_test/arriving.wav"


/*
 * How to play an wav file from C code.
 *
 * This is using a thread to play the sound - so that the main-code, can 
 * perform something useful - err like counting a number....
 *
 *  
 *
 */

pthread_mutex_t mtx= PTHREAD_MUTEX_INITIALIZER;



int   play_audio(void)
{
    pthread_mutex_lock( &mtx );
    printf(  "al_init\n" );
    sleep(THREAD_SLEEP);
    if (!al_init()) {
    pthread_mutex_unlock(&mtx);
        return 1;
    }
    printf(  "install_audio\n" );
    if (!al_install_audio()) {
    pthread_mutex_unlock(&mtx);
        return 2;
    }
    sleep(THREAD_SLEEP);
    printf(  "ac_codec\n" );
    if (!al_init_acodec_addon()) {
    pthread_mutex_unlock(&mtx);
        return 3;
    }
    sleep(THREAD_SLEEP);
    printf(  "reserve_samples\n" );
    if (!al_reserve_samples(1)) {
    pthread_mutex_unlock(&mtx);
        return 4;
    }
    sleep(THREAD_SLEEP);
    ALLEGRO_SAMPLE *idle_sound = al_load_sample(AUDIO_FILE);
    ALLEGRO_SAMPLE_INSTANCE *sample_instance = al_create_sample_instance(idle_sound);
     if (!idle_sound || !sample_instance) {
        printf("Setup error.\n");
    pthread_mutex_unlock(&mtx);
        return 5;
    }
    ALLEGRO_SAMPLE_ID sample_id;

    if (!al_play_sample(idle_sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &sample_id)) {
        printf("Failed to play sample.\n");
    }
    if (!al_play_sample_instance(sample_instance)) {
        printf("Failed to play sample instance.\n");
    }
    al_rest(5.0);

    al_destroy_sample_instance(sample_instance);
    al_destroy_sample(idle_sound);
    printf(  "Thread I have finished" );
    pthread_mutex_unlock(&mtx);
    return 1;
}


void *print_message_function( void *ptr );

main()
{
     pthread_t thread2;
     int  iret2;
     int counter=0;

    /* Create independent threads each of which will execute function */

     iret2 = pthread_create( &thread2, NULL, play_audio, NULL);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */
     sleep(MAIN_SLEEP);
     while (pthread_mutex_trylock(&mtx))
     {
	counter +=1;
	printf("Count is %d\n",counter);
	sleep(MAIN_SLEEP);
     }
     printf("in Main got lock\n");
     pthread_join( thread2, NULL); 
     printf("Thread 2 returns: %d\n",iret2);
     exit(0);
}

void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}
