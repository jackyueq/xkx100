// Room: /d/huangshan/renzi.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
��ɽ������֮һ����������Ȫ��������λ�����ƣ���ɰ������ɽ
��֮�У�������й����ɽ֮ʱ�����о�ʯ��ɽ��б����������԰�;һ
��Ϊ�����γ�һ�����֣���������������������ֵ�����ֱ�����¡�
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"qingluan",
	]));
	set("objects", ([
		__DIR__"npc/xiangke" : 3,
	]) );
	set("resources/water",1);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
