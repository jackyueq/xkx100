// Room: /d/nanshaolin/gulou7.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¥�߲�");
	set("long", @LONG
������ǹ�¥֮����ֱ�������ı���һֻ��ġ���Ĺ���ͨ�죬��
�ɰ���ľ���ɡ���ͷ����ˮţƤ����һ�Ѵ�ͭ�����ڹ����Ե��������
һȦ���գ���������Ϊ��λ����γɵġ�������ķ���һ��һ�˸ߵļ�
���ϣ����ӵײ�����������鳡�
LONG );
	set("exits", ([
		"down" : __DIR__"gulou6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
