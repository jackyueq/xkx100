// Room: /lingzhou/deling.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�������Ԫ껵ĸ����Ե�������Ĺ����ʮ�׸����ף�Ϊ����������
��ߴ�Ҳ���������Ľ�������ǰ���Ҹ�������ʯ����ʿ��������ǰ�к�
��������Χ�ɵ�ƽ̨������ʯ��ʯ��һӦ��ȫ��
LONG );
	set("exits", ([
		"south"   : __DIR__"chiling",
		"north"   : __DIR__"gongling",
	]));
	set("objects", ([
		__DIR__"npc/shiwushi" : 2,
	]));
	set("outdoors", "lingzhou");
	set("coor/x", -17920);
	set("coor/y", 32160);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
