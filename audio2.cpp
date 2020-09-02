#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>       // std::std::cout
#include <thread>         // std::thread
#include <unistd.h>
#include <mutex>          // std::mutex
#include <cstdio>
std::mutex mtx; //mutex for critical section

int		    play_audio() {
    if (!al_init()) {
	return 1;
    }
    if (!al_install_audio()) {
	return 2;
    }
    if (!al_init_acodec_addon()) {
	return 3;
    }
    if (!al_reserve_samples(1)) {
	return 4;
    }
    ALLEGRO_SAMPLE *idle_sound = al_load_sample("leaving.wav");
    ALLEGRO_SAMPLE_INSTANCE *sample_instance = al_create_sample_instance(idle_sound);
    if (!idle_sound || !sample_instance) {
	printf("Setup error.\n");
	return 5;
    }
    ALLEGRO_SAMPLE_ID sample_id;

    mtx.lock();
    if (!al_play_sample(idle_sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &sample_id)) {
	printf("Failed to play sample.\n");
    }
    if (!al_play_sample_instance(sample_instance)) {
	printf("Failed to play sample instance.\n");
    }
    al_rest(5.0);

    al_destroy_sample_instance(sample_instance);
    al_destroy_sample(idle_sound);
    std::cout << "Thread I have finished" << std::endl;
    mtx.unlock();
    return 1;
    }


    int		    main   (int argc, char **argv){
	int		n = 1;

	printf("creating thread\n ");
	std::thread t_audio(play_audio);
	sleep(1);
	while (!mtx.try_lock()) {
		// Still can not lock this mutex
		    printf("N is %d\n", n);
		    n += 1;
		    sleep(1);
	}
	// Ha ha ... we locked it - the other code must be done
	t_audio.join();
	mtx.unlock();
	printf("Main closing\n");
	printf("All done... Closing\n");
	return (0);
    }
