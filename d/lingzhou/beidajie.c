// Room: /lingzhou/beidajie.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�������ݱ���֣��ɾ�������������˫�˺ϱ�������ʮ��һ�꣬
���������·�����ߡ�����Ͷ��涼�Ǹ߸ߵ�Χǽ������ͨ������ģ�
����������Ļʹ������ˡ���Ϊ�ǻʳǺͳ����ĵ�Ψһ����ͨ�����㲻
���������߿��꣬�Ե��ر��徲��
LONG );
	set("exits", ([
		"south" : __DIR__"center",
		"north" : __DIR__"gonggate",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	set("coor/x", -17960);
	set("coor/y", 32080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
