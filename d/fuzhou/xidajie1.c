// Room: /d/fuzhou/xidajie1.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����Ǹ����ϳǵ�����֡������������������λС�����ڽ�����
�ֵ��ϱ߾����Ϻ���ˡ�
LONG );

	set("exits", ([
		"east"  : __DIR__"dongjiekou",
		"west"  : __DIR__"xidajie",
		"south" : __DIR__"nanhoujie1",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1835);
	set("coor/y", -6300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
