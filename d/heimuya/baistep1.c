// Room: /d/heimuya/baistep1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","����");
	set("long", @LONG
�����ǰ׻��õĳ��ȡ�����һƬ�ǽ壬�����Ӹձ�ϴ��һ�������
��ʬ���Ҳ��̶á�
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"east" : __DIR__"dating2",
		"south" : __DIR__"baistep2",
	]));
	set("objects",([
		__DIR__"npc/jiaotu"   :1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
