// Room: /d/nanshaolin/sengshe2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ɮ��");
	set("long", @LONG
������ɮ������ʳ��ӵĵط�����ǽһ����ż���ľ���������̵�
����ϯ����ͷ���Ŵ�������������غ��䣬ɮ����ȫ����ʵ���ڹ�����
��������������ķ��ż������ź�ľ�㡣
LONG );
	set("sleep_room",1);
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"sengshe3",
		"south" : __DIR__"sengshe1",
    	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
