// Room: /d/nanshaolin/gchang-2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�㳡����");
	set("long", @LONG
������������ǰ��һ���㳡���㳡���з��Ÿ����˸ߵ���ͭ����¯��
ǰ����Ÿ���̨����λ����������Ӱݡ��Դ�������һ��ƫ�����
���Ǵ����о�֮�á�������һ�����ȣ�ͨ���������
LONG );

	set("exits", ([
		"east"  : __DIR__"gchang-1",
		"west"  : __DIR__"cdian-2",
		"north" : __DIR__"celang-1",
	]));

	set("outdoors", "nanshaolin");
	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));
	set("coor/x", 1810);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

