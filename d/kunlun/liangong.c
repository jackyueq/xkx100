// Room: /d/kunlun/liangong.c ������
// Last Modified by Winder on Nov. 15 2000

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ҵط��ż������ţ������˴󵶳�����ɳ��
���ȵȣ������ص����ճ������ĵط���
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"jiuqulang4",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", -119970);
	set("coor/y", 40120);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}