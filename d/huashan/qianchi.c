// qianchi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "ǧ�ߴ�");
	set("long", @LONG
ǰ����һб���촹ʯ�ݵ�ɽ�ף�����Ǻպ�������ǧ�ߴ���ǧ�ߴ�
����һ�����Ҽ����ѷ쿪����ɣ�б��Լ��ʮ�ȣ���Լ��ʮ�ף�����һ
�����䡣̧ͷ����һ����⣬�����ұڶ��ͣ���ͷ�Ǹ���������ķ���
ʯ�����׳ơ��쾮�����쾮�Ե�Σ���Ͽ��С�̫���ʺ�����̡�
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"huixinshi",
		"southup" : __DIR__"baichi",
	]));
	set("objects", ([
		__DIR__"npc/youke": 2,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -890);
	set("coor/y", 240);
	set("coor/z", 40);
	setup();
}
 
int valid_leave(object me, string dir)
{
	if (dir == "southup" && userp(me))
	{
		me->receive_damage("jing", 30);
		me->receive_damage("qi", 30);
	}
	return 1;
}
