// Room: /d/heimuya/baistep2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","����");
	set("long", @LONG
�����ǰ׻��õĳ��ȡ�����һƬ�ǽ壬�����Ӹձ�ϴ��һ�������
��ʬ���Ҳ��̶ġ�
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"north" : __DIR__"baistep1",
		"south" : __DIR__"baihutang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
