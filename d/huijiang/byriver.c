// Room: /d/huijiang/byriver.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set ("short", "����");
	set ("long", @LONG
��ԭ����һ����ɽ�������������������ɽ����ȫ�ǰ�����ѩ��
ɽ������ȴ�����Դ���ľ������С����ౣ����б���ײ�����ٲ�����֯
��һƬ������
LONG);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"byriver1",
		"south" : __DIR__"xiaoxi2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50030);
	set("coor/y", 9020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
