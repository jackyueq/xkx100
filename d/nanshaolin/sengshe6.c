// Room: /d/nanshaolin/sengshe6.c
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
		"north" : __DIR__"sengshe4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}



