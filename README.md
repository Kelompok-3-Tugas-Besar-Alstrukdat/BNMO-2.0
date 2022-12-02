# BNMO-2.0
## Deskripsi
BNMO (dibaca: Binomo) adalah sebuah robot video game console milik Indra dan Doni yang membantu mereka melepas stress ketika mendapatkan tugas selama di Institut Teknologi Bandung. BNMO dulunya memiliki sistem inventarisasi & toko game yang baik. Indra dan Doni menjalani kuliah dua semester di ITB dan merasa kesulitan, juga stress. Doni menghabiskan waktu dengan BNMO untuk bermain game. Namun, Indra lebih suka bersenang-senang bermain gacha, tetapi ia rugi terus. Namun, dua bulan yang lalu, Indra membanting BNMO sehingga BNMO pun rusak. Doni dan Indra merasa depresi saat mereka tahu BNMO rusak. Mereka pun segera berusaha memperbaiki BNMO. Akan tetapi, setelah diperbaiki, BNMO justru mendapatkan lebih banyak bug dalam sistemnya. Oleh karena itu, Doni dan Indra pun meminta bantuan kami sebagai programmer handal untuk memperbaiki dan ulang memprogram robot video game console kesayangan mereka, yaitu BNMO karena mereka tidak cukup ahli dalam coding. Kelompok kami pun segera memperbaiki BNMO yang terdiri dari beberapa fungsi ini dengan menggunakan bahasa pemrograman C. Program ini tidak hanya ditujukan untuk Doni ataupun Indra, tetapi siapapun yang ingin mengakses robot game ini dapat menggunakannya, asal sesuai dengan ketentuan yang telah ditetapkan. Semoga dengan program yang telah kami buat ini Doni dan Indra dapat lebih mudah dalam mengakses seluruh item di dalam robot gamenya dengan menggunakan komputer. BNMO diprogram menggunakan Bahasa C dan merupakan permainan yang berbasis CLI (Command Line Interface). Program permainan BNMO ini memanfaatkan berbagai struktur data terkait list, array, mesin karakter, mesin kata, queue, stack, set, map, dan linked list yang dibuat demi memenuhi kebutuhan program dalam permainan. Alur permainan BNMO dimulai dari pengguna yang dapat login ke dalam robot game dan melakukan berbagai aksi seperti menambah game, menghapus game, menambah game ke antrian, dll. Pada BNMO 2.0 ini, tiga game tambahan yang dibuat yaitu Hangman, Tower of Hanoi, dan Snake on Meteor. 

## Anggota Kelompok 03 K03
Khairunnisa Hurun’Iin (18221004) <br />
Fahreza Yunanda (18221013) <br />
Nabilah Amanda Putri (18221021) <br />
Wildhan Hidayatullah (18221024) <br />
Vasya Izza Parsa (18221030)

## How to Play?
Compile terlebih dahulu pada terminal: gcc -o BNMO main.c src/ADT/Array/array.c src/ADT/LinkedList/linkedlist.c src/ADT/MesinKarakter/mesinkarakter.c src/ADT/MesinKata/mesinkata.c src/ADT/Point/point.c src/ADT/Queue/queue.c src/ADT/SetMap/setmap.c src/ADT/Stack/stack.c src/CONSOLE/console.c src/GAMES/dinerdash.c src/GAMES/magicshell.c src/GAMES/rng.c src/GAMES/hideincartesian.c src/GAMES/snakeonmeteor.c src/GAMES/hangman.c src/GAMES/towerofhanoi.c

Setelah itu jalankan pada terminal: ./BNMO.exe

## Available Commands <br />
START <br />
LOAD <br />
SAVE <br />
CREATEGAME <br />
LISTGAME <br />
DELETEGAME <br />
QUEUEGAME <br />
PLAYGAME <br />
SKIPGAME <br />
SCOREBOARD <br />
RESET SCOREBOARD <br />
HISTORY <br />
RESET HISTORY <br />
QUIT <br />
HELP <br />
<br />
## Available Games <br />
RNG <br />
Diner Dash <br />
Magic Shell <br />
Hide in Cartesian <br />
Hangman <br />
Tower of Hanoi <br />
Snake on Meteor <br />
