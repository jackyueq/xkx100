// Room: /d/baituo/huayuan.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
���Ǹ������Ĵ�԰��԰�������������޵ĺ�õ�塣������Ů����
������Ϸ���������������Ļ���������ͨ��ɽׯ�����ط��������ǳ�
���������ǰ���ɽ������ŷ���ˡ������ң��������ţ���֪�����ڲ��ڡ�
LONG	);
	set("exits",([
		"west"  : __DIR__"neishi",
		"north" : __DIR__"zhuyuan",
		"east"  : __DIR__"chufang",
		"south" : __DIR__"tuitang",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/whitelady" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 20060);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}




