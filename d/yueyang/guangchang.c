// Room: /d/yueyang/guangchang.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
����һ������С����ʯ�㳡���㳡��Χ��һЩ�Ͱ����񷿣��϶�
��һ��Ϸ̨��Ϸ̨�����񱻷��괵����Щ�ưܣ�̨�϶��˲��������
���ϴ��˲���С���������Щ���ҡ�
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"xijie",
	]));
	set("objects", ([
		__DIR__"npc/liumang" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 1,
	]));
	set("coor/x", -1420);
	set("coor/y", -2280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
