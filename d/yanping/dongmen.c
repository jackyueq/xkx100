// Room: /d/yanping/xiaoshuimen.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ź߳ơ�Сˮ�š�����Ϊ�����±�����ͷ�����ճ�֮��Сˮ�š�
������ӽ�����Ӹ����Ǹ�����ˮ�š����Եġ���ƽ����ɽ��ˮ����ͷ
���Ǵ��Ļ��������ͣ���ǽ���Ǵ�����ש���������ˡ������⣬һ
�����ź��������
LONG );
	set("exits", ([
		"north"    : __DIR__"fengguanyan",
		"south"    : __DIR__"road1",
		"westup"   : __DIR__"meishanpo",
		"eastdown" : __DIR__"fuqiao1",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1520);
	set("coor/y", -6170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
