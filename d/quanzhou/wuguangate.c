// Room: /d/quanzhou/wuguangate.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ݴ���");
	set("long", @LONG
һ�����ɻԻ͵���ݡ���������Ա߰�������ͷ�ߴ����ͣ�������
����ʯʨ�ӡ����Ϲ���һ��ڵ״��Ҷ�ĸ�ˢ��Ĵ��֡�������ݡ�
�������⡣��߲���һ�����ɶ�ߵ���ˣ����š��䡱�ֵĺ������Ʈ
�����ǳ����������ϣ�������������ݣ��ö���е��ӵܶ��ڴ�ѧ
Щȭ�ű������򡣹�������º����ÿͣ������ϳ�֮�硣��Ƹ��ͷ����
һ��һ����湦��ĺ��֡�
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"west" : __DIR__"kaojiaochang",
		"east" : __DIR__"zhaiqu2",
	]));
	set("objects", ([
		__DIR__"npc/mengding" : 2,
	]));
	set("coor/x", 1830);
	set("coor/y", -6550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
