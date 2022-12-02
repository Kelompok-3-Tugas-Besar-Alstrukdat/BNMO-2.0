# BNMO-2.0
## Deskripsi
BNMO (dibaca: Binomo) adalah sebuah robot video game console milik Indra dan Doni yang membantu mereka melepas stress ketika mendapatkan tugas selama di Institut Teknologi Bandung. BNMO dulunya memiliki sistem inventarisasi & toko game yang baik. Indra dan Doni menjalani kuliah dua semester di ITB dan merasa kesulitan, juga stress. Doni menghabiskan waktu dengan BNMO untuk bermain game. Namun, Indra lebih suka bersenang-senang bermain gacha, tetapi ia rugi terus. Namun, dua bulan yang lalu, Indra membanting BNMO sehingga BNMO pun rusak. Doni dan Indra merasa depresi saat mereka tahu BNMO rusak. Mereka pun segera berusaha memperbaiki BNMO. Akan tetapi, setelah diperbaiki, BNMO justru mendapatkan lebih banyak bug dalam sistemnya. Oleh karena itu, Doni dan Indra pun meminta bantuan kami sebagai programmer handal untuk memperbaiki dan ulang memprogram robot video game console kesayangan mereka, yaitu BNMO karena mereka tidak cukup ahli dalam coding. Kelompok kami pun segera memperbaiki BNMO yang terdiri dari beberapa fungsi ini dengan menggunakan bahasa pemrograman C. Program ini tidak hanya ditujukan untuk Doni ataupun Indra, tetapi siapapun yang ingin mengakses robot game ini dapat menggunakannya, asal sesuai dengan ketentuan yang telah ditetapkan. Semoga dengan program yang telah kami buat ini Doni dan Indra dapat lebih mudah dalam mengakses seluruh item di dalam robot gamenya dengan menggunakan komputer. BNMO diprogram menggunakan Bahasa C dan merupakan permainan yang berbasis CLI (Command Line Interface). Program permainan BNMO ini memanfaatkan berbagai struktur data terkait list, array, mesin karakter, mesin kata, queue, stack, set, map, dan linked list yang dibuat demi memenuhi kebutuhan program dalam permainan. Alur permainan BNMO dimulai dari pengguna yang dapat login ke dalam robot game dan melakukan berbagai aksi seperti menambah game, menghapus game, menambah game ke antrian, dll. Pada BNMO 2.0 ini, tiga game tambahan yang dibuat yaitu Hangman, Tower of Hanoi, dan Snake on Meteor. 

## Anggota Kelompok 03 K03
Khairunnisa Hurun’Iin (18221004)
Fahreza Yunanda (18221013)
Nabilah Amanda Putri (18221021)
Wildhan Hidayatullah (18221024)
Vasya Izza Parsa (18221030)

## How to Play?
Compile terlebih dahulu pada terminal: gcc -o BNMO main.c BNMO_display.c src/ADT/Array/arraydin.c src/ADT/MesinKarakter/mesinkarakter.c src/ADT/MesinKata/mesinkata.c src/ADT/Point/point.c src/ADT/Queue/queue.c src/Command/another_command.c src/Command/save.c src/Command/creategame.c src/Command/deletegame.c src/Command/queuegame.c src/Command/playgame.c src/Command/skipgame.c src/Command/help.c src/Games/DinerDash/diner_dash.c src/Games/HideInCartesian/hide_in_cartesian.c src/Games/MagicShell/magic_shell.c src/Games/RNG/rng.c

Setelah itu jalankan pada terminal: ./BNMO.exe

Available Commands
START
LOAD
SAVE
CREATEGAME
LISTGAME
DELETEGAME
QUEUEGAME
PLAYGAME
SKIPGAME
QUIT
HELP
Available Games
RNG
Diner Dash
Magic Shell
Hide in Cartesian
