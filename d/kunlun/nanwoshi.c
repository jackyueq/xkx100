// Room: /d/kunlun/nanwoshi.c
// Last Modified by winder on Nov. 15 2000

inherit ROOM;

void create()
{
	set("short","�е�����Ϣ��");
	set("long",@LONG
���Ǽ�������᷿�������������е����ǵ���Ϣ�ң���Ϊ�Ŵ�����
�ţ����ߺܻ谵��������ż�����ʰ�����������ľ�������ž�������
˯����
LONG );
	set("exits",([
		"northeast" : __DIR__"jiuqulang8",
	]) );
	set("no_clean_up",0);
	set("no_fight", 1);
	set("sleep_room", 1);
	set("coor/x", -120010);
	set("coor/y", 40080);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}