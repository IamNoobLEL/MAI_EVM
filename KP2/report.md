**Московский Авиационный Институт**

**(Национально Исследовательский Университет)**

**Факультет информационных технологий и прикладной математики**

**Курсовая работа по курсу**

**«Вычислительные системы»**

**Первый семестр**

**Задание 2**

«Схема лабораторной вычислительной системы»

Студент: Боев Савелий Сергеевич

Группа: М8О-107Б-21

Преподаватель: Найдёнов И.Е.

Оценка:

Дата: 04.12.2021

# **Оглавление**

**[Введение](#введение)**

**[Схема терминального класса](#схема-терминального-класса)**

**[Оборудование лаборатории](#оборудование-лаборатории)**

**[Описание и протоколы подсетей](#описание-и-протоколы-подсетей)**

**[Серверы](#серверы)**

**[Операционная система (linux ubuntu server 16.04)](#операционная-система-linux-ubuntu-server-1604)**

**[Принтер HP LaserJet 4000TN](#принтер-hp-laserjet-4000tn)**

**[Проектор InFocus](#проектор-infocus)**

**[Коммутаторы](#коммутаторы)**

**[Беспроводные точки доступа](#беспроводные-точки-доступа)**

**[Заключение](#заключение)**

**[Список литературы](#список-литературы)**

# **Введение**

В жизни человек, который делает всю работу в одиночку обычно делает ее намного медленнее чем группа людей, делающая  абсолютно туже работу. Так же и с компьютера один компьютер делает работу дольше, чем ее делали бы два объединенных компьютера. Но речь пойдет не кластерах, а объединение компьютеров в сеть.

Давайте на секунду представим, что люди работают за компьютерами и не имеют возможности удаленно общаться, обмениваться информацией, обсуждать идеи, устраивать демонстрации. Во сколько упадет производительность труда? Ответ дали давно – в десятки раз, а в некоторых случаях, работа вообще будет не возможна. Именно для сокращение времени выполнения работы в большинстве случаев используют объединение компьютеров в одну сеть.

В своей курсовом проекте я опишу структуру сети компьютерного класса МАИ. Сеть называется UMC-8.Основанная на протоколе TCP/ IP сеть имеет вид звезды. Подключенный к коммутатору компьютер имеет доступ ко все другим в этой сети. И получает доступ к любым данным на них (к которым разрешен доступ). Так же к этой сети можно подключаться через Wi-Fi.

# **Схема терминального класса**

![](https://i.imgur.com/OvHpsOj.gif)

# **Оборудование лаборатории**

В кабинетах, для проведения практических занятий по информатике и вычислительным системам, находятся два сервера: Cameron и Axp4 (Альфа), к ним посредством различных коммутаторов и роутеров подключены персональные компьютеры, расположенные в двух классах, а также другое вспомогательное оборудование. Начнем с кабинета 438б, в котором расположены 23 вычислительные машины с разными внутренними характеристиками. 10 компьютеров используют процессор Pentium E5300, а также 64-битную операционную систему Ubuntu 16.04. Эти компьютеры подключены к коммутатору TP-Link TL-SG1024D, который в свою очередь напрямую подключен к серверам, а также к коммутатору MicroTik.

Остальные 13 машин основаны на процессоре Intel Celeron и 32-битной версии операционной системы Ubuntu 16.04. Эти машины подключены к коммутатору MicroTik, соединённым Cameron&#39;ом и Альфой, а также с коммутаторами TP-Link TLSG1024D и 3COM 3300XM. Также в кабинете установлен принтер HP LaserJet 4000TN и имеется точка доступа Wi-Fi MicroTik.

Перейдем к кабинету 440, в котором установлены более мощные компьютеры, работающие на процессорах Intel Core i5-3470. Для решения более сложных и обширных задач на этих компьютерах установлено сразу по две операционные системы – это Windows 7 Pro 64 bit и Ubuntu 16.04 LTS. Все они подключены к коммутатору 24x1000BT. Этот коммутатор собирает и передает всю информацию уже через другой коммутатор – 3COM 3300XM. В этом классе также имеется принтер, установлена точка доступа к Wi-Fi и проектор.

Такое расположение и соединение позволяет добиться бесперебойности работы сети даже при поломке одного из коммутаторов. Так например при поломке роутера MicrоTik перестанут работать только 10 машин из 46

# **Описание и протоколы подсетей**

Подсеть 192.168.0.0/24

Включает компьютеры, находящиеся в аудитории 428 (DNS-зона zzz.umc8.ru). Это компьютеры на рабочих местах сотрудников кафедры. Объединены в 100-мегабитную сеть посредством двух свичей. Выход в подсети 192.168.2.0/24 и 172.16.80.0/24 осуществляется через сервер chinua, причем при выходе в подсеть 172.16.80.0/24 осуществляется трансляция адресов ([?](http://k806.ru/ikiwiki.cgi?from=admiron&amp;do=create&amp;page=NAT)http://ru.wikipedia.org/wiki/NAT), чтобы предотвратить доступ к компьютерам сотрудников из сети института.

Подсеть 192.168.2.0/24

Включает компьютеры 438-й ауд. (рабочие компьютеры и сервера kuantan, axp4 и axp1), а также ноутбуки, подключенные к WiFi-сети zzznet. В ней находятся 13 немного устаревших (с белыми корпусами) и 10 относительно новых (с черными корпусами) машин, работающих как бездисковые рабочие станции, которые загружаются по сети с kuantan&#39;а и работают через NFS. Бездисковые машины работают под FreeBSD 8.2. Белые компьютеры соединены через 2 100-мегабитных свича (8- и 24-портовые). Черные — посредством двух 8-портовых гигабитных свичей, к одному из которых подключен сервер kuantan. !WiFi и Bluetooth точки доступа подключены к 24-портовому свичу.

Подсеть 172.16.80.0/24

Включает компьютеры 440-й ауд. (зона alice.umc8.ru), а также другие компьютеры факультета. Сервера kuantan и chinua также подключены к ней посредством дополнительных сетевых карт.

DNS (англ. Domain Name System — система доменных имён) — компьютерная распределённая система для получения информации о доменах. Чаще всего используется для получения IP-адреса по имени хоста (компьютера или устройства), получения информации о маршрутизации почты, обслуживающих узлах для протоколов в домене (SRV-запись). Распределённая база данных DNS поддерживается с помощью иерархии DNSсерверов, взаимодействующих по определённому протоколу. Основой DNS является представление об иерархической структуре доменного имени и зонах. Каждый сервер, отвечающий за имя, может делегировать ответственность за дальнейшую часть домена другому серверу (с административной точки зрения — другой организации или человеку), что позволяет возложить ответственность за актуальность информации на серверы различных организаций (людей), отвечающих только за «свою» часть доменного имени.

DHCP (англ. Dynamic Host Conﬁguration Protocol — протокол динамической настройки узла) — сетевой протокол, позволяющий компьютерам автоматически получать IP-адрес и другие параметры, необходимые для работы в сети TCP/IP. Данный протокол работает по модели «клиент-сервер». Для автоматической конфигурации компьютер-клиент на этапе конфигурации сетевого устройства обращается к так называемому серверу DHCP, и получает от него нужные параметры. Сетевой администратор может задать диапазон адресов, распределяемых сервером среди компьютеров. Это позволяет избежать ручной настройки компьютеров сети и уменьшает количество ошибок. Протокол DHCP используется в большинстве сетей TCP/IP.

Network File System (NFS) — протокол сетевого доступа к файловым системам, первоначально разработан Sun Microsystems в 1984 году. Основан на протоколе вызова удалённых процедур (ONC RPC[1]). Позволяет подключать (монтировать) удалённые файловые системы через сеть. NFS абстрагирован от типов файловых систем как сервера, так и клиента, существует множество реализаций NFS-серверов и клиентов для различных операционных систем и аппаратных архитектур. Наиболее зрелая версия NFS — v. 4[2], поддерживающая различные средства аутентификации (в частности, Kerberos и LIPKEY с использованием протокола RPCSEC GSS) и списков контроля доступа (как POSIX, так и Windows-типов). NFS предоставляет клиентам прозрачный доступ к файлам и файловой системе сервера. В отличие от FTP, протокол NFS осуществляет доступ только к тем частям файла, к которым обратился процесс, и основное достоинство его в том, что он делает этот доступ прозрачным. Это означает, что любое приложение клиента, которое может работать с локальным файлом, с таким же успехом может работать и с NFS файлом, без каких-либо модификаций самой программы.

# **Серверы**

Серверам называется компьютер, выделенный из группы персональных компьютеров (или рабочих станций) для выполнения какой-либо сервисной задачи без непосредственного участия человека.

Сервер и рабочая станция могут иметь одинаковую аппаратную конфигурацию, так как различаются лишь по участию в своей работе человека за консолью.

**Описание серверов**

**Сервер chinua**

Расположен в ауд. 428 и подключен одновременно к трем сетям и имеет следующие адреса: 192.168.0.1 - с.zzz.umc8.ru. 192.168.2.10 chinua.zzz.umc8.ru. 172.16.80.237 c.806.umc8.ru и chinua.alice.umc8.ru.

Он выполняет функции маршрутизатора, а также является DНСР-сервером для компьютеров 428-й и 440-ауд. и DNS-сервером зон zzz.umc8.ru, zzz.umc8.ru и 806.um08.ru.

Конфигурация chjnua:

Процессор: АМВ Athlon П Х2 240, 2.8 ГГц

Оперативная память: 8 ГБ DDR2

Жесткий диск: RAID-1 SATA 1,5 Тб

ОС: DragonflyBSD 2.8.2

**Сервер Cameron 12**

Расположен в ауд, 438 и выполняет функции NFS», DHCP-, NIS-, fip-, а также кеширующего DNSсервера ауд. 438. Он находится одновременно в двух сетях и доступен по адресам 192.168.2.50 (kuantan.zzz.ume8.ru) и 172.16.80.225 (k.806.umc8.ru и kuaman.alice.um08.ru)

Конфигурация cameron:

Процессор: Intel CoreZ Duo, 3.16 ГГц

Оперативная память: 4Гб DDR2

Жесткий диск: RAID-l SATA 500Гб

**Сервер Alice**

Сервер Alice — файловый сервер и сервер приложений.

Файл-сервер — это выделенный сервер, предназначенный для выполнения файловых операций ввода-вывода и хранящий файлы любого типа. Как правило, обладает большим объемом дискового пространства, реализованном в форме RAID-массива для обеспечения бесперебойной работы и повышенной скорости записи и чтения данных.

Сервер приложений (англ. applicalion server) — это программная платформа (фреймворк), предназначения для эффективного исполнения процедур (программ. скриптов). на которых построены приложения. Сервер приложений действует как набор компонентов, доступных разработчику программного обеспечения через АРI (интерфейс прикладного программирования), определённый самой платформой.

**Соглашения об именовании узлов сети**

Компьютеры подсетей 192.168.2.0/24 и 192.168.0.0/24 имеют имена монстров компьютерной игры Nelhack, а также городов Малайзии и Тайланда. Находятся в DNS-зоне zzz.umc8.ru.

B подсети 172.16.80.0/24 часть компьютеров, которые физически находятся в ауд. 440 имеют 13 однобуквенные имена в DNS- зоне zzz.umc8.ru. Адресам kuaman&#39;a и chinua из этой подсети соответствуют имена c.alice.um08.ru и k.806.umc8.ru. Для удобства они имеют также синонимы из зоны alice: chinua.alice.um08.ru и kuantan.umc8.ru DNS-сервером для этих зон является сервер chinua.zzz.um08.ru (192.168.2.10).

# **Операционная система (linux ubuntu server 16.04)**

Компьютеры оснащены операционной системой linux ubuntu server 16.04.

Дистрибутив Ubuntu от Canonical известен в первую очередь как система, ориентированная для начинающих. Но кроме версии для рабочего стола, Canonical выпускает еще несколько редакций, среди которых версия для облака и для серверов. Серверная версия отличается наличием пакетов и настроек, характерных для сервера, например, по умолчанию включен брандмауэр, а также нет графического интерфейса.

**СИСТЕМНЫЕ ТРЕБОВАНИЯ**

Ubuntu Server 16.04 имеет следующие минимальный системные требования:

 Процессор с частотой 300 МГц;

Оперативная память: 192 Мб;

Место на диске: 1 Гб;

Графическая карта и монитор с разрешением 640×480 или больше;

Возможность загрузки с CD или USB.

В серверной версии используется только псевдографический интерфейс, поэтому она может быть установлена даже на старые компьютеры.

Ядро версии 4.4

В основе Ubuntu 16.04 LTS лежит ядро последней стабильной версии -  4.4 которая вышла  — 10 января 2016 года.

**Управление пакетами**

Как во всех основанных на Debian дистрибутивах Linux для управления пакетами в Ubuntu используется apt (Advanced Package Tool). В Ubuntu 16.04 используется его новая версия — Apt 1.2, существенно от предыдущих не отличающася, но улучшенная с точки зрения безопасности.

Помимо традиционных deb-пакетов в Ubuntu 16.04 могут быть установлены ещё и так называемые snap-пакеты. В чём смысл этого нововведения?

Пользователям Linux довольно часто приходится сталкиваться с проблемой зависимостей, из-за которой новые версии многих программ очень сложно установить: новые версии программ требует новые версии библиотек и системных компонентов, которые в LTS-релизах получают лишь обновления безопасности. Snap-пакеты помогают эту проблему решить.

В отличие от deb-пакета, snap-пакет включает и файл приложения, и его зависимости. Это существенно упрощает жизнь пользователя: для установки последних версий не нужно ничего обновлять вручную и добавлять PPA.

# **Принтер HP LaserJet 4000TN**

Производитель: HP

Теги: Двусторонняя печать, HP LaserJet, Монохромный

Монохромный лазерный принтер.

Peйтиpoванная cкopocть мoтopа - 16 cтp. в минуту.

Пpoцeccop - RISC на 100 МГц.

Выxoд пepвoй cтpаницы - мeнee чeм чepeз 15 ceкунд.

Вpeмя pазoгpeва:  мeнee 15 ceкунд благoдаpя уcтpoйcтву тepмичecкoгo закpeплeния мгнoвeннoгo включeния.

Тexнoлoгии уcкopeния пeчати.

Функция HP TRANSMIT ONCE даeт вoзмoжнocть пoлучать МОПии (Мнoжecтвeнныe Opигинальныe pаcПeчатки).

# **Проектор InFocus**

Компания InFocus производит широкий спектр продукции, предназначенный для различных областей применения — образования, бизнеса, государственных корпораций, домашних пользователей. Основным направлением деятельности компании является производство проекторов. В ассортименте представлены модели всех основных категорий: ультрапортативные, короткофокусные, интерактивные, для офиса и образования, для крупных мероприятий, для домашнего кинотеатра — от начального уровня до сложных профессиональных со сменной оптикой. Проекторы InFocus выпускаются с яркостью до 8300 ANSI лм и разрешением до WUXGA.

В последнее время, в свете самых актуальных современных тенденций, в её ассортимент также вошли устройства формата Collaboration Technology: крупногабаритные интерактивные системы Mondopad, компьютеры с сенсорным экраном BigTouch, сенсорные дисплеи JTouch, системы для видеоконференций MVP100, а также планшеты QTablet, аксессуарика, периферийное оборудование и ПО для цифровых подписей и видеозвонков. С 2013 года InFocus участвует в совместном проекте с тайваньской компанией FIH Mobile LTd  по производству смартфонов под собственной маркой InFocus.

# **Коммутаторы**

Функциональность коммутатора 3com 3300XM

Управляемый дуплекс на всех портах (авто, полу-дуплексный и полнодуплексный режимы)

Возможность автоматического или принудительного перехода на 10base-TX на 100Mbit&#39;ных портах

Полная поддержка VLAN (802.1q)

Встроенный web-сервер для управления

Приоритезациятрафика (802.1p)

Различныеметодыработыкоммутатора - cut-through/fast forward, cut-through/fragment-free, store-and-forward, and intelligent forwarding modes

Возможность объединения до 4х коммутаторов 3com 3300 или 3com 1100 в одно устройство

Режим security - привязка MAC-адреса к порту вручную

Слот для модуля расширения (существуют модули для оптики, гигабитного ethernet)

Память на 6000 MAC адресов

Управление потоками трафика по стандарту 802.3x

Поддержка протокола Spanning Tree - увеличение надежности используя избыточную топологию

Возможность объединять порты в транки для увеличения скорости

Возможность обновления прошивки

Возможность установки в 19&quot; стойку (Rack-mount) или на стену (Wall-mount)

Поддержка IGMP Snooping

**TP-Link TL-SG1024D**

Все 24 порта коммутатора являются гигабитными портами RJ-45, обеспечивают передачу файлов большого размера, а также совместимы с устройствами, работающими на скоростях 10 Мбит/с и 100 Мбит/с. Благодаря использованию неблокирующей архитектуры коммутатор TL-SG1024D может передавать и фильтровать пакеты на максимально возможной для сетевой среды скорости, обеспечивая максимальную пропускную способность. Значительным образом улучшена передача файлов большого размера за счет использования Jumbo-кадров размером в 10 Кбайт. Функция контроля потока IEEE 802.3x для полнодуплескного режима и Back Pressure (функция приостановки/задержки передачи при переполнении буфера) предотвращают перегрузку сетевого трафика и повышают надёжность работы коммутатора TL-SG1024D. Устройство представляет собой идеальный выбор для усовершенствования сети до гигабитных скоростей, позволяя сэкономить на приобретении новых устройств. Функции автосогласования гигабитного коммутатора значительно облегчают установку устройства. Не требуется дополнительной настройки. Функция авто-MDI/MDIX устраняет необходимость применения кабеля с перекрещивающимися парами. Функция автосогласования на каждом порту определяет скорость соединения сетевого устройства (10, 100 или 1000 Мбит/с) и производит настройку совместимости и оптимального режима работы.

# **Беспроводные точки доступа**

MikroTik:

Компания MikroTik, основанная 1995 году, известный в Мире латвийский производитель сетевого и компьютерного оборудования. Сфера деятельности MikroTik включает в себя производство беспроводных маршрутизаторов и разработку операционных систем к ним, а так же выпуск сопутствующего оборудования.

Одна из ведущих разработок MikroTik – операционная система RouterOS, обеспечивающая высокую гибкость конфигурирования, стабильность и контроль всех типов соединений и аппаратных платформ. RouterOS создана на базе известной ОС Linux и лицензирована в расширении уровней. Чем выше номер уровня лицензии RouterOS, тем больше функций заложено в операционную систему.

В 2002 году MikroTik выпустил собственный маршрутизатор, который положил начало целой линейки продукции под названием RouterBoard. Точка доступа MikroTik RouterBoard Groove набирает популярность среди пользователей и не уступает по производительности известным Ubiquiti Bullet.

Линейка точек доступа MikroTik SXT стала одной из самых популярных на рынке, благодаря отличным техническим характеристикам и удобной конструкции со встроенной антенной. Внутри точек mikrotik rb sxt установлена операционная система RouterOS.

# **Заключение**

В заключение хотелось бы подвести итог всему вышесказанному.

Сеть лабораторного класса позволяет позволяет пользователю бес проблем подключиться к любой машине, к которой у него есть доступ. Каждый пользователь заходит в систему под своим логином и паролем. Благодаря такой структуре, существенно уменьшаются затраты на винчестеры, так как установлена бесплатная операционная система, затраты сокращаются и на нее.

Но минус такой системы в том, что каждый компьютер зависит от сервера, и если сервер падает, то падают все компьютеры.

Наша сеть полностью выполняет свой функционал, пока я работал на терминале, ошибок и падений не было, что свидетельствую о ее грамотном составлении.

# **Список литературы**

- Сайт для создания диаграмм [Электронный ресурс]. - URL: https://www.draw.io/
- Информация по подсетям и серверам [Электронный ресурс]. – URL:  http://k806.ru/
- Информация по принтеру [Электронный ресурс]. – URL:  https://www.standardcopy.ru
- Информация по роутеру [Электронный ресурс]. –URL:  http://we-it.net
- Информация по коммутаторам[Электронный ресурс]. URL: http://www.tp-linkru.com/
- [КП2. Боев Савелий.docx](https://github.com/CS806/kp2-IamNoobLEL/files/7653534/2.docx)
