// Room: /d/huijiang/xiepo.c
// Last Modified by winder on Sep. 12 2001
inherit ROOM;

void create()
{
	set ("short", "б��");
	set ("long", @LONG
���ߵ�����ϡϡ����ģ������������ĺ��紵���з���ɳɳ��������
����Ĳ�ԭ��ţ���ڳԲݣ�����Ĺ�������Ļ��ű��ӣ������������
�м�������͸��һ��ɱ����
LONG);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"caoyuan",
		"southup"   : __DIR__"buluo2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50050);
	set("coor/y", 9070);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
