// shaluo.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "ɯ��ƺ");
	set("long", @LONG
������Ȫ��̤������ʯ������ɽ�����ζ��ϣ���������ɯ��ƺ������
��ɽ·��ʼ���ͣ�����һ���ػ�������ɽ����������ʮ���̡���ͨ��ɽ�ϡ�
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"northwest" : __DIR__"path1",
		"northeast" : __DIR__"shanhongpb",
		"southup" : __DIR__"yunmen",
	]));
	set("objects", ([
		__DIR__"npc/haoke": 2,
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "huashan" );
	set("coor/x", -910);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
}
 
void init()
{
	object me = this_player();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/shaluo", 1);
	return;
}
