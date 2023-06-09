#ifndef WRITER_EXCLUDE
#define WRITER_EXCLUDE

void* writer();
/*
 * Funkcja reprezentująca wątek pisarza.
 * 
 * Wątek pisarza próbuje uzyskać dostęp do czytelni, redukując liczbę pisarzy oczekujących na wejście
 * i zwiększając liczbę pisarzy w czytelni. Następnie odczekuje określony czas pisania,
 * po czym opuszcza czytelnię, redukując liczbę pisarzy w czytelni.
 * Jeśli są jeszcze inni pisarze oczekujący, sygnalizuje dostęp kolejnemu pisarzowi.
 * W przeciwnym razie sygnalizuje czytelnikom możliwość dostępu. 
 * Po odczekaniu czasu odpoczynku, zwiększa liczbę pisarzy w oczekujących na wejście i kontynuuje działanie w pętli.
 */

#endif
