// Room: /d/kunlun/nvwoshi.c
// Last Modified by winder on Nov. 15 2000

inherit ROOM;

void create()
{
	set("short","Ů������Ϣ��");
	set("long",@LONG
���Ǽ�������᷿������������Ů�����ǵ���Ϣ�ң���Ϊ�Ŵ�����
�ţ����ߺܻ谵��������ż�����ʰ�����������ľ�������ž�������
˯����
LONG
);
	set("exits",([
		"northwest" : __DIR__"jiuqulang2",
	]) );
	set("no_clean_up",0);
	set("no_fight", 1);
	set("sleep_room", 1);
	set("coor/x", -119970);
	set("coor/y", 40080);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}