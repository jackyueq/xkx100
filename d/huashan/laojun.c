// laojun.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "�Ͼ���");
	set("long", @LONG
��������Ҫ�������£�������������ЪϢ���Ͼ�����һ������೤
��ɽ�����ഫΪ̫���Ͼ����ˣ�����·��ͨ��������ϴ���ţ��������
������������Ϊ��ɽͨ����
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"pingxinshi",
		"southup"  : __DIR__"husun",
	]));
	set("objects", ([
		 __DIR__"npc/lao-denuo": 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -870);
	set("coor/y", 230);
	set("coor/z", 70);
	setup();
}
 
int valid_leave(object me, string dir)
{
	if ((me->query("family/family_name") == "��ɽ�ɽ���") &&
		dir == "southup" &&
		objectp(present("lao denuo", environment(me))))
		return notify_fail("�͵�ŵȰ������ʦ�н���������إ����ǰ���뿪��ɽ�ˣ����ϲ��ǻ�ɽ�����ˡ�\n�������Ϻ��ˣ���λ" + RANK_D->query_respect(me) + "������ذɡ�\n");
	return ::valid_leave(me, dir);
}
 
