// Room: /d/huijiang/zhangpeng2.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set ("short", "����");
	set ("long", @LONG
���Ƕ��ݲݼӹ���ţƤ���񣬵���������ձ�ӣ������Ѿ����ƾ��ˣ�
����ϴˢ�úܸɾ���һ�ߵ������Ϸ��Ÿ�СС�ĺ�ɫ���ӣ�����֮�⣬��
���о�һ������ˮ��������ˮ�롣
LONG);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"buluo2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50040);
	set("coor/y", 9060);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
