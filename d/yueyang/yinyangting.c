// Room: /d/yueyang/yinyangting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ͤһ��һС��һ��һ�͡�һ��һ���������������Ů��������
���Ա�����ͥ��ɽ��ɫ��
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"dongtingmiao1",
	]));
	set("coor/x", -1650);
	set("coor/y", 2350);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
