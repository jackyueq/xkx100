// Room: /d/xingxiu/xxroad1.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ��������������һ����ǳأ�����ǽ��
����Ʈ�������������ˡ�������ȥһƬ�����ͻ�Ұ��
LONG );
	set("exits", ([
	    "east"  : "/d/lanzhou/westgate",
	    "west"  : __DIR__"xxroad2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "silu");
	set("coor/x", -9500);
	set("coor/y", 2700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
