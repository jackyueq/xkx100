// Room: /lingzhou/qingtongxia.c
// Java Sep.23 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ͭϿ");
	set("long", @LONG
�����ǻƺӺ������ȶ������ļ�����ͭϿ���ƺ�һ·���ʵ����
�����ĺ���һ���ӱ�խ���������ͱ���һ���������˽�����Ը�ֿ���
�ƺ�ȴ�󲻶��µĺ��Ӵ���Ӳ�����������ˮ��һ���ӱ������������
�������죬ˮ��¡¡��
LONG	);
	set("exits", ([
		"northeast" : __DIR__"xiaoba",
		"southwest" : __DIR__"mingshazhou",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	set("coor/x", -17980);
	set("coor/y", 32020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
