// Room: /d/wuxi/sanfengqiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ǰһ�����׹��ţ���һ���ʺ�����ϳ����ϣ��ŵ������·�����
����̦�������ˮ����ʾ���꼾ʱ��ˮλ�������Ϲ��ϵ���ש�����Ե�
��ʯ������˵�����ƾõ���ʷ�������Ͽ���ȥ�������Ǵ�Խ���е��˺�
���ٻ������˺�����߮��һ��ҹĻ���٣���ˮ�����ǵ�㣬ǡ�����ϵ�
���ǡ�����֮�����ŵ��ϱ���ͷ���ϴ�����
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"south" : __DIR__"southroad2",
		"north" : __DIR__"southroad1",
	]));
	set("objects", ([
		"/d/city/npc/liumangtou" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -820);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}