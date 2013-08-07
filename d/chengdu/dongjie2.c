// Room: /d/chengdu/dongjie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����ߵ��⣬�����������������������������ƺ��������š����ˡ�
��ľ��֮������˳��������ȥ��������ǰһ���ϸߵ����ţ�����������
�����֡��Ѿ��¡��������ϱ߿�ȥ��ֻ����һ��С�֡�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"west"  : __DIR__"dongjie1",
		"east"  : __DIR__"dongjie3",
		"north" : __DIR__"shimiao",
		"south" : __DIR__"xiaojie",
	]));
	set("objects", ([
		__DIR__"npc/seng-ren" : 1,
	]));
	set("coor/x", -8030);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

