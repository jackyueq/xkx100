// square.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����ǻ�ɽ�ɵ����䳡���������ż���ľ�ˣ������Ǳ����⣬����
�Ǹ�С�ꡣͨ������໪ɽ�ɵ����ڴ�ϰ�����������ߵķ������Ϲ���
һ���ң����顸Ⱥ�ɹۡ����������ƺ�����С��ͨ��ɽ�ϡ�
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west"      : __DIR__"shop",
		"east"      : __DIR__"bingqifang",
		"south"     : __DIR__"yunu",
		"north"     : __DIR__"qunxianguan",
		"northwest" : __DIR__"chaopath1",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -860);
	set("coor/y", 200);
	set("coor/z", 120);
	setup();
}
 
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam=(mapping)me->query("family");
	if ((!myfam ||myfam["family_name"] != "��ɽ��") && (dir == "east"))
		return notify_fail("�Ǳ��ǻ�ɽ�ɵı����⣬��λ" + RANK_D->query_respect(me) + "��ֹ����\n");
	return ::valid_leave(me, dir);
}
 
