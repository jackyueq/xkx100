// Room: /d/xiakedao/xkroad5.c
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����Ǹ�СС��ۡ����溣��Ư���ż���С����̧������������
�����ޱ��޼ʡ���Ÿ�ӹ��˼⣬������Ȼ��
LONG );
        set("outdoors", "xiakedao");
	set("exits", ([
		"east"    : __DIR__"xkroad4",
	]));
	set("objects", ([
		__DIR__"npc/shizhe" : 1,
	]));
	set("coor/x", -1410);
	set("coor/y", -9000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}