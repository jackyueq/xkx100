// Room: /d/wuxi/shuchang.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����鳡");
	set("long", @LONG
����Ȼ��һ���Ϸ����鳡����Ҳ���ü��ݲ������������Ա�����
���ϴ�����ˡ���ԭ�����������������գ���Ȼ��������ܻ�ӭ�Ļ�
�Ǹ������������������õ�������Ŀ����м�������ȥ�������Ų�ˮ
��ë�������������ڡ�
LONG );
	set("exits", ([
		"east" : __DIR__"southroad2",
	]));
	set("objects", ([
		__DIR__"npc/shuke" : 1,
	]));
	set("coor/x", 360);
	set("coor/y", -830);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}