// Room: /d/xingxiu/kezhan2.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;
void create()
{
	set("short", "��ջ��¥");
	set("long", @LONG
���������������ջ�Ķ�¥��¥���������ڣ���ʱƮ����һ��������
��Ŀ�����ζ����������˿����ڴ������������˯һ����
LONG);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([ 
	     "down" : __DIR__"kezhan",
	]));
	set("objects", ([
		__DIR__"npc/yin": 1,
	]));
	set("coor/x", -39000);
	set("coor/y", 13100);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
